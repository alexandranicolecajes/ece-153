#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

void stack_init(Stack* self)
{
	self->sp = 0;
	size_t i;
	for(i = 0; i < STACK_SIZE; i++) {
		self->table[i] = NULL;
	}
}

BTree* stack_pop(Stack* self)
{
	if(self->sp == 0) {
		return self->table[0];
	} else if(self->sp > 0) {
		return self->table[--self->sp];
	} else {
		printf("error: stack underflow\n");
		exit(1);
	}
}

void stack_push(Stack* self, BTree* node)
{
	// wrap if neccessary
	self->table[((unsigned char)self->sp++)] = node;
	
}
