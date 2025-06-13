#pragma once
#include "utils.h"
#define true 1 
#define false 0

typedef struct{
    Str str;
    Str file_name;
    u32 line;
    u8 start_col;
}Token;
enable_vec_type(Token);

CTILS_STATIC
bool token_equals(Token tok, Str str);

CTILS_STATIC
String token_print(Arena * arena,Token tok);

CTILS_STATIC
StrVec tokenize_str_no_info(Arena * arena, Str base, Str * delims, int delims_count);

CTILS_STATIC
TokenVec tokenize_str(Arena * arena, Str base, Str * delims, int delims_count, Str file);

CTILS_STATIC
bool is_numbers(Str str);

typedef enum {
    LPAN_ERROR,
    LPAN_LIST, 
    LPAN_IDENTIFIER,
    LPAN_INTEGER,
    LPAN_FLOAT
}ListParserAstNodeType;
typedef struct ListParserAstNode{
    ListParserAstNodeType type;
    union{
        struct{
            struct ListParserAstNode * v_list_begin;
            size_t v_list_len;
        };
        Token v_identifier;
        f64 v_float;
        i64 v_long;
    };
}ListParserAstNode;
enable_vec_type(ListParserAstNode);

CTILS_STATIC
String list_parser_ast_node_print(Arena * arena,ListParserAstNode list);

CTILS_STATIC
ListParserAstNode parse_tokens_to_list(Arena * arena, Token **tokens, Token * tokens_end, Str list_begin, Str list_end, Str seperator);

CTILS_STATIC
ListParserAstNode parse_str_to_list(Arena * arena, Str base, Str list_begin, Str list_end, Str seperator, Str file_name);
#ifdef CTILS_IMPLEMENTATION 

CTILS_STATIC
bool token_equals(Token tok, Str str){
    return str_equals(tok.str, str);
}

typedef struct{
    Str str;
    u32 line;
    u8 start_col;
    bool finalized;
} CTILS_InternalToken;
enable_vec_type(CTILS_InternalToken);

CTILS_STATIC
StrVec tokenize_str_no_info(Arena * arena, Str base, Str * delims, int delims_count){
    Arena * local = arena_create();
    TokenVec vec= tokenize_str(local, base, delims, delims_count, STR(""));
    StrVec out = make_with_cap(arena, Str, vec.length);
    for(size_t i=0; i<vec.length; i++){
        v_append(out, vec.items[i].str);
    }
    arena_destroy(local);
    return out;
}



CTILS_STATIC
bool is_numbers(Str str){
    bool hit_point = false;
    if(str.length <1){
        return false;
    }
    int start = 0;
    if(str.items[0] == '-'){
        start = 1;
    }
    for(size_t i= start; i<str.length; i++){
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

CTILS_STATIC
String string_indent(Arena * arena,String s, int depth){
    String out = new_string(arena, "");
    if(s.length>0){    
        for(int i =0; i<depth; i++){
            str_v_append(out, ' ');
        }
    }
    for(size_t i =0; i<s.length; i++){
        if(s.items[i] == '\n'){
            if(i<s.length-1){
                str_v_append(out, '\n');
                for(int j =0; j<depth; j++){
                    str_v_append(out, ' ');
                } 
            }
        } else{
            str_v_append(out, s.items[i]);
        }
    }
    return out;
}

CTILS_STATIC
String token_print(Arena * arena,Token tok){
    String out = string_format(arena, "token{    file name:%s;\n    line:%d;\n    start collumn:%d;\n    string:%s;\n}", str_to_c_string(arena,tok.file_name), tok.line, tok.start_col,str_to_c_string(arena,tok.str));
    return out;
}

CTILS_STATIC
String list_parser_ast_node_print(Arena * arena,ListParserAstNode list){
    Arena * local = arena_create();
    String out = new_string(arena,"");
    switch (list.type){
        case LPAN_ERROR: str_concat(out, "    ERROR"); break;
        case LPAN_FLOAT: str_concat(out, string_format(local,"    %lf,",list.v_float).items); break;
        case LPAN_INTEGER:str_concat(out, string_format(local,"    %ld,",list.v_long).items); break;
        case LPAN_IDENTIFIER:out= string_format(arena, "%s %s,",out.items, str_to_c_string(arena,list.v_identifier.str)); break;
        case LPAN_LIST:{
            str_concat(out, "{\n");
            for(size_t i =0; i<list.v_list_len; i++){
                String tmp = list_parser_ast_node_print(local, list.v_list_begin[i]);
                str_concat(out,string_indent(local, tmp, 4).items);
                str_concat(out, "\n");
            }
            str_concat(out, "\n}");
            break;
        }
    }
    str_concat(out, "");
    arena_destroy(local);
    return out;
}

CTILS_STATIC
ListParserAstNode parse_tokens_to_list(Arena * arena, Token **tokens, Token * tokens_end, Str list_begin, Str list_end, Str seperator){
    size_t sz = sizeof(ListParserAstNode);
    ListParserAstNode out = {};
    if(str_equals((*tokens)[0].str, list_begin)){
        (*tokens)++;
        ListParserAstNodeVec nodes = make(arena, ListParserAstNode);
        while(!str_equals((*tokens)[0].str, list_end)){
            if(*tokens >= tokens_end){
                break;
            }
            v_append(nodes, parse_tokens_to_list(arena, tokens, tokens_end, list_begin, list_end, seperator));
            (*tokens)++;
        }
        out.type = LPAN_LIST;
        out.v_list_begin = nodes.items;
        out.v_list_len = nodes.length;
    } else{
        if(*tokens < tokens_end){
            out.type = LPAN_IDENTIFIER;
            out.v_identifier = (*tokens)[0];
        }
    }
    return out;
}

CTILS_STATIC
ListParserAstNode parse_str_to_list(Arena * arena, Str base, Str list_begin, Str list_end, Str seperator, Str file_name){
    Arena * local = arena_create();
    bool is_white_space = str_equals(seperator, STR(" "));
    StrVec delims = make_with_cap(local, Str, is_white_space? 5: 3);
    v_append(delims, list_begin);
    v_append(delims, list_end);
    if(is_white_space){
        v_append(delims,STR("\t"));
        v_append(delims, STR("\r"));
    } else{
        v_append(delims, seperator);
    }
    TokenVec tokens = tokenize_str(local, base,delims.items,delims.length, file_name);
    TokenVec new_tokens = make_with_cap(local, Token, tokens.length);  
    for(size_t i =0; i<tokens.length; i++){
        if(is_white_space){
            if(!token_equals(tokens.items[i], seperator) && !token_equals(tokens.items[i], STR("\t"))&& !token_equals(tokens.items[i], STR("\r"))){
                v_append(new_tokens, tokens.items[i]);
            }
        }
        else if(!token_equals(tokens.items[i], seperator)){
            v_append(new_tokens, tokens.items[i]);
        }
    } 
    ListParserAstNode out = parse_tokens_to_list(arena,&(new_tokens.items), new_tokens.items+new_tokens.length, list_begin, list_end, seperator);
    arena_destroy(local);
    return out;
}
CTILS_STATIC
CTILS_InternalTokenVec tokenize_string_literals(Arena * arena, Str base){
    CTILS_InternalTokenVec out = make(arena, CTILS_InternalToken);
    size_t start =0;
    CTILS_InternalToken current = {0};
    size_t line =1;
    size_t collumn =1;
    current.str.items = base.items;
    current.str.length =0;
    current.line = 1;
    current.start_col = 1;
    bool inside_string = false;
    bool pushed = false;
    bool finalized = false;
    while(start<base.length){
        if(pushed){
            current.str.items = &base.items[start];
            current.str.length =0;
            current.line = line;
            current.finalized = false;
            current.start_col=  collumn;
            pushed = false;
        }
        if(base.items[start] == '\n'){
            if(!inside_string) v_append(out, current);
            line+=1;
            collumn= 1;
            if(!inside_string)pushed = true;
        } else if(base.items[start] == '"'){
            if(inside_string){
                current.str.length+= 1;
                current.finalized = true;
                v_append(out, current);
                inside_string = false;
                pushed = true;
                finalized = true;
            } else{
                v_append(out, current);
                inside_string = true;
                current.str.items = &base.items[start];
                current.str.length = 0;
                current.start_col = collumn;
                current.line = line; 
            }
        }
        if(!pushed){
            current.str.length+= 1;
        } 
        start+=1;   
    }
    if(!pushed){
        v_append(out,current);
    }
    return out;
}
CTILS_STATIC
TokenVec tokenize_str(Arena * arena, Str base, Str * delims, int delims_count, Str file_name){
    Arena * local = arena_create();
    StrVec in_delims = make_with_cap(local, Str, delims_count);
    for(int i =0; i<delims_count; i++){
        v_append(in_delims, delims[i]);
    }
    qsort(in_delims.items, in_delims.length, sizeof(Str), (int (*)(const void *, const void * ))strlen_cmp_reversed);
    CTILS_InternalTokenVec tokens = tokenize_string_literals(local, base); 
    CTILS_InternalTokenVec tmp = make(local, CTILS_InternalToken);
    for(size_t i =0; i<in_delims.length; i++){
        for(size_t j =0; j<tokens.length; j++){
            if(tokens.items[j].finalized){
                v_append(tmp, tokens.items[j]);
                continue;
            }
            StrVec strs = str_split_by_delim(local,tokens.items[j].str, in_delims.items[i]);
            int offset =tokens.items[j].start_col;
            for(size_t k= 0; k<strs.length; k++){
                CTILS_InternalToken tok;
                tok.line = tokens.items[j].line;
                tok.start_col = offset;
                tok.finalized = str_equals(strs.items[k], in_delims.items[i]);
                tok.str = strs.items[k];
                offset += tok.str.length;
                if(str_equals(tok.str, STR(" ")) || str_equals(tok.str, STR("\t")) || str_equals(tok.str, STR("\r"))){
                    continue;
                }
                v_append(tmp, tok);
            }
        }
        v_resize(tokens, 0);
        for(size_t j =0; j<tmp.length; j++){
            v_append(tokens, tmp.items[j]);
        }
        v_swap(tmp, tokens);  
        tmp.length =0;
    }

    TokenVec out = make_with_cap(arena, Token, tokens.length);
    for(size_t i =0; i<tokens.length; i++){
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
#endif
