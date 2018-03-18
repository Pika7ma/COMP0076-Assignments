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
* Date: 11/14/17
* Time: 14:24:21
* 
* ALex Version: 2.07
****************************************************************************/

#ifndef _MYLEXER_H
#define _MYLEXER_H

#include <yyclex.h>

#line 14 ".\\mylexer.l"

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

#line 48 "mylexer.h"
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
};

#ifndef YYLEXERNAME
#define YYLEXERNAME mylexer
#endif

#ifndef INITIAL
#define INITIAL 0
#endif

#endif
