#ifndef _B_TREE_H
#define _B_TREE_H

#include <stdbool.h>

typedef enum OPType {
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_ASSIGN
} OPType;

typedef enum ValueType {
	IS_OP,
	IS_INT,
	IS_IDEN
} ValueType;

typedef struct BTree BTree;
typedef struct Value {
	ValueType type;
	union {
		OPType op;
		long long int value;
		char* str;
	} u1;
} Value;

typedef struct BTree {
	struct BTree* left;
	struct BTree* right;
	struct Value* value;
} BTree;

BTree* new_empty_node();
Value* value_new_operation(OPType otype);
Value* value_new_number(long long int value);
Value* value_new_variable(const char* v);

#endif


