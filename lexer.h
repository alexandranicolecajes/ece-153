#ifndef __LEX_H__
#define __LEX_H__

typedef struct parser_t parser_t;

typedef enum Token {
	T_ILLEGAL,
	T_MUL,
	T_DIV,
	T_PLUS,
	T_MINUS,
	T_IDEN,
	T_NUM,
	T_ASSIGN,
	T_OPAREN,
	T_CPAREN
} Token;

Token lexer_lex(parser_t* self);

#endif
