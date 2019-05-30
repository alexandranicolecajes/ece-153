#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"
#include "parser.h"

Token lexer_lex(parser_t* self) 
{
	if(self->look == '=') {
		
		self->last_token = self->current_token;
		self->current_token = T_ASSIGN;
		return T_ASSIGN;

	} else if(self->look == '+') {
		self->last_token = self->current_token;
		self->current_token = T_PLUS;	
		return T_PLUS; 
	
	} else if(self->look == '*') {
		
		self->last_token = self->current_token;
		self->current_token = T_MUL;
		return T_MUL;
	
	} else if(self->look == '/') {
		
		self->last_token = self->current_token;
		self->current_token = T_DIV;
		return T_DIV;

	} else if(self->look == '-') { 

		self->last_token = self->current_token;
		self->current_token = T_MINUS;
		return T_MINUS; 
	
	} else if((isalpha((int)self->look)) || (self->look == '_')) {
		
		self->last_token = self->current_token;
		self->current_token = T_IDEN;
		return T_IDEN;
	
	} else if(isdigit((int)self->look)) {
		
		self->last_token = self->current_token;
		self->current_token = T_NUM;
		return T_NUM;
	
	} else if(self->look == '(') {
		
		self->last_token = self->current_token;
		self->current_token = T_OPAREN;
		return T_OPAREN;
	
	} else if(self->look == ')') {
		
		self->last_token = self->current_token;
		self->current_token = T_CPAREN;
		return T_CPAREN;
		
	} else {
		
		self->last_token = self->current_token;
		self->current_token = T_ILLEGAL;
		return T_ILLEGAL;
	}
}
