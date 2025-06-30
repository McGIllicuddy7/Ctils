#include "utils.h"
void test11(){
    new_arena(eepy);
    char * cv = arena_alloc(eepy,5000);
    printf("enter message:");
    fgets(cv, 4999, stdin);
    printf("your message was:%s\n", cv); 
}
