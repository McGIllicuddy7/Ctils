#include <stdio.h>
#include "spawn.h"
#include <assert.h>
volatile static int inc_count =0;
void test3(void * less){
	yield();
	for(int i =0; i<100000; i++){
		inc_count++;	
		yield();
	}
}
void test(void *nothing){
	yield();
	for(int i =0; i<10; i++){	
		spawn_task(test3, 0);
	}

}

int main(){ char * stack = alloc_stack_memory(4);	

	int max_count = 100;
	for(size_t i = 0; i<max_count; i++){
		spawn_task(test, (void *)i);
	}
	printf("done\n");
	wait_for_all_tasks();
	printf("inc_count:%d\n", inc_count);
	printf("done count:%zu\n",done_count);
	printf("yield count:%zu\n", yield_count);
}
