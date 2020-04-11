#include "lexer.h"
#include <stdio.h>
#include <ctype.h>

char *text = "";
int leng = 0;
int lineno = 0;

lexer()
{
	static char input_buffer[128];
	char *current;

	current = yytext + yyleng;

	while (1)
	{
		while(!*current)
		{
			current = input_buffer;
			if ( !gets(input_buffer) )
			{
				*current = '\0';
				return EIO;
			}

			++lineno;

			while( isspace(*current))
				++current;
		}

		for ( ;*current ; ++current)
		{
			text = current;
			leng = 1;

			switch(*current)
			{
				case EOF : return EOI ;
				case ';' : return SEMI ;
				case '+' : return PLUS ;
				case '*' : return TIMES ;
				case '(' : return LP ;
				case ')' : return RP ;

				case '\n' : 
				case '\t' : 
				case ' ' : break;

				default:
				if( !isalnum(*current))
					fprintf(stderr, "Ignoring illegal input <%c>\n", *current );
				else
				{
					while (isalnum (*current))
						++current;

					leng = current - text;
					return NUM_OR_ID;
				}
				break;
			}
		}
	}

static int Lookahead = -1;

int match (token)
int token;
{
	if (Lookahead == -1)
		Lookahead = lexer();

	return token == Lookahead;
}

void advance ()
{
	Lookahead = lexer();
}
