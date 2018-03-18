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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 01/03/18
* Time: 10:26:52
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

#line 17 ".\\myparser.y"

#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "mylexer.h"
#include "Ast.h"
#include "AstNode.h"
#include "SymTabNode.h"
#include "SymTab.h"
#include "str_util.h"
extern Ast *ast;
extern std::ifstream myIn;

#line 46 "myparser.h"
/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 36 ".\\myparser.y"

    void yyerror(char const YYFAR *s);

#line 83 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#define BIT_NOT_OP 257
#define BIT_XOR_OP 258
#define BIT_AND_OP 259
#define BIT_OR_OP 260
#define BIT_RS_OP 261
#define BIT_LS_OP 262
#define INC_OP 263
#define DEC_OP 264
#define ARROW_OP 265
#define DOT_OP 266
#define ADD_OP 267
#define SUB_OP 268
#define MUL_OP 269
#define DIV_OP 270
#define MOD_OP 271
#define NOT_OP 272
#define LESS_OP 273
#define GREATER_OP 274
#define LE_OP 275
#define GE_OP 276
#define EQ_OP 277
#define NE_OP 278
#define AND_OP 279
#define OR_OP 280
#define SEMICOLON 281
#define COMMA 282
#define QUESTION 283
#define COLON 284
#define INPUT 285
#define PRINT 286
#define MAIN 287
#define ROUND_LEFT 288
#define ROUND_RIGHT 289
#define SQUARE_LEFT 290
#define SQUARE_RIGHT 291
#define CURLY_LEFT 292
#define CURLY_RIGHT 293
#define EQ_ASGN 294
#define SUB_ASGN 295
#define LS_ASGN 296
#define RS_ASGN 297
#define AND_ASGN 298
#define XOR_ASGN 299
#define OR_ASGN 300
#define MUL_ASGN 301
#define DIV_ASGN 302
#define MOD_ASGN 303
#define ADD_ASGN 304
#define CHAR 305
#define INT 306
#define FLOAT 307
#define VOID 308
#define STRUCT 309
#define UNION 310
#define IF 311
#define ELSE 312
#define WHILE 313
#define DO 314
#define FOR 315
#define GOTO 316
#define CONTINUE 317
#define BREAK 318
#define RETURN 319
#ifndef YYSTYPE
union tagYYSTYPE {
#line 48 ".\\myparser.y"

    char * charPtrType;
    AstNode * nodeType;
    BinaryExprType asgnType;
    UnaryExprType unaryType;

#line 162 "myparser.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

#define IDENTIFIER 320
#define STRING_VAL 321
#define CHAR_VAL 322
#define BOOL_VAL 323
#define INT_VAL 324
#define FLOAT_VAL 325
#define IFX 326
#endif
