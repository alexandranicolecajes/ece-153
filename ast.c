#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ast.h"

BTree* new_empty_node()
{
	BTree* node = malloc(sizeof(BTree));
	return node;
}

Value* value_new_operation(OPType otype)
{
	Value* value = malloc(sizeof(Value));
	if(!value) {
		return NULL;
	}
	
	value->type = IS_OP;
	value->u1.op = otype;
	return value;
}

Value* value_new_variable(const char* v)
{
	Value* value = malloc(sizeof(Value));
	if(!value) {
		return NULL;
	}	
	value->type = IS_IDEN;
	value->u1.str = strdup(v);
	return value;
}

Value* value_new_number(long long int v)
{
	Value* value = malloc(sizeof(Value));
	if(!value) {
		return NULL;
	}	
	value->type = IS_INT;
	value->u1.value = v;
	return value;
}
