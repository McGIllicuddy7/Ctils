#pragma once
/*use #define CTILS_IMPLEMENTATION*/
#ifndef CTILS_STATIC
#define CTILS_STATIC
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>
#include <wchar.h>
#include <sys/time.h>
#include <stdint.h>
#include <math.h>
#include <pthread.h>
#include <signal.h>

/*
	Initial Defines
*/
CTILS_STATIC
void no_op_void(void*);
#define STRINGIFY1(S) #S 
#define STRINGIFY(S) STRINGIFY1(S)
#define CONSTRUCTED(Type, name, fn, ...) Type name; __attribute__((constructor)) static void construct__##name__##fn () { name = fn(VA_ARGS);}
CTILS_STATIC
void * debug_alloc(size_t count, size_t size);

CTILS_STATIC
void debug_global_free(void * ptr);

CTILS_STATIC
void *debug_realloc(void * ptr, size_t size);

CTILS_STATIC
void debug_alloc_and_global_free_counts(void);

#ifndef global_alloc
#define global_alloc(count,sz) debug_alloc(count, sz)
#endif 
#ifndef global_free
#define global_free(ptr) debug_global_free(ptr)
#endif
#ifndef global_realloc
#define global_realloc(ptr, sz) debug_realloc(ptr, sz);
#endif
#ifndef str_type
#define str_type char
#endif
#define nil 0

#define todo(...) {fprintf(stderr, "todo " __VA_OPT__("%s ")"line:%d, file:%s""\n",__VA_ARGS__ __VA_OPT__(,)__LINE__, __FILE__ ); raise(SIGINT);}
typedef unsigned char Byte;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef __int128_t i128;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef __uint128_t u128;
typedef double f64;
typedef float f32;
typedef char * cstr;
typedef void * void_ptr;
#ifdef __cplusplus
#include <type_traits>
#define typeof(T) decltype(T)
#endif
/*
Memory stuff
*/

CTILS_STATIC
void mem_shift(void * start, size_t size, size_t count, size_t distance);
/*
Arena stuff 
*/
typedef struct ArenaDestructor{
	void (*destructor)(void*);
	void * address;
	struct ArenaDestructor * next;
	
} ArenaDestructor;
typedef struct Arena{
	pthread_mutex_t lock;
	char* buffer;
	char* next_ptr;
	char*end;
	char* previous_allocation;
	struct Arena * next;
	void * defer_queue;
	ArenaDestructor * destructor_queue;
	bool is_static;
} Arena;

CTILS_STATIC
Arena * arena_create(void);

void arena_destroy_thunk(Arena **);
#define new_arena(name) __attribute__((cleanup(arena_destroy_thunk))) Arena * name; name = arena_create()


CTILS_STATIC
void arena_destroy(Arena * arena);

CTILS_STATIC
void * arena_alloc(Arena * arena, size_t size);

CTILS_STATIC
void * arena_realloc(Arena * arena, void * ptr, size_t previous_size, size_t new_size);

CTILS_STATIC
void arena_free(Arena * arena, void * ptr);

CTILS_STATIC
void arena_reset(Arena * arena);

CTILS_STATIC 
void defer(Arena * arena, void (*func)(void*),void * data);

CTILS_STATIC
void arena_queue_destructor(Arena * arena,void (*fn)(void *), void * address);
#ifdef __cplusplus
CTILS_STATIC template<typename T> void destruct(T * value){
	value->~T();
}
template <typename T>void arena_qd(Arena * arena, T* v){
	arena_queue_destructor(arena, (void (*)(void *))destruct<T>, v);
}
#endif
#define tmp_alloc(size) arena_alloc(&temporary_allocator, size);


#define tmp_realloc(ptr,size, new_size) arena_realloc(&temporary_allocator, size, new_size)
#define tmp_free(ptr) arena_free(&temporary_allocator, ptr)
#define tmp_reset() arena_reset(&temporary_allocator)
#define tmp_init() temporary_allocator = *arena_create()
#ifndef CTILS_IMPLEMENTATION
extern Arena temporary_allocator;
#endif
#ifdef CTILS_IMPLEMENTATION
Arena temporary_allocator = {0};
#endif
/*
Slice stuff
*/

CTILS_STATIC
void * memdup(Arena * arena,void * ptr, size_t size);
#ifdef __cplusplus
#include <new>
CTILS_STATIC template<typename T>T * memdup_destructors(Arena * arena, T * ptr,size_t count){
	T * out = (T*)arena_alloc(arena, sizeof(T)*count);
	for(int i =0; i<count; i++){
		new (&out[i]) T(ptr[i]);
		void (*func)(void *) = (void (*)(void *))(T::~T);
		void * vptr = (void *)(((T*)out +i));
		if constexpr (!std::is_trivially_destructible<T>()){
			arena_queue_destructor(arena, func, vptr);
		}
	}
}
CTILS_STATIC template<typename T> void arena_copy_to(Arena * arena,T* dest, T * src, size_t count){
	for(int i =0; i<count; i++){
		dest[i] = src[i];
	}
	if constexpr(!std::is_trivially_destructible<T>()){
		for(int i =0; i<count; i++){
			arena_queue_destructor(arena, (void (*)(void*))destruct<T>, &dest[i]);
		}
	}
}
CTILS_STATIC template<typename T, typename...Args> T * arena_new(Arena * arena, Args...args){
	T * out = (T*)arena_alloc(arena, sizeof(T));
	new (out) T(args...);
	if constexpr(!std::is_trivially_destructible<T>()){
		arena_queue_destructor(arena, (void (*)(void *))destruct<T>, out);
	}
	return out;
}
#endif
#define enable_vec_type(T) typedef struct {T * items; size_t length; size_t capacity; Arena * arena;} T##Vec; 
#ifdef __cplusplus 
template<typename T> struct Vec{T * items; size_t length; size_t capacity; Arena * arena;};
#endif
enable_vec_type(void)
enable_vec_type(Byte)
enable_vec_type(i8)
enable_vec_type(i16)
enable_vec_type(i32)
enable_vec_type(i64)
enable_vec_type(i128)
enable_vec_type(u8)
enable_vec_type(u16)
enable_vec_type(u32)
enable_vec_type(u64)
enable_vec_type(u128)
enable_vec_type(f32)
enable_vec_type(f64)
enable_vec_type(cstr)
enable_vec_type(void_ptr)

#define make(arena, T) (T##Vec){0,0,0, arena}
#define tmp_make(T) (T##Vec){0,0,0, &temporary_allocator}

#define make_static(T, ...) (const T##Vec){.items = (T[]){VA_ARGS}, .length = (size_t)sizeof((T[]){args})/sizeof(T), .capacity =0, .arena = 0}

#define make_with_cap(arena, T, cap) (T##Vec){(T*)(arena_alloc(arena,cap*sizeof(T))), 0, (size_t)(cap), arena}
#define tmp_make_with_cap(T, cap) (T##Vec){(T*)(arena_alloc(&temporary_allocator, cap*sizeof(T))), 0,(size_t)cap, &temporary_allocator}

#ifdef __cplusplus
#define clone(vec, arena) (typeof((vec))){memdup_destructors(arena,vec.items, vec.length), vec.length, vec.capacity}
#else
#define clone(vec, arena) (typeof((vec))){memdup(arena,vec.items, vec.capacity*sizeof(vec.items[0])), vec.length, vec.capacity}
#endif 

#define v_swap(a, b) {typeof(a) v_swap_temporary_value = a; a =b; b = v_swap_temporary_value;}
#ifdef __cplusplus
static bool arena_object_exists(Arena *arena, void * ptr){
	ArenaDestructor *a = arena->destructor_queue;
	while(a){
		if(a->address == ptr){
			return true;
		}
		a = a->next;
	} 
	return false;
}
template<typename T, typename U> void v_append(U& vec, T value){
	if((vec).capacity<=(vec).length+1){
		if ((vec).capacity != 0){
			T* vtmp = (T*)arena_alloc((vec).arena,(vec).capacity*sizeof(T)*2);(vec).capacity *= 2;
			memset(vtmp, 0, sizeof(T)*(vec).capacity);
			arena_copy_to((vec).arena, vtmp, (vec.items), (vec).length);
			vec.items = vtmp;
		}else{
			(vec).capacity = 16;\
			T* vtmp = (T*)arena_alloc((vec).arena, 16*sizeof((vec).items[0]));
			if((vec).items && (vec).length>0){
				arena_copy_to((vec).arena, vtmp, (vec).items, (vec).length);
			}
			(vec).items = vtmp;
		}
  	}   
  	(vec).items[(vec).length] = value; 
	size_t old_len = vec.length;
	vec.length += 1;
	if constexpr(!std::is_trivially_destructible<T>()){
		arena_qd((vec).arena, &(vec).items[(vec).length-1]);
	}
}
#else
 #define v_append(vec, value){if((vec).capacity<=(vec).length+1){\
    if ((vec).capacity != 0){\
	(vec).items =(void *)arena_realloc((vec).arena,(vec).items,(vec).capacity*sizeof((vec).items[0]), (vec).capacity*sizeof((vec).items[0])*2);(vec).capacity *= 2;}\
     else{\
		(vec).capacity = 16;\
		void *vtmp = (void *)arena_alloc((vec).arena, 16*sizeof((vec).items[0]));\
		if((vec).items && (vec).length>0){\
			memcpy(vtmp, (vec).items, sizeof((vec).items[0])*(vec).length);\
		}\
		(vec).items = vtmp;\
		}\
  }   \
  	(vec).items[(vec).length] = value; (&(vec))->length+= 1;\
  }

#endif
#define unmake(vec) arena_free((vec).arena,(vec).items) 

#ifdef __cplusplus
#define v_append_slice(vec, other_items, other_len)\
 {if(vec.capacity<vec.length+other_len){\
    size_t previous = vec.capacity*sizeof(vec.items[0]);\
    while (vec.capacity<vec.length+other_len){if(vec.capacity != 0){vec.capacity *= 2;} else{vec.capacity = 1;}}\
    vec.items = arena_realloc(vec.arena,vec.items,previous,vec.capacity*sizeof(vec.items[0]));}\
	arena_copy_to((&vec.items[vec.length], other_items, other_len);\
    vec.length += other_len; } 
#else 
#define v_append_slice(vec, other_items, other_len)\
 {if(vec.capacity<vec.length+other_len){\
    size_t previous = vec.capacity*sizeof(vec.items[0]);\
    while (vec.capacity<vec.length+other_len){if(vec.capacity != 0){vec.capacity *= 2;} else{vec.capacity = 1;}}\
    vec.items = arena_realloc(vec.arena,vec.items,previous,vec.capacity*sizeof(vec.items[0]));}\
    memcpy(&vec.items[vec.length], other_items, sizeof(vec.items[0])*other_len);\
    vec.length += other_len; } 
#endif
#define v_append_as_bytes(byte_vec, V)\
	v_append_slice(byte_vec, &((typeof(V)[1]){V}), sizeof(V))

#define v_consume(vec) (typeof(vec.items[0])*)vector_consume((voidVec *)(&vec), sizeof(vec.items[0]))
#define v_consume_type(vec,T) (T*)vector_consume((voidVec * )(&vec), sizeof(T))

#define v_remove(vec, idx)\
 if ((size_t)idx < vec.length){\
    memmove(&vec.items[idx-1], &vec.items[idx], (vec.length-idx-1)*sizeof(vec.items[0])); vec.length--;\
    } else if (vec.length == (size_t)idx){\
        vec.length--;\
    } else if (idx == 0 && vec.length>0){memmove(&vec.items[0], &vec.items[1], (vec.length-1)*sizeof(vec.items[0])); vec.length--;}else{\
        assert(idx>=0 &&(size_t)idx <vec.length);\
    }

#ifdef __cplusplus
#define v_insert(vec, idx, item)\
    assert((size_t)idx<vec.length+1 && idx>=0);\
    if(vec.length+1> vec.capacity){vec.items = (typeof(vec.items))arena_realloc(vec.arena,vec.items, vec.capacity,(vec.capacity+1)*sizeof(vec.items[0]));vec.capacity++;}\
    memmove(&vec.items[idx+1], &vec.items[idx], (vec.capacity-idx)*sizeof(vec.items[0])); vec.items[idx] = item; vec.length ++;  arena_queue_destructor((vec.arena), (void (*)(void *))destruct<typeof(vec.items)>, &vec.items[vec.length-1]);
#else 
#define v_insert(vec, idx, item)\
    assert((size_t)idx<vec.length+1 && idx>=0);\
    if(vec.length+1> vec.capacity){vec.items = arena_realloc(vec.arena,vec.items, vec.capacity,(vec.capacity+1)*sizeof(vec.items[0]));vec.capacity++;}\
    memmove(&vec.items[idx+1], &vec.items[idx], (vec.capacity-idx)*sizeof(vec.items[0])); vec.items[idx] = item; vec.length ++;
#endif
#define v_resize(vec, len){\
vec.length= len;\
size_t previous_cap = vec.capacity;\
while (vec.capacity<vec.length){if(vec.capacity != 0){vec.capacity *= 2;} else{vec.capacity = 1;}}\
vec.items = (void*)arena_realloc(vec.arena,vec.items, previous_cap,vec.capacity*sizeof(vec.items[0]));}

#define len(vec) (vec).length

#define unmake_fn(vec, fn) for(int i =0; i<vec.length; i++){fn(vec.items[i]);} unmake(vec);



CTILS_STATIC
void * vector_consume(voidVec * vec, size_t size);

/*
String stuff
*/
typedef struct{str_type * items; size_t length; size_t capacity;Arena * arena;}String;
#define STRING(str) (String){.items = (cstr)str, .length = sizeof(str),.arena = 0, .capacity = 0}
enable_vec_type(String)
CTILS_STATIC
String new_string(Arena * arena,const char* str);

#define tmp_new_string(str) new_string(&temporary_allocator,str)

CTILS_STATIC
String new_string_wide(Arena * arena,const wchar_t* str);


#define tmp_new_string_wide(str) new_string_wide(&temporary_allocator, str)

CTILS_STATIC
String string_format(Arena * arena, const char * fmt, ...);
#define tmp_string_format(VA_ARGS) string_format(&temporary_allocator, VA_ARGS)

CTILS_STATIC
String string_random(Arena * arena, int minlen, int maxlen);
#define tmp_string_random(min_len, max_len) string_random(&temporary_allocator, minlen, max_len)

CTILS_STATIC
void _strconcat(String * a, const char* b, size_t b_size);

CTILS_STATIC
bool string_equals(String a, String b);
#define str_concat(a, b)\
	_strconcat(&a,(const char *)b, sizeof(b[0]));

#define str_v_append(a,b)\
	v_resize(a, len(a)+1);\
	a.items[len(a)-3] = b;\
	a.items[len(a)-2] = '\0'\


/*
Str stuff
*/
typedef struct {char * items; size_t length;}Str;
enable_vec_type(Str)

CTILS_STATIC
Str string_to_str(String s);

CTILS_STATIC
String str_to_string(Arena * arena,Str s);

CTILS_STATIC
void put_str_ln(Str str);
#define STR(st) (Str){(char*)st, (size_t)strlen(st)}
#define substring(st, start, end)(Str){(char*)(st.items+start), (size_t)(end-start)}

CTILS_STATIC
char * str_to_c_string(Arena * arena, Str s);

CTILS_STATIC
StrVec str_split_by_delim(Arena * arena,Str base, Str delim);

CTILS_STATIC
StrVec str_split_by_delim_no_delims(Arena * arena,Str base, Str delim);

CTILS_STATIC
bool str_equals(Str a, Str b);

CTILS_STATIC
int strlen_cmp(const void* a, const void* b);

CTILS_STATIC
int strlen_cmp_reversed(const void* a, const void* b);

CTILS_STATIC
String string_indent(Arena * arena,String s, int depth);

CTILS_STATIC
void unmake_string(String * f);
/*
HashFunctions
*/

CTILS_STATIC
size_t hash_bytes(Byte * byte, size_t size);

CTILS_STATIC
size_t hash_int(int in);

CTILS_STATIC
size_t hash_float(float fl);

CTILS_STATIC
size_t hash_long(long lg);

CTILS_STATIC
size_t hash_double(double db);

CTILS_STATIC
size_t hash_string(String str);
CTILS_STATIC
size_t hash_cstring(const char * str);
/*
Hashtable
*/
//maps Ts to Us
// I love you so much - Anna/toast <3
#define enable_hash_type(T,U)\
typedef struct{\
	T key;\
	U value;\
}T##U##KeyValuePair;\
enable_vec_type(T##U##KeyValuePair)\
typedef struct{\
	T##U##KeyValuePairVec *Table;\
	size_t TableSize;\
	size_t (*hash_func)(T);\
	bool (*eq_func)(T,T);\
	void (*not_key)(T*);\
	void (*not_value)(U*);\
}T##U##HashTable;\
static __attribute((unused)) T##U##HashTable * T##U##HashTable_create(size_t size,size_t (*hash_func)(T),bool (*eq_func)(T,T), void (*tdestructor)(T *), void (*udestructor)(U*)){\
	T##U##HashTable * out = (T##U##HashTable *)global_alloc(1, sizeof(T##U##HashTable));\
	out->Table= (T##U##KeyValuePairVec *)global_alloc(1,sizeof(T##U##KeyValuePairVec)*size);\
	out->TableSize = size;\
	out->hash_func = hash_func;\
	out->eq_func = eq_func;\
	out->not_key = tdestructor;\
	out->not_value = udestructor;\
	size_t i;\
	for(i =0; i<size; i++){\
		out->Table[i] = make_with_cap(0,T##U##KeyValuePair,16);\
	}\
	return out;\
}\
static __attribute((unused)) void T##U##HashTable_v_resize(T##U##HashTable * table, size_t new_size){\
	T##U##KeyValuePairVec* new_table = (T##U##KeyValuePairVec *)global_alloc(8,new_size);\
	size_t i;\
	for(i =0; i<new_size; i++){\
		new_table[i] = make_with_cap(0,T##U##KeyValuePair,8);\
	}\
	for(i =0; i<table->TableSize; i++){\
		size_t j;\
		for(j = 0; j<len(table->Table[i]); j++){\
			size_t hashval = table->hash_func(table->Table[i].items[j].key);\
			size_t hash = hashval%new_size;\
			T##U##KeyValuePair pair = {.key = table->Table[i].items[j].key, .value = table->Table[i].items[j].value};\
			v_append(new_table[hash], pair);\
		}\
	}\
	T##U##KeyValuePairVec * old = table->Table;\
	size_t old_len = table->TableSize;\
	table->Table = new_table;\
	table->TableSize = new_size;\
	for(i =0; i<old_len; i++){\
		unmake(old[i]);\
	}\
    global_free(old);\
}\
static __attribute((unused)) U* T##U##HashTable_find(T##U##HashTable* table, T key){\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
	size_t i;\
	for(i =0 ; i<len(table->Table[hash]); i++){\
		T##U##KeyValuePair p = table->Table[hash].items[i];\
		if(table->eq_func(p.key, key)){\
			return &table->Table[hash].items[i].value;\
		}\
	}\
	return nil;\
}\
static __attribute((unused)) T##U##KeyValuePair* T##U##HashTable_find_kv(T##U##HashTable* table, T key){\
	if(table->TableSize == 0){\
		return 0;\
	}\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
	size_t i;\
	for(i =0 ; i<len(table->Table[hash]); i++){\
		T##U##KeyValuePair p = table->Table[hash].items[i];\
		if(table->eq_func(p.key, key)){\
			return &table->Table[hash].items[i];\
		}\
	}\
	return nil;\
}\
static __attribute((unused)) void T##U##HashTable_insert(T##U##HashTable* table, T key, U value){\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
	T##U##KeyValuePair pair = (T##U##KeyValuePair){.key = key,.value = value};\
	T##U##KeyValuePairVec tmp = table->Table[hash];\
    int idx = -1;\
	size_t i;\
    for(i =0; i<table->Table[hash].length; i++){\
        if(table->eq_func(key, table->Table[hash].items[i].key)){\
            idx = i;\
            break;\
        }\
    }\
    if (idx>-1){\
        table->Table[hash].items[idx].value = value; \
    } else{\
	    v_append(tmp, pair);\
        table->Table[hash] = tmp;\
    }\
}\
static __attribute((unused)) bool T##U##HashTable_contains(T##U##HashTable * table, T key){\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
    int idx = -1;\
	size_t i;\
    for(i =0; i<table->Table[hash].length; i++){\
        if(table->eq_func(key, table->Table[hash].items[i].key)){\
            idx = i;\
            break;\
        }\
    }\
    return idx != -1;\
}\
static __attribute((unused)) void T##U##HashTable_remove(T##U##HashTable * table, T key){\
    size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
    int idx = -1;\
	size_t i;\
    for(i =0; i<table->Table[hash].length; i++){\
        if( table->eq_func(key, table->Table[hash].items[i].key)){\
            idx = i;\
            break;\
        }\
    }\
    if(idx>=0){\
		table->not_key(&table->Table[hash].items[idx].key);\
		table->not_value(&table->Table[hash].items[idx].value);\
        v_remove(table->Table[hash], idx);\
    }\
}\
static __attribute((unused)) void T##U##HashTable_unmake(T##U##HashTable * table){\
size_t i;\
size_t j;\
	for(i =0; i<table->TableSize; i++){\
		for(j =0; j<table->Table[i].length; j++){\
			if(table->not_key){table->not_key(&table->Table[i].items[j].key);}\
			if(table->not_value){table->not_value(&table->Table[i].items[j].value);}\
		}\
		unmake(table->Table[i]);\
	}\
	global_free(table->Table);\
	global_free(table);\
}\
static __attribute((unused)) T##U##HashTable * T##U##HashTable_construct_from_list(T##U##KeyValuePair * pairs, size_t count,size_t (*hash_func)(T),bool (*eq_func)(T,T)){\
	T##U##HashTable* tmp = T##U##HashTable_create(count,hash_func, eq_func, (void (*)(T *))no_op_void, (void(*)(U*))no_op_void);\
	size_t i;\
	for(i =0; i<count; i++){\
		T##U##HashTable_insert(tmp,pairs[i].key, pairs[i].value);\
	}\
	return tmp;\
}

#define CONSTRUCT_HASHTABLE(T, name, hash_func, eq_func,...) CONSTRUCTED(T##HashTable*, name, T##HashTable_construct_from_list, (T##KeyValuePair[]){VA_ARGS}, sizeof((T##KeyValuePair[]){args})/(sizeof(T##KeyValuePair)), hash_func, eq_func)
enable_hash_type(void_ptr, void_ptr)

/*
Utils
*/

CTILS_STATIC
long get_time_microseconds(void);

CTILS_STATIC
void begin_profile(void);

CTILS_STATIC
long end_profile(void);

CTILS_STATIC
void end_profile_print(const char * message);

CTILS_STATIC
int execute(const char ** strings);

CTILS_STATIC
int execute_fd(int f_out, int f_in, int f_er, const char ** strings);

CTILS_STATIC
bool write_string_to_file(const char * s, const char * file_name);

CTILS_STATIC
String read_file_to_string(Arena * arena,const char * file_name);

CTILS_STATIC
bool write_bytes_to_file(ByteVec bytes, const char * file_name);

CTILS_STATIC
ByteVec read_file_to_bytes(Arena * arena, const char *file_name);

CTILS_STATIC
bool is_number(char a);

CTILS_STATIC
bool cstr_equals(const char * a,const char * b);
/*
 Noise functionality 
*/
typedef struct{
    i64 v0;
    i64 v1;
    i64 v2;
    double scale_divisor;
}NoiseOctave2d;

CTILS_STATIC
NoiseOctave2d noise_octave_2d_new(double scale_divisor);

CTILS_STATIC
f64 perlin(NoiseOctave2d * self,f64 xbase, f64 ybase);

/*
Option
*/
#define enable_option_type(T)\
typedef struct {\
	bool is_valid;\
	T value;\
}Option##T;
#define Some(v) {true,v}
#define None {false}


typedef struct Unit{
	unsigned char _;
}Unit;
/*
Iterators
*/
typedef struct Iterator{
    void * data;
    size_t idx;
    size_t end;
    size_t stride;
    size_t value_offset;
    void *(*next)(struct Iterator*);
}Iterator;
#define hack_offsetof(st, m) \
    (size_t)&(((st)0)->m)

#define NEXT(value,It) (value = (typeof(value))It.next(&It))
#define ITER_VEC(v) make_vec_iterator(*(voidVec*)(&v), sizeof(v.items[0]))
//#define ITER_HASHTABLE(v) make_hash_map_iter(v, sizeof(v->Table[0].items[0]), (size_t)&(typeof(*(v->Table->items)) *0->value)))
#define ITER_HASHTABLE(v) make_hash_map_iter(v, sizeof(v->Table[0].items),(hack_offsetof(typeof(v->Table[0].items),value)))
#define ITER_HASHTABLE_KV(v) make_hash_map_iter(v, sizeof(v->Table[0].items[0]), 0)

CTILS_STATIC
void * next_vec_iter(Iterator * iter);

CTILS_STATIC
Iterator make_vec_iterator(voidVec v,size_t stride);

CTILS_STATIC
void * next_hash_map_iter(Iterator * iter);

CTILS_STATIC
Iterator make_hash_map_iter(void * v, size_t stride, size_t offset);
/*
Implementation
*/
#ifdef CTILS_IMPLEMENTATION 
#ifdef ARENA_REGISTER
void register_arena(Arena * arena);
void deregister_arena(Arena * arena);
#endif
#include <unistd.h>
static int alloc_count = 0;
static int global_free_count =0;

CTILS_STATIC
void * debug_alloc(size_t count, size_t size){
	alloc_count++;
	return calloc(count, size);
}

CTILS_STATIC
void debug_global_free(void * ptr){
	global_free_count++;
	free(ptr);
}

CTILS_STATIC
void *debug_realloc(void * ptr, size_t size){
    if(!ptr){
        alloc_count++;
    }
    return realloc(ptr, size);
}

CTILS_STATIC
void debug_alloc_and_global_free_counts(void){
	printf("alloc count: %d, global_free_count: %d\n", alloc_count, global_free_count);
}
/*
Memory Stuff
*/

CTILS_STATIC
void mem_shift(void * start, size_t size, size_t count, size_t distance){
	char * data = (char *)start;
	size_t j;
	size_t i;
	for(j = 0; j<size*distance; j++){
		for (i = count*size; i>0; i--){
			data[i] = data[i-1];
		}
	}
}

CTILS_STATIC
void * memdup(Arena* arena, void * ptr, size_t size){
	if(!ptr){
		return 0;
	} else{
		void * out = arena_alloc(arena,size);
		memcpy(out, ptr, size);
		return out;
	}
}
/*
Arena stuff
*/

CTILS_STATIC
void arena_destroy_thunk(Arena **arena){
	arena_destroy(*arena);
}

typedef struct arena_defer{
	void (*func)(void *);
	void * data;
	struct arena_defer * next;
}arena_defer;

CTILS_STATIC 
void defer(Arena * arena, void(*func)(void *), void * data){
	if(!arena){
		return;
	}
	arena_defer * def = (arena_defer*)arena_alloc(arena, sizeof(arena_defer));
	def->next = (arena_defer *)arena->defer_queue;
	def->func = func;
	def->data = data;
	arena->defer_queue =def;
}
CTILS_STATIC
Arena * arena_create(void){
    char * buffer = (char *)global_alloc(1,4096*8);
    char * next_ptr = buffer;
    char * end = buffer+4096*8;
    char * previous_allocation = 0;
    struct Arena * next = 0;
    Arena * out = (Arena*)global_alloc(1,sizeof(Arena));
	out->destructor_queue =0;
	pthread_mutex_t lck;
	pthread_mutex_init(&lck,0);
    *out = (Arena){lck,buffer, next_ptr, end, previous_allocation, next, 0,0,0};
	#ifdef ARENA_REGISTER
	register_arena(out);
	#endif
    return out;
}

CTILS_STATIC
Arena * arena_create_sized(size_t reqsize){
    size_t size = 4096;
    while(size<=reqsize){
        size *= 2;
    }
    char * buffer = (char *)global_alloc(1,size);
    char * next_ptr = buffer;
    char * end = buffer+size;
    char * previous_allocation = 0;
    struct Arena * next = 0;
	pthread_mutex_t lck;
	pthread_mutex_init(&lck,0);
    Arena * out = (Arena*)global_alloc(1,sizeof(Arena));
    *out = (Arena){lck,buffer, next_ptr, end, previous_allocation, next,0,0,0};
	out->destructor_queue =0;
	#ifdef ARENA_REGISTER
	register_arena(out);
	#endif
    return out;
}

CTILS_STATIC
void arena_destroy(Arena * arena){
    if (arena == 0){
        return;
    }
	while(arena->defer_queue){
		arena_defer *def = (arena_defer*)arena->defer_queue;
		def->func(def->data);
		arena->defer_queue = def->next;
	}
	while(arena->destructor_queue){
		ArenaDestructor * dest = arena->destructor_queue;
		dest->destructor(dest->address);
		arena->destructor_queue = dest->next;
	}
	arena->destructor_queue =0;
	#ifdef ARENA_REGISTER
	deregister_arena(arena);
	#endif
    global_free(arena->buffer);
    arena_destroy(arena->next);
	pthread_mutex_destroy(&arena->lock);
    global_free(arena);
}

CTILS_STATIC
void * arena_alloc(Arena * arena, size_t size){
    if(!arena){
        return global_alloc(1,size);
    }
	pthread_mutex_lock(&arena->lock);	
	
    size_t act_sz = size+(16-size%16);
	if(size >= 16 && size%16==0){
		act_sz = size;
	}
    char * previous = arena->next_ptr;
    if(previous + act_sz>=arena->end){
        if (!arena->next){
            arena->next = arena_create_sized(size);
        }
        if (arena->next){
			pthread_mutex_unlock(&arena->lock);
            return arena_alloc(arena->next, size);
        } else{
			pthread_mutex_unlock(&arena->lock);
            return NULL;
        }
    }
    arena->next_ptr += act_sz;
    arena->previous_allocation = previous;
	pthread_mutex_unlock(&arena->lock);
    return previous;
}
CTILS_STATIC
void * arena_realloc(Arena * arena, void * ptr, size_t previous_size, size_t new_size){
    if(!arena){
        return global_realloc(ptr,new_size);
    }
	pthread_mutex_lock(&arena->lock);
    if (arena->previous_allocation == ptr && ptr){
        arena->next_ptr = (char*)ptr;
    }
	pthread_mutex_unlock(&arena->lock);
    void * out = arena_alloc(arena, new_size);
	pthread_mutex_lock(&arena->lock);
    memmove(out, ptr, previous_size);
	pthread_mutex_unlock(&arena->lock);
    return out;
}

CTILS_STATIC
void arena_reset(Arena * arena){
	pthread_mutex_lock(&arena->lock);
    arena_destroy(arena->next);
	arena->next = 0;
    arena->next_ptr= arena->buffer;
    arena->previous_allocation = 0;
	while(arena->defer_queue){
		arena_defer *def = (arena_defer*)arena->defer_queue;
		def->func(def->data);
		arena->defer_queue = def->next;
	}
	arena->defer_queue =0;
	while(arena->destructor_queue){
		ArenaDestructor * dest = arena->destructor_queue;
		dest->destructor(dest->address);
		arena->destructor_queue = dest->next;
	}
	arena->destructor_queue = 0;
	pthread_mutex_unlock(&arena->lock);
}

CTILS_STATIC
void arena_free(Arena * arena, void * ptr){
    if(!arena){
        global_free(ptr);
    }
}
CTILS_STATIC
void arena_queue_destructor_span(Arena * arena, void (*fn)(void *), void * start, size_t offset, size_t count){
	(void)arena;
	(void)fn;
	(void)start;
	(void)offset;
	(void)count;
}
CTILS_STATIC
void arena_queue_destructor(Arena * arena,void (*fn)(void *), void * address){
	if(!arena){
		return;
	}
	ArenaDestructor * dest = arena->destructor_queue;	
	while(dest){
		
		if(dest->address == address){
			return;
		}else{
			dest = dest->next;
		}
	}
	ArenaDestructor * nw =(ArenaDestructor*) arena_alloc(arena, sizeof(ArenaDestructor)*2);
	nw->next =0;
	nw->next = arena->destructor_queue;
	nw->destructor = fn;
	nw->address = address;
	arena->destructor_queue = nw;
}
/*
vector stuff
*/

CTILS_STATIC
void * vector_consume(voidVec * vec, size_t size){
	if(vec->items == 0 || vec->length == 0){
		return 0;
	}
	void * out = vec->items;
	vec->length-=1;
	vec->items = (char *)vec->items+size;
	vec->capacity -=1;
	return out;
}

/*
Hashing
*/

CTILS_STATIC
size_t hash_bytes(Byte * bytes, size_t size){
	size_t out = 0;
	const size_t pmlt = 31;
	size_t mlt = 31;
	size_t i;
	for( i =0; i<size;i++){
		out += bytes[i]*mlt;
		mlt*=pmlt;
	}
	return out;
}

CTILS_STATIC
size_t hash_int(int in){
	int tmp = in;
	return hash_bytes((Byte *)&tmp, sizeof(tmp));
}

CTILS_STATIC
size_t hash_float(float fl){
	float tmp = fl;
	return hash_bytes((Byte *)&tmp, sizeof(tmp));
}

CTILS_STATIC
size_t hash_long(long lg){
	long tmp = lg;
	return hash_bytes((Byte *)&tmp, sizeof(tmp));
}

CTILS_STATIC
size_t hash_double(double db){
	double tmp = db;
	return hash_bytes((Byte *)&tmp, sizeof(tmp));
}

CTILS_STATIC
size_t hash_string(String str){
	size_t out = 0;
	const size_t pmlt = 31;
	size_t mlt = 1;
	size_t i;
	for(i =0; i<len(str);i++){
		out += str.items[i]*mlt;
		mlt*=pmlt;
	}
	return out;
}
CTILS_STATIC
size_t hash_cstring(const char * str){
	size_t out = 0;
	const size_t pmlt = 31;
	size_t mlt = 31;
	int i =0;
	while(str[i] != 0){
		out += str[i]*mlt;
		mlt*=pmlt;
		i++;
	}
	return out;
}
/*
Utils
*/
#ifdef __linux__
int fileno(FILE * file);
#endif

CTILS_STATIC
long get_time_microseconds(void){
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_usec+tv.tv_sec*1000000;
}


static long profile_time = 0;
void begin_profile(void){
	if(profile_time == 0){
		profile_time = get_time_microseconds();
	}
}

CTILS_STATIC
long end_profile(void){
	if(profile_time != 0){
		long out =  get_time_microseconds()-profile_time;
		profile_time = 0;
		return out;
	}
	return -1;
}

CTILS_STATIC
void end_profile_print(const char * message){
	printf("%s took %f seconds\n",message, ((double)end_profile())/1000000);
}

CTILS_STATIC
int execute(const char ** strings){
    if(strings == nil){
        return 1;
    }
    if(*strings == nil){
        return 1;
    }
    int s = fork();
    if(!s){
        int a =execvp(strings[0], (char*const*)strings);
		exit(a);
    }else{
        return s;
    }
    return 1;
}

CTILS_STATIC
int execute_fd(int f_out, int f_in, int f_er, const char ** strings){
    if(strings == nil){
        return 1;
    }
    if(*strings == nil){
        return 1;
    }
    int s = fork();
    if(!s){
        dup2(f_out,fileno(stdout));
        dup2(f_in, fileno(stdin));
        dup2(f_er, fileno(stderr));
        int a = execvp(strings[0], (char*const*)strings);
		exit(a);
    }else{
        return s;
    }
    return 1;
}
/* 
Str stuff
*/

CTILS_STATIC
Str string_to_str(String s){
    return (Str){s.items, s.length};
}

CTILS_STATIC
String str_to_string(Arena * arena,Str s){
    char * out = (char*)arena_alloc(arena, s.length+1);
    memset(out, 0,s.length+1);
    memcpy(out, s.items, s.length);
    return (String){out, s.length, s.length, arena};
}

CTILS_STATIC
bool str_equals(Str a, Str b){
    if(a.length != b.length){
        return 0;
    } 
	size_t i;
    for(i= 0; i<a.length; i++){
        if(a.items[i] != b.items[i]){
            return false;
        }
    }
    return true;
}

CTILS_STATIC
void put_str_ln(Str str){
    printf("<");
    assert(str.length >0);
    size_t i;
    for(i =0;i<str.length; i++){
        printf("%c", str.items[i]);
    }
    printf(">\n");
}

CTILS_STATIC
char * str_to_c_string(Arena * arena, Str s){
    char * out = (char*)arena_alloc(arena, s.length+1);
    memset(out, 0,s.length+1);
    memcpy(out, s.items, s.length);
    return out;
}

CTILS_STATIC
bool lookahead_matches(Str base, size_t start, Str delim){
    if(start+delim.length>base.length){
        return false;
    }
    size_t i;
    for(i=(size_t)start; i<(size_t)start+delim.length; i++){
        if(base.items[i] != delim.items[i-start]){

            return false;
        }
    }
    return true;

}

CTILS_STATIC
StrVec str_split_by_delim(Arena * arena,Str base, Str delim){
    StrVec out = make(arena, Str);
    size_t start = 0;
    size_t i;
    for(i =0; i<base.length; i++){
        if(lookahead_matches(base, i, delim)){
            if(i>start){
                v_append(out, substring(base, start,i));
            }
            while(lookahead_matches(base, i, delim)){
                v_append(out, substring(base,i, i+delim.length));
                i += delim.length;
            }
            start = i;
        }
    }
    if(base.length>start){
        v_append(out, substring(base, start,base.length));
    }
    return out;
}

CTILS_STATIC
StrVec str_split_by_delim_no_delims(Arena * arena,Str base, Str delim){
    StrVec out = make(arena, Str);
    size_t start = 0;
    size_t i;
    for(i =0; i<base.length; i++){
        if(lookahead_matches(base, i, delim)){
            if(i>start){
                v_append(out, substring(base, start,i));
            }
            while(lookahead_matches(base, i, delim)){
                i += delim.length;
            }
            start = i;
        }
    }
    if(base.length>start){
        v_append(out, substring(base, start,base.length));
    }
    return out;
}

CTILS_STATIC
int strlen_cmp(const void *  a,const void * b){
    Str* s1 = (Str * )a;
    Str* s2 = (Str * )b;
    return s1->length>s2->length ? 1: s1->length<s2->length ? -1 : 0;
}

CTILS_STATIC
int strlen_cmp_reversed(const void *  a,const void * b){
    Str* s2 = (Str * )a;
    Str* s1 = (Str * )b;
    return s1->length>s2->length ? 1: s1->length<s2->length ? -1 : 0;
}
/*
String Stuff
*/
#include <stdarg.h>
bool string_equals(String a, String b);

CTILS_STATIC
String new_string(Arena * arena,const char* str){
	int l = strlen(str)+1;
    String out;
	out.items = (char*)arena_alloc(arena, l*sizeof(str_type));
	out.length =0; 
	out.capacity = l;
	out.arena = arena;
	int i;
	for(i = 0; i<l; i++){
		v_append(out, (str_type)str[i]);
	}
	v_append(out, '\0');
	return out;
}

CTILS_STATIC
String new_string_wide(Arena * arena,const wchar_t* str){
    int l = wcslen(str);
	String out;
	out.items = (char *)arena_alloc(arena, l*sizeof(str_type));
	out.length =0; 
	out.capacity = l;
	out.arena = arena;
	int i;
	for(i = 0; i<l; i++){
		v_append(out, (str_type)str[i]);
	}
	v_append(out, '\0');
	return out;
}

CTILS_STATIC
void _strconcat(String * a, const char* b, size_t b_size){
	if(sizeof(str_type) == 1){
        int l = (*a).length-2;
        int l2 = strlen(b);
		int i;
		v_resize((*a), (*a).length+l2);
		for(i=0; i<l2; i++){
			(*a).items[l+i] = (str_type)(b[i]);
		}
		(*a).items[l+l2] = '\0';
	}
	else{
		if(b_size <4){
			int i;
			int l = len(*a)-1;
			v_resize((*a), len((*a))+strlen(b));
			int l2 = strlen(b);
			for(i=0; i<strlen(b); i++){
				(*a).items[l+i] = (str_type)(b[i]);
			}
			(*a).items[l+l2] = '\0';
		}
		else {
			int i;
			int l = len(*a)-1;
			v_resize((*a), len((*a))+wcslen((const wchar_t *)b));
			const wchar_t * v = (const wchar_t *)b;
			int l2 = wcslen(v);
			for(i=0; i<l2; i++){
				(*a).items[l+i] = (str_type)(v[i]);
			}
			(*a).items[l+l2] = '\0';
		}
	}
}

CTILS_STATIC
String string_format(Arena *arena,const char * fmt, ...){
	String s =new_string(arena,"");
	va_list args;
	va_start(args, fmt);
	int l = strlen(fmt);
	int i;
	for(i = 0; i<l; i++){
		if(fmt[i] != '%'){
			str_v_append(s, fmt[i]);
		}
		else{
			if(fmt[i+1] == 'c'){
				char buff[2];
				buff[0] = (char)(va_arg(args,int));
				buff[1] = '\0';
				str_concat(s, buff);
				i++;
			}
			if(fmt[i+1] == 'l' && fmt[i+2] == 'u'){
				char buff[128];
				snprintf(buff,127, "%lu", va_arg(args,unsigned long));
				str_concat(s,buff);
				i+= 2;
			}
			if(fmt[i+1] == 'u'){		
				char buff[128];
				snprintf(buff,127, "%u", va_arg(args,unsigned int));
				str_concat(s,buff);
				i+= 1;
			}
			if(fmt[i+1] == 'l' && fmt[i+2] == 'd'){
				char buff[128];
				snprintf(buff,127, "%ld", va_arg(args,long));
				str_concat(s,buff);
				i+= 2;
			}
			if(fmt[i+1] == 'l' && fmt[i+2] == 's'){
				str_concat(s,va_arg(args, wchar_t *));
				i+= 2;
			}
			else if(fmt[i+1] == 's'){
				char * s2 =  va_arg(args,char *);
				str_concat(s, s2);
				i++;
			}
			else if(fmt[i+1] == 'f'){
				char buff[128];
				snprintf(buff,127,"%f", va_arg(args,double));
				str_concat(s,buff);
				i++;
			}
			else if(fmt[i+1] == 'd'){
				char buff[128];
				snprintf(buff,127,"%d", va_arg(args,int));
				str_concat(s,buff);
				i++;
			}
			else if(fmt[i+1] == '%'){
				v_append(s, '%');
				i++;
			}
		}
	}
	va_end(args);
	return s;
}

CTILS_STATIC
bool string_equals(String a, String b){
	if(len(a) != len(b)){
		return 0;
	}
	size_t i;
	for(i= 0; i<len(a); i++){
		if(a.items[i] != b.items[i]){
			return 0;
		}
	}
	return 1;
}

CTILS_STATIC
String string_random(Arena * arena,int minlen, int maxlen){
	int length = rand()%(maxlen-minlen)+minlen;
	String out;
	out.items = (char*)arena_alloc(arena,(length+1)*sizeof(str_type));
	out.length =0; 
	out.capacity = length+1;
	out.arena = arena;
	int i;
	for(i= 0; i<length+1; i++){
		out.items[i] = 0;
	}
    v_resize(out, length+3);
	for(i =0; i<length; i++){
		char c = rand()%(90-65)+65;
		if(rand()%2){
			c += 32;
		}
		out.items[i] = c;
	}
	out.items[length+1] = 0;
	return out;
}

CTILS_STATIC
void unmake_string(String * f){
	unmake(*f);
}

/*
IO FUNCTIONALITY
*/

CTILS_STATIC
bool write_string_to_file(const char * s, const char * file_name){
	FILE * f = fopen(file_name, "w");
	if(f == 0){
		return 0;
	}
	size_t size = strlen(s);
	size_t w_size = fwrite(s, 1,size, f);
	fclose(f);
	return size == w_size;
}

CTILS_STATIC
String read_file_to_string(Arena * arena, const char *file_name){
	FILE *f= fopen(file_name, "rb");
	if (!f){
		perror("ERROR:");
		exit(1);
	}
	fseek(f, 0, SEEK_END);
	size_t fsize = ftell(f);
	fseek(f, 0, SEEK_SET); 
	String out = new_string(arena,"");
	v_resize(out, fsize+1);
	fread(out.items, 1, fsize, f);
	fclose(f);
	out.items[fsize]= 0;
	return out;
}

CTILS_STATIC
bool write_bytes_to_file(ByteVec bytes, const char * file_name){
	FILE * f = fopen(file_name, "w");
	if(f == 0){
		return 0;
	}
	size_t size = bytes.length;
	size_t w_size = fwrite(bytes.items, 1,size, f);
	fclose(f);
	return size == w_size;
}

CTILS_STATIC
ByteVec read_file_to_bytes(Arena * arena, const char *file_name){
	FILE *f= fopen(file_name, "rb");
	if (!f){
		perror("ERROR:");
		exit(1);
	}
	fseek(f, 0, SEEK_END);
	size_t fsize = ftell(f);
	fseek(f, 0, SEEK_SET); 
	String out = new_string(arena,"");
	v_resize(out, fsize);
	fread(out.items, 1, fsize, f);
	fclose(f);
	return (ByteVec){.items = (Byte *)out.items, .length = out.length, .capacity = out.capacity, .arena = out.arena};
}

CTILS_STATIC
bool is_number(char a){
	return a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9';
}
CTILS_STATIC
void no_op_void(void*ptr){
	(void)ptr;
}
CTILS_STATIC
bool cstr_equals(const char * a,const char * b){
	return strcmp(a, b) ==0;
}
/*
 Noise stuff 
 */
typedef struct{double x; double y;} float2;

CTILS_STATIC
f64 interpolate(f64 a, f64 b, f64 s){
    return a*(1-s)+b*s;
}

CTILS_STATIC
NoiseOctave2d noise_octave_2d_new(double scale_divisor){
        i64 v0 = rand()%1000000000;
        i64 v1 = rand()%1000000000;
        i64 v2 = rand()%1000000000;
        return (NoiseOctave2d){v0,v1,v2,scale_divisor};
}

CTILS_STATIC
float2 random_gradient(NoiseOctave2d * self, i32 x, i32 y) {
        i64 w = 64;
        i64 s = w / 2;
        i64 a = x;
        i64 b = y;
        a *= self->v0;
        b ^= a << s | a >> (w - s);
        b *= self->v1;
        a &= b << s | b >> (w - s);
        a *= self->v2;
        f64 random = (f64)a * (3.14159265 / (f64)(!(!(u64)0 >> 1)));
        return (float2){cos(random), sin(random)};
        //return self.points[y as usize % self.points.len()][x as usize % self.points.len()];
}

CTILS_STATIC
f64 dot_grid_gradient(NoiseOctave2d * self, i32 ix, i32 iy, f64 x, f64 y){
    float2 gradient = random_gradient(self,ix, iy);
    f64 dx = x - (f64)ix;
    f64 dy = y - (f64)iy;
    return (dx * gradient.x + dy * gradient.y);
}

CTILS_STATIC
f64 perlin(NoiseOctave2d * self,f64 xbase, f64 ybase){
    f64 x = xbase / 16.0;
    f64 y = ybase / 16.0;
    i32 x0 = floor(x);
    i32 x1 = x0 + 1;
    i32 y0 = floor(y);
    i32 y1 = y0 + 1;
    f64 sx = (f64)x - (f64)x0;
    f64 sy = (f64)y- (f64)y0;
    f64 n00 = dot_grid_gradient(self,x0, y0, x, y);
    f64 n10 = dot_grid_gradient(self,x1, y0, x, y);
    f64 ix0 = interpolate(n00, n10, sx);
    f64 n01 = dot_grid_gradient(self,x0, y1, x, y);
    f64 n11 = dot_grid_gradient(self,x1, y1, x, y);
    f64 ix1 = interpolate(n01, n11, sx);
    f64 value = interpolate(ix0, ix1, sy);
    return value;
}
/*
Iterators
*/
CTILS_STATIC
void * next_vec_iter(Iterator * iter){
    if(iter->idx == iter->end){
        return 0;
    }
    else{
        void * nxt = (void*)((char *)iter->data+iter->idx*iter->stride);
        iter->idx +=1;
        return nxt;
    }
}

CTILS_STATIC
Iterator make_vec_iterator(voidVec v,size_t stride){
    Iterator out;
    out.data = v.items;
    out.end = v.length;
    out.idx =0;
    out.stride = stride;
    out.next= next_vec_iter;
    return out;
}

CTILS_STATIC
//typedef struct{ KeyValuePairVec *Table; 
//size_t TableSize; size_t (*hash_func)(T); bool (*eq_func)(T,T);}TUHashTable;
void * next_hash_map_iter(Iterator * iter){
    voidVec* v = (voidVec*)iter->data;
    if(v == (void*)iter->end){
        return 0;
    }
    if(iter->idx == v->length){
        if(v == (voidVec*)iter->end){
            return 0;
        }
        while(iter->idx == v->length){
            iter->idx = 0;
            v ++;
            void * old = iter->data;
            iter->data = v;
            assert(iter->data != old);
            if(v == (voidVec*)iter->end){
                return 0;
            }
        }
    } 
    void * out = (void*)((char*)v->items+iter->idx*iter->stride);
    iter->idx = iter->idx+1;
    return (void*)((char*)out+iter->value_offset);
}

CTILS_STATIC
Iterator make_hash_map_iter(void * v, size_t stride, size_t offset){
    void_ptrvoid_ptrHashTable* t = (void_ptrvoid_ptrHashTable*)v;
    Iterator out;
    out.data = t->Table;
    out.end = (size_t)(t->Table+t->TableSize);
    out.idx = 0;
    out.next = next_hash_map_iter;
    out.stride = stride;
    out.value_offset = offset;
    return out;
}
#endif
