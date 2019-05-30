#ifndef __PARSER_H__
#define __PARSER_H__

#include "lexer.h"
#include "ast.h"
#include "stack.h"

#define NORETURN __attribute__ ((noreturn))

typedef struct parser_t {
	char* text;
	size_t pos;
	size_t len;
	char look;
	int status;
	int line;
	Token last_token;
	Token current_token;
	BTree* ast;
	Stack stack;
} parser_t;

BTree* do_assignment(parser_t* self);
BTree* do_expression(parser_t* self);
void NORETURN expected(parser_t* self, const char* s);
int  parser_init(parser_t*, char*);
void parser_next(parser_t*);
void parse_assignment(parser_t* self);
void parser_parse(parser_t*); 
void parser_shutdown(parser_t*);

#endif


