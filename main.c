#define CTILS_IMPLEMENTATION
#include "string_utils.h"
#include "utils.h"
//#include "utils_math.h"
#include "lambda.h"
#include <stdio.h>
#include <stdio.h>

enable_vec_type(int);
enable_hash_type(String, int);

make_lambda_type(void, void);
make_lambda(fn_void, void, testing123, {printf("hello world\n");});
make_lambda_capture(fn_void,void, testing12,{printf("%s\n", captures->hello);},{const char * hello;});
make_lambda_type(int_to_int,int, int);
make_lambda_capture(fn_int_to_int, int, add, {return a+captures->b;}, {int b;}, int a)
make_lambda(fn_int_to_int, int, add12, {return a+12;}, int a)

make_lambda_type(int, int);
void test(){
    Arena * local = arena_create();
    fn_void test = lambda(local,testing123);
    call(test);
    test = tmp_lambda(testing12,{"abcdefghijklmnopqrstuvwxyz"});
    call(test);
    arena_destroy(local);
}   

void hash_test(){
    Arena * arena = arena_create();
    StringintHashTable * s = StringintHashTable_create(10, hash_string, string_equals, unmake_string, (void(*)(int*))no_op_void);
    StringVec strings = make(arena,String);
    for(int i =0; i<1000; i++){
        String tmp = string_random(arena,10, 20);
        v_append(strings, tmp);
        StringintHashTable_insert(s, tmp, i);
    }
    for(int i =0; i<len(strings); i++){
        int * a= StringintHashTable_find(s, strings.items[i]);
        assert(a);
        printf("%s, %d,%d\n", strings.items[i].items, i, *a);
    }
    printf("%zu\n", s->TableSize);
    StringintHashTable_unmake(s);
    arena_destroy(arena);
    debug_alloc_and_global_free_counts();
}
void test3(){
    Arena * local =arena_create();
    String str = read_file_to_string(local, "test.lisp");
    ListParserAstNode list = parse_str_to_list(local, string_to_str(str), STR("("), STR(")"), STR(","), STR("test.lisp"));
    printf("%s\n", list_parser_ast_node_print(local,list).items);
    arena_destroy(local);
}
void test4(){
    Arena * local = arena_create();
    String s = read_file_to_string(local, "test.lisp");
    s= string_indent(local, s, 4);
    printf("%s\n", s.items);
    arena_destroy(local);
}
void test5(){
    Arena * local = arena_create();
    String s = read_file_to_string(local, "test.lisp");
    StrVec delims = make_with_cap(local, Str,3);
    v_append(delims, STR("("));
    v_append(delims, STR(")"));
    v_append(delims, STR(" "));
    TokenVec tokens = tokenize_str(local, string_to_str(s), delims.items, 
    delims.length, STR("test.lisp"));
    for(int i =0; i<tokens.length; i++){
       printf("<%s>\n", str_to_string(local,tokens.items[i].str).items); 
    }
    arena_destroy(local);
}

void test6(){
    Arena * local = arena_create();
    u32Vec a = make(local, u32);
    u32Vec b = make(local, u32);
    const int cap = 10;
    for(int i =0; i<cap; i++){
        if(rand()%2){
        v_append(a, i*2);
        } else{
            v_append(b,i*2+1);
        }

    }
    for(int i =0; i<a.length; i++){
        printf("%d,",a.items[i]);
    }
    printf("\n");
    for(int i =0; i<b.length; i++){
        printf("%d,",b.items[i]);
    }
}


enable_hash_type(String, i32);
void test7(){
    Stringi32HashTable * table = Stringi32HashTable_create(1000, hash_string, string_equals, unmake_string, (void(*)(int*))no_op_void);
    for(int i =0; i<100000; i++){
        Stringi32HashTable_insert(table, string_format(0, "%d", i), i);
    }
    Iterator iter = ITER_HASHTABLE(table);
    i32* p = 0;
    while(NEXT(p,iter)){
        printf("%d\n", *p);
    }
    Stringi32HashTable_unmake(table);
    debug_alloc_and_global_free_counts();
}
void test8(){
    new_arena(local);
    u64Vec items = make(local, u64);
    for(int i =0; i<32; i++){
        v_append(items, i);
    }
    u64 * iter = 0;
    while((iter = v_consume_type(items, u64))){
        printf("%llu\n", *iter);
    }
    printf("%zu\n", items.length);
}
StringVec strings = make_static(String,STRING("hello"), STRING("world"),STRING("lol"), STRING(":3"));

void test9(){
    Iterator it = ITER_VEC(strings);
    String * t;
    while(NEXT(t,it)){
        printf("%s\n", t->items);
    }
}

static CONSTRUCT_HASHTABLE(Stringi32, table,hash_string, string_equals,{STRING("hey"),1}, {STRING("toast"), 2}, {STRING("i"), 4},{STRING("love"), 8}, {STRING("you"), 16}, {STRING("\n"),32});

void test10(){
    printf("%d\n", *Stringi32HashTable_find(table, STRING("hey")));
}
extern void test11();
int main(int argc, const char ** argv){
    test11();
    return 0;
}
