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
* mylexer.h
* C++ header file generated from mylexer.l.
* 
* Date: 01/03/18
* Time: 10:26:52
* 
* ALex Version: 2.07
****************************************************************************/

#ifndef _MYLEXER_H
#define _MYLEXER_H

#include <yyclex.h>

#line 16 ".\\mylexer.l"

#include "myparser.h"
#include "string.h"
#include "SymTab.h"

#line 38 "mylexer.h"
/////////////////////////////////////////////////////////////////////////////
// mylexer

#ifndef YYEXPLEXER
#define YYEXPLEXER
#endif

class YYEXPLEXER YYFAR mylexer : public _YL yyflexer {
public:
	mylexer();
	virtual ~mylexer();

	// backards compatibility with lex
#ifdef input
	virtual int yyinput();
#endif
#ifdef output
	virtual void yyoutput(int ch);
#endif
#ifdef unput
	virtual void yyunput(int ch);
#endif

protected:
	void yytables();
	virtual int yyaction(int action);

public:
#line 25 ".\\mylexer.l"

    void yyerror(char const YYFAR* s);
    void comment();

#line 72 "mylexer.h"
};

#ifndef YYLEXERNAME
#define YYLEXERNAME mylexer
#endif

#ifndef INITIAL
#define INITIAL 0
#endif

#endif
