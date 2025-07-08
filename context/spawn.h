#pragma once
#include <stdlib.h>
#include <stdbool.h>
typedef int task_id_t;
extern volatile size_t done_count;
extern volatile size_t yield_count;
void * alloc_stack_memory(size_t page_count);
void yield();
task_id_t spawn_task(void (*to_call)(void *args), void * args);
task_id_t get_task_id();
void wait_for_task(task_id_t to_wait_for);
void wait_for_all_tasks();
void setup();
