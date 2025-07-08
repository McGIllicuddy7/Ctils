#include "spawn.h"
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>
#include <setjmp.h>
#include <assert.h>
#include <string.h>
#include <aio.h>
typedef struct task_t{
	jmp_buf current;	
	volatile bool is_valid;
	void * stack_ptr;
}task_t;
volatile void * to_free = 0;
#define TASK_COUNT 4096*16
task_t task_queue[TASK_COUNT] = {0};
size_t current_task =0;
volatile size_t done_count =0;
volatile size_t yield_count =0;
void proc_call_thunk(volatile void * buffer, void to_call(void * args), void * args){
	assert(to_call);
	to_call(args);
	printf("done %zu\n",current_task);
	done_count++;
	task_queue[current_task].is_valid = false;	

	to_free = buffer;
//	printf("completed task: %zu\n", current_task);
	int i = current_task;
		do{
			i++;
			i%= TASK_COUNT;
			if(task_queue[i].is_valid){
				break;
			}	
		}while(i != current_task);	
	current_task =i;
	longjmp(task_queue[i].current,1);
}

/*void create_context(volatile void * buffer,  void (*to_call)(void* args), volatile void * args){	
	__asm("mov sp,x0");
	__asm("mov fp, x0");
	__asm("stp fp, lr,[sp, #-0x10]!");
	__asm("stp x0, x1, [sp, #-0x10]!");
	__asm("bl _proc_call_thunk");	
}*/

void create_context(volatile void * buffer,  void (*to_call)(void* args), volatile void * args);

task_id_t spawn_task(void (*to_call)(void* args), void * args){	
	char * buffer = alloc_stack_memory(2);
	if(!buffer){
		return -1;
	}
	int task_to_use = -1;
	task_queue[current_task].is_valid = true;
	for(int i =0; i<TASK_COUNT; i++){
		if(!task_queue[i].is_valid){
			task_to_use = i;
			break;
		}
	}
	if(task_to_use == -1){
		return task_to_use;
	}
	printf("spawned task %d\n",task_to_use);
	task_queue[task_to_use].is_valid = true;
	task_queue[task_to_use].stack_ptr = buffer;
	if(!setjmp(task_queue[current_task].current)){	
		current_task = task_to_use;	
		create_context(buffer, to_call, args);
	}		
	yield();
	return task_to_use;
}
void yield(){	
	yield_count ++;
	if(to_free){
		munmap((void*)to_free,2*4096);
		to_free =0;
	}
	if(!setjmp(task_queue[current_task].current)){
		int i = current_task;
		do{
			i++;
			i%= TASK_COUNT;
			if(task_queue[i].is_valid){
				break;
			}	else{	
			}
		}while(i != current_task);	
		current_task = i;	
		longjmp(task_queue[i].current,1);
	}	
}
void * alloc_stack_memory(size_t page_count){
	size_t size = page_count*4096;
	void * out =mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	//memset(out, 0,size);
	return out+size;
}
void wait_for_task(task_id_t to_wait_for){
	int current = current_task;
	if(!task_queue[to_wait_for].is_valid){return;}
//	printf("waiting for task:%d\n", to_wait_for);
	size_t idx =0;
	while(task_queue[to_wait_for].is_valid){	
		idx ++;
		yield();
	}	
}
void wait_for_all_tasks(){
	while(true){
	bool done  = true;
	for(int i =0; i<TASK_COUNT; i++){
		if(i == current_task){
				continue;
			}
		if(task_queue[i].is_valid){
			done = false;
			break;
		}
	}
	if(done){
		break;	
	}
	yield();
	}
}
task_id_t get_task_id(){
	return current_task;
}
void setup(){
	task_queue[0].is_valid = true;
}
