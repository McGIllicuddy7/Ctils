#define CTILS_IMPLEMENTATION
#include "utils.h"
#include "utils_math.h"
#include <stdio.h>
CreateVecType(int);
CreateVecType(String);
enable_hash_type(String, int);
int main(int argc, const char ** argv){
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
    return 0;
}
