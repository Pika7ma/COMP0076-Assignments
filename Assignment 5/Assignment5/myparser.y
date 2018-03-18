%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Author: Pingchuan Ma
ID number: 1511442
Majoring: Software Engineering

Date: Tuesday, November 28, 2017
****************************************************************************/
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

%include {
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
}

// parser name
%name myparser

// place any declarations here

{
    void yyerror(char const YYFAR *s);
}

%token BIT_NOT_OP BIT_XOR_OP BIT_AND_OP BIT_OR_OP BIT_RS_OP BIT_LS_OP
%token INC_OP DEC_OP ARROW_OP DOT_OP ADD_OP SUB_OP MUL_OP DIV_OP MOD_OP NOT_OP
%token LESS_OP GREATER_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token SEMICOLON COMMA QUESTION COLON INPUT PRINT MAIN
%token ROUND_LEFT ROUND_RIGHT SQUARE_LEFT SQUARE_RIGHT CURLY_LEFT CURLY_RIGHT
%token EQ_ASGN SUB_ASGN LS_ASGN RS_ASGN AND_ASGN XOR_ASGN OR_ASGN MUL_ASGN DIV_ASGN MOD_ASGN ADD_ASGN
%token CHAR INT FLOAT VOID STRUCT UNION IF ELSE WHILE DO FOR GOTO CONTINUE BREAK RETURN

%union {
    char * charPtrType;
    AstNode * nodeType;
    BinaryExprType asgnType;
    UnaryExprType unaryType;
}

%token <charPtrType> IDENTIFIER STRING_VAL CHAR_VAL BOOL_VAL INT_VAL FLOAT_VAL

%type <asgnType> assignment_operator
%type <unaryType> unary_operator

%type <nodeType> primary_expression postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression
%type <nodeType> shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
%type <nodeType> logical_or_expression conditional_expression assignment_expression expression constant_expression declaration init_declarator_list
%type <nodeType> init_declarator type_specifier struct_or_union_specifier struct_or_union struct_declaration struct_declaration_list
%type <nodeType> specifier_list struct_declarator_list struct_declarator enum_specifier enumerator_list enumerator type_qualifier declarator direct_declarator
%type <nodeType> pointer_list type_qualifier_list parameter_type_list parameter_list parameter_declaration type_name abstract_declarator direct_abstract_declarator_list
%type <nodeType> initializer initializer_list statement labeled_statement compound_statement expression_statement selection_statement input_statement
%type <nodeType> iteration_statement jump_statement translation_unit external_declaration function_definition declaration_statement_list print_statement

%nonassoc IFX
%nonassoc ELSE

%start translation_unit

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

primary_expression
    : IDENTIFIER {
        SymTabNode* symTabNode = SymTab::currentTab->getNode(std::string($1));
        if (symTabNode) {
            $$ = new IdentifierAstNode($1, symTabNode);
            $$->setSymTabNode(symTabNode);
        } else {
            yyerror("undeclared identifier");
        }
    }
    | CHAR_VAL {
        $$ = new CharValAstNode(cstrlit_chr($1), $1);
    }
    | INT_VAL {
        $$ = new IntValAstNode(atoi($1));
    }
    | ROUND_LEFT expression ROUND_RIGHT { $$ = $2; }
    ;

postfix_expression
    : primary_expression
    | postfix_expression INC_OP {
        $$ = new UnaryExprAstNode(_POST_INC, $1);
    }
    | postfix_expression DEC_OP {
        $$ = new UnaryExprAstNode(_POST_DEC, $1);
    }
    ;

unary_expression
    : postfix_expression
    | INC_OP unary_expression {
        $$ = new UnaryExprAstNode(_INC, $2);
    }
    | DEC_OP unary_expression {
        $$ = new UnaryExprAstNode(_DEC, $2);
    }
    | unary_operator unary_expression {
        $$ = new UnaryExprAstNode($1, $2);
    }
    ;

unary_operator
    : ADD_OP {
        $$ = _POS_OP;
    }
    | SUB_OP {
        $$ = _NEG_OP;
    }
    | BIT_NOT_OP {
        $$ = _BIT_NOT_OP;
    }
    | NOT_OP {
        $$ = _NOT_OP;
    }
    ;

multiplicative_expression
    : unary_expression
    | multiplicative_expression MUL_OP unary_expression {
        $$ = new BinaryExprAstNode(_MUL_OP, $1, $3);
    }
    | multiplicative_expression DIV_OP unary_expression {
        $$ = new BinaryExprAstNode(_DIV_OP, $1, $3);
    }
    | multiplicative_expression MOD_OP unary_expression {
        $$ = new BinaryExprAstNode(_MOD_OP, $1, $3);
    }
    ;

additive_expression
    : multiplicative_expression
    | additive_expression ADD_OP multiplicative_expression {
        $$ = new BinaryExprAstNode(_ADD_OP, $1, $3);
    }
    | additive_expression SUB_OP multiplicative_expression {
        $$ = new BinaryExprAstNode(_SUB_OP, $1, $3);
    }
    ;

shift_expression
    : additive_expression
    | shift_expression BIT_LS_OP additive_expression {
        $$ = new BinaryExprAstNode(_BIT_LS_OP, $1, $3);
    }
    | shift_expression BIT_RS_OP additive_expression {
        $$ = new BinaryExprAstNode(_BIT_RS_OP, $1, $3);
    }
    ;

relational_expression
    : shift_expression
    | relational_expression LESS_OP shift_expression {
        $$ = new BinaryExprAstNode(_LESS_OP, $1, $3);
    }
    | relational_expression GREATER_OP shift_expression {
        $$ = new BinaryExprAstNode(_GREATER_OP, $1, $3);
    }
    | relational_expression LE_OP shift_expression {
        $$ = new BinaryExprAstNode(_LE_OP, $1, $3);
    }
    | relational_expression GE_OP shift_expression {
        $$ = new BinaryExprAstNode(_GE_OP, $1, $3);
    }
    ;

equality_expression
    : relational_expression
    | equality_expression EQ_OP relational_expression {
        $$ = new BinaryExprAstNode(_EQ_OP, $1, $3);
    }
    | equality_expression NE_OP relational_expression {
        $$ = new BinaryExprAstNode(_NE_OP, $1, $3);
    }
    ;

and_expression
    : equality_expression
    | and_expression BIT_AND_OP equality_expression {
        $$ = new BinaryExprAstNode(_BIT_AND_OP, $1, $3);
    }
    ;

exclusive_or_expression
    : and_expression
    | exclusive_or_expression BIT_XOR_OP and_expression {
        $$ = new BinaryExprAstNode(_BIT_XOR_OP, $1, $3);
    }
    ;

inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression BIT_OR_OP exclusive_or_expression {
        $$ = new BinaryExprAstNode(_BIT_OR_OP, $1, $3);
    }
    ;

logical_and_expression
    : inclusive_or_expression
    | logical_and_expression AND_OP inclusive_or_expression {
        $$ = new BinaryExprAstNode(_AND_OP, $1, $3);
    }
    ;

logical_or_expression
    : logical_and_expression
    | logical_or_expression OR_OP logical_and_expression {
        $$ = new BinaryExprAstNode(_OR_OP, $1, $3);
    }
    ;

assignment_expression
    : logical_or_expression
    | unary_expression assignment_operator assignment_expression {
        $$ = new BinaryExprAstNode($2, $1, $3);
    }
    ;

assignment_operator
    : EQ_ASGN {
        $$ = _EQ_ASGN;
    }
    | MUL_ASGN {
        $$ = _MUL_ASGN;
    }
    | DIV_ASGN {
        $$ = _DIV_ASGN;
    }
    | MOD_ASGN {
        $$ = _MOD_ASGN;
    }
    | ADD_ASGN {
        $$ = _ADD_ASGN;
    }
    | SUB_ASGN {
        $$ = _SUB_ASGN;
    }
    | LS_ASGN {
        $$ = _LS_ASGN;
    }
    | RS_ASGN {
        $$ = _RS_ASGN;
    }
    | AND_ASGN {
        $$ = _AND_ASGN;
    }
    | XOR_ASGN {
        $$ = _XOR_ASGN;
    }
    | OR_ASGN {
        $$ = _OR_ASGN;
    }
    ;

expression
    : assignment_expression
    | expression COMMA assignment_expression {
        $$ = new BinaryExprAstNode(_COMMA_OP, $1, $3);
    }
    ;

declaration
    : type_specifier init_declarator_list SEMICOLON {
        DoubleOtherAstNode* doubleOtherAstNode = new DoubleOtherAstNode(_INIT_DECLARE, $1, $2);

        // get member list
        MultipleAstNode* multipleAstNode = (MultipleAstNode *)$2;
        std::vector<VarSymTabNode * > *memberList = multipleAstNode->getMemberList();
        VarSymTabNode *varSymTabNode;

        // get specifier and qualifier node
        VarSymTabNode *varSymTabNode_ = (VarSymTabNode *)($1->getSymTabNode());

        // set declarator type
        for (uint i = 0; i < memberList->size(); ++i) {
            varSymTabNode = memberList->at(i);
            varSymTabNode->setSpecifier(varSymTabNode_->getSpecifier());
        }
        $$ = doubleOtherAstNode;
    }
    ;

init_declarator_list
    : direct_declarator {
        MultipleAstNode *multipleAstNode = new MultipleAstNode(_INIT_DECLARATOR_LIST);
        multipleAstNode->insertChild($1);
        multipleAstNode->addMember((VarSymTabNode *)($1->getSymTabNode()));
        $$ = multipleAstNode;
    }
    | init_declarator_list COMMA direct_declarator {
        MultipleAstNode *multipleAstNode = (MultipleAstNode *)$1;
        multipleAstNode->insertChild($3);
        multipleAstNode->addMember((VarSymTabNode *)($3->getSymTabNode()));
        $$ = multipleAstNode;
    }
    ;

type_specifier
    : CHAR {
        // make ast
        TypeAstNode *astNode = new TypeAstNode(_CHAR);

        // make symTabNode from $1
        VarSymTabNode *symTabNode = new VarSymTabNode(SymTab::currentTab);
        symTabNode->setSpecifier(_S_CHAR);
        astNode->setSymTabNode(symTabNode);
        $$ = astNode;
    }
    | INT {
        // make ast
        TypeAstNode *astNode = new TypeAstNode(_INT);

        // make symTabNode from $1
        VarSymTabNode *symTabNode = new VarSymTabNode(SymTab::currentTab);
        symTabNode->setSpecifier(_S_INT);
        astNode->setSymTabNode(symTabNode);
        $$ = astNode;
    }
    ;

direct_declarator
    : IDENTIFIER {
        if (SymTab::currentTab->isDuplicatedHere(std::string($1))) {
            yyerror("redefinition");
        }

        // make a symTabNode within this scope
        VarSymTabNode* symTabNode = new VarSymTabNode(SymTab::currentTab);

        // insert a symTabNode into this scope
        SymTab::currentTab->insertNode(std::string($1), symTabNode);

        // make identifier astNode
        AstNode *astNode = new IdentifierAstNode($1, symTabNode);

        $$ = astNode;
    }
    ;

statement
    : compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | input_statement
    | print_statement
    ;

input_statement
    : INPUT ROUND_LEFT IDENTIFIER ROUND_RIGHT SEMICOLON {
        SymTabNode* symTabNode = SymTab::currentTab->getNode(std::string($3));
        if (symTabNode) {
            IdentifierAstNode *astNode = new IdentifierAstNode($3, symTabNode);
            astNode->setSymTabNode(symTabNode);
            $$ = new SingleOtherAstNode(_INPUT, astNode);
        } else {
            yyerror("undeclared identifier");
        }
    }
    ;

print_statement
    : PRINT ROUND_LEFT expression ROUND_RIGHT SEMICOLON {
        $$ = new SingleOtherAstNode(_PRINT, $3);
    }
    ;

compound_statement
    : CURLY_LEFT {
        if (!SymTab::keepTable) {
            SymTab::currentTab = new SymTab(SymTab::currentTab);
            SymTab::currentTab->parent->printVector.push_back(SymTab::currentTab);
        } else {
            SymTab::keepTable = false;
        }
    } CURLY_RIGHT {
        $$ = new OtherNoneAstNode(_BLANK_COMPOUND);
        SymTab::currentTab = SymTab::currentTab->parent;
    }
    | CURLY_LEFT {
        if (!SymTab::keepTable) {
            SymTab::currentTab = new SymTab(SymTab::currentTab);
            SymTab::currentTab->parent->printVector.push_back(SymTab::currentTab);
        } else {
            SymTab::keepTable = false;
        }
    } declaration_statement_list CURLY_RIGHT {
        $$ = new SingleOtherAstNode(_COMPOUND, $3);
        SymTab::currentTab = SymTab::currentTab->parent;
    }
    ;

declaration_statement_list
    : declaration_statement_list declaration {
        $$ = $1;
        ((MultipleAstNode *)$$)->insertChild($2);
    }
    | declaration_statement_list statement {
        $$ = $1;
        ((MultipleAstNode *)$$)->insertChild($2);
    }
    | declaration {
        $$ = new MultipleAstNode(_DECLARE_STMT_LIST);
        ((MultipleAstNode *)$$)->insertChild($1);
    }
    | statement {
        $$ = new MultipleAstNode(_DECLARE_STMT_LIST);
        ((MultipleAstNode *)$$)->insertChild($1);
    }
    ;

expression_statement
    : SEMICOLON {
        $$ = new OtherNoneAstNode(_BLANK_STMT);
    }
    | expression SEMICOLON {
        $$ = new SingleOtherAstNode(_EXPR_STMT, $1);
    }
    ;

selection_statement
    : IF ROUND_LEFT expression ROUND_RIGHT statement %prec IFX {
        $$ = new DoubleOtherAstNode(_IF_STMT, $3, $5);
    }
    | IF ROUND_LEFT expression ROUND_RIGHT statement ELSE statement {
        $$ = new TripleOtherAstNode(_IF_ELSE_STMT, $3, $5, $7);
    }
    ;

iteration_statement
    : WHILE ROUND_LEFT expression ROUND_RIGHT statement {
        $$ = new DoubleOtherAstNode(_WHILE_STMT, $3, $5);
    }
    | DO statement WHILE ROUND_LEFT expression ROUND_RIGHT SEMICOLON {
        $$ = new DoubleOtherAstNode(_DO_WHILE_STMT, $2, $5);
    }
    | FOR ROUND_LEFT expression_statement expression_statement ROUND_RIGHT statement {
        DoubleOtherAstNode *node = new DoubleOtherAstNode(_TWO_FOR_CONDITION, $3, $4);
        $$ = new DoubleOtherAstNode(_FOR_STMT, node, $6);
    }
    | FOR ROUND_LEFT expression_statement expression_statement expression ROUND_RIGHT statement {
        TripleOtherAstNode *node = new TripleOtherAstNode(_THREE_FOR_CONDITION, $3, $4, $5);
        $$ = new DoubleOtherAstNode(_FOR_STMT, node, $7);
    }
    ;

jump_statement
    : CONTINUE SEMICOLON {
        $$ = new OtherNoneAstNode(_CONTINUE_STMT);
    }
    | BREAK SEMICOLON {
        $$ = new OtherNoneAstNode(_BREAK_STMT);
    }
    ;

translation_unit
    : external_declaration {
        ast = new Ast();
        $$ = ast->getRoot();
        ((MultipleAstNode *)$$)->insertChild($1);
    }
    | translation_unit external_declaration {
        $$ = $1;
        ((MultipleAstNode *)$$)->insertChild($2);
    }
    ;

external_declaration
    : function_definition
    | declaration
    ;

function_definition
    : MAIN ROUND_LEFT ROUND_RIGHT compound_statement {
        $$ = new SingleOtherAstNode(_MAIN_FUNC, $4);
    }
    | type_specifier MAIN ROUND_LEFT ROUND_RIGHT compound_statement {
        $$ = new SingleOtherAstNode(_MAIN_FUNC, $5);
    }
    ;

%%

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
