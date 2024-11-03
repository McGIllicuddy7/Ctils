#pragma once
#include "utils.h"
#define CTILS_IMPLEMENTATION
typedef struct {char * items; size_t length;}Str;
enable_vec_type(Str);
Str String_to_Str(String s);
#define STR(st) (Str){(char*)st, strlen(st)}
#define substring(st, start, end)(Str){st.items+start, end-start};
char * Str_to_c_string(Arena * arena, Str s);
StrVec split_str_by_delim(Arena * arena,Str base, Str delim);
StrVec split_str_by_delim_no_delims(Arena * arena,Str bases, Str delim);

#ifdef CTILS_IMPLEMENTATION 
void put_str_ln(Str str){
    printf("length:%zu\n", str.length);
    for(int i =0;i<str.length; i++){
        printf("%c", str.items[i]);
    }
    printf("\n");
}
char * Str_to_c_string(Arena * arena, Str s){
    char * out = arena_alloc(arena, s.length+1);
    memset(out, 0,s.length+1);
    memcpy(out, s.items, s.length);
    return out;
}

StrVec split_str_by_delim(Arena * arena,Str base, Str delim){
    StrVec out = make(arena, Str);
    int start = 0;
    for(int i =0; i<base.length; i++){
        if(base.items[i] == delim.items[0]){
            int j = 0; 
            bool matched = 1;
            while(j<=base.length-i &&j<delim.length){
                if(base.items[i+j] != delim.items[j]){
                    matched = 0;
                    break;
                }
                if(j>base.length-i){
                    matched = 0;
                }
                j = j+1;
            } 
            if(matched){
                if(i>start){
                    Str tmp = substring(base, start, i);
                    append(out, tmp);
                }
                Str tmp = substring(base, i, i+delim.length);
                append(out,tmp);
                i += delim.length;
                start = i;
            }
        }
    }
    if(base.length>start){
        append(out, substring(base, start,base.length));
    }
    return out;
}
StrVec split_str_by_delim_no_delims(Arena * arena,Str base, Str delim){
    StrVec out = make(arena, Str);
    int start = 0;
    for(int i =0; i<base.length; i++){
        if(base.items[i] == delim.items[0]){
            int j = 0; 
            bool matched = 1;
            while(j<=base.length-i &&j<delim.length){
                if(base.items[i+j] != delim.items[j]){
                    matched = 0;
                    break;
                }
                if(j>base.length-i){
                    matched = 0;
                }
                j = j+1;
            } 
            if(matched){
                if(i>start){
                    Str tmp = substring(base, start, i);
                    append(out, tmp);
                }
                i += delim.length;
                start = i;
            }
        }
    }
    if(base.length>start){
        append(out, substring(base, start,base.length));
    }
    return out;
}
#endif
