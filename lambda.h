#include "utils.h"
//creates a lambda type named "name" that returns return type, the variadics are the arguments of the function 
#define make_lambda_type(name,return_type, ...) typedef struct{union {return_type (*fn)(const void * __VA_OPT__(,__VA_ARGS__));return_type (*fn_no_args)(__VA_ARGS__); };void * data;}fn_##name;


//creates a lamdba of type lambda type(defined using the above make_lambda_type macro) that returns return_type, is named name, has body body(the body of the function), can captures the captures(passed as a struct body) and accessed using captures->capture, this is absolutely not thread safe,once again the variadics are the arguments to the function
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

//creates a lambda of type lambda_type (defined using the above make_lambda_type macro) that returns return_type, is named name, has body body, and takes args as a variadic parameter
#define make_lambda(lambda_type,return_type, name, body, ...)\
    return_type name(const void * captures __VA_OPT__(,__VA_ARGS__)) body\
    lambda_type make##name##fn(){\
        return (lambda_type){name,0};\
    }\
    lambda_type make##name##fn_arena(Arena * arena){\
        return (lambda_type){name,0};\
    }

//this creates an actual lambda function along with captures, it using the function defined using make_lambda or make_lambda capture passed using the name parameter and takes the captures as a variadic parameter, it stores captures(if any) using the provided arena, note that the only safe way to free a lambda is through destroying or reseting the arena it's captures are stored on
#define lambda(arena,name,...) make##name##fn_arena(arena __VA_OPT__(,(struct name##Captures)__VA_ARGS__))

//this creates an actual lambda function along with captures, it using the function defined using make_lambda or make_lambda capture passed using the name parameter and takes the captures as a variadic parameter, it stores captures(if any) using the temporary arena, note that the only safe way to free a lambda is through destroying or reseting the arena it's captures are stored on
#define tmp_lambda(name,...) make##name##fn_arena(&temporary_allocator __VA_OPT__(,(struct name##Captures)__VA_ARGS__))

//this creates an actual lambda function along with no captures that uses fn_name as its function and is of type name, 
#define lambda_arb(name, fn_name) (name){fn_name,0};

//this calls a lambda func with parameters passed using the variadic, it will handle both the case with captures and without
#define call(func,...) ((func).data? (func).fn((func).data __VA_OPT__(,__VA_ARGS__)) :(func).fn_no_args(__VA_ARGS__))
