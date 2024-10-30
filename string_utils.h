#pragma once
#include "utils.h"

enable_vec_type(String);
typedef struct {char * base; size_t len;}Str;
#define STR(st) _Generic((st), (char *): (Str){st, strlen(st)},(const char *): (Str){(char*)st, strlen(st)}, (String):(Str){st.items, st.length})
StringVec split_str_by_delim(Arena * arena,Str base, Str delim);
StringVec split_str_by_delim_no_delims(Arena * arena,Str base, Str delim);
#define PARENS ()

#define EXPAND(...) EXPAND6(EXPAND6(EXPAND6(EXPAND6(__VA_ARGS__))))
#define EXPAND6(...) EXPAND5(EXPAND5(EXPAND5(EXPAND5(__VA_ARGS__))))
#define EXPAND5(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__

#define FOR_EACH(macro, ...)                                    \
  __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...)                         \
  macro(a1)                                                     \
  __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER
#define ARGS_FIRST(arg,...) arg
#define ARGS_REMAINDER(arg,...) __VAL_OPT(__VA_ARGS__)
#define print(args...) {printf(ARGS_FIRST(args));}