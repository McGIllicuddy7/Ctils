#define CTILS_IMPLEMENTATION
#include "utils.h"
#include "utils_math.h"
#include "lambda.h"
#include <stdio.h>
#include "string_utils.h"
#include <stdio.h>
#include "set.h"
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
    Arena * local =create_arena();
    Str delimns[] = {STR("+"), STR("/"), STR("->")};
    StrVec dels = tokenize_str_no_info(local, STR("a+b/c->d"), delimns, sizeof(delimns)/sizeof(Str));
    for(int i =0; i<dels.length; i++){
        put_str_ln(dels.items[i]);
    }
    free_arena(local);
}   
void hash_test(){
    Arena * arena = create_arena();
    StringintHashTable * s = StringintHashTable_create(10, HashString, StringEquals);
    StringVec strings = make(arena,String);
    for(int i =0; i<1000; i++){
        String tmp = RandomString(arena,10, 20);
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
    free_arena(arena);
    debug_alloc_and_global_free_counts();
}
int main(int argc, const char ** argv){
    test();
    return 0;
}