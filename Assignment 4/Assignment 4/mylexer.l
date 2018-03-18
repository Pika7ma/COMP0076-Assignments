%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Author: Pingchuan Ma
ID number: 1511442
Majoring: Software Engineering

Date: Saturday, November 11, 2017
****************************************************************************/
%}

%include{
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <stdlib.h>
using namespace std;

void logging(string word, string lexeme, bool isConst, bool isOp, bool isNum);

unsigned int cnt = 0;
unordered_map<string, unsigned int> properties;
ifstream in("input.c");
ofstream out("log.txt");
}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// place any declarations here

letter 			[_A-Za-z]
decDigit 		[0-9]
octDigit 		[0-7]
hexDigit 		[0-9a-fA-F]
charVal			'([^\n\\]|(\\.)|(\\{octDigit}{1,3})|(\\[xX]{hexDigit}{1,2}))'
stringVal		\"(\\.|[^\\"\n])*\"
boolVal			("true"|"false")

identity		{letter}({letter}|{decDigit})*
decimal			(({decDigit}|[1-9]{decDigit}+)(((\.){decDigit}+)?))|(\.){decDigit}+
octal			(0)({octDigit}+)
hex				(0)[xX]({hexDigit}+)
numberSci		(({decDigit}+((\.){decDigit}+)?)|((\.){decDigit}+)|{hex})[eE]([+-]?){decDigit}+
number			{decimal}|{octal}|{hex}|{numberSci}
delimitation	[ \n\t\f\v]
whitespace		{delimitation}+

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here

{charVal}	{ logging("CHARVAR",	yytext,	true, false, false); }
{stringVal}	{ logging("STRINGVAR",	yytext,	true, false, false); }
{boolVal}	{ logging("BOOLVAR",	yytext,	true, false, false); }
{number}	{ logging("NUMBER", 	yytext, false, false, true); }

"//".*							{ /* do nothing */ }
"/*"([^\*\/]|"*"[^\/])*"*/"		{ /* do nothing */ }

"auto"		{ logging("AUTO",		yytext, false, true, false); }
"break"		{ logging("BREAK",		yytext, false, true, false); }
"case"		{ logging("CASE",		yytext, false, true, false); }
"char"		{ logging("CHAR",		yytext, false, true, false); }
"const"		{ logging("CONST",		yytext, false, true, false); }
"continue"	{ logging("CONTINUE",	yytext, false, true, false); }
"default"	{ logging("DEFAULT",	yytext, false, true, false); }
"do"		{ logging("DO",			yytext, false, true, false); }
"double"	{ logging("DOUBLE",		yytext, false, true, false); }
"else"		{ logging("ELSE",		yytext, false, true, false); }
"enum"		{ logging("ENUM",		yytext, false, true, false); }
"extern"	{ logging("EXTERN",		yytext, false, true, false); }
"float"		{ logging("FLOAT",		yytext, false, true, false); }
"for"		{ logging("FOR",		yytext, false, true, false); }
"goto"		{ logging("GOTO",		yytext, false, true, false); }
"if"		{ logging("IF",			yytext, false, true, false); }
"inline"	{ logging("INLINE",		yytext, false, true, false); }
"int"		{ logging("INT",		yytext, false, true, false); }
"long"		{ logging("LONG",		yytext, false, true, false); }
"register"	{ logging("REGISTER",	yytext, false, true, false); }
"restrict"	{ logging("RESTRICT",	yytext, false, true, false); }
"return"	{ logging("RETURN",		yytext, false, true, false); }
"short"		{ logging("SHORT",		yytext, false, true, false); }
"signed"	{ logging("SIGNED",		yytext, false, true, false); }
"sizeof"	{ logging("SIZEOF",		yytext, false, true, false); }
"static"	{ logging("STATIC",		yytext, false, true, false); }
"struct"	{ logging("STRUCT",		yytext, false, true, false); }
"switch"	{ logging("SWITCH",		yytext, false, true, false); }
"typedef"	{ logging("TYPEDEF",	yytext, false, true, false); }
"union"		{ logging("UNION",		yytext, false, true, false); }
"unsigned"	{ logging("UNSIGNED",	yytext, false, true, false); }
"void"		{ logging("VOID",		yytext, false, true, false); }
"volatile"	{ logging("VOLATILE",	yytext, false, true, false); }
"while"		{ logging("WHILE",		yytext, false, true, false); }

"..."	{ logging("ELLIPSIS",	yytext, false, true, false); }

"="		{ logging("ASG",	yytext, false, true, false); }
"+="	{ logging("ADDASG",	yytext, false, true, false); }
"-="	{ logging("SUBASG",	yytext, false, true, false); }
"*="	{ logging("MULASG",	yytext, false, true, false); }
"/="	{ logging("DIVASG",	yytext, false, true, false); }
"%="	{ logging("MODASG",	yytext, false, true, false); }
">>="	{ logging("SHRASG",	yytext, false, true, false); }
"<<="	{ logging("SHLASG",	yytext, false, true, false); }
"&="	{ logging("ANDASG",	yytext, false, true, false); }
"^="	{ logging("XORASG",	yytext, false, true, false); }
"|="	{ logging("ORASG",	yytext, false, true, false); }

"~"		{ logging("NOT",	yytext, false, true, false); }

"^"		{ logging("XOR",	yytext, false, true, false); }
"&"		{ logging("AND",	yytext, false, true, false); }
"|"		{ logging("OR",		yytext, false, true, false); }
">>"	{ logging("SHR",	yytext, false, true, false); }
"<<"	{ logging("SHL",	yytext, false, true, false); }

"++"	{ logging("INC",	yytext, false, true, false); }
"--"	{ logging("DEC",	yytext, false, true, false); }

"->"	{ logging("PTR",	yytext, false, true, false); }
"."		{ logging("DOT",	yytext, false, true, false); }

"<"		{ logging("LT",		yytext, false, true, false); }
">"		{ logging("GT",		yytext, false, true, false); }
"<="	{ logging("LEQ",	yytext, false, true, false); }
">="	{ logging("GEQ",	yytext, false, true, false); }
"=="	{ logging("EQ",		yytext, false, true, false); }
"!="	{ logging("NEQ",	yytext, false, true, false); }

";"		{ logging("SEMICOLON",	yytext, false, true, false); }
","		{ logging("COMMA",		yytext, false, true, false); }
"?"		{ logging("QUESTION",	yytext, false, true, false); }
":"		{ logging("COLON",		yytext, false, true, false); }

"("		{ logging("LPAREN",		yytext, false, true, false); }
")"		{ logging("RPAREN",		yytext, false, true, false); }
"["		{ logging("LSQPAREN",	yytext, false, true, false); }
"]"		{ logging("RSQPAREN",	yytext, false, true, false); }
"{"		{ logging("LBRACE",		yytext, false, true, false); }
"}"		{ logging("RBRACE",		yytext, false, true, false); }

"!"		{ logging("NOTLOGIC",	yytext, false, true, false); }

"&&"	{ logging("ANDLOGIC",	yytext, false, true, false); }
"||"	{ logging("ORLOGIC",	yytext, false, true, false); }

"-"		{ logging("SUB",	yytext, false, true, false); }
"+"		{ logging("ADD",	yytext, false, true, false); }
"*"		{ logging("MUL",	yytext, false, true, false); }
"/"		{ logging("DIV",	yytext, false, true, false); }
"%"		{ logging("MOD",	yytext, false, true, false); }

{identity}		{ logging("IDENTITY", 	yytext, false, false, false); }

{whitespace} 	{ /* do nothing */ }
.				{ /* do nothing */ }

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

void logging(string word, string lexeme, bool isConst = false, bool isOp = false, bool isNum = false) {
	if (isNum) {
		out << word << '\t' << lexeme << '\t' << atof(lexeme.c_str()) << endl;
		return;
	}
	if (isConst) {
		out << word << '\t' << lexeme << '\t' << lexeme << endl;
		return;
	}
	if (isOp) {
		out << word << '\t' << lexeme << endl;
		return;
	}
	if (properties.find(lexeme) == properties.end()) {
		properties[lexeme] = cnt++;
	}
	out << word << '\t' << lexeme << '\t' << properties[lexeme] << endl;
}

int main(void)
{
	int n = 1;
	mylexer lexer;
	if (lexer.yycreate()) {
		lexer.yyin = &in;
		n = lexer.yylex();
	}
	return n;
}

