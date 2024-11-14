#pragma once
#include "utils.h"
typedef struct {char * items; size_t length;}Str;
enable_vec_type(Str);
Str string_to_str(String s);
String str_to_string(Arena * arena,Str s);
void put_str_ln(Str str);
#define STR(st) (Str){(char*)st, (size_t)strlen(st)}
#define substring(st, start, end)(Str){(char*)(st.items+start), (size_t)(end-start)}
char * str_to_c_string(Arena * arena, Str s);
StrVec str_split_by_delim(Arena * arena,Str base, Str delim);
StrVec str_split_by_delim_no_delims(Arena * arena,Str base, Str delim);
StrVec str_extract_string_literals(Arena *arena, Str base);
bool str_equals(Str a, Str b);
int strlen_cmp(const void* a, const void* b);
int strlen_cmp_reversed(const void* a, const void* b);

typedef struct{
    Str str;
    Str file_name;
    u32 line;
    u8 start_col;
}Token;
enable_vec_type(Token);
StrVec tokenize_str_no_info(Arena * arena, Str base, Str * delims, int delims_count);
TokenVec tokenize_str(Arena * arena, Str base, Str * delims, int delims_count, Str file);
bool is_numbers(Str str);
#ifdef CTILS_IMPLEMENTATION 
Str string_to_str(String s){
    return (Str){s.items, s.length};
}
String str_to_string(Arena * arena,Str s){
    char * out = (char*)arena_alloc(arena, s.length+1);
    memset(out, 0,s.length+1);
    memcpy(out, s.items, s.length);
    return (String){out, s.length, s.length, arena};
}
bool str_equals(Str a, Str b){
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
    printf("<");
    for(int i =0;i<str.length; i++){
        printf("%c", str.items[i]);
    }
    printf(">\n");
}
char * str_to_c_string(Arena * arena, Str s){
    char * out = (char*)arena_alloc(arena, s.length+1);
    memset(out, 0,s.length+1);
    memcpy(out, s.items, s.length);
    return out;
}
bool lookahead_matches(Str base, int start, Str delim){
    if(start+delim.length>base.length){
        return false;
    }
    for(int i=start; i<start+delim.length; i++){
        if(base.items[i] != delim.items[i-start]){

            return false;
        }
    }
    return true;
}
StrVec str_split_by_delim(Arena * arena,Str base, Str delim){
    StrVec out = make(arena, Str);
    int start = 0;
    for(int i =0; i<base.length; i++){
        if(lookahead_matches(base, i, delim)){
            if(i>start){
                v_append(out, substring(base, start,i));
            }
            while(lookahead_matches(base, i, delim)){
                v_append(out, substring(base,i, i+delim.length));
                i += delim.length;
            }
            start = i;
        }
    }
    if(base.length>start){
        v_append(out, substring(base, start,base.length));
    }
    return out;
}

StrVec str_split_by_delim_no_delims(Arena * arena,Str base, Str delim){
    StrVec out = make(arena, Str);
    int start = 0;
    for(int i =0; i<base.length; i++){
        if(lookahead_matches(base, i, delim)){
            if(i>start){
                v_append(out, substring(base, start,i));
            }
            while(lookahead_matches(base, i, delim)){
                i += delim.length;
            }
            start = i;
        }
    }
    if(base.length>start){
        v_append(out, substring(base, start,base.length));
    }
    return out;
}

int strlen_cmp(const void *  a,const void * b){
    Str* s1 = (Str * )a;
    Str* s2 = (Str * )b;
    return s1->length>s2->length ? 1: s1->length<s2->length ? -1 : 0;
}
int strlen_cmp_reversed(const void *  a,const void * b){
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
    Arena * local = arena_create();
    TokenVec vec= tokenize_str(local, base, delims, delims_count, STR(""));
    StrVec out = make_with_cap(arena, Str, vec.length);
    for(int i=0; i<vec.length; i++){
        v_append(out, vec.items[i].str);
    }
    arena_destroy(local);
    return out;
}
TokenVec tokenize_str(Arena * arena, Str base, Str * delims, int delims_count, Str file_name){
    Arena * local = arena_create();

    CTILS_InternalTokenVec tokens = make(local, CTILS_InternalToken);
    StrVec in_delims = make_with_cap(local, Str, delims_count);
    for(int i =0; i<delims_count; i++){
        v_append(in_delims, delims[i]);
    }
    v_append(in_delims, STR("\""));
    v_append(in_delims, STR("\\\""));
    qsort(in_delims.items, in_delims.length, sizeof(Str), (int (*)(const void *, const void * ))strlen_cmp_reversed);
    StrVec s = str_split_by_delim(local, base, STR("\n"));
    int indx = 0;
    int lines=1;
    for(int i =0; i<s.length; i++){
        if(!str_equals(s.items[i], STR("\n"))){
            CTILS_InternalToken tok = {};
            tok.str = s.items[i];
            tok.start_col = 0;
            tok.line = lines;
            v_append(tokens, tok);
        } else{
            lines ++;
        }
    }
    CTILS_InternalTokenVec tmp_buffer = make(local, CTILS_InternalToken);
    for(int i =0; i<tokens.length; i++){
        int tmp_idx =0;
        if(tokens.items[i].finalized){
            v_append(tmp_buffer, tokens.items[i]);
            continue;
        }
        StrVec tmp = str_split_by_delim(local, tokens.items[i].str, STR("\t"));
        for(int j =0; j<tmp.length; j++){
            if(str_equals(tmp.items[j], STR("\t"))){
                tmp_idx ++;
                continue;
            }
            CTILS_InternalToken v;
            v.finalized = false;
            v.str = tmp.items[j];
            v.start_col = tmp_idx;
            v.line = tokens.items[i].line;
            v_append(tmp_buffer, v);
            tmp_idx += v.str.length;
        }
    }
    tokens = tmp_buffer;
    v_resize(tmp_buffer, 0);
    for(int i =0; i<tokens.length; i++){
        if(tokens.items[i].finalized){
            v_append(tmp_buffer, tokens.items[i]);
            continue;
        }
        int tmp_idx =0;
        StrVec tmp = str_split_by_delim(local, tokens.items[i].str, STR(" "));
        for(int j =0; j<tmp.length; j++){
            if(str_equals(tmp.items[j], STR(" "))){
                tmp_idx ++;
                continue;
            }
            CTILS_InternalToken v;
            v.finalized = false;
            v.str = tmp.items[j];
            v.start_col = tmp_idx;
            v.line = tokens.items[i].line;
            v_append(tmp_buffer, v);
            tmp_idx += v.str.length;
        }
    }
    tokens = tmp_buffer;
    for(int i =0; i<in_delims.length; i++){
        Arena * temps = arena_create();
        CTILS_InternalTokenVec tmp = make(temps, CTILS_InternalToken);
        for(int j =0; j<tokens.length; j++){
            if(tokens.items[j].finalized){
                v_append(tmp, tokens.items[j]);
                continue;
            }
            StrVec strs = str_split_by_delim(temps,tokens.items[j].str, in_delims.items[i]);
            int offset =tokens.items[j].start_col;
            for(int k= 0; k<strs.length; k++){
                CTILS_InternalToken tok;
                tok.line = tokens.items[j].line;
                tok.start_col = offset;
                tok.finalized = str_equals(strs.items[k], in_delims.items[i]);
                tok.str = strs.items[k];
                offset += tok.str.length;
                v_append(tmp, tok);
            }
        }
        v_resize(tokens, 0);
        for(int j =0; j<tmp.length; j++){
            v_append(tokens, tmp.items[j]);
        }
        arena_destroy(temps);
    }
    CTILS_InternalTokenVec tmp = make(local, Token);
    for(int i =0; i<tokens.length; i++){
        if(str_equals(tokens.items[i].str, STR("\""))){
            int start = i;
            int length =0;
            for(int j =i+1; j<tokens.length;j++){
                length += tokens.items[j].str.length;
                i++;
                if(str_equals(tokens.items[j].str, STR("\""))){
                    CTILS_InternalToken tok = tokens.items[start];
                    tok.str.length += length;
                    v_append(tmp,tok);
                    break;
                }
            }
            if(i>tokens.length){
                    CTILS_InternalToken tok = tokens.items[start];
                    tok.str.length += length;
                    v_append(tmp,tok);
                    break; 
            }
        } else{
            v_append(tmp, tokens.items[i]);
        }
    }
    tokens = tmp;
    TokenVec out = make_with_cap(arena, Token, tokens.length);
    for(int i =0; i<tokens.length; i++){
        CTILS_InternalToken s = tokens.items[i];
        Token tok = {};
        tok.file_name = file_name;
        tok.line = s.line;
        tok.start_col = s.start_col;
        tok.str = s.str;
        v_append(out, tok);
    }
    arena_destroy(local);
    return out;
}
bool is_numbers(Str str){
    bool hit_point = false;
    if(str.length <1){
        return false;
    }
    int start = 0;
    if(str.items[0] == '-'){
        start = 1;
    }
    for(int i= start; i<str.length; i++){
        if(!is_number(str.items[i]) && !(str.items[i] == '-')){
            if(!hit_point){
                if(str.items[i] == '.'){
                    hit_point = true;
                } else{
                    return false;
                }
            } else{
                return false;
            }
        }
    }
    return true;
}

#endif
