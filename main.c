#define CTILS_IMPLEMENTATION
#include "utils.h"
#include "utils_math.h"
#include "lambda.h"
#include <stdio.h>
#include "string_utils.h"
#include <stdio.h>
enable_vec_type(int);
enable_vec_type(String);
enable_hash_type(String, int);

make_lambda_type(void, void);
make_lambda_capture(fn_void, void, testing123, {printf("%s\n", captures->name);}, {const char * name;});
make_lambda_type(int_to_int,int, int);
make_lambda_capture(fn_int_to_int, int, add, {return a+captures->b;}, {int b;}, int a)
make_lambda(fn_int_to_int, int, add12, {return a+12;}, int a)

make_lambda_type(int, int);
make_lambda_capture(fn_int, int, boxed, {return captures->i;}, {int i;});
fn_int box(int i){
    return lambda(boxed, {i});
}
void test(){
    printf("<3");
    Arena * local =create_arena();
    Str s = STR("hello world\n");
    StrVec strs = split_str_by_delim(local, s, STR(" "));
    for(int i =0; i<strs.length; i++){
        printf("%s\n",Str_to_c_string(local, strs.items[i]));
    }
    free_arena(local);
}   
void hash_test(){
    Arena * arena = create_arena();
    StringintHashTable * s = StringintHashTable_create(10, HashString, StringEquals);
    StringVec strings = arena_make(arena,String);
    for(int i =0; i<1000; i++){
        String tmp = RandomStringArena(arena,10, 20);
        append(strings, tmp);
        StringintHashTable_insert(s, tmp, i);
    }
    for(int i =0; i<len(strings); i++){
        int * a= StringintHashTable_find(s, strings.items[i]);
        assert(a);
        printf("%s, %d,%d\n", strings.items[i].items, i, *a);
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