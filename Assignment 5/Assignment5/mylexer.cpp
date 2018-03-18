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
* Date: 01/03/18
* Time: 10:26:52
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

Date: Tuesday, November 28, 2017
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
#line 56 ".\\mylexer.l"

YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 146 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 62 ".\\mylexer.l"

    AstNode::moveForward(yyleng);
    yylval.charPtrType = new char[yyleng + 1];
    strcpy(yylval.charPtrType, yytext);
    return CHAR_VAL;

#line 158 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 69 ".\\mylexer.l"

    AstNode::moveForward(yyleng);
    yylval.charPtrType = new char[yyleng + 1];
    strcpy(yylval.charPtrType, yytext);
    return INT_VAL;

#line 170 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 76 ".\\mylexer.l"
 /* do nothing */ 
#line 177 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 77 ".\\mylexer.l"

    for (char *c = yytext; *c != '\0'; ++c) {
        if (*c == '\n') {
            AstNode::incLineCnt();
        } else {
            AstNode::moveForward(1);
        }
    }

#line 192 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 87 ".\\mylexer.l"
 AstNode::moveForward(5); return BREAK; 
#line 199 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 88 ".\\mylexer.l"
 AstNode::moveForward(4); return CHAR; 
#line 206 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 89 ".\\mylexer.l"
 AstNode::moveForward(8); return CONTINUE; 
#line 213 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 90 ".\\mylexer.l"
 AstNode::moveForward(2); return DO; 
#line 220 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 91 ".\\mylexer.l"
 AstNode::moveForward(4); return ELSE; 
#line 227 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 93 ".\\mylexer.l"
 AstNode::moveForward(5); return FLOAT; 
#line 234 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 94 ".\\mylexer.l"
 AstNode::moveForward(3); return FOR; 
#line 241 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 95 ".\\mylexer.l"
 AstNode::moveForward(4); return GOTO; 
#line 248 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 96 ".\\mylexer.l"
 AstNode::moveForward(2); return IF; 
#line 255 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 97 ".\\mylexer.l"
 AstNode::moveForward(3); return INT; 
#line 262 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 98 ".\\mylexer.l"
 AstNode::moveForward(6); return RETURN; 
#line 269 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 99 ".\\mylexer.l"
 AstNode::moveForward(6); return STRUCT; 
#line 276 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 100 ".\\mylexer.l"
 AstNode::moveForward(5); return UNION; 
#line 283 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 101 ".\\mylexer.l"
 AstNode::moveForward(4); return VOID; 
#line 290 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 102 ".\\mylexer.l"
 AstNode::moveForward(5); return WHILE; 
#line 297 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 103 ".\\mylexer.l"
 AstNode::moveForward(5); return INPUT; 
#line 304 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 104 ".\\mylexer.l"
 AstNode::moveForward(5); return PRINT; 
#line 311 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 105 ".\\mylexer.l"
 AstNode::moveForward(4); return MAIN; 
#line 318 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 107 ".\\mylexer.l"
 AstNode::moveForward(1); return EQ_ASGN; 
#line 325 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 108 ".\\mylexer.l"
 AstNode::moveForward(2); return ADD_ASGN; 
#line 332 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 109 ".\\mylexer.l"
 AstNode::moveForward(2); return SUB_ASGN; 
#line 339 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 110 ".\\mylexer.l"
 AstNode::moveForward(2); return MUL_ASGN; 
#line 346 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 111 ".\\mylexer.l"
 AstNode::moveForward(2); return DIV_ASGN; 
#line 353 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 112 ".\\mylexer.l"
 AstNode::moveForward(2); return MOD_ASGN; 
#line 360 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 113 ".\\mylexer.l"
 AstNode::moveForward(2); return RS_ASGN; 
#line 367 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 114 ".\\mylexer.l"
 AstNode::moveForward(2); return LS_ASGN; 
#line 374 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 115 ".\\mylexer.l"
 AstNode::moveForward(2); return AND_ASGN; 
#line 381 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 116 ".\\mylexer.l"
 AstNode::moveForward(2); return XOR_ASGN; 
#line 388 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 117 ".\\mylexer.l"
 AstNode::moveForward(2); return OR_ASGN; 
#line 395 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 119 ".\\mylexer.l"
 AstNode::moveForward(1); return BIT_NOT_OP; 
#line 402 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 121 ".\\mylexer.l"
 AstNode::moveForward(1); return BIT_XOR_OP; 
#line 409 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 122 ".\\mylexer.l"
 AstNode::moveForward(1); return BIT_AND_OP; 
#line 416 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 123 ".\\mylexer.l"
 AstNode::moveForward(1); return BIT_OR_OP; 
#line 423 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 124 ".\\mylexer.l"
 AstNode::moveForward(2); return BIT_RS_OP; 
#line 430 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 125 ".\\mylexer.l"
 AstNode::moveForward(2); return BIT_LS_OP; 
#line 437 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 127 ".\\mylexer.l"
 AstNode::moveForward(2); return INC_OP; 
#line 444 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 128 ".\\mylexer.l"
 AstNode::moveForward(2); return DEC_OP; 
#line 451 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 130 ".\\mylexer.l"
 AstNode::moveForward(2); return ARROW_OP; 
#line 458 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 131 ".\\mylexer.l"
 AstNode::moveForward(1); return DOT_OP; 
#line 465 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 133 ".\\mylexer.l"
 AstNode::moveForward(1); return LESS_OP; 
#line 472 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 134 ".\\mylexer.l"
 AstNode::moveForward(1); return GREATER_OP; 
#line 479 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 135 ".\\mylexer.l"
 AstNode::moveForward(2); return LE_OP; 
#line 486 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 136 ".\\mylexer.l"
 AstNode::moveForward(2); return GE_OP; 
#line 493 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 137 ".\\mylexer.l"
 AstNode::moveForward(2); return EQ_OP; 
#line 500 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 138 ".\\mylexer.l"
 AstNode::moveForward(2); return NE_OP; 
#line 507 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 140 ".\\mylexer.l"
 AstNode::moveForward(1); return SEMICOLON; 
#line 514 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 141 ".\\mylexer.l"
 AstNode::moveForward(1); return COMMA; 
#line 521 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 142 ".\\mylexer.l"
 AstNode::moveForward(1); return QUESTION; 
#line 528 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 143 ".\\mylexer.l"
 AstNode::moveForward(1); return COLON; 
#line 535 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 145 ".\\mylexer.l"
 AstNode::moveForward(1); return ROUND_LEFT; 
#line 542 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 146 ".\\mylexer.l"
 AstNode::moveForward(1); return ROUND_RIGHT; 
#line 549 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 147 ".\\mylexer.l"
 AstNode::moveForward(1); return SQUARE_LEFT; 
#line 556 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 148 ".\\mylexer.l"
 AstNode::moveForward(1); return SQUARE_RIGHT; 
#line 563 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 150 ".\\mylexer.l"
 AstNode::moveForward(1); return CURLY_LEFT; 
#line 570 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 152 ".\\mylexer.l"
 AstNode::moveForward(1); return CURLY_RIGHT; 
#line 577 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 154 ".\\mylexer.l"
 AstNode::moveForward(1); return NOT_OP; 
#line 584 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 156 ".\\mylexer.l"
 AstNode::moveForward(2); return AND_OP; 
#line 591 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 157 ".\\mylexer.l"
 AstNode::moveForward(2); return OR_OP; 
#line 598 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 159 ".\\mylexer.l"
 AstNode::moveForward(1); return SUB_OP; 
#line 605 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 160 ".\\mylexer.l"
 AstNode::moveForward(1); return ADD_OP; 
#line 612 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 161 ".\\mylexer.l"
 AstNode::moveForward(1); return MUL_OP; 
#line 619 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 162 ".\\mylexer.l"
 AstNode::moveForward(1); return DIV_OP; 
#line 626 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 163 ".\\mylexer.l"
 AstNode::moveForward(1); return MOD_OP; 
#line 633 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 165 ".\\mylexer.l"

    AstNode::moveForward(yyleng);
    yylval.charPtrType = new char[yyleng + 1];
    strcpy(yylval.charPtrType, yytext);
    return IDENTIFIER;

#line 645 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 172 ".\\mylexer.l"
 AstNode::incLineCnt(); 
#line 652 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 173 ".\\mylexer.l"
 AstNode::moveForward(yyleng * 4); 
#line 659 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 174 ".\\mylexer.l"
 AstNode::moveForward(yyleng); 
#line 666 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 175 ".\\mylexer.l"
 yyerror("invalid character"); 
#line 673 "mylexer.cpp"
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

	yytransitionmax = 351;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 6, 1 },
		{ 51, 9 },
		{ 0, 10 },
		{ 61, 18 },
		{ 76, 35 },
		{ 56, 14 },
		{ 81, 38 },
		{ 77, 35 },
		{ 62, 18 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 20, 20 },
		{ 82, 39 },
		{ 6, 1 },
		{ 7, 1 },
		{ 63, 18 },
		{ 57, 14 },
		{ 52, 9 },
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
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 25, 1 },
		{ 26, 1 },
		{ 88, 46 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 28, 1 },
		{ 0, 54 },
		{ 29, 1 },
		{ 30, 1 },
		{ 27, 1 },
		{ 54, 10 },
		{ 27, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 36, 1 },
		{ 27, 1 },
		{ 37, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 38, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 39, 1 },
		{ 27, 1 },
		{ 40, 1 },
		{ 41, 1 },
		{ 27, 1 },
		{ 42, 1 },
		{ 43, 1 },
		{ 44, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 27, 1 },
		{ 45, 1 },
		{ 46, 1 },
		{ 47, 1 },
		{ 48, 1 },
		{ 89, 46 },
		{ 6, 6 },
		{ 6, 6 },
		{ 91, 54 },
		{ 91, 54 },
		{ 91, 54 },
		{ 91, 54 },
		{ 91, 54 },
		{ 91, 54 },
		{ 91, 54 },
		{ 91, 54 },
		{ 79, 37 },
		{ 93, 61 },
		{ 72, 32 },
		{ 104, 80 },
		{ 68, 25 },
		{ 69, 25 },
		{ 0, 61 },
		{ 105, 80 },
		{ 80, 37 },
		{ 73, 32 },
		{ 83, 40 },
		{ 6, 6 },
		{ 84, 41 },
		{ 58, 16 },
		{ 65, 23 },
		{ 66, 23 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 85, 42 },
		{ 0, 19 },
		{ 0, 19 },
		{ 59, 16 },
		{ 60, 16 },
		{ 86, 43 },
		{ 92, 54 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 64, 19 },
		{ 87, 44 },
		{ 67, 24 },
		{ 90, 53 },
		{ 27, 143 },
		{ 92, 54 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 27, 143 },
		{ 64, 19 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 49, 7 },
		{ 70, 30 },
		{ 0, 62 },
		{ 95, 65 },
		{ 96, 69 },
		{ 97, 71 },
		{ 98, 72 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 99, 73 },
		{ 100, 75 },
		{ 101, 76 },
		{ 102, 77 },
		{ 103, 78 },
		{ 71, 31 },
		{ 106, 81 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 53, 114 },
		{ 53, 114 },
		{ 107, 82 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 94, 94 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 113 },
		{ 53, 113 },
		{ 53, 113 },
		{ 53, 113 },
		{ 53, 113 },
		{ 53, 113 },
		{ 53, 113 },
		{ 53, 113 },
		{ 108, 83 },
		{ 109, 84 },
		{ 110, 85 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 114, 92 },
		{ 113, 91 },
		{ 113, 91 },
		{ 113, 91 },
		{ 113, 91 },
		{ 113, 91 },
		{ 113, 91 },
		{ 113, 91 },
		{ 113, 91 },
		{ 111, 86 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 53, 114 },
		{ 112, 87 },
		{ 55, 13 },
		{ 74, 33 },
		{ 115, 93 },
		{ 75, 34 },
		{ 116, 97 },
		{ 117, 98 },
		{ 118, 99 },
		{ 119, 100 },
		{ 120, 101 },
		{ 121, 103 },
		{ 122, 104 },
		{ 123, 106 },
		{ 124, 107 },
		{ 125, 108 },
		{ 126, 109 },
		{ 127, 110 },
		{ 128, 111 },
		{ 129, 112 },
		{ 50, 8 },
		{ 78, 36 },
		{ 130, 116 },
		{ 131, 118 },
		{ 132, 120 },
		{ 133, 122 },
		{ 134, 124 },
		{ 135, 125 },
		{ 136, 126 },
		{ 137, 127 },
		{ 138, 129 },
		{ 139, 131 },
		{ 140, 135 },
		{ 141, 136 },
		{ 142, 139 },
		{ 143, 142 },
		{ 4, 4 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 72 },
		{ 0, 341, 70 },
		{ 0, 0, 69 },
		{ 0, 109, 71 },
		{ 0, 171, 60 },
		{ 0, 273, 67 },
		{ 0, -33, 36 },
		{ -53, -4, 72 },
		{ 0, 0, 54 },
		{ 0, 0, 55 },
		{ 0, 255, 65 },
		{ 0, -34, 64 },
		{ 0, 0, 51 },
		{ 0, 98, 63 },
		{ 0, 0, 43 },
		{ 0, -35, 66 },
		{ 20, 101, 2 },
		{ 0, -35, 2 },
		{ 0, 0, 53 },
		{ 0, 0, 50 },
		{ 0, 84, 44 },
		{ 0, 130, 23 },
		{ 0, 73, 45 },
		{ 0, 0, 52 },
		{ 143, 0, 68 },
		{ 0, 0, 56 },
		{ 0, 0, 57 },
		{ 0, 172, 35 },
		{ 143, 146, 68 },
		{ 143, 28, 68 },
		{ 143, 206, 68 },
		{ 143, 211, 68 },
		{ 143, -100, 68 },
		{ 143, 224, 68 },
		{ 143, 28, 68 },
		{ 143, -87, 68 },
		{ 143, -91, 68 },
		{ 143, 39, 68 },
		{ 143, 26, 68 },
		{ 143, 46, 68 },
		{ 143, 50, 68 },
		{ 143, 86, 68 },
		{ 0, 0, 58 },
		{ 0, -5, 37 },
		{ 0, 0, 59 },
		{ 0, 0, 34 },
		{ 0, 0, 49 },
		{ 0, 0, 28 },
		{ 0, 0, 61 },
		{ 0, 0, 31 },
		{ 0, 153, 0 },
		{ -53, 74, 0 },
		{ 0, 0, 26 },
		{ 0, 0, 40 },
		{ 0, 0, 24 },
		{ 0, 0, 41 },
		{ 0, 0, 25 },
		{ 0, 0, 42 },
		{ -61, 89, 0 },
		{ -62, 224, 3 },
		{ 0, 0, 27 },
		{ 94, 0, 0 },
		{ 0, 174, 39 },
		{ 0, 0, 46 },
		{ 0, 0, 48 },
		{ 0, 0, 47 },
		{ 0, 175, 38 },
		{ 0, 0, 32 },
		{ 143, 136, 68 },
		{ 143, 141, 68 },
		{ 143, 145, 68 },
		{ 143, 0, 8 },
		{ 143, 141, 68 },
		{ 143, 146, 68 },
		{ 143, 144, 68 },
		{ 143, 143, 68 },
		{ 143, 0, 13 },
		{ 143, 21, 68 },
		{ 143, 156, 68 },
		{ 143, 165, 68 },
		{ 143, 175, 68 },
		{ 143, 178, 68 },
		{ 143, 188, 68 },
		{ 143, 203, 68 },
		{ 143, 210, 68 },
		{ 0, 0, 33 },
		{ 0, 0, 62 },
		{ 0, 0, 1 },
		{ 113, 252, 0 },
		{ 114, 197, 0 },
		{ -61, 271, 0 },
		{ 0, 174, 2 },
		{ 0, 0, 30 },
		{ 0, 0, 29 },
		{ 143, 223, 68 },
		{ 143, 207, 68 },
		{ 143, 206, 68 },
		{ 143, 222, 68 },
		{ 143, 227, 68 },
		{ 143, 0, 11 },
		{ 143, 214, 68 },
		{ 143, 209, 68 },
		{ 143, 0, 14 },
		{ 143, 217, 68 },
		{ 143, 218, 68 },
		{ 143, 212, 68 },
		{ 143, 213, 68 },
		{ 143, 220, 68 },
		{ 143, 232, 68 },
		{ 143, 225, 68 },
		{ 53, 235, 0 },
		{ 113, 212, 0 },
		{ 0, 0, 4 },
		{ 143, 229, 68 },
		{ 143, 0, 6 },
		{ 143, 232, 68 },
		{ 143, 0, 9 },
		{ 143, 222, 68 },
		{ 143, 0, 12 },
		{ 143, 223, 68 },
		{ 143, 0, 22 },
		{ 143, 224, 68 },
		{ 143, 227, 68 },
		{ 143, 243, 68 },
		{ 143, 233, 68 },
		{ 143, 0, 18 },
		{ 143, 243, 68 },
		{ 143, 0, 5 },
		{ 143, 235, 68 },
		{ 143, 0, 10 },
		{ 143, 0, 20 },
		{ 143, 0, 21 },
		{ 143, 236, 68 },
		{ 143, 231, 68 },
		{ 143, 0, 17 },
		{ 143, 0, 19 },
		{ 143, 231, 68 },
		{ 143, 0, 15 },
		{ 143, 0, 16 },
		{ 143, 248, 68 },
		{ 0, 98, 7 }
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
		0
	};
	yybackup = backup;
}
#line 177 ".\\mylexer.l"


int yywrap() {
    return 1;
}

void mylexer::yyerror(char const YYFAR* s) {
    std::cout << "Line " << AstNode::getLineCnt() << ", Column " << AstNode::getColCnt() << ": " << s << std::endl;
    exit(0);
}

