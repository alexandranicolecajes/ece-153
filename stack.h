#ifndef _STACK_H_
#define _STACK_H_

#include "ast.h"

#define STACK_SIZE 1000 

typedef struct Stack {
	BTree *table[STACK_SIZE];
	unsigned char sp;
} Stack;

void stack_init(Stack* self);
void stack_push(Stack* self, BTree* node);
BTree* stack_pop(Stack* self);

#endif
