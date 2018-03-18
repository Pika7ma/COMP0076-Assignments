%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Author: Pingchuan Ma
ID number: 1511442
Majoring: Software Engineering

Date: Tuesday, November 28, 2017
****************************************************************************/
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%include {
#include "myparser.h"
#include "string.h"
#include "SymTab.h"
}

// lexical analyser name
%name mylexer

{
    void yyerror(char const YYFAR* s);
    void comment();
}

// place any declarations here

letter          [_A-Za-z]
decDigit        [0-9]
octDigit        [0-7]
hexDigit        [0-9a-fA-F]
charVal         '([^\n\\]|(\\.)|(\\{octDigit}{1,3})|(\\[xX]{hexDigit}{1,2}))'
stringVal       \"(\\.|[^\\"\n])*\"
boolVal         ("true"|"false")

identifier      {letter}({letter}|{decDigit})*
decimal         {decDigit}|[1-9]{decDigit}+
octal           (0)({octDigit}+)
hex             (0)[xX]({hexDigit}+)
intVal          {decimal}|{octal}|{hex}
floatVal        ({decimal}(\.){decDigit}+)|(\.){decDigit}+
newline         [\n]
delimitation    [ \f\v]
tab             [\t]+
whitespace      {delimitation}+

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here

{charVal} {
    AstNode::moveForward(yyleng);
    yylval.charPtrType = new char[yyleng + 1];
    strcpy(yylval.charPtrType, yytext);
    return CHAR_VAL;
}

{intVal} {
    AstNode::moveForward(yyleng);
    yylval.charPtrType = new char[yyleng + 1];
    strcpy(yylval.charPtrType, yytext);
    return INT_VAL;
}

"//".*                      { /* do nothing */ }
"/*"([^\*\/]|"*"[^\/])*"*/" {
    for (char *c = yytext; *c != '\0'; ++c) {
        if (*c == '\n') {
            AstNode::incLineCnt();
        } else {
            AstNode::moveForward(1);
        }
    }
}

"break"         { AstNode::moveForward(5); return BREAK; }
"char"          { AstNode::moveForward(4); return CHAR; }
"continue"      { AstNode::moveForward(8); return CONTINUE; }
"do"            { AstNode::moveForward(2); return DO; }
"else"          { AstNode::moveForward(4); return ELSE; }

"float"         { AstNode::moveForward(5); return FLOAT; }
"for"           { AstNode::moveForward(3); return FOR; }
"goto"          { AstNode::moveForward(4); return GOTO; }
"if"            { AstNode::moveForward(2); return IF; }
"int"           { AstNode::moveForward(3); return INT; }
"return"        { AstNode::moveForward(6); return RETURN; }
"struct"        { AstNode::moveForward(6); return STRUCT; }
"union"         { AstNode::moveForward(5); return UNION; }
"void"          { AstNode::moveForward(4); return VOID; }
"while"         { AstNode::moveForward(5); return WHILE; }
"input"         { AstNode::moveForward(5); return INPUT; }
"print"         { AstNode::moveForward(5); return PRINT; }
"main"          { AstNode::moveForward(4); return MAIN; }

"="     { AstNode::moveForward(1); return EQ_ASGN; }
"+="    { AstNode::moveForward(2); return ADD_ASGN; }
"-="    { AstNode::moveForward(2); return SUB_ASGN; }
"*="    { AstNode::moveForward(2); return MUL_ASGN; }
"/="    { AstNode::moveForward(2); return DIV_ASGN; }
"%="    { AstNode::moveForward(2); return MOD_ASGN; }
">>="   { AstNode::moveForward(2); return RS_ASGN; }
"<<="   { AstNode::moveForward(2); return LS_ASGN; }
"&="    { AstNode::moveForward(2); return AND_ASGN; }
"^="    { AstNode::moveForward(2); return XOR_ASGN; }
"|="    { AstNode::moveForward(2); return OR_ASGN; }

"~"     { AstNode::moveForward(1); return BIT_NOT_OP; }

"^"     { AstNode::moveForward(1); return BIT_XOR_OP; }
"&"     { AstNode::moveForward(1); return BIT_AND_OP; }
"|"     { AstNode::moveForward(1); return BIT_OR_OP; }
">>"    { AstNode::moveForward(2); return BIT_RS_OP; }
"<<"    { AstNode::moveForward(2); return BIT_LS_OP; }

"++"    { AstNode::moveForward(2); return INC_OP; }
"--"    { AstNode::moveForward(2); return DEC_OP; }

"->"    { AstNode::moveForward(2); return ARROW_OP; }
"."     { AstNode::moveForward(1); return DOT_OP; }

"<"     { AstNode::moveForward(1); return LESS_OP; }
">"     { AstNode::moveForward(1); return GREATER_OP; }
"<="    { AstNode::moveForward(2); return LE_OP; }
">="    { AstNode::moveForward(2); return GE_OP; }
"=="    { AstNode::moveForward(2); return EQ_OP; }
"!="    { AstNode::moveForward(2); return NE_OP; }

";"     { AstNode::moveForward(1); return SEMICOLON; }
","     { AstNode::moveForward(1); return COMMA; }
"?"     { AstNode::moveForward(1); return QUESTION; }
":"     { AstNode::moveForward(1); return COLON; }

"("     { AstNode::moveForward(1); return ROUND_LEFT; }
")"     { AstNode::moveForward(1); return ROUND_RIGHT; }
"["     { AstNode::moveForward(1); return SQUARE_LEFT; }
"]"     { AstNode::moveForward(1); return SQUARE_RIGHT; }

"{"     { AstNode::moveForward(1); return CURLY_LEFT; }

"}"     { AstNode::moveForward(1); return CURLY_RIGHT; }

"!"     { AstNode::moveForward(1); return NOT_OP; }

"&&"    { AstNode::moveForward(2); return AND_OP; }
"||"    { AstNode::moveForward(2); return OR_OP; }

"-"     { AstNode::moveForward(1); return SUB_OP; }
"+"     { AstNode::moveForward(1); return ADD_OP; }
"*"     { AstNode::moveForward(1); return MUL_OP; }
"/"     { AstNode::moveForward(1); return DIV_OP; }
"%"     { AstNode::moveForward(1); return MOD_OP; }

{identifier} {
    AstNode::moveForward(yyleng);
    yylval.charPtrType = new char[yyleng + 1];
    strcpy(yylval.charPtrType, yytext);
    return IDENTIFIER;
}

{newline}       { AstNode::incLineCnt(); }
{tab}           { AstNode::moveForward(yyleng * 4); }
{whitespace}    { AstNode::moveForward(yyleng); }
.               { yyerror("invalid character"); }

%%

int yywrap() {
    return 1;
}

void mylexer::yyerror(char const YYFAR* s) {
    std::cout << "Line " << AstNode::getLineCnt() << ", Column " << AstNode::getColCnt() << ": " << s << std::endl;
    exit(0);
}
