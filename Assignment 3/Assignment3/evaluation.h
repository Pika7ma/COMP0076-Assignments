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
* evaluation.h
* C++ header file generated from evaluation.y.
* 
* Date: 10/29/17
* Time: 18:11:03
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _EVALUATION_H
#define _EVALUATION_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// evaluation

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR evaluation : public _YL yyfparser {
public:
	evaluation();
	virtual ~evaluation();

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
#line 19 ".\\evaluation.y"

	// place any extra class members here
	virtual int yygettoken();

#line 69 "evaluation.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME evaluation
#endif

#line 36 ".\\evaluation.y"

#ifndef YYSTYPE
#define YYSTYPE double
#endif

#define yylval (*(YYSTYPE *)yylvalptr)


#line 85 "evaluation.h"
#define NUMBER 257
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define UMINUS 262
#endif
