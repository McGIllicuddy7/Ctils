#include "utils.h"
#define make_lambda_type(name,return_type, args...) typedef struct{return_type (*fn)(void * __VA_OPT__(,args)); void * data;}fn_##name;
#define make_lambda_capture(lambda_type,return_type,name, body,fn_captures,args...) \
    struct name##Captures fn_captures;\
    return_type name(struct name##Captures * captures __VA_OPT__(,args)) body\
    lambda_type make##name##fn(struct name##Captures captures){\
        void * data = malloc(sizeof(struct name##Captures));\
        memcpy(data, &captures, sizeof(captures));\
        return (lambda_type){(return_type (*)(void * __VA_OPT__(, args)))name, data};\
    }\
    lambda_type make##name##fn_arena(Arena * arena,struct name##Captures captures){\
        void * data = arena_alloc(arena,sizeof(struct name##Captures));\
        memcpy(data, &captures, sizeof(captures));\
        return (lambda_type){(return_type (*)(void * __VA_OPT__(, args)))name, data};\
    }
#define make_lambda(lambda_type,return_type, name, body, args...)\
    return_type name(void * captures __VA_OPT__(,args)) body\
    lambda_type make##name##fn(){\
        return (lambda_type){name,0};\
    }\
    lambda_type make##name##fn_arena(Arena * arena){\
        return (lambda_type){name,0};\
    }
#define lambda(name, captures...) make##name##fn(__VA_OPT__((struct name##Captures)captures));
#define lambda_arena(name, arena,captures...) make##name##fn_arena(arena,__VA_OPT__(,captures));
#define call(func,args...) func.fn(func.data __VA_OPT__(, args))

