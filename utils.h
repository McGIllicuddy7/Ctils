#pragma once
//use #define CTILS_IMPLEMENTATION
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>
#include <wchar.h>
#include <sys/time.h>
#include <errno.h>
#include <stdint.h>
#include <math.h>
/*
	Initial Defines
*/
void * debug_alloc(size_t count, size_t size);
void debug_global_free(void * ptr);
void *debug_realloc(void * ptr, size_t size);
void debug_alloc_and_global_free_counts();
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
#ifdef __cplusplus
#include <type_traits>
#define typeof(T) decltype(T)
#endif
/*
Memory stuff
*/

void mem_shift(void * start, size_t size, size_t count, size_t distance);
/*
Arena stuff 
*/

typedef struct Arena{
    char* buffer;
    char* next_ptr;
    char*end;
    char* previous_allocation;
    struct Arena * next;
} Arena;
Arena * create_arena();
void free_arena(Arena * arena);
void * arena_alloc(Arena * arena, size_t size);
void * arena_realloc(Arena * arena, void * ptr, size_t previous_size, size_t new_size);
void arena_free(Arena * arena, void * ptr);
void arena_reset(Arena * arena);
/*
Slice stuff
*/

void * memdup(Arena * arena,void * ptr, size_t size);

#define enable_vec_type(T) typedef struct {T * items; size_t length; size_t capacity; Arena * arena;} T##Vec



#define make(arena, T) {0,0,0, arena}

#define make_with_capacity(arena, T, cap){(T*)(arena_alloc(arena,cap*sizeof(T))), 0, (size_t)cap, arena}
#define clone(vec, arena){arena_memdup(arena,vec.items, vec.capacity*sizeof(vec.items[0])), vec.length, vec.capacity}
#define v_append(vec, value)\
 {if(vec.capacity<vec.length+1){\
    if (vec.capacity != 0){ vec.items =(typeof(vec.items))arena_realloc(vec.arena,vec.items,vec.capacity*sizeof(vec.items[0]), vec.capacity*sizeof(vec.items[0])*2);vec.capacity *= 2;}\
     else{vec.capacity = 1;vec.items = (typeof(vec.items))arena_realloc(vec.arena, vec.items, 0, 1*sizeof(vec.items[0]));}\
    } \
    vec.items[vec.length++] = value;}

#define unmake(vec) arena_free((vec).arena,(vec).items); 

#define v_append_slice(vec, other_items, other_len)\
 {if(vec.capacity<vec.length+other_len){\
    size_t previous = vec.capacity*sizeof(vec.items[0]);\
    while (vec.capacity<vec.length+other_len){if(vec.capacity != 0){vec.capacity *= 2;} else{vec.capacity = 1;}}\
    vec.items = arena_realloc(vec.arena,vec.items,previous,vec.capacity*sizeof(vec.items[0]));}\
    memcpy(&vec.items[vec.length], other_items, sizeof(vec.items[0])*other_len);\
    vec.length += other_len; } 

#define v_remove(vec, idx)\
 if (idx < vec.length&& idx>0){\
    memmove(&vec.items[idx-1], &vec.items[idx], (vec.length-idx-1)*sizeof(vec.items[0])); vec.length--;\
    } else if (vec.length == idx){\
        vec.length--;\
    } else if (idx == 0 && vec.length>0){memmove(&vec.items[0], &vec.items[1], (vec.length-1)*sizeof(vec.items[0])); vec.length--;}else{\
        assert(idx>=0 &&idx <vec.length);\
    }

#define v_insert(vec, idx, item)\
    assert(idx<vec.length+1 && idx>=0);\
    if(vec.length+1> vec.capacity){vec.items = arena_realloc(vec.arena,vec.items, vec.capacity,(vec.capacity+1)*sizeof(vec.items[0]));vec.capacity++;}\
    memmove(&vec.items[idx+1], &vec.items[idx], (vec.capacity-idx)*sizeof(vec.items[0])); vec.items[idx] = item; vec.length ++;
#define v_resize(vec, len){\
vec.length= len;\
size_t previous_cap = vec.capacity;\
while (vec.capacity<vec.length){if(vec.capacity != 0){vec.capacity *= 2;} else{vec.capacity = 1;}}\
vec.items = (typeof(vec.items))arena_realloc(vec.arena,vec.items, previous_cap,vec.capacity*sizeof(vec.items[0]));}

#define len(vec) (vec).length
/*
String stuff
*/
typedef struct{str_type * items; size_t length; size_t capacity;Arena * arena;}String;
String new_string(Arena * arena,const char* str);
String new_string_wide(Arena * arena,const wchar_t* str);
String string_format(Arena * arena, const char * fmt, ...);
String RandomStrina(Arena * arena, int minlen, int maxlen);
void _strconcat(String * a, const char* b, size_t b_size);
bool StringEquals(String a, String b);
#define str_concat(a, b)\
	_strconcat(&a,(const char *)b, sizeof(b[0]));

#define str_v_append(a,b)\
	v_resize(a, len(a)+1);\
	a.items[len(a)-3] = b;\
	a.items[len(a)-2] = '\0'\

/*
HashFunctions
*/
size_t HashBytes(Byte * byte, size_t size);
size_t HashInt(int in);
size_t HashFloat(float fl);
size_t HashLong(long lg);
size_t HashDouble(double db);
size_t HashString(String str);
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
enable_vec_type(T##U##KeyValuePair);\
typedef struct{\
	T##U##KeyValuePairVec *Table;\
	size_t TableSize;\
	size_t (*hash_func)(T);\
	bool (*eq_func)(T,T);\
}T##U##HashTable;\
static T##U##HashTable * T##U##HashTable_create(size_t size,size_t (*hash_func)(T),bool (*eq_func)(T,T)){\
	T##U##HashTable * out = (T##U##HashTable *)global_alloc(1, sizeof(T##U##HashTable));\
	out->Table= (T##U##KeyValuePairVec *)global_alloc(1,sizeof(T##U##KeyValuePairVec)*size);\
	out->TableSize = size;\
	out->hash_func = hash_func;\
	out->eq_func = eq_func;\
	for(int i =0; i<size; i++){\
		out->Table[i] = (T##U##KeyValuePairVec)make_with_capacity(0,T##U##KeyValuePair,16);\
	}\
	return out;\
}\
static void T##U##HashTable_v_resize(T##U##HashTable * table, size_t new_size){\
	T##U##KeyValuePairVec* new_table = (T##U##KeyValuePairVec *)global_alloc(8,new_size);\
	for(int i =0; i<new_size; i++){\
		new_table[i] = (T##U##KeyValuePairVec)make_with_capacity(0,T##U##KeyValuePair,8);\
	}\
	for(int i =0; i<table->TableSize; i++){\
		for(int j = 0; j<len(table->Table[i]); j++){\
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
	for(int i =0; i<old_len; i++){\
		unmake(old[i]);\
	}\
    global_free(old);\
}\
static U* T##U##HashTable_find(T##U##HashTable* table, T key){\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
	for(int i =0 ; i<len(table->Table[hash]); i++){\
		T##U##KeyValuePair p = table->Table[hash].items[i];\
		if(table->eq_func(p.key, key)){\
			return &table->Table[hash].items[i].value;\
		}\
	}\
	return nil;\
}\
static T##U##KeyValuePair* T##U##HashTable_find_kv(T##U##HashTable* table, T key){\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
	for(int i =0 ; i<len(table->Table[hash]); i++){\
		T##U##KeyValuePair p = table->Table[hash].items[i];\
		if(table->eq_func(p.key, key)){\
			return &table->Table[hash].items[i];\
		}\
	}\
	return nil;\
}\
static void T##U##HashTable_insert(T##U##HashTable* table, T key, U value){\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
	T##U##KeyValuePair pair = (T##U##KeyValuePair){.key = key,.value = value};\
	T##U##KeyValuePairVec tmp = table->Table[hash];\
    int idx = -1;\
    for(int i =0; i<table->Table[hash].length; i++){\
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
static bool T##U##HashTable_contains(T##U##HashTable * table, T key){\
	size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
	T##U##KeyValuePairVec tmp = table->Table[hash];\
    int idx = -1;\
    for(int i =0; i<table->Table[hash].length; i++){\
        if(table->eq_func(key, table->Table[hash].items[i].key)){\
            idx = i;\
            break;\
        }\
    }\
    return idx != -1;\
}\
static void T##U##HashTable_remove(T##U##HashTable * table, T key){\
    size_t hashval = table->hash_func(key);\
	size_t hash = hashval%table->TableSize;\
    int idx = -1;\
    for(int i =0; i<table->Table[hash].length; i++){\
        if( table->eq_func(key, table->Table[hash].items[i].key)){\
            idx = i;\
            break;\
        }\
    }\
    if(idx>=0){\
        v_remove(table->Table[hash], idx);\
    }\
}\
static void T##U##HashTable_unmake(T##U##HashTable * table){\
	for(int i =0; i<table->TableSize; i++){\
		unmake(table->Table[i]);\
	}\
	global_free(table->Table);\
	global_free(table);\
}\




/*
Utils
*/
long get_time_microseconds();
void begin_profile();
long end_profile();
void end_profile_print(const char * message);
int execute(const char ** strings);
int execute_fd(int f_out, int f_in, int f_er, const char ** strings);
bool write_string_to_file(const char * s, const char * file_name);
String read_file_to_string(Arena * arena,const char * file_name);
bool is_number(char a);
/*
 Noise functionality 
*/
typedef struct{
    i64 v0;
    i64 v1;
    i64 v2;
    double scale_divisor;
}NoiseOctave2d;
NoiseOctave2d noise_octave_2d_new(double scale_divisor);
f64 perlin(NoiseOctave2d * self,f64 xbase, f64 ybase);

/*
Implementation
*/

#ifdef CTILS_IMPLEMENTATION 
#include <unistd.h>
static int alloc_count = 0;
static int global_free_count =0;
void * debug_alloc(size_t count, size_t size){
	alloc_count++;
	return calloc(count, size);
}
void debug_global_free(void * ptr){
	global_free_count++;
	free(ptr);
}
void *debug_realloc(void * ptr, size_t size){
    if(!ptr){
        alloc_count++;
    }
    return realloc(ptr, size);
}
void debug_alloc_and_global_free_counts(){
	printf("alloc count: %d, global_free_count: %d\n", alloc_count, global_free_count);
}
/*
Memory Stuff
*/

void mem_shift(void * start, size_t size, size_t count, size_t distance){
	char * data = (char *)start;
	for(int j = 0; j<size*distance; j++){
		for (int i = count*size; i>0; i--){
			data[i] = data[i-1];
		}
	}
}
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
Arena * create_arena(){
    char * buffer = (char *)global_alloc(1,4096*8);
    char * next_ptr = buffer;
    char * end = buffer+4096*8;
    char * previous_allocation = 0;
    struct Arena * next = 0;
    Arena * out = (Arena*)global_alloc(1,sizeof(Arena));
    *out = (Arena){buffer, next_ptr, end, previous_allocation, next};
    return out;
}
Arena * create_arena_sized(size_t reqsize){
    size_t size = 4096;
    while(size<=reqsize){
        size *= 2;
    }
    char * buffer = (char *)global_alloc(1,size);
    char * next_ptr = buffer;
    char * end = buffer+size;
    char * previous_allocation = 0;
    struct Arena * next = 0;
    Arena * out = (Arena*)global_alloc(1,sizeof(Arena));
    *out = (Arena){buffer, next_ptr, end, previous_allocation, next};
    return out;
}
void free_arena(Arena * arena){
    if (arena == 0){
        return;
    }
    global_free(arena->buffer);
    free_arena(arena->next);
    global_free(arena);
}
void * arena_alloc(Arena * arena, size_t size){
    if(!arena){
        return global_alloc(1,size);
    }
    size_t act_sz = size+(8-size%8);
    char * previous = arena->next_ptr;
    if(previous + act_sz>arena->end){
        if (!arena->next){
            arena->next = create_arena_sized(size);
        }
        if (arena->next){
            return arena_alloc(arena->next, size);
        } else{
            return NULL;
        }
    }
    arena->next_ptr += act_sz;
    arena->previous_allocation = previous;
    return previous;
}
void * arena_realloc(Arena * arena, void * ptr, size_t previous_size, size_t new_size){
    if(!arena){
        return global_realloc(ptr,new_size);
    }
    size_t act_sz = new_size+(8-new_size%8);
    if (arena->previous_allocation == ptr && ptr){
        arena->next_ptr = (char*)ptr;
    }
    void * out = arena_alloc(arena, new_size);
    memmove(out, ptr, previous_size);
    return out;
}
void arena_reset(Arena * arena){
    free_arena(arena->next);
    arena->next_ptr= arena->buffer;
    arena->previous_allocation = 0;
}
void arena_free(Arena * arena, void * ptr){
    if(!arena){
        global_free(ptr);
    }
}
/*
Hashing
*/

size_t HashBytes(Byte * bytes, size_t size){
	size_t out = 0;
	const size_t pmlt = 31;
	size_t mlt = 31;
	for(int i =0; i<size;i++){
		out += bytes[i]*mlt;
		mlt*=pmlt;
	}
	return out;
}
size_t HashInt(int in){
	int tmp = in;
	return HashBytes((Byte *)&tmp, sizeof(tmp));
}
size_t HashFloat(float fl){
	float tmp = fl;
	return HashBytes((Byte *)&tmp, sizeof(tmp));
}
size_t HashLong(long lg){
	long tmp = lg;
	return HashBytes((Byte *)&tmp, sizeof(tmp));
}
size_t HashDouble(double db){
	double tmp = db;
	return HashBytes((Byte *)&tmp, sizeof(tmp));
}
size_t HashString(String str){
	size_t out = 0;
	const size_t pmlt = 31;
	size_t mlt = 1;
	for(int i =0; i<len(str);i++){
		out += str.items[i]*mlt;
		mlt*=pmlt;
	}
	return out;
}
/*
Utils
*/
#ifdef __linux__
int fileno(FILE * file);
#endif
long get_time_microseconds(){
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_usec+tv.tv_sec*1000000;
}
static long profile_time = 0;
void begin_profile(){
	if(profile_time == 0){
		profile_time = get_time_microseconds();
	}
}
long end_profile(){
	if(profile_time != 0){
		long out =  get_time_microseconds()-profile_time;
		profile_time = 0;
		return out;
	}
	return -1;
}
void end_profile_print(const char * message){
	printf("%s took %f seconds\n",message, ((double)end_profile())/1000000);
}
int execute(const char ** strings){
    if(strings == nil){
        return 1;
    }
    if(*strings == nil){
        return 1;
    }
    int s = fork();
    if(s){
        int a = execvp(strings[0], (char*const*)strings);
		exit(0);
    }else{
        return 0;
    }
    return 1;
}
int execute_fd(int f_out, int f_in, int f_er, const char ** strings){
    if(strings == nil){
        return 1;
    }
    if(*strings == nil){
        return 1;
    }
    int s = fork();
    if(s){
        dup2(f_out,fileno(stdout));
        dup2(f_in, fileno(stdin));
        dup2(f_er, fileno(stderr));
        int a = execvp(strings[0], (char*const*)strings);
		exit(0);
    }else{
        return 0;
    }
    return 1;
}

/*
String Stuff
*/
#include <stdarg.h>
bool StringEquals(String a, String b);
String new_string(Arena * arena,const char* str){
	int l = strlen(str)+1;
    String out = make_with_capacity(arena,str_type,l);
	for(int i = 0; i<l; i++){
		v_append(out, (str_type)str[i]);
	}
	v_append(out, '\0');
	return out;
}
String new_string_wide(Arena * arena,const wchar_t* str){
    int l = wcslen(str);
	String out = make_with_capacity(arena,str_type, l);
	for(int i = 0; i<l; i++){
		v_append(out, (str_type)str[i]);
	}
	v_append(out, '\0');
	return out;
}
void _strconcat(String * a, const char* b, size_t b_size){
	if(sizeof(str_type) == 1){
        int l = (*a).length-2;
        int l2 = strlen(b);
		v_resize((*a), (*a).length+l2);
		for(int i=0; i<l2; i++){
			(*a).items[l+i] = (str_type)(b[i]);
		}
		(*a).items[l+l2] = '\0';
	}
	else{
		if(b_size <4){
			int l = len(*a)-1;
			v_resize((*a), len((*a))+strlen(b));
			int l2 = strlen(b);
			for(int i=0; i<strlen(b); i++){
				(*a).items[l+i] = (str_type)(b[i]);
			}
			(*a).items[l+l2] = '\0';
		}
		else {
			int l = len(*a)-1;
			v_resize((*a), len((*a))+wcslen((const wchar_t *)b));
			const wchar_t * v = (const wchar_t *)b;
			int l2 = wcslen(v);
			for(int i=0; i<l2; i++){
				(*a).items[l+i] = (str_type)(v[i]);
			}
			(*a).items[l+l2] = '\0';
		}
	}
}
String string_format(Arena *arena,const char * fmt, ...){
	String s =new_string(arena,"");
	va_list args;
	va_start(args, fmt);
	int l = strlen(fmt);
	for(int i = 0; i<l; i++){
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
bool StringEquals(String a, String b){
	if(len(a) != len(b)){
		return 0;
	}
	for(int i= 0; i<len(a); i++){
		if(a.items[i] != b.items[i]){
			return 0;
		}
	}
	return 1;
}
String RandomString(Arena * arena,int minlen, int maxlen){
	int length = rand()%(maxlen-minlen)+minlen;
	String out = make_with_capacity(arena,str_type, length+1);
	for(int i= 0; i<length+1; i++){
		out.items[i] = 0;
	}
    v_resize(out, length+3);
	for(int i =0; i<length; i++){
		char c = rand()%(90-65)+65;
		if(rand()%2){
			c += 32;
		}
		out.items[i] = c;
	}
	out.items[length+1] = 0;
	return out;
}

/*
IO FUNCTIONALITY
*/
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
bool is_number(char a){
	return a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9';
}
/*
 Noise stuff 
 */
typedef struct{double x; double y;} float2;
f64 interpolate(f64 a, f64 b, f64 s){
    return a*(1-s)+b*s;
}

NoiseOctave2d noise_octave_2d_new(double scale_divisor){
        i64 v0 = rand()%1000000000;
        i64 v1 = rand()%1000000000;
        i64 v2 = rand()%1000000000;
        return (NoiseOctave2d){v0,v1,v2,scale_divisor};
}

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

f64 dot_grid_gradient(NoiseOctave2d * self, i32 ix, i32 iy, f64 x, f64 y){
    float2 gradient = random_gradient(self,ix, iy);
    f64 dx = x - (f64)ix;
    f64 dy = y - (f64)iy;
    return (dx * gradient.x + dy * gradient.y);
}

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
#endif
