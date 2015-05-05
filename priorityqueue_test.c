#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"
#include <assert.h>

void int_print(void *s){
	printf("%d", *((int*)s));
}
void cstring_print(void *s){
	printf("%s", (char*)s);
}
int int_compare(void *o1, void *o2){
	return *((int*)o1) - *((int*)o2);
}
int cstring_compare(void *o1, void *o2){
	return strcmp((char*)o1, (char*)o2);
}

int main(){
	char* a1 = "Brian";
	char* b1 = "Julia";
	char* c1 = "Rex";

	PriorityQueue* queue = priorityqueue_constructor(&cstring_compare);

	priorityqueue_push(a1, queue);
	priorityqueue_push(b1, queue);
	priorityqueue_push(c1, queue);
	
	assert(strcmp( (char*) priorityqueue_pop(queue), c1) == 0 );
	assert(strcmp( (char*) priorityqueue_pop(queue), b1) == 0 );
	assert(strcmp( (char*) priorityqueue_pop(queue), a1) == 0 );

	printf("test complete\n");
}