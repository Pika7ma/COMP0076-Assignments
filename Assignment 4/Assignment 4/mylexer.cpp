/****************************************************************************
*                         A C A D E M I C   C O P Y
* 
* This file was produced by an ACADEMIC COPY of Parser Generator. It is for
* use in non-commercial software only. An ACADEMIC COPY of Parser Generator
* can only be used by a student, or a member of an academic community. If
* however you want to use Parser Generator for commercial purposes then you
* will need to purchase a license. For more information see the online help or
* go to the Bumble-Bee Software homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 11/14/17
* Time: 14:24:21
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Author: Pingchuan Ma
ID number: 1511442
Majoring: Software Engineering

Date: Saturday, November 11, 2017
****************************************************************************/

#line 50 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 62 ".\\mylexer.l"
 logging("CHARVAR",	yytext,	true, false, false); 
#line 148 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 63 ".\\mylexer.l"
 logging("STRINGVAR",	yytext,	true, false, false); 
#line 155 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 64 ".\\mylexer.l"
 logging("BOOLVAR",	yytext,	true, false, false); 
#line 162 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 65 ".\\mylexer.l"
 logging("NUMBER", 	yytext, false, false, true); 
#line 169 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 67 ".\\mylexer.l"
 /* do nothing */ 
#line 176 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 68 ".\\mylexer.l"
 /* do nothing */ 
#line 183 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 70 ".\\mylexer.l"
 logging("AUTO",		yytext, false, true, false); 
#line 190 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 71 ".\\mylexer.l"
 logging("BREAK",		yytext, false, true, false); 
#line 197 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 72 ".\\mylexer.l"
 logging("CASE",		yytext, false, true, false); 
#line 204 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 73 ".\\mylexer.l"
 logging("CHAR",		yytext, false, true, false); 
#line 211 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 74 ".\\mylexer.l"
 logging("CONST",		yytext, false, true, false); 
#line 218 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 75 ".\\mylexer.l"
 logging("CONTINUE",	yytext, false, true, false); 
#line 225 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 76 ".\\mylexer.l"
 logging("DEFAULT",	yytext, false, true, false); 
#line 232 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 77 ".\\mylexer.l"
 logging("DO",			yytext, false, true, false); 
#line 239 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 78 ".\\mylexer.l"
 logging("DOUBLE",		yytext, false, true, false); 
#line 246 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 79 ".\\mylexer.l"
 logging("ELSE",		yytext, false, true, false); 
#line 253 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 80 ".\\mylexer.l"
 logging("ENUM",		yytext, false, true, false); 
#line 260 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 81 ".\\mylexer.l"
 logging("EXTERN",		yytext, false, true, false); 
#line 267 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 82 ".\\mylexer.l"
 logging("FLOAT",		yytext, false, true, false); 
#line 274 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 83 ".\\mylexer.l"
 logging("FOR",		yytext, false, true, false); 
#line 281 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 84 ".\\mylexer.l"
 logging("GOTO",		yytext, false, true, false); 
#line 288 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 85 ".\\mylexer.l"
 logging("IF",			yytext, false, true, false); 
#line 295 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 86 ".\\mylexer.l"
 logging("INLINE",		yytext, false, true, false); 
#line 302 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 87 ".\\mylexer.l"
 logging("INT",		yytext, false, true, false); 
#line 309 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 88 ".\\mylexer.l"
 logging("LONG",		yytext, false, true, false); 
#line 316 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 89 ".\\mylexer.l"
 logging("REGISTER",	yytext, false, true, false); 
#line 323 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 90 ".\\mylexer.l"
 logging("RESTRICT",	yytext, false, true, false); 
#line 330 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 91 ".\\mylexer.l"
 logging("RETURN",		yytext, false, true, false); 
#line 337 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 92 ".\\mylexer.l"
 logging("SHORT",		yytext, false, true, false); 
#line 344 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 93 ".\\mylexer.l"
 logging("SIGNED",		yytext, false, true, false); 
#line 351 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 94 ".\\mylexer.l"
 logging("SIZEOF",		yytext, false, true, false); 
#line 358 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 95 ".\\mylexer.l"
 logging("STATIC",		yytext, false, true, false); 
#line 365 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 96 ".\\mylexer.l"
 logging("STRUCT",		yytext, false, true, false); 
#line 372 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 97 ".\\mylexer.l"
 logging("SWITCH",		yytext, false, true, false); 
#line 379 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 98 ".\\mylexer.l"
 logging("TYPEDEF",	yytext, false, true, false); 
#line 386 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 99 ".\\mylexer.l"
 logging("UNION",		yytext, false, true, false); 
#line 393 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 100 ".\\mylexer.l"
 logging("UNSIGNED",	yytext, false, true, false); 
#line 400 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 101 ".\\mylexer.l"
 logging("VOID",		yytext, false, true, false); 
#line 407 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 102 ".\\mylexer.l"
 logging("VOLATILE",	yytext, false, true, false); 
#line 414 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 103 ".\\mylexer.l"
 logging("WHILE",		yytext, false, true, false); 
#line 421 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 105 ".\\mylexer.l"
 logging("ELLIPSIS",	yytext, false, true, false); 
#line 428 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 107 ".\\mylexer.l"
 logging("ASG",	yytext, false, true, false); 
#line 435 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 108 ".\\mylexer.l"
 logging("ADDASG",	yytext, false, true, false); 
#line 442 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 109 ".\\mylexer.l"
 logging("SUBASG",	yytext, false, true, false); 
#line 449 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 110 ".\\mylexer.l"
 logging("MULASG",	yytext, false, true, false); 
#line 456 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 111 ".\\mylexer.l"
 logging("DIVASG",	yytext, false, true, false); 
#line 463 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 112 ".\\mylexer.l"
 logging("MODASG",	yytext, false, true, false); 
#line 470 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 113 ".\\mylexer.l"
 logging("SHRASG",	yytext, false, true, false); 
#line 477 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 114 ".\\mylexer.l"
 logging("SHLASG",	yytext, false, true, false); 
#line 484 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 115 ".\\mylexer.l"
 logging("ANDASG",	yytext, false, true, false); 
#line 491 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 116 ".\\mylexer.l"
 logging("XORASG",	yytext, false, true, false); 
#line 498 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 117 ".\\mylexer.l"
 logging("ORASG",	yytext, false, true, false); 
#line 505 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 119 ".\\mylexer.l"
 logging("NOT",	yytext, false, true, false); 
#line 512 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 121 ".\\mylexer.l"
 logging("XOR",	yytext, false, true, false); 
#line 519 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 122 ".\\mylexer.l"
 logging("AND",	yytext, false, true, false); 
#line 526 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 123 ".\\mylexer.l"
 logging("OR",		yytext, false, true, false); 
#line 533 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 124 ".\\mylexer.l"
 logging("SHR",	yytext, false, true, false); 
#line 540 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 125 ".\\mylexer.l"
 logging("SHL",	yytext, false, true, false); 
#line 547 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 127 ".\\mylexer.l"
 logging("INC",	yytext, false, true, false); 
#line 554 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 128 ".\\mylexer.l"
 logging("DEC",	yytext, false, true, false); 
#line 561 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 130 ".\\mylexer.l"
 logging("PTR",	yytext, false, true, false); 
#line 568 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 131 ".\\mylexer.l"
 logging("DOT",	yytext, false, true, false); 
#line 575 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 133 ".\\mylexer.l"
 logging("LT",		yytext, false, true, false); 
#line 582 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 134 ".\\mylexer.l"
 logging("GT",		yytext, false, true, false); 
#line 589 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 135 ".\\mylexer.l"
 logging("LEQ",	yytext, false, true, false); 
#line 596 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 136 ".\\mylexer.l"
 logging("GEQ",	yytext, false, true, false); 
#line 603 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 137 ".\\mylexer.l"
 logging("EQ",		yytext, false, true, false); 
#line 610 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 138 ".\\mylexer.l"
 logging("NEQ",	yytext, false, true, false); 
#line 617 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 140 ".\\mylexer.l"
 logging("SEMICOLON",	yytext, false, true, false); 
#line 624 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 141 ".\\mylexer.l"
 logging("COMMA",		yytext, false, true, false); 
#line 631 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 142 ".\\mylexer.l"
 logging("QUESTION",	yytext, false, true, false); 
#line 638 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 143 ".\\mylexer.l"
 logging("COLON",		yytext, false, true, false); 
#line 645 "mylexer.cpp"
		}
		break;
	case 73:
		{
#line 145 ".\\mylexer.l"
 logging("LPAREN",		yytext, false, true, false); 
#line 652 "mylexer.cpp"
		}
		break;
	case 74:
		{
#line 146 ".\\mylexer.l"
 logging("RPAREN",		yytext, false, true, false); 
#line 659 "mylexer.cpp"
		}
		break;
	case 75:
		{
#line 147 ".\\mylexer.l"
 logging("LSQPAREN",	yytext, false, true, false); 
#line 666 "mylexer.cpp"
		}
		break;
	case 76:
		{
#line 148 ".\\mylexer.l"
 logging("RSQPAREN",	yytext, false, true, false); 
#line 673 "mylexer.cpp"
		}
		break;
	case 77:
		{
#line 149 ".\\mylexer.l"
 logging("LBRACE",		yytext, false, true, false); 
#line 680 "mylexer.cpp"
		}
		break;
	case 78:
		{
#line 150 ".\\mylexer.l"
 logging("RBRACE",		yytext, false, true, false); 
#line 687 "mylexer.cpp"
		}
		break;
	case 79:
		{
#line 152 ".\\mylexer.l"
 logging("NOTLOGIC",	yytext, false, true, false); 
#line 694 "mylexer.cpp"
		}
		break;
	case 80:
		{
#line 154 ".\\mylexer.l"
 logging("ANDLOGIC",	yytext, false, true, false); 
#line 701 "mylexer.cpp"
		}
		break;
	case 81:
		{
#line 155 ".\\mylexer.l"
 logging("ORLOGIC",	yytext, false, true, false); 
#line 708 "mylexer.cpp"
		}
		break;
	case 82:
		{
#line 157 ".\\mylexer.l"
 logging("SUB",	yytext, false, true, false); 
#line 715 "mylexer.cpp"
		}
		break;
	case 83:
		{
#line 158 ".\\mylexer.l"
 logging("ADD",	yytext, false, true, false); 
#line 722 "mylexer.cpp"
		}
		break;
	case 84:
		{
#line 159 ".\\mylexer.l"
 logging("MUL",	yytext, false, true, false); 
#line 729 "mylexer.cpp"
		}
		break;
	case 85:
		{
#line 160 ".\\mylexer.l"
 logging("DIV",	yytext, false, true, false); 
#line 736 "mylexer.cpp"
		}
		break;
	case 86:
		{
#line 161 ".\\mylexer.l"
 logging("MOD",	yytext, false, true, false); 
#line 743 "mylexer.cpp"
		}
		break;
	case 87:
		{
#line 163 ".\\mylexer.l"
 logging("IDENTITY", 	yytext, false, false, false); 
#line 750 "mylexer.cpp"
		}
		break;
	case 88:
		{
#line 165 ".\\mylexer.l"
 /* do nothing */ 
#line 757 "mylexer.cpp"
		}
		break;
	case 89:
		{
#line 166 ".\\mylexer.l"
 /* do nothing */ 
#line 764 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 498;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 4, 1 },
		{ 4, 1 },
		{ 4, 1 },
		{ 54, 8 },
		{ 0, 9 },
		{ 90, 35 },
		{ 141, 99 },
		{ 82, 32 },
		{ 87, 34 },
		{ 134, 95 },
		{ 88, 34 },
		{ 102, 41 },
		{ 150, 105 },
		{ 79, 29 },
		{ 83, 32 },
		{ 151, 105 },
		{ 91, 35 },
		{ 135, 95 },
		{ 103, 41 },
		{ 92, 35 },
		{ 89, 34 },
		{ 84, 32 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 142, 99 },
		{ 55, 8 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 118, 74 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 0, 57 },
		{ 28, 1 },
		{ 29, 1 },
		{ 26, 1 },
		{ 57, 9 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 26, 1 },
		{ 37, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 38, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 39, 1 },
		{ 40, 1 },
		{ 41, 1 },
		{ 42, 1 },
		{ 43, 1 },
		{ 44, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 26, 1 },
		{ 45, 1 },
		{ 46, 1 },
		{ 47, 1 },
		{ 48, 1 },
		{ 69, 18 },
		{ 119, 78 },
		{ 59, 13 },
		{ 110, 57 },
		{ 110, 57 },
		{ 110, 57 },
		{ 110, 57 },
		{ 110, 57 },
		{ 110, 57 },
		{ 110, 57 },
		{ 110, 57 },
		{ 143, 100 },
		{ 117, 73 },
		{ 72, 65 },
		{ 107, 46 },
		{ 51, 50 },
		{ 4, 4 },
		{ 4, 4 },
		{ 4, 4 },
		{ 4, 4 },
		{ 60, 13 },
		{ 113, 66 },
		{ 66, 17 },
		{ 0, 117 },
		{ 120, 80 },
		{ 0, 117 },
		{ 0, 66 },
		{ 67, 17 },
		{ 144, 100 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 4, 4 },
		{ 0, 114 },
		{ 68, 17 },
		{ 73, 18 },
		{ 111, 57 },
		{ 117, 73 },
		{ 72, 65 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 0, 114 },
		{ 52, 50 },
		{ 73, 18 },
		{ 111, 57 },
		{ 26, 238 },
		{ 108, 46 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 26, 238 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 115, 72 },
		{ 121, 81 },
		{ 115, 72 },
		{ 162, 124 },
		{ 163, 124 },
		{ 74, 22 },
		{ 75, 22 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 157, 157 },
		{ 117, 157 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 77, 24 },
		{ 78, 24 },
		{ 122, 82 },
		{ 123, 83 },
		{ 124, 84 },
		{ 125, 85 },
		{ 126, 86 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 56, 154 },
		{ 56, 154 },
		{ 61, 15 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 117, 157 },
		{ 157, 157 },
		{ 117, 157 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 148, 104 },
		{ 127, 87 },
		{ 128, 88 },
		{ 62, 15 },
		{ 63, 15 },
		{ 98, 40 },
		{ 99, 40 },
		{ 129, 89 },
		{ 85, 33 },
		{ 137, 97 },
		{ 149, 104 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 154, 111 },
		{ 100, 40 },
		{ 86, 33 },
		{ 130, 90 },
		{ 101, 40 },
		{ 138, 97 },
		{ 139, 97 },
		{ 131, 91 },
		{ 132, 92 },
		{ 94, 37 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 56, 154 },
		{ 114, 71 },
		{ 95, 37 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 71, 71 },
		{ 69, 19 },
		{ 133, 93 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 19, 19 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 156, 156 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 116, 116 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 65, 69 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 70, 70 },
		{ 153, 110 },
		{ 153, 110 },
		{ 153, 110 },
		{ 153, 110 },
		{ 153, 110 },
		{ 153, 110 },
		{ 153, 110 },
		{ 153, 110 },
		{ 56, 153 },
		{ 56, 153 },
		{ 56, 153 },
		{ 56, 153 },
		{ 56, 153 },
		{ 56, 153 },
		{ 56, 153 },
		{ 56, 153 },
		{ 80, 30 },
		{ 136, 96 },
		{ 104, 42 },
		{ 140, 98 },
		{ 105, 43 },
		{ 106, 44 },
		{ 145, 101 },
		{ 146, 102 },
		{ 147, 103 },
		{ 81, 31 },
		{ 49, 5 },
		{ 152, 106 },
		{ 0, 52 },
		{ 109, 56 },
		{ 155, 113 },
		{ 53, 7 },
		{ 112, 64 },
		{ 64, 16 },
		{ 158, 120 },
		{ 159, 121 },
		{ 160, 122 },
		{ 161, 123 },
		{ 76, 23 },
		{ 164, 125 },
		{ 165, 126 },
		{ 166, 127 },
		{ 167, 128 },
		{ 168, 129 },
		{ 146, 130 },
		{ 169, 131 },
		{ 170, 133 },
		{ 171, 134 },
		{ 172, 136 },
		{ 173, 137 },
		{ 174, 138 },
		{ 175, 139 },
		{ 176, 140 },
		{ 177, 141 },
		{ 178, 142 },
		{ 179, 143 },
		{ 180, 144 },
		{ 181, 145 },
		{ 182, 146 },
		{ 183, 147 },
		{ 184, 148 },
		{ 185, 149 },
		{ 186, 150 },
		{ 187, 151 },
		{ 188, 152 },
		{ 0, 67 },
		{ 93, 36 },
		{ 58, 12 },
		{ 96, 38 },
		{ 189, 159 },
		{ 190, 162 },
		{ 191, 163 },
		{ 192, 164 },
		{ 193, 165 },
		{ 194, 168 },
		{ 195, 169 },
		{ 196, 171 },
		{ 197, 173 },
		{ 198, 174 },
		{ 199, 175 },
		{ 200, 176 },
		{ 201, 177 },
		{ 202, 178 },
		{ 203, 179 },
		{ 204, 180 },
		{ 205, 181 },
		{ 206, 183 },
		{ 207, 184 },
		{ 208, 185 },
		{ 209, 187 },
		{ 210, 188 },
		{ 211, 191 },
		{ 212, 192 },
		{ 213, 193 },
		{ 214, 194 },
		{ 215, 196 },
		{ 216, 197 },
		{ 217, 198 },
		{ 218, 199 },
		{ 219, 201 },
		{ 220, 202 },
		{ 221, 203 },
		{ 222, 204 },
		{ 223, 205 },
		{ 224, 206 },
		{ 225, 208 },
		{ 226, 209 },
		{ 227, 211 },
		{ 228, 212 },
		{ 229, 216 },
		{ 230, 217 },
		{ 231, 224 },
		{ 232, 225 },
		{ 233, 226 },
		{ 234, 227 },
		{ 235, 229 },
		{ 236, 230 },
		{ 237, 232 },
		{ 238, 233 },
		{ 97, 39 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 89 },
		{ 0, 126, 88 },
		{ 0, 343, 79 },
		{ 50, 0, 89 },
		{ 0, 348, 86 },
		{ 0, -33, 55 },
		{ -56, -4, 89 },
		{ 0, 0, 73 },
		{ 0, 0, 74 },
		{ 0, 384, 84 },
		{ 0, 78, 83 },
		{ 0, 0, 70 },
		{ 0, 226, 82 },
		{ 69, 365, 62 },
		{ 0, 99, 85 },
		{ 70, 73, 4 },
		{ 156, 282, 4 },
		{ 0, 0, 72 },
		{ 0, 0, 69 },
		{ 0, 178, 63 },
		{ 0, 355, 42 },
		{ 0, 195, 64 },
		{ 0, 0, 71 },
		{ 238, 0, 87 },
		{ 0, 0, 75 },
		{ 0, 0, 76 },
		{ 0, -46, 54 },
		{ 238, 277, 87 },
		{ 238, 289, 87 },
		{ 238, -88, 87 },
		{ 238, 191, 87 },
		{ 238, -98, 87 },
		{ 238, -90, 87 },
		{ 238, 333, 87 },
		{ 238, 207, 87 },
		{ 238, 335, 87 },
		{ 238, 396, 87 },
		{ 238, 185, 87 },
		{ 238, -101, 87 },
		{ 238, 286, 87 },
		{ 238, 287, 87 },
		{ 238, 295, 87 },
		{ 0, 0, 77 },
		{ 0, 72, 56 },
		{ 0, 0, 78 },
		{ 0, 0, 53 },
		{ 0, 0, 68 },
		{ 52, 100, 0 },
		{ 0, 0, 2 },
		{ -50, 396, 0 },
		{ 0, 0, 47 },
		{ 0, 0, 80 },
		{ 0, 0, 50 },
		{ 0, 368, 0 },
		{ -56, 74, 0 },
		{ 0, 0, 45 },
		{ 0, 0, 59 },
		{ 0, 0, 43 },
		{ 0, 0, 60 },
		{ 0, 0, 44 },
		{ 0, 0, 61 },
		{ 0, 364, 0 },
		{ 69, 63, 4 },
		{ -66, 98, 0 },
		{ -67, 433, 5 },
		{ 0, 0, 46 },
		{ 0, 312, 0 },
		{ 71, 322, 4 },
		{ 156, 270, 0 },
		{ 116, 190, 0 },
		{ 117, 62, 0 },
		{ 0, -5, 58 },
		{ 0, 0, 65 },
		{ 0, 0, 67 },
		{ 0, 0, 66 },
		{ 0, 59, 57 },
		{ 0, 0, 51 },
		{ 238, 27, 87 },
		{ 238, 133, 87 },
		{ 238, 143, 87 },
		{ 238, 162, 87 },
		{ 238, 150, 87 },
		{ 238, 159, 87 },
		{ 238, 145, 14 },
		{ 238, 170, 87 },
		{ 238, 169, 87 },
		{ 238, 175, 87 },
		{ 238, 195, 87 },
		{ 238, 196, 87 },
		{ 238, 194, 87 },
		{ 238, 213, 87 },
		{ 238, 0, 22 },
		{ 238, -97, 87 },
		{ 238, 285, 87 },
		{ 238, 190, 87 },
		{ 238, 286, 87 },
		{ 238, -95, 87 },
		{ 238, 33, 87 },
		{ 238, 295, 87 },
		{ 238, 284, 87 },
		{ 238, 290, 87 },
		{ 238, 179, 87 },
		{ 238, -91, 87 },
		{ 238, 300, 87 },
		{ 0, 0, 52 },
		{ 0, 0, 81 },
		{ 0, 0, 1 },
		{ 153, 330, 0 },
		{ 154, 198, 0 },
		{ 0, 0, 41 },
		{ -66, 361, 0 },
		{ 156, 90, 0 },
		{ 116, 0, 0 },
		{ 0, 302, 4 },
		{ 157, 99, 4 },
		{ 0, 0, 49 },
		{ 0, 0, 48 },
		{ 238, 301, 87 },
		{ 238, 316, 87 },
		{ 238, 313, 87 },
		{ 238, 301, 87 },
		{ 238, 121, 87 },
		{ 238, 320, 87 },
		{ 238, 320, 87 },
		{ 238, 318, 87 },
		{ 238, 311, 87 },
		{ 238, 320, 87 },
		{ 238, 307, 87 },
		{ 238, 326, 87 },
		{ 238, 0, 20 },
		{ 238, 313, 87 },
		{ 238, 320, 87 },
		{ 238, 0, 24 },
		{ 238, 323, 87 },
		{ 238, 322, 87 },
		{ 238, 312, 87 },
		{ 238, 312, 87 },
		{ 238, 316, 87 },
		{ 238, 321, 87 },
		{ 238, 331, 87 },
		{ 238, 317, 87 },
		{ 238, 317, 87 },
		{ 238, 319, 87 },
		{ 238, 335, 87 },
		{ 238, 336, 87 },
		{ 238, 327, 87 },
		{ 238, 334, 87 },
		{ 238, 340, 87 },
		{ 238, 344, 87 },
		{ 238, 334, 87 },
		{ 56, 338, 0 },
		{ 153, 213, 0 },
		{ 0, 0, 6 },
		{ 65, 292, 0 },
		{ 72, 175, 4 },
		{ 238, 0, 7 },
		{ 238, 340, 87 },
		{ 238, 0, 9 },
		{ 238, 0, 10 },
		{ 238, 332, 87 },
		{ 238, 344, 87 },
		{ 238, 333, 87 },
		{ 238, 343, 87 },
		{ 238, 0, 16 },
		{ 238, 0, 17 },
		{ 238, 338, 87 },
		{ 238, 337, 87 },
		{ 238, 0, 21 },
		{ 238, 344, 87 },
		{ 238, 0, 25 },
		{ 238, 340, 87 },
		{ 238, 342, 87 },
		{ 238, 343, 87 },
		{ 238, 342, 87 },
		{ 238, 358, 87 },
		{ 238, 349, 87 },
		{ 238, 356, 87 },
		{ 238, 363, 87 },
		{ 238, 364, 87 },
		{ 238, 0, 3 },
		{ 238, 364, 87 },
		{ 238, 355, 87 },
		{ 238, 363, 87 },
		{ 238, 0, 38 },
		{ 238, 351, 87 },
		{ 238, 367, 87 },
		{ 238, 0, 8 },
		{ 238, 0, 11 },
		{ 238, 359, 87 },
		{ 238, 362, 87 },
		{ 238, 370, 87 },
		{ 238, 362, 87 },
		{ 238, 0, 19 },
		{ 238, 372, 87 },
		{ 238, 358, 87 },
		{ 238, 370, 87 },
		{ 238, 366, 87 },
		{ 238, 0, 29 },
		{ 238, 377, 87 },
		{ 238, 376, 87 },
		{ 238, 380, 87 },
		{ 238, 364, 87 },
		{ 238, 377, 87 },
		{ 238, 381, 87 },
		{ 238, 0, 36 },
		{ 238, 373, 87 },
		{ 238, 379, 87 },
		{ 238, 0, 40 },
		{ 238, 368, 87 },
		{ 238, 370, 87 },
		{ 238, 0, 15 },
		{ 238, 0, 18 },
		{ 238, 0, 23 },
		{ 238, 386, 87 },
		{ 238, 389, 87 },
		{ 238, 0, 28 },
		{ 238, 0, 30 },
		{ 238, 0, 31 },
		{ 238, 0, 32 },
		{ 238, 0, 33 },
		{ 238, 0, 34 },
		{ 238, 387, 87 },
		{ 238, 389, 87 },
		{ 238, 383, 87 },
		{ 238, 391, 87 },
		{ 238, 0, 13 },
		{ 238, 379, 87 },
		{ 238, 378, 87 },
		{ 238, 0, 35 },
		{ 238, 395, 87 },
		{ 238, 395, 87 },
		{ 238, 0, 12 },
		{ 238, 0, 26 },
		{ 238, 0, 27 },
		{ 238, 0, 37 },
		{ 0, 100, 39 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 168 ".\\mylexer.l"


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


