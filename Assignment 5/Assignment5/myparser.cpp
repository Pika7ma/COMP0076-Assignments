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
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 01/03/18
* Time: 10:26:52
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Author: Pingchuan Ma
ID number: 1511442
Majoring: Software Engineering

Date: Tuesday, November 28, 2017
****************************************************************************/

#line 50 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 82 ".\\myparser.y"

        SymTabNode* symTabNode = SymTab::currentTab->getNode(std::string(yyattribute(1 - 1).charPtrType));
        if (symTabNode) {
            (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new IdentifierAstNode(yyattribute(1 - 1).charPtrType, symTabNode);
            (*(YYSTYPE YYFAR*)yyvalptr).nodeType->setSymTabNode(symTabNode);
        } else {
            yyerror("undeclared identifier");
        }
    
#line 196 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 91 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new CharValAstNode(cstrlit_chr(yyattribute(1 - 1).charPtrType), yyattribute(1 - 1).charPtrType);
    
#line 211 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 94 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new IntValAstNode(atoi(yyattribute(1 - 1).charPtrType));
    
#line 226 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 97 ".\\myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr).nodeType = yyattribute(2 - 3).nodeType; 
#line 239 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 102 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new UnaryExprAstNode(_POST_INC, yyattribute(1 - 2).nodeType);
    
#line 254 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 105 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new UnaryExprAstNode(_POST_DEC, yyattribute(1 - 2).nodeType);
    
#line 269 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 112 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new UnaryExprAstNode(_INC, yyattribute(2 - 2).nodeType);
    
#line 284 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 115 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new UnaryExprAstNode(_DEC, yyattribute(2 - 2).nodeType);
    
#line 299 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 118 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new UnaryExprAstNode(yyattribute(1 - 2).unaryType, yyattribute(2 - 2).nodeType);
    
#line 314 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 124 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).unaryType = _POS_OP;
    
#line 329 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 127 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).unaryType = _NEG_OP;
    
#line 344 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 130 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).unaryType = _BIT_NOT_OP;
    
#line 359 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 133 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).unaryType = _NOT_OP;
    
#line 374 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 140 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_MUL_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 389 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 143 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_DIV_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 404 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 146 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_MOD_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 419 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 153 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_ADD_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 434 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 156 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_SUB_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 449 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 163 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_BIT_LS_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 464 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 166 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_BIT_RS_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 479 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 173 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_LESS_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 494 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 176 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_GREATER_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 509 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 179 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_LE_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 524 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 182 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_GE_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 539 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 189 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_EQ_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 554 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 192 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_NE_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 569 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 199 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_BIT_AND_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 584 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 206 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_BIT_XOR_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 599 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 213 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_BIT_OR_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 614 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 220 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_AND_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 629 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 227 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_OR_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 644 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 234 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(yyattribute(2 - 3).asgnType, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 659 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 240 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _EQ_ASGN;
    
#line 674 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 243 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _MUL_ASGN;
    
#line 689 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 246 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _DIV_ASGN;
    
#line 704 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 249 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _MOD_ASGN;
    
#line 719 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 252 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _ADD_ASGN;
    
#line 734 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 255 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _SUB_ASGN;
    
#line 749 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 258 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _LS_ASGN;
    
#line 764 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 261 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _RS_ASGN;
    
#line 779 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 264 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _AND_ASGN;
    
#line 794 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 267 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _XOR_ASGN;
    
#line 809 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 270 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).asgnType = _OR_ASGN;
    
#line 824 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 277 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new BinaryExprAstNode(_COMMA_OP, yyattribute(1 - 3).nodeType, yyattribute(3 - 3).nodeType);
    
#line 839 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 283 ".\\myparser.y"

        DoubleOtherAstNode* doubleOtherAstNode = new DoubleOtherAstNode(_INIT_DECLARE, yyattribute(1 - 3).nodeType, yyattribute(2 - 3).nodeType);

        // get member list
        MultipleAstNode* multipleAstNode = (MultipleAstNode *)yyattribute(2 - 3).nodeType;
        std::vector<VarSymTabNode * > *memberList = multipleAstNode->getMemberList();
        VarSymTabNode *varSymTabNode;

        // get specifier and qualifier node
        VarSymTabNode *varSymTabNode_ = (VarSymTabNode *)(yyattribute(1 - 3).nodeType->getSymTabNode());

        // set declarator type
        for (uint i = 0; i < memberList->size(); ++i) {
            varSymTabNode = memberList->at(i);
            varSymTabNode->setSpecifier(varSymTabNode_->getSpecifier());
        }
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = doubleOtherAstNode;
    
#line 869 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 304 ".\\myparser.y"

        MultipleAstNode *multipleAstNode = new MultipleAstNode(_INIT_DECLARATOR_LIST);
        multipleAstNode->insertChild(yyattribute(1 - 1).nodeType);
        multipleAstNode->addMember((VarSymTabNode *)(yyattribute(1 - 1).nodeType->getSymTabNode()));
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = multipleAstNode;
    
#line 887 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 310 ".\\myparser.y"

        MultipleAstNode *multipleAstNode = (MultipleAstNode *)yyattribute(1 - 3).nodeType;
        multipleAstNode->insertChild(yyattribute(3 - 3).nodeType);
        multipleAstNode->addMember((VarSymTabNode *)(yyattribute(3 - 3).nodeType->getSymTabNode()));
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = multipleAstNode;
    
#line 905 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 319 ".\\myparser.y"

        // make ast
        TypeAstNode *astNode = new TypeAstNode(_CHAR);

        // make symTabNode from $1
        VarSymTabNode *symTabNode = new VarSymTabNode(SymTab::currentTab);
        symTabNode->setSpecifier(_S_CHAR);
        astNode->setSymTabNode(symTabNode);
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = astNode;
    
#line 927 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 329 ".\\myparser.y"

        // make ast
        TypeAstNode *astNode = new TypeAstNode(_INT);

        // make symTabNode from $1
        VarSymTabNode *symTabNode = new VarSymTabNode(SymTab::currentTab);
        symTabNode->setSpecifier(_S_INT);
        astNode->setSymTabNode(symTabNode);
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = astNode;
    
#line 949 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 342 ".\\myparser.y"

        if (SymTab::currentTab->isDuplicatedHere(std::string(yyattribute(1 - 1).charPtrType))) {
            yyerror("redefinition");
        }

        // make a symTabNode within this scope
        VarSymTabNode* symTabNode = new VarSymTabNode(SymTab::currentTab);

        // insert a symTabNode into this scope
        SymTab::currentTab->insertNode(std::string(yyattribute(1 - 1).charPtrType), symTabNode);

        // make identifier astNode
        AstNode *astNode = new IdentifierAstNode(yyattribute(1 - 1).charPtrType, symTabNode);

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = astNode;
    
#line 977 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 371 ".\\myparser.y"

        SymTabNode* symTabNode = SymTab::currentTab->getNode(std::string(yyattribute(3 - 5).charPtrType));
        if (symTabNode) {
            IdentifierAstNode *astNode = new IdentifierAstNode(yyattribute(3 - 5).charPtrType, symTabNode);
            astNode->setSymTabNode(symTabNode);
            (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new SingleOtherAstNode(_INPUT, astNode);
        } else {
            yyerror("undeclared identifier");
        }
    
#line 999 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 384 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new SingleOtherAstNode(_PRINT, yyattribute(3 - 5).nodeType);
    
#line 1014 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 390 ".\\myparser.y"

        if (!SymTab::keepTable) {
            SymTab::currentTab = new SymTab(SymTab::currentTab);
            SymTab::currentTab->parent->printVector.push_back(SymTab::currentTab);
        } else {
            SymTab::keepTable = false;
        }
    
#line 1034 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 397 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new OtherNoneAstNode(_BLANK_COMPOUND);
        SymTab::currentTab = SymTab::currentTab->parent;
    
#line 1050 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 401 ".\\myparser.y"

        if (!SymTab::keepTable) {
            SymTab::currentTab = new SymTab(SymTab::currentTab);
            SymTab::currentTab->parent->printVector.push_back(SymTab::currentTab);
        } else {
            SymTab::keepTable = false;
        }
    
#line 1070 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 408 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new SingleOtherAstNode(_COMPOUND, yyattribute(3 - 4).nodeType);
        SymTab::currentTab = SymTab::currentTab->parent;
    
#line 1086 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 415 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = yyattribute(1 - 2).nodeType;
        ((MultipleAstNode *)(*(YYSTYPE YYFAR*)yyvalptr).nodeType)->insertChild(yyattribute(2 - 2).nodeType);
    
#line 1102 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 419 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = yyattribute(1 - 2).nodeType;
        ((MultipleAstNode *)(*(YYSTYPE YYFAR*)yyvalptr).nodeType)->insertChild(yyattribute(2 - 2).nodeType);
    
#line 1118 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 423 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new MultipleAstNode(_DECLARE_STMT_LIST);
        ((MultipleAstNode *)(*(YYSTYPE YYFAR*)yyvalptr).nodeType)->insertChild(yyattribute(1 - 1).nodeType);
    
#line 1134 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 427 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new MultipleAstNode(_DECLARE_STMT_LIST);
        ((MultipleAstNode *)(*(YYSTYPE YYFAR*)yyvalptr).nodeType)->insertChild(yyattribute(1 - 1).nodeType);
    
#line 1150 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 434 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new OtherNoneAstNode(_BLANK_STMT);
    
#line 1165 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 437 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new SingleOtherAstNode(_EXPR_STMT, yyattribute(1 - 2).nodeType);
    
#line 1180 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 443 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new DoubleOtherAstNode(_IF_STMT, yyattribute(3 - 5).nodeType, yyattribute(5 - 5).nodeType);
    
#line 1195 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 446 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new TripleOtherAstNode(_IF_ELSE_STMT, yyattribute(3 - 7).nodeType, yyattribute(5 - 7).nodeType, yyattribute(7 - 7).nodeType);
    
#line 1210 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 452 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new DoubleOtherAstNode(_WHILE_STMT, yyattribute(3 - 5).nodeType, yyattribute(5 - 5).nodeType);
    
#line 1225 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 455 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new DoubleOtherAstNode(_DO_WHILE_STMT, yyattribute(2 - 7).nodeType, yyattribute(5 - 7).nodeType);
    
#line 1240 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 458 ".\\myparser.y"

        DoubleOtherAstNode *node = new DoubleOtherAstNode(_TWO_FOR_CONDITION, yyattribute(3 - 6).nodeType, yyattribute(4 - 6).nodeType);
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new DoubleOtherAstNode(_FOR_STMT, node, yyattribute(6 - 6).nodeType);
    
#line 1256 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 462 ".\\myparser.y"

        TripleOtherAstNode *node = new TripleOtherAstNode(_THREE_FOR_CONDITION, yyattribute(3 - 7).nodeType, yyattribute(4 - 7).nodeType, yyattribute(5 - 7).nodeType);
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new DoubleOtherAstNode(_FOR_STMT, node, yyattribute(7 - 7).nodeType);
    
#line 1272 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 469 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new OtherNoneAstNode(_CONTINUE_STMT);
    
#line 1287 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 472 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new OtherNoneAstNode(_BREAK_STMT);
    
#line 1302 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 478 ".\\myparser.y"

        ast = new Ast();
        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = ast->getRoot();
        ((MultipleAstNode *)(*(YYSTYPE YYFAR*)yyvalptr).nodeType)->insertChild(yyattribute(1 - 1).nodeType);
    
#line 1319 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 483 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = yyattribute(1 - 2).nodeType;
        ((MultipleAstNode *)(*(YYSTYPE YYFAR*)yyvalptr).nodeType)->insertChild(yyattribute(2 - 2).nodeType);
    
#line 1335 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 495 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new SingleOtherAstNode(_MAIN_FUNC, yyattribute(4 - 4).nodeType);
    
#line 1350 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 498 ".\\myparser.y"

        (*(YYSTYPE YYFAR*)yyvalptr).nodeType = new SingleOtherAstNode(_MAIN_FUNC, yyattribute(5 - 5).nodeType);
    
#line 1365 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "BIT_NOT_OP", 257 },
		{ "BIT_XOR_OP", 258 },
		{ "BIT_AND_OP", 259 },
		{ "BIT_OR_OP", 260 },
		{ "BIT_RS_OP", 261 },
		{ "BIT_LS_OP", 262 },
		{ "INC_OP", 263 },
		{ "DEC_OP", 264 },
		{ "ADD_OP", 267 },
		{ "SUB_OP", 268 },
		{ "MUL_OP", 269 },
		{ "DIV_OP", 270 },
		{ "MOD_OP", 271 },
		{ "NOT_OP", 272 },
		{ "LESS_OP", 273 },
		{ "GREATER_OP", 274 },
		{ "LE_OP", 275 },
		{ "GE_OP", 276 },
		{ "EQ_OP", 277 },
		{ "NE_OP", 278 },
		{ "AND_OP", 279 },
		{ "OR_OP", 280 },
		{ "SEMICOLON", 281 },
		{ "COMMA", 282 },
		{ "INPUT", 285 },
		{ "PRINT", 286 },
		{ "MAIN", 287 },
		{ "ROUND_LEFT", 288 },
		{ "ROUND_RIGHT", 289 },
		{ "CURLY_LEFT", 292 },
		{ "CURLY_RIGHT", 293 },
		{ "EQ_ASGN", 294 },
		{ "SUB_ASGN", 295 },
		{ "LS_ASGN", 296 },
		{ "RS_ASGN", 297 },
		{ "AND_ASGN", 298 },
		{ "XOR_ASGN", 299 },
		{ "OR_ASGN", 300 },
		{ "MUL_ASGN", 301 },
		{ "DIV_ASGN", 302 },
		{ "MOD_ASGN", 303 },
		{ "ADD_ASGN", 304 },
		{ "CHAR", 305 },
		{ "INT", 306 },
		{ "IF", 311 },
		{ "ELSE", 312 },
		{ "WHILE", 313 },
		{ "DO", 314 },
		{ "FOR", 315 },
		{ "CONTINUE", 317 },
		{ "BREAK", 318 },
		{ "IDENTIFIER", 320 },
		{ "CHAR_VAL", 322 },
		{ "INT_VAL", 324 },
		{ "IFX", 326 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: translation_unit",
		"primary_expression: IDENTIFIER",
		"primary_expression: CHAR_VAL",
		"primary_expression: INT_VAL",
		"primary_expression: ROUND_LEFT expression ROUND_RIGHT",
		"postfix_expression: primary_expression",
		"postfix_expression: postfix_expression INC_OP",
		"postfix_expression: postfix_expression DEC_OP",
		"unary_expression: postfix_expression",
		"unary_expression: INC_OP unary_expression",
		"unary_expression: DEC_OP unary_expression",
		"unary_expression: unary_operator unary_expression",
		"unary_operator: ADD_OP",
		"unary_operator: SUB_OP",
		"unary_operator: BIT_NOT_OP",
		"unary_operator: NOT_OP",
		"multiplicative_expression: unary_expression",
		"multiplicative_expression: multiplicative_expression MUL_OP unary_expression",
		"multiplicative_expression: multiplicative_expression DIV_OP unary_expression",
		"multiplicative_expression: multiplicative_expression MOD_OP unary_expression",
		"additive_expression: multiplicative_expression",
		"additive_expression: additive_expression ADD_OP multiplicative_expression",
		"additive_expression: additive_expression SUB_OP multiplicative_expression",
		"shift_expression: additive_expression",
		"shift_expression: shift_expression BIT_LS_OP additive_expression",
		"shift_expression: shift_expression BIT_RS_OP additive_expression",
		"relational_expression: shift_expression",
		"relational_expression: relational_expression LESS_OP shift_expression",
		"relational_expression: relational_expression GREATER_OP shift_expression",
		"relational_expression: relational_expression LE_OP shift_expression",
		"relational_expression: relational_expression GE_OP shift_expression",
		"equality_expression: relational_expression",
		"equality_expression: equality_expression EQ_OP relational_expression",
		"equality_expression: equality_expression NE_OP relational_expression",
		"and_expression: equality_expression",
		"and_expression: and_expression BIT_AND_OP equality_expression",
		"exclusive_or_expression: and_expression",
		"exclusive_or_expression: exclusive_or_expression BIT_XOR_OP and_expression",
		"inclusive_or_expression: exclusive_or_expression",
		"inclusive_or_expression: inclusive_or_expression BIT_OR_OP exclusive_or_expression",
		"logical_and_expression: inclusive_or_expression",
		"logical_and_expression: logical_and_expression AND_OP inclusive_or_expression",
		"logical_or_expression: logical_and_expression",
		"logical_or_expression: logical_or_expression OR_OP logical_and_expression",
		"assignment_expression: logical_or_expression",
		"assignment_expression: unary_expression assignment_operator assignment_expression",
		"assignment_operator: EQ_ASGN",
		"assignment_operator: MUL_ASGN",
		"assignment_operator: DIV_ASGN",
		"assignment_operator: MOD_ASGN",
		"assignment_operator: ADD_ASGN",
		"assignment_operator: SUB_ASGN",
		"assignment_operator: LS_ASGN",
		"assignment_operator: RS_ASGN",
		"assignment_operator: AND_ASGN",
		"assignment_operator: XOR_ASGN",
		"assignment_operator: OR_ASGN",
		"expression: assignment_expression",
		"expression: expression COMMA assignment_expression",
		"declaration: type_specifier init_declarator_list SEMICOLON",
		"init_declarator_list: direct_declarator",
		"init_declarator_list: init_declarator_list COMMA direct_declarator",
		"type_specifier: CHAR",
		"type_specifier: INT",
		"direct_declarator: IDENTIFIER",
		"statement: compound_statement",
		"statement: expression_statement",
		"statement: selection_statement",
		"statement: iteration_statement",
		"statement: jump_statement",
		"statement: input_statement",
		"statement: print_statement",
		"input_statement: INPUT ROUND_LEFT IDENTIFIER ROUND_RIGHT SEMICOLON",
		"print_statement: PRINT ROUND_LEFT expression ROUND_RIGHT SEMICOLON",
		"$$1:",
		"compound_statement: CURLY_LEFT $$1 CURLY_RIGHT",
		"$$2:",
		"compound_statement: CURLY_LEFT $$2 declaration_statement_list CURLY_RIGHT",
		"declaration_statement_list: declaration_statement_list declaration",
		"declaration_statement_list: declaration_statement_list statement",
		"declaration_statement_list: declaration",
		"declaration_statement_list: statement",
		"expression_statement: SEMICOLON",
		"expression_statement: expression SEMICOLON",
		"selection_statement: IF ROUND_LEFT expression ROUND_RIGHT statement",
		"selection_statement: IF ROUND_LEFT expression ROUND_RIGHT statement ELSE statement",
		"iteration_statement: WHILE ROUND_LEFT expression ROUND_RIGHT statement",
		"iteration_statement: DO statement WHILE ROUND_LEFT expression ROUND_RIGHT SEMICOLON",
		"iteration_statement: FOR ROUND_LEFT expression_statement expression_statement ROUND_RIGHT statement",
		"iteration_statement: FOR ROUND_LEFT expression_statement expression_statement expression ROUND_RIGHT statement",
		"jump_statement: CONTINUE SEMICOLON",
		"jump_statement: BREAK SEMICOLON",
		"translation_unit: external_declaration",
		"translation_unit: translation_unit external_declaration",
		"external_declaration: function_definition",
		"external_declaration: declaration",
		"function_definition: MAIN ROUND_LEFT ROUND_RIGHT compound_statement",
		"function_definition: type_specifier MAIN ROUND_LEFT ROUND_RIGHT compound_statement"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 1, 1, 1 },
		{ 1, 1, 2 },
		{ 1, 3, 3 },
		{ 2, 1, -1 },
		{ 2, 2, 4 },
		{ 2, 2, 5 },
		{ 3, 1, -1 },
		{ 3, 2, 6 },
		{ 3, 2, 7 },
		{ 3, 2, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 4, 1, 12 },
		{ 5, 1, -1 },
		{ 5, 3, 13 },
		{ 5, 3, 14 },
		{ 5, 3, 15 },
		{ 6, 1, -1 },
		{ 6, 3, 16 },
		{ 6, 3, 17 },
		{ 7, 1, -1 },
		{ 7, 3, 18 },
		{ 7, 3, 19 },
		{ 8, 1, -1 },
		{ 8, 3, 20 },
		{ 8, 3, 21 },
		{ 8, 3, 22 },
		{ 8, 3, 23 },
		{ 9, 1, -1 },
		{ 9, 3, 24 },
		{ 9, 3, 25 },
		{ 10, 1, -1 },
		{ 10, 3, 26 },
		{ 11, 1, -1 },
		{ 11, 3, 27 },
		{ 12, 1, -1 },
		{ 12, 3, 28 },
		{ 13, 1, -1 },
		{ 13, 3, 29 },
		{ 14, 1, -1 },
		{ 14, 3, 30 },
		{ 15, 1, -1 },
		{ 15, 3, 31 },
		{ 16, 1, 32 },
		{ 16, 1, 33 },
		{ 16, 1, 34 },
		{ 16, 1, 35 },
		{ 16, 1, 36 },
		{ 16, 1, 37 },
		{ 16, 1, 38 },
		{ 16, 1, 39 },
		{ 16, 1, 40 },
		{ 16, 1, 41 },
		{ 16, 1, 42 },
		{ 17, 1, -1 },
		{ 17, 3, 43 },
		{ 18, 3, 44 },
		{ 19, 1, 45 },
		{ 19, 3, 46 },
		{ 20, 1, 47 },
		{ 20, 1, 48 },
		{ 21, 1, 49 },
		{ 22, 1, -1 },
		{ 22, 1, -1 },
		{ 22, 1, -1 },
		{ 22, 1, -1 },
		{ 22, 1, -1 },
		{ 22, 1, -1 },
		{ 22, 1, -1 },
		{ 23, 5, 50 },
		{ 24, 5, 51 },
		{ 26, 0, 52 },
		{ 25, 3, 53 },
		{ 27, 0, 54 },
		{ 25, 4, 55 },
		{ 28, 2, 56 },
		{ 28, 2, 57 },
		{ 28, 1, 58 },
		{ 28, 1, 59 },
		{ 29, 1, 60 },
		{ 29, 2, 61 },
		{ 30, 5, 62 },
		{ 30, 7, 63 },
		{ 31, 5, 64 },
		{ 31, 7, 65 },
		{ 31, 6, 66 },
		{ 31, 7, 67 },
		{ 32, 2, 68 },
		{ 32, 2, 69 },
		{ 33, 1, 70 },
		{ 33, 2, 71 },
		{ 34, 1, -1 },
		{ 34, 1, -1 },
		{ 35, 4, 72 },
		{ 35, 5, 73 }
	};
	yyreduction = reduction;

	yytokenaction_size = 307;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 6, YYAT_ACCEPT, 0 },
		{ 155, YYAT_SHIFT, 27 },
		{ 162, YYAT_SHIFT, 103 },
		{ 145, YYAT_SHIFT, 89 },
		{ 145, YYAT_SHIFT, 90 },
		{ 65, YYAT_SHIFT, 119 },
		{ 164, YYAT_SHIFT, 168 },
		{ 155, YYAT_SHIFT, 28 },
		{ 155, YYAT_SHIFT, 29 },
		{ 162, YYAT_SHIFT, 166 },
		{ 160, YYAT_SHIFT, 164 },
		{ 155, YYAT_SHIFT, 30 },
		{ 155, YYAT_SHIFT, 31 },
		{ 166, YYAT_SHIFT, 34 },
		{ 166, YYAT_SHIFT, 35 },
		{ 158, YYAT_SHIFT, 163 },
		{ 155, YYAT_SHIFT, 32 },
		{ 65, YYAT_SHIFT, 2 },
		{ 65, YYAT_SHIFT, 3 },
		{ 154, YYAT_ERROR, 0 },
		{ 166, YYAT_SHIFT, 19 },
		{ 60, YYAT_SHIFT, 104 },
		{ 60, YYAT_SHIFT, 105 },
		{ 60, YYAT_SHIFT, 106 },
		{ 60, YYAT_SHIFT, 107 },
		{ 60, YYAT_SHIFT, 108 },
		{ 60, YYAT_SHIFT, 109 },
		{ 60, YYAT_SHIFT, 110 },
		{ 60, YYAT_SHIFT, 111 },
		{ 60, YYAT_SHIFT, 112 },
		{ 60, YYAT_SHIFT, 113 },
		{ 60, YYAT_SHIFT, 114 },
		{ 155, YYAT_SHIFT, 36 },
		{ 155, YYAT_SHIFT, 161 },
		{ 140, YYAT_SHIFT, 96 },
		{ 140, YYAT_SHIFT, 97 },
		{ 140, YYAT_SHIFT, 98 },
		{ 140, YYAT_SHIFT, 99 },
		{ 151, YYAT_SHIFT, 157 },
		{ 166, YYAT_SHIFT, 37 },
		{ 150, YYAT_SHIFT, 156 },
		{ 166, YYAT_SHIFT, 38 },
		{ 166, YYAT_SHIFT, 39 },
		{ 166, YYAT_SHIFT, 40 },
		{ 141, YYAT_SHIFT, 87 },
		{ 166, YYAT_SHIFT, 41 },
		{ 166, YYAT_SHIFT, 42 },
		{ 139, YYAT_SHIFT, 96 },
		{ 139, YYAT_SHIFT, 97 },
		{ 139, YYAT_SHIFT, 98 },
		{ 139, YYAT_SHIFT, 99 },
		{ 56, YYAT_SHIFT, 96 },
		{ 56, YYAT_SHIFT, 97 },
		{ 56, YYAT_SHIFT, 98 },
		{ 56, YYAT_SHIFT, 99 },
		{ 147, YYAT_SHIFT, 84 },
		{ 147, YYAT_SHIFT, 85 },
		{ 147, YYAT_SHIFT, 86 },
		{ 146, YYAT_SHIFT, 84 },
		{ 146, YYAT_SHIFT, 85 },
		{ 146, YYAT_SHIFT, 86 },
		{ 47, YYAT_SHIFT, 84 },
		{ 47, YYAT_SHIFT, 85 },
		{ 47, YYAT_SHIFT, 86 },
		{ 155, YYAT_SHIFT, 43 },
		{ 138, YYAT_SHIFT, 88 },
		{ 155, YYAT_SHIFT, 44 },
		{ 134, YYAT_SHIFT, 95 },
		{ 155, YYAT_SHIFT, 45 },
		{ 144, YYAT_SHIFT, 89 },
		{ 144, YYAT_SHIFT, 90 },
		{ 143, YYAT_SHIFT, 89 },
		{ 143, YYAT_SHIFT, 90 },
		{ 142, YYAT_SHIFT, 89 },
		{ 142, YYAT_SHIFT, 90 },
		{ 137, YYAT_SHIFT, 93 },
		{ 137, YYAT_SHIFT, 94 },
		{ 136, YYAT_SHIFT, 100 },
		{ 136, YYAT_SHIFT, 101 },
		{ 135, YYAT_SHIFT, 100 },
		{ 135, YYAT_SHIFT, 101 },
		{ 63, YYAT_SHIFT, 117 },
		{ 63, YYAT_SHIFT, 118 },
		{ 59, YYAT_SHIFT, 102 },
		{ 59, YYAT_SHIFT, 103 },
		{ 57, YYAT_SHIFT, 100 },
		{ 57, YYAT_SHIFT, 101 },
		{ 54, YYAT_SHIFT, 93 },
		{ 54, YYAT_SHIFT, 94 },
		{ 51, YYAT_SHIFT, 89 },
		{ 51, YYAT_SHIFT, 90 },
		{ 12, YYAT_SHIFT, 17 },
		{ 12, YYAT_SHIFT, 18 },
		{ 132, YYAT_SHIFT, 91 },
		{ 128, YYAT_SHIFT, 33 },
		{ 127, YYAT_SHIFT, 154 },
		{ 126, YYAT_SHIFT, 153 },
		{ 125, YYAT_SHIFT, 152 },
		{ 123, YYAT_SHIFT, 151 },
		{ 122, YYAT_SHIFT, 150 },
		{ 80, YYAT_SHIFT, 127 },
		{ 77, YYAT_SHIFT, 124 },
		{ 75, YYAT_SHIFT, 122 },
		{ 58, YYAT_SHIFT, 11 },
		{ 55, YYAT_SHIFT, 95 },
		{ 53, YYAT_SHIFT, 92 },
		{ 52, YYAT_SHIFT, 91 },
		{ 49, YYAT_SHIFT, 88 },
		{ 48, YYAT_SHIFT, 87 },
		{ 42, YYAT_SHIFT, 83 },
		{ 41, YYAT_SHIFT, 82 },
		{ 40, YYAT_SHIFT, 81 },
		{ 38, YYAT_SHIFT, 79 },
		{ 37, YYAT_SHIFT, 78 },
		{ 35, YYAT_SHIFT, 76 },
		{ 34, YYAT_SHIFT, 75 },
		{ 24, YYAT_ERROR, 0 },
		{ 23, YYAT_SHIFT, 26 },
		{ 21, YYAT_SHIFT, 19 },
		{ 19, YYAT_REDUCE, 74 },
		{ 16, YYAT_SHIFT, 21 },
		{ 10, YYAT_SHIFT, 16 },
		{ 9, YYAT_SHIFT, 15 },
		{ 5, YYAT_SHIFT, 10 },
		{ 1, YYAT_SHIFT, 9 },
		{ 0, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 6, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 6, YYAT_SHIFT, 2 },
		{ 6, YYAT_SHIFT, 3 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 125, 1, YYAT_DEFAULT, 6 },
		{ -164, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ -164, 1, YYAT_DEFAULT, 58 },
		{ 0, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ -167, 1, YYAT_ERROR, 0 },
		{ -167, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ -190, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_DEFAULT, 21 },
		{ -169, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 58 },
		{ -174, 1, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ -174, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ -176, 1, YYAT_ERROR, 0 },
		{ -177, 1, YYAT_DEFAULT, 65 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ -173, 1, YYAT_ERROR, 0 },
		{ -174, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ -175, 1, YYAT_ERROR, 0 },
		{ -176, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -177, 1, YYAT_ERROR, 0 },
		{ -171, 1, YYAT_ERROR, 0 },
		{ -172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ -208, 1, YYAT_REDUCE, 20 },
		{ -150, 1, YYAT_REDUCE, 38 },
		{ -172, 1, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ -172, 1, YYAT_REDUCE, 26 },
		{ -153, 1, YYAT_REDUCE, 36 },
		{ -175, 1, YYAT_REDUCE, 44 },
		{ -190, 1, YYAT_REDUCE, 34 },
		{ -156, 1, YYAT_REDUCE, 40 },
		{ -222, 1, YYAT_REDUCE, 31 },
		{ -182, 1, YYAT_REDUCE, 23 },
		{ -217, 1, YYAT_ERROR, 0 },
		{ -198, 1, YYAT_ERROR, 0 },
		{ -273, 1, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ -182, 1, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ -288, 1, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -218, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ -188, 1, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ -213, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ -190, 1, YYAT_ERROR, 0 },
		{ -191, 1, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -192, 1, YYAT_DEFAULT, 162 },
		{ -193, 1, YYAT_DEFAULT, 162 },
		{ -193, 1, YYAT_ERROR, 0 },
		{ -187, 1, YYAT_DEFAULT, 154 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ -166, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -193, 1, YYAT_REDUCE, 41 },
		{ -188, 1, YYAT_REDUCE, 25 },
		{ -190, 1, YYAT_REDUCE, 24 },
		{ -202, 1, YYAT_REDUCE, 35 },
		{ -214, 1, YYAT_REDUCE, 43 },
		{ -226, 1, YYAT_REDUCE, 32 },
		{ -239, 1, YYAT_REDUCE, 33 },
		{ -214, 1, YYAT_REDUCE, 39 },
		{ -188, 1, YYAT_REDUCE, 27 },
		{ -190, 1, YYAT_REDUCE, 28 },
		{ -192, 1, YYAT_REDUCE, 29 },
		{ -258, 1, YYAT_REDUCE, 30 },
		{ -211, 1, YYAT_REDUCE, 21 },
		{ -214, 1, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ -241, 1, YYAT_ERROR, 0 },
		{ -243, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -270, 1, YYAT_DEFAULT, 155 },
		{ -256, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ -297, 1, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ -279, 1, YYAT_DEFAULT, 162 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -280, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 166 },
		{ -275, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ -272, 1, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 89 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 84;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 166, 169 },
		{ 166, 66 },
		{ 166, 64 },
		{ 166, 69 },
		{ 155, 60 },
		{ 128, 59 },
		{ 163, 167 },
		{ 166, 70 },
		{ 166, 71 },
		{ 166, 67 },
		{ 166, 68 },
		{ 6, 4 },
		{ 161, 165 },
		{ 6, 5 },
		{ 155, 49 },
		{ 155, 53 },
		{ 155, 50 },
		{ 128, 155 },
		{ 155, 162 },
		{ 101, 61 },
		{ 101, 63 },
		{ 101, 133 },
		{ 101, 62 },
		{ 101, 147 },
		{ 115, 149 },
		{ 24, 46 },
		{ 115, -1 },
		{ 6, 14 },
		{ 6, 8 },
		{ 24, 72 },
		{ 65, 120 },
		{ 86, 131 },
		{ 65, 58 },
		{ 86, -1 },
		{ 65, 121 },
		{ 24, 65 },
		{ 95, 54 },
		{ 95, 52 },
		{ 95, 141 },
		{ 58, 12 },
		{ 154, 160 },
		{ 58, 13 },
		{ 99, 57 },
		{ 99, 145 },
		{ 94, 51 },
		{ 94, 140 },
		{ 92, 55 },
		{ 92, 138 },
		{ 91, 56 },
		{ 91, 137 },
		{ 90, 47 },
		{ 90, 136 },
		{ 88, 48 },
		{ 88, 134 },
		{ 87, 132 },
		{ 87, -1 },
		{ 19, 23 },
		{ 19, 24 },
		{ 0, 6 },
		{ 0, 7 },
		{ 153, 159 },
		{ 152, 158 },
		{ 103, 148 },
		{ 100, 146 },
		{ 98, 144 },
		{ 97, 143 },
		{ 96, 142 },
		{ 93, 139 },
		{ 89, 135 },
		{ 85, 130 },
		{ 84, 129 },
		{ 81, 128 },
		{ 79, 126 },
		{ 78, 125 },
		{ 76, 123 },
		{ 62, 116 },
		{ 60, 115 },
		{ 39, 80 },
		{ 36, 77 },
		{ 29, 74 },
		{ 28, 73 },
		{ 21, 25 },
		{ 18, 22 },
		{ 15, 20 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 25, 6 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 58 },
		{ -7, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 58, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 61, -1 },
		{ 30, -1 },
		{ 0, -1 },
		{ 56, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, 65 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, 86 },
		{ 76, 86 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 61, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 55, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 20, -1 },
		{ 0, -1 },
		{ 60, -1 },
		{ 0, -1 },
		{ 72, 86 },
		{ 0, -1 },
		{ 0, -1 },
		{ 12, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 155 },
		{ 0, -1 },
		{ 56, 155 },
		{ 55, 155 },
		{ 0, -1 },
		{ 42, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 67, 86 },
		{ 66, 86 },
		{ 28, 101 },
		{ 44, 95 },
		{ 41, 95 },
		{ 62, 90 },
		{ 45, 101 },
		{ 40, 94 },
		{ 34, 88 },
		{ 59, 94 },
		{ 37, 99 },
		{ 27, 91 },
		{ 59, 99 },
		{ 58, 99 },
		{ 57, 99 },
		{ 36, 90 },
		{ 58, 101 },
		{ 18, -1 },
		{ 0, -1 },
		{ 47, 115 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 9, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -12, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 166 },
		{ 38, 166 },
		{ 23, 155 },
		{ 1, 92 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -10, 166 },
		{ 0, -1 },
		{ -16, 166 },
		{ 0, -1 },
		{ 0, -1 },
		{ -22, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 503 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

void myparser::yyerror(char const YYFAR* s) {
    std::cout << "Line " << AstNode::getLineCnt() << ", Column " << AstNode::getColCnt() << ": " << s << std::endl;
    exit(0);
}

int main() {
    int n = 1;
    mylexer lexer;
    myparser parser;
    lexer.yyin = &myIn;
    //freopen("input.txt", "r", stdin);
    if (parser.yycreate(&lexer)) {
        if (lexer.yycreate(&parser)) {
            n = parser.yyparse();
        }
    }
    if (ast && ast->getRoot()) {
        ast->getRoot()->print(0);
        // while (SymTab::currentTab->parent) {
        //     SymTab::currentTab = SymTab::currentTab->parent;
        // }
        // SymTab::currentTab->print();
        ast->genAsm();
    }
    return n;
}

