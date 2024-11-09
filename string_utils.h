#pragma once
#include "utils.h"
#define CTILS_IMPLEMENTATION
typedef struct {char * items; size_t length;}Str;
enable_vec_type(Str);
Str String_to_Str(String s);
#define STR(st) (Str){(char*)st, (size_t)strlen(st)}
#define substring(st, start, end)(Str){(char*)(st.items+start), (size_t)(end-start)};
char * Str_to_c_string(Arena * arena, Str s);
StrVec split_str_by_delim(Arena * arena,Str base, Str delim);
StrVec split_str_by_delim_no_delims(Arena * arena,Str bases, Str delim);
bool StrEquals(Str a, Str b);
int StrlenCmp(const void* a, const void* b);
int StrlenCmpReversed(const void* a, const void* b);

typedef struct{
    Str str;
    Str file_name;
    u32 line;
    u8 start_col;
}Token;
enable_vec_type(Token);
StrVec tokenize_str_no_info(Arena * arena, Str base, Str * delims, int delims_count);
TokenVec tokenize_str(Arena * arena, Str base, Str * delims, int delims_count, Str file);

#ifdef CTILS_IMPLEMENTATION 
bool StrEquals(Str a, Str b){
    if(a.length != b.length){
        return 0;
    } 
    for(int i= 0; i<a.length; i++){
        if(a.items[i] != b.items[i]){
            return false;
        }
    }
    return true;
}
void put_str_ln(Str str){
    for(int i =0;i<str.length; i++){
        printf("%c", str.items[i]);
    }
    printf("\n");
}
char * Str_to_c_string(Arena * arena, Str s){
    char * out = (char*)arena_alloc(arena, s.length+1);
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
                    append_v(out, tmp);
                }
                Str tmp = substring(base, i, i+delim.length);
                append_v(out,tmp);
                i += delim.length;
                start = i;
            }
        }
    }
    if(base.length>start){
        append_v(out, substring(base, start,base.length));
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
                    append_v(out, tmp);
                }
                i += delim.length;
                start = i;
            }
        }
    }
    if(base.length>start){
        append_v(out, substring(base, start,base.length));
    }
    return out;
}

int StrlenCmp(const void *  a,const void * b){
    Str* s1 = (Str * )a;
    Str* s2 = (Str * )b;
    return s1->length>s2->length ? 1: s1->length<s2->length ? -1 : 0;
}
int StrlenCmpReversed(const void *  a,const void * b){
    Str* s2 = (Str * )a;
    Str* s1 = (Str * )b;
    return s1->length>s2->length ? 1: s1->length<s2->length ? -1 : 0;
}
typedef struct{
    Str str;
    u32 line;
    u8 start_col;
    bool finalized;
} CTILS_InternalToken;
enable_vec_type(CTILS_InternalToken);
StrVec tokenize_str_no_info(Arena * arena, Str base, Str * delims, int delims_count){
    Arena * local = create_arena();
    CTILS_InternalTokenVec tokens = make(local, CTILS_InternalToken);
    StrVec in_delims = make_with_capacity(local, Str, delims_count);
    for(int i =0; i<delims_count; i++){
        append_v(in_delims, delims[i]);
    }
    qsort(in_delims.items, in_delims.length, sizeof(Str), (int (* _Nonnull )(const void *, const void * ))StrlenCmpReversed);
    StrVec s = split_str_by_delim(local, base, STR("\n"));
    int indx = 0;
    int lines=0;
    for(int i =0; i<s.length; i++){
        if(!StrEquals(s.items[i], STR("\n"))){
            CTILS_InternalToken tok = {};
            tok.str = s.items[i];
            tok.start_col = 0;
            tok.line = lines;
            append_v(tokens, tok);
        } else{
            lines ++;
        }
    }
    for(int i =0; i<in_delims.length; i++){
        Arena * temps = create_arena();
        CTILS_InternalTokenVec tmp = make(temps, CTILS_InternalToken);
        for(int j =0; j<tokens.length; j++){
            if(tokens.items[j].finalized){
                append_v(tmp, tokens.items[j]);
                continue;
            }
            StrVec strs = split_str_by_delim(temps,tokens.items[j].str, in_delims.items[i]);
            int offset =tokens.items[j].start_col;
            for(int k= 0; k<strs.length; k++){
                CTILS_InternalToken tok;
                tok.line = tokens.items[j].line;
                tok.start_col = offset;
                tok.finalized = StrEquals(strs.items[k], in_delims.items[i]);
                tok.str = strs.items[k];
                offset += tok.str.length;
                append_v(tmp, tok);
            }
        }
        resize_vec(tokens, 0);
        for(int j =0; j<tmp.length; j++){
            append_v(tokens, tmp.items[j]);
        }
        free_arena(temps);
    }
    StrVec out = make_with_capacity(arena, Str, tokens.length);
    for(int i =0; i<tokens.length; i++){
        append_v(out, tokens.items[i].str);
    }
    free_arena(local);
    return out;
}
TokenVec tokenize_str(Arena * arena, Str base, Str * delimns, int delims_count, Str file_name){
    Arena * local = create_arena();
    CTILS_InternalTokenVec tokens = make(local, CTILS_InternalToken);
    StrVec in_delims = make_with_capacity(local, Str, delims_count);
    for(int i =0; i<delims_count; i++){
        append_v(in_delims, delimns[i]);
    }
    qsort(in_delims.items, in_delims.length, sizeof(Str), (int (* _Nonnull )(const void *, const void * ))StrlenCmpReversed);
    StrVec s = split_str_by_delim(local, base, STR("\n"));
    int indx = 0;
    int lines=0;
    for(int i =0; i<s.length; i++){
        if(!StrEquals(s.items[i], STR("\n"))){
            CTILS_InternalToken tok = {};
            tok.str = s.items[i];
            tok.start_col = 0;
            tok.line = lines;
            append_v(tokens, tok);
        } else{
            lines ++;
        }
    }
    for(int i =0; i<in_delims.length; i++){
        Arena * temps = create_arena();
        CTILS_InternalTokenVec tmp = make(temps, CTILS_InternalToken);
        for(int j =0; j<tokens.length; j++){
            if(tokens.items[j].finalized){
                append_v(tmp, tokens.items[j]);
                continue;
            }
            StrVec strs = split_str_by_delim(temps,tokens.items[j].str, in_delims.items[i]);
            int offset =tokens.items[j].start_col;
            for(int k= 0; k<strs.length; k++){
                CTILS_InternalToken tok;
                tok.line = tokens.items[j].line;
                tok.start_col = offset;
                tok.finalized = StrEquals(strs.items[k], in_delims.items[i]);
                tok.str = strs.items[k];
                offset += tok.str.length;
                append_v(tmp, tok);
            }
        }
        resize_vec(tokens, 0);
        for(int j =0; j<tmp.length; j++){
            append_v(tokens, tmp.items[j]);
        }
        free_arena(temps);
    }
    TokenVec out = make_with_capacity(arena, Token, tokens.length);
    for(int i =0; i<tokens.length; i++){
        CTILS_InternalToken s = tokens.items[i];
        Token tok = {};
        tok.file_name = file_name;
        tok.line = s.line;
        tok.start_col = s.start_col;
        tok.str = s.str;
        append_v(out, tok);
    }
    free_arena(local);
    return out;
}
#endif
