#define CTILS_IMPLEMENTATION
#include "utils.h"
#include <string>
#include <string.h>
struct Deleted{
    const char * str;
    Deleted(const char * v){
        str = (char *)global_alloc(strlen(v)+1, 1);
        memcpy((void*)str, (void*)v, strlen(v)+1);
    }
    Deleted(Deleted && other){
        str = other.str;
        other.str =0;
    }
    Deleted(Deleted & other){
        const char *v = other.str;
        str = (char *)global_alloc(strlen(v)+1, 1);
        memcpy((void*)str, (void*)v, strlen(v)+1);
    }
    void operator=(Deleted && other){
        if(str){
            global_free((void*)str);
        }
        str = other.str;
        other.str = 0;
    }
    void operator=(Deleted& other){
        if(str){
            global_free((void*)str);
        }
        if(!other.str){
            return;
        }
        char * tmp =  (char *)global_alloc(strlen(other.str)+1, 1);
        str =tmp;
        memcpy((void*)str,(void*) other.str, strlen(other.str)+1); 
    }
    ~Deleted(){
        if(str){
            printf("deleted <%s>\n", str);
            global_free((void*)str);
        }
    }
};
enable_vec_type(Deleted);
int main(){
    Arena * local = arena_create();
    DeletedVec ints = make(local, Deleted);
    for(int i =0; i<5000; i++){
        v_append(ints, std::move(Deleted(string_format(local,"%d", i).items)));
    }
    for(int i =0; i<ints.length; i++){
        printf("%d\n",i);
    }
    printf("hello\n");
    arena_destroy(local);
    debug_alloc_and_global_free_counts();
    return 0;
}
