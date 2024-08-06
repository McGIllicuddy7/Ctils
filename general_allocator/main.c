#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/mman.h>

typedef struct free_node_t{
	size_t size;
	struct free_node_t * next;
}free_node_t;
static free_node_t* free_list = 0;
static char bytes[4096] = {0};
void mem_init(){
	const size_t map_size = 4096;
	assert(free_list == 0);
	free_list = (void *)bytes;
	free_list->size = map_size-sizeof(free_node_t)+sizeof(size_t);
	free_list->next = 0;
}

void * mem_alloc(size_t size, size_t count){
	assert(free_list);
	size_t requested_size = size*count;
	if(requested_size<8){
		requested_size = 8;
	}
	free_node_t * current = free_list;
	free_node_t * previous = NULL;
	while(current){
		if(current->size>=(requested_size+sizeof(size_t))){
			void * out = current;	
			if(current->size>=sizeof(free_node_t)+requested_size+sizeof(size_t)){
				free_node_t * next_pointer = (free_node_t *)((char *)(current)+requested_size+sizeof(size_t));
				next_pointer->size = current->size-sizeof(size_t)-requested_size;
				if(previous){
					previous->next = next_pointer;
				} else{
					free_list = next_pointer;
				}
				*(size_t*)out = sizeof(size_t)+requested_size;
				assert(next_pointer == out+requested_size+sizeof(size_t));
			} else {
				free_node_t * nxt = current->next;
				if(nxt == 0){
					return 0;
				}
				*(size_t*)out = current->size;
				if(previous){
					previous->next = nxt;
				} else{
					free_list = nxt;
				}
			}
			return out+sizeof(size_t);
		}else {
			previous = current;
			current = current->next;	
		}
	}
	return NULL;
}
void debug_free_list();

void mem_free(void * ptr){
	free_node_t * old = free_list;
	free_list = ptr-sizeof(size_t);
	free_list->next = old;
	free_node_t * base = free_list;
	free_node_t * iter;
hit_compress:
	iter = base->next;
	while(iter){
		void * next =(char*)base+base->size;
		void * iter_next = (char*)iter+iter->size;
		if (next ==iter){
			base->next = iter->next;
			base->size += iter->size;
			goto hit_compress;
		} 
		else if(iter_next == base){
			iter->size += base->size;
			free_list = iter;
			goto hit_compress;
		}
		assert(iter != iter->next);
		iter = iter->next;
	}
	return;
}

void debug_free_list(){
	free_node_t * current = free_list;
	while(current){
		printf("|current: %zu, size:%zu, next:%zu, iter_next:%zu|\n", (size_t)current, current->size, (size_t)current->next,(size_t)((char*)current+current->size));
		assert(current != current->next);
		current = current->next;
	}
	printf("\n");
}

void debug_alloc_size(void * ptr){
	printf("%p is %zu bytes\n", ptr, *((size_t*)ptr-1));
}

int main(void){
	int count = 0;
	mem_init();
	debug_free_list();
	long ** pointers;
restart:
	pointers = mem_alloc(sizeof(long *), 400);
	debug_free_list();
	for(int i =0; i<400; i++){
		long * ptr = mem_alloc(sizeof(long *), 1);
		assert(ptr);
		pointers[i] = ptr;
	}
	debug_free_list();
	for(int i =0; i<400; i++){
		mem_free(pointers[i]);
	}
	mem_free(pointers);
	debug_free_list();
	if(count<0){
		count++;
		goto restart;
	}
	return 255;
}



