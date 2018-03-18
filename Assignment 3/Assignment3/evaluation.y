%{
/****************************************************************************
evaluation.y
ParserWizard generated YACC file.

Date: Saturday, October 28, 2017
****************************************************************************/
#include <iostream>
using namespace std;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name evaluation

// class definition
{
	// place any extra class members here
	virtual int yygettoken();
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here

%include {
#ifndef YYSTYPE
#define YYSTYPE double
#endif

#define yylval (*(YYSTYPE *)yylvalptr)

}

%token NUMBER
%left PLUS MINUS
%left MUL DIV
%right UMINUS

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

lines	:	lines expr '\n'	{ cout << $2 << endl; }
		|	lines '\n'
		|
		;

expr	:	expr PLUS expr			{ $$ = $1 + $3; }
		|	expr MINUS expr			{ $$ = $1 - $3; }
		|	expr MUL expr			{ $$ = $1 * $3; }
		|	expr DIV expr			{ $$ = $1 / $3; }
		|	'(' expr ')'			{ $$ = $2; }
		|	MINUS expr %prec UMINUS	{ $$ = -$2; }
		|	NUMBER
		;

//NUMBER	:	'0'				{ $$ = 0.0; }
//		|	'1'				{ $$ = 1.0; }
//		|	'2'				{ $$ = 2.0; }
//		|	'3'				{ $$ = 3.0; }
//		|	'4'				{ $$ = 4.0; }
//		|	'5'				{ $$ = 5.0; }
//		|	'6'				{ $$ = 6.0; }
//		|	'7'				{ $$ = 7.0; }
//		|	'8'				{ $$ = 8.0; }
//		|	'9'				{ $$ = 9.0; }
//		;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int YYPARSERNAME::yygettoken()
{
	// place your token retrieving code here
	char* input = new char[0];
	double number = 0;
	while (true) {
		*input = getchar();
		if (*input == ' ' || *input == '\t') {
			continue;
		} else if (*input == '*') {
			return MUL;
		} else if (*input == '/') {
			return DIV;
		} else if (*input == '+') {
			return PLUS;
		} else if (*input == '-') {
			return MINUS;
		} else if (*input >= '0' && *input <= '9') {
			do {
				number = 10 * number + atoi(input);
				*input = getchar();
			} while (*input >= '0' && *input <= '9');
			ungetc(*input, stdin);
			yylval = YYSTYPE(number);
			return NUMBER;
		} else {
			return (int)(*input);
		}
	}
}

int main(void)
{
	int n = 1;
	evaluation parser;
	if (parser.yycreate()) {
		n = parser.yyparse();
	}
	return n;
}
