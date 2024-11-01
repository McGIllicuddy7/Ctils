#pragma once
#include "utils.h"
#define CTILS_IMPLEMENTATION
typedef struct {char * items; size_t length;}Str;
enable_vec_type(Str);
Str String_to_Str(String s);
#define STR(st) (Str){(char*)st, strlen(st)}
#define substring(st, start, end)(Str){st.items+start, end+1};
char * Str_to_c_string(Arena * arena, Str s);
StrVec split_str_by_delim(Arena * arena,Str base, Str delim);
StrVec split_str_by_delim_no_delims(Arena * arena,Str bases, Str delim);

#ifdef CTILS_IMPLEMENTATION 
char * Str_to_c_string(Arena * arena, Str s){
    char * out = arena_alloc(arena, s.length+1);
    memset(out, 0,s.length+1);
    memcpy(out, s.items, s.length);
    return out;
}

StrVec split_str_by_delim(Arena * arena,Str base, Str delim){
    StrVec out = arena_make(arena, Str);
    int start = 0;
    for(int i =0; i<base.length; i++){
        if(base.items[i] == delim.items[0]){
            int j = 0; 
            bool matched = 1;
            while(j<base.length-i &&j<delim.length){
                if(base.items[i+j] != delim.items[j]){
                    matched = 0;
                    break;
                }
                j = j+1;
                if(j>=base.length-i){
                    matched = 0;
                }
            }
            if(matched){
                append(out, substring(base, start, i));
                append(out, substring(base, i, delim.length));
                start = i;
                i += delim.length;
            }
        }
    }
    return out;
}
StrVec split_str_by_delim_no_delims(Arena * arena,Str base, Str delim){

}
#endif
