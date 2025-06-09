#include "utils.h"
#warning "PLEASE DON'T USE THIS"
#define make_lambda_type(name,return_type, ...) typedef struct{union {return_type (*fn)(const void * __VA_OPT__(,__VA_ARGS__));return_type (*fn_no_args)(__VA_ARGS__); };void * data;}fn_##name;
#define make_lambda_capture(lambda_type,return_type,name, body,fn_captures,...) \
    struct name##Captures fn_captures;\
    return_type name(const struct name##Captures * captures __VA_OPT__(,__VA_ARGS__)) body\
    lambda_type make##name##fn(struct name##Captures captures){\
        void * data = malloc(sizeof(struct name##Captures));\
        memcpy(data, &captures, sizeof(captures));\
        return (lambda_type){(return_type (*)(const void * __VA_OPT__(, __VA_ARGS__)))name, data};\
    }\
    lambda_type make##name##fn_arena(Arena * arena,struct name##Captures captures){\
        void * data = arena_alloc(arena,sizeof(struct name##Captures));\
        memcpy(data, &captures, sizeof(captures));\
        return (lambda_type){(return_type (*)(const void * __VA_OPT__(,__VA_ARGS__)))name, data};\
    }
#define make_lambda(lambda_type,return_type, name, body, ...)\
    return_type name(const void * captures __VA_OPT__(,__VA_ARGS__)) body\
    lambda_type make##name##fn(){\
        return (lambda_type){name,0};\
    }\
    lambda_type make##name##fn_arena(Arena * arena){\
        return (lambda_type){name,0};\
    }


#define lambda(name, ...) make##name##fn(__VA_OPT__((struct name##Captures)__VA_ARGS__))
#define lambda_arena(name, arena,...) make##name##fn_arena(arena __VA_OPT__(,(struct name##Captures)__VA_ARGS__))
#define tmp_lambda(name,...) make##name##fn_arena(&temporary_allocator __VA_OPT__(,(struct name##Captures)__VA_ARGS__))
#define lambda_arb(name, fn_name) (name){fn_name,0};
#define call(func,...) func.data? func.fn(func.data __VA_OPT__(,__VA_ARGS__)) :func.fn_no_args(__VA_ARGS__)
