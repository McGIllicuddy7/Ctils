#define CTILS_IMPLEMENTATION
#include "utils.h"
#include "utils_math.h"
#include "lambda.h"
#include <stdio.h>
enable_vec_type(int);
enable_vec_type(String);
enable_hash_type(String, int);

make_lambda_type(void, void);
make_lambda_capture(fn_void, void, testing123, {printf("%s\n", captures->name);}, {const char * name;});
make_lambda_type(int_to_int,int, int);
make_lambda_capture(fn_int_to_int, int, add, {return a+captures->b;}, {int b;}, int a)
make_lambda(fn_int_to_int, int, add12, {return a+12;}, int a)
void test(){
    fn_void a = lambda(testing123, {"hello world\n"});
    fn_int_to_int b = lambda(add, {10});
    b = lambda(add12);
    call(a);
    printf("%d\n", call(b, 32));
}   
void hash_test(){
    Arena * arena = create_arena();
    StringintHashTable * s = StringintHashTable_create(10, HashString, StringEquals);
    StringVec strings = arena_make(arena,String);
    for(int i =0; i<1; i++){
        String tmp = RandomStringArena(arena,10, 20);
        append(strings, tmp);
        StringintHashTable_insert(s, tmp, i);
    }
    for(int i =0; i<len(strings); i++){
        int * a= StringintHashTable_find(s, strings.items[i]);
        assert(a);
        //printf("%s, %d,%d\n", strings.items[i].items, i, *a);
    }
    printf("%zu\n", s->TableSize);
    StringintHashTable_destroy(s);
    free_arena(arena);
    debug_alloc_and_global_free_counts();
    vector2d a = {10,10};
    vector2d b = {10,10};
}
int main(int argc, const char ** argv){
    test();
    return 0;
}