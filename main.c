#define CTILS_IMPLEMENTATION
#include "utils.h"
//#include "utils_math.h"
#include "lambda.h"
#include <stdio.h>
#include "string_utils.h"
#include <stdio.h>

enable_vec_type(int);
enable_vec_type(String);
enable_hash_type(String, int);

make_lambda_type(void, void);
make_lambda(fn_void, void, testing123, {printf("hello world\n");});
make_lambda_capture(fn_void,void, testing12,{printf("%s\n", captures->hello);},{const char * hello;});
make_lambda_type(int_to_int,int, int);
make_lambda_capture(fn_int_to_int, int, add, {return a+captures->b;}, {int b;}, int a)
make_lambda(fn_int_to_int, int, add12, {return a+12;}, int a)

make_lambda_type(int, int);
void test(){
    fn_void test = lambda(testing123);
    call(test);
    test = tmp_lambda(testing12,{"help uwu"});
    call(test);
    Arena * local =arena_create();
    Str delimns[] = {STR("+"), STR("-"), STR("*"),STR("/"),STR("<"), STR(">"), STR("#"), STR("->"), STR("("), STR(")"),STR("()") ,STR(","), STR("{"), STR("}"), STR(";"), STR("="), STR("==")};
    StrVec dels = tokenize_str_no_info(local, string_to_str(read_file_to_string(local, "main.c")), delimns, sizeof(delimns)/sizeof(Str));
    for(int i =0; i<dels.length; i++){
        put_str_ln(dels.items[i]);
    }
    arena_destroy(local);
}   

void hash_test(){
    Arena * arena = arena_create();
    StringintHashTable * s = StringintHashTable_create(10, hash_string, string_equals);
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
int main(int argc, const char ** argv){
    test3();
    return 0;
}