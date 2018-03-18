#include "AstNode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std::string_literals;

uint AstNode::nodeCnt = 0;
uint AstNode::lineCnt = 1;
uint AstNode::colCnt  = 1;
int AstNode::labelCnt = 0;
int AstNode::tempVarCnt = 0;
std::stack<Label * > * AstNode::loopStack = new std::stack<Label * >();

std::ifstream myIn("input.cpp");
std::ofstream myOut("output.asm");

std::vector<std::string> TypeAstNode::map = {
    "char",
    "int",
};

std::vector<std::string> OtherNoneAstNode::map = {
    "Blank Compond",
    "Blank Stmt",
    "Continue",
    "Break",
};

std::vector<std::string> UnaryExprAstNode::map = {
    "+",
    "-",
    "~",
    "!",
    "++",
    "++",
    "--",
    "--",
};

std::vector<std::string> SingleOtherAstNode::map = {
    "Compound Stmt",
    "Expr Stmt",
    "Main Function",
    "Print",
    "Input"
};

std::vector<std::string> BinaryExprAstNode::map = {
    "=",
    "-=",
    "<<=",
    ">>=",
    "&=",
    "^=",
    "|=",
    "*=",
    "/=",
    "%=",
    "+=",
    "<",
    ">",
    "<=",
    ">=",
    "==",
    "!=",
    "&&",
    "||",
    "+",
    "-",
    "*",
    "/",
    "%",
    ",",
    "<<",
    ">>",
    "&",
    "|",
    "^",
};

std::vector<std::string> DoubleOtherAstNode::map = {
    "Init Declare",
    "If Stmt",
    "While Stmt",
    "Do While Stmt",
    "For Stmt",
    "For Condition",
};

std::vector<std::string> TripleOtherAstNode::map = {
    "If Else Stmt",
    "For Condition",
};

std::vector<std::string> MultipleAstNode::map = {
    "Init Declarator List",
    "Declare Stmt List",
    "Program",
};

void AstNode::printIndent(uint _depth) {
    //for (uint i = 0; i < _depth; ++i) {
    //    std::cout << "|   ";
    //}
}

void AstNode::printExpr(uint _no, std::string & _type, std::string & _op, AstNode *_child, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << _type;
    std::cout << "Op: " << std::setw(16) << std::left << _op;
    std::cout << "Sub: " << _child->getNodeNum() << std::endl;
}

void AstNode::printExpr(uint _no, std::string & _type, std::string & _op, AstNode *_left, AstNode *_right, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << _type;
    std::cout << "Op: " << std::setw(16) << std::left << _op;
    std::cout << "Sub: " << _left->getNodeNum() << " " << _right->getNodeNum() << std::endl;
}

void AstNode::printExpr(uint _no, std::string & _type, std::string & _op, AstNode *_left, AstNode *_middle, AstNode *_right, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << _type;
    std::cout << "Op: " << std::setw(16) << std::left << _op;
    std::cout << "Sub: " << _left->getNodeNum() << " " << _middle->getNodeNum() << " " << _right->getNodeNum() << std::endl;
}

void AstNode::printOther(uint _no, std::string & _type, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << _type << std::endl;
}

void AstNode::printOther(uint _no, std::string & _type, AstNode *_child, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(50) << std::left << _type;
    std::cout << "Sub: " << _child->getNodeNum() << std::endl;
}

void AstNode::printOther(uint _no, std::string & _type, AstNode *_left, AstNode *_right, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(50) << std::left << _type;
    std::cout << "Sub: " << _left->getNodeNum() << " " << _right->getNodeNum() << std::endl;
}

void AstNode::printOther(uint _no, std::string & _type, AstNode *_left, AstNode *_middle, AstNode *_right, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(50) << std::left << _type;
    std::cout << "Sub: " << _left->getNodeNum() << " " << _middle->getNodeNum() << " " << _right->getNodeNum() << std::endl;
}

void AstNode::printOther(uint _no, std::string & _type, std::vector<AstNode*>& _children, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(50) << std::left << _type;
    std::cout << "Sub:";
    for (uint i = 0; i < _children.size(); ++i) {
        std::cout << " " << _children[i]->getNodeNum();
    }
    std::cout << std::endl;
}

void AstNode::printIdentifier(uint _no, std::string & _name, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << "Identifier";
    std::cout << "Name: " << _name << std::endl;
}

void AstNode::printChar(uint _no, std::string & _literalValue, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << "Char Const";
    std::cout << "literal: " << _literalValue << std::endl;
}

void AstNode::printBool(uint _no, bool _value, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << "Bool Const";
    std::cout << "Val: " << std::boolalpha << _value << std::endl;
}

void AstNode::printString(uint _no, std::string & _literalValue, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << "String Const";
    std::cout << "literal: " << _literalValue << std::endl;
}

void AstNode::printInt(uint _no, int _value, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << "Int Const";
    std::cout << "Val: " << _value << std::endl;
}

void AstNode::printFloat(uint _no, float _value, uint _depth) {
    AstNode::printIndent(_depth);
    std::cout << "No: " << std::setw(4) << std::left << _no;
    std::cout << "Type: " << std::setw(30) << std::left << "Float Const";
    std::cout << "Val: " << _value << std::endl;
}

void TypeAstNode::print(uint _depth) {
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printOther(getNodeNum(), TypeAstNode::map[value], _depth);
}

void TypeAstNode::genLabel() {
    return;
}

void TypeAstNode::genCode() {
    return;
}

void OtherNoneAstNode::print(uint _depth) {
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printOther(getNodeNum(), OtherNoneAstNode::map[value], _depth);
}

void OtherNoneAstNode::genLabel() {
    switch (value) {
    case _CONTINUE_STMT:
        if (AstNode::loopStack->empty()) {
            AstNode::error("Continue Label Outside a Loop", lineNum, colNum);
        }
        this->createLabel();
        this->setBeginLabel(AstNode::loopStack->top()->beginLabel);
        break;
    case _BREAK_STMT:
        if (AstNode::loopStack->empty()) {
            AstNode::error("Break Label Outside a Loop", lineNum, colNum);
        }
        this->createLabel();
        this->setNextLabel(AstNode::loopStack->top()->nextLabel);
        break;
    }
    return;
}

void OtherNoneAstNode::genCode() {
    switch (value) {
    case _CONTINUE_STMT:
        code << "\tjmp @" << label->beginLabel << std::endl;
        break;
    case _BREAK_STMT:
        code << "\tjmp @" << label->nextLabel << std::endl;
        break;
    }
}

void SingleAstNode::print(uint _depth) {
    child->print(_depth + 1);
}

void UnaryExprAstNode::print(uint _depth) {
    SingleAstNode::print(_depth);
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printExpr(getNodeNum(), "Expr"s, UnaryExprAstNode::map[value], child, _depth);
}

void UnaryExprAstNode::genLabel() {
    if (value == _NOT_OP) {
        child->createLabel();
        child->setTrueLabel(label->falseLabel);
        child->setFalseLabel(label->trueLabel);
    }
    child->genLabel();
}

void UnaryExprAstNode::genCode() {
    child->genCode();
    code << child->getCode();
    int t1;
    switch (value) {
    case _POS_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << child->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _NEG_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << child->getVar() << std::endl;
        code << "\tneg eax" << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _BIT_NOT_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << child->getVar() << std::endl;
        code << "\tnot eax" << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _POST_INC:
        if (child->isTempVar()) {
            AstNode::error("Not Incrementable", this->lineNum, this->colNum);
        }
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << child->getVar() << std::endl;
        code << "\tinc " << child->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _INC:
        if (child->isTempVar()) {
            AstNode::error("Not Incrementable", this->lineNum, this->colNum);
        }
        code << "\tinc " << child->getVar() << std::endl;
        setResult(child->getResult());
        setNotTemp();
        break;
    case _POST_DEC:
        if (child->isTempVar()) {
            AstNode::error("Not Decrementable", this->lineNum, this->colNum);
        }
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << child->getVar() << std::endl;
        code << "\tdec " << child->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _DEC:
        if (child->isTempVar()) {
            AstNode::error("Not Decrementable", this->lineNum, this->colNum);
        }
        code << "\tdec " << child->getVar() << std::endl;
        setResult(child->getResult());
        setNotTemp();
        break;
    }
}

void SingleOtherAstNode::print(uint _depth) {
    SingleAstNode::print(_depth);
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printOther(getNodeNum(), SingleOtherAstNode::map[value], child, _depth);
}

void SingleOtherAstNode::genLabel() {
    if (value == _EXPR_STMT) {
        if (label) {
            child->createLabel();
            child->setTrueLabel(label->trueLabel);
            child->setFalseLabel(label->falseLabel);
        }
    }
    child->genLabel();
}

void SingleOtherAstNode::genCode() {
    child->genCode();
    code << child->getCode();
    switch (value) {
    case _PRINT:
        code << "\tprint str$(" << child->getVar() << ")" << std::endl;
        code << "\tprint chr$(13, 10)" << std::endl;
        break;
    case _INPUT:
        if (child->isTempVar()) {
            AstNode::error("Cannot Input", this->lineNum, this->colNum);
        }
        code << "\tmov " << child->getVar() << ", sval(input(\"Input: \"))" << std::endl;
        break;
    }
}

void DoubleAstNode::print(uint _depth) {
    left->print(_depth + 1);
    right->print(_depth + 1);
}

void BinaryExprAstNode::print(uint _depth) {
    DoubleAstNode::print(_depth);
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printExpr(getNodeNum(), "Expr"s, BinaryExprAstNode::map[value], left, right, _depth);
}

void BinaryExprAstNode::genLabel() {
    int label1;
    switch (value) {
    case _AND_OP:
        label1 = AstNode::getNewLabel();
        left->createLabel();
        left->setTrueLabel(label1);
        left->setFalseLabel(label->falseLabel);
        right->createLabel();
        right->setTrueLabel(label->trueLabel);
        right->setFalseLabel(label->falseLabel);
        break;
    case _OR_OP:
        label1 = AstNode::getNewLabel();
        left->createLabel();
        left->setTrueLabel(label->trueLabel);
        left->setFalseLabel(label1);
        right->createLabel();
        right->setTrueLabel(label->trueLabel);
        right->setFalseLabel(label->falseLabel);
        break;
    }
    left->genLabel();
    right->genLabel();
}

void BinaryExprAstNode::genCode() {
    left->genCode();
    right->genCode();
    if (value != _AND_OP && value != _OR_OP) {
        code << left->getCode();
        code << right->getCode();
    }
    int t1;
    switch (value) {
    case _EQ_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << right->getVar() << std::endl;
        code << "\tmov " << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _SUB_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tsub eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _LS_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tshl eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _RS_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tshr eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _AND_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tand eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _XOR_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\txor eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _OR_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tor eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _MUL_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\timul eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _DIV_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\txor edx, edx" << std::endl;
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tidiv " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _MOD_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\txor edx, edx" << std::endl;
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tidiv " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", edx" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _ADD_ASGN:
        if (left->isTempVar()) {
            AstNode::error("Not a Left Value", this->lineNum, this->colNum);
        }
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tadd eax, " << right->getVar() << std::endl;
        code << "\tmov" << left->getVar() << ", eax" << std::endl;
        setResult(left->getResult());
        setNotTemp();
        break;
    case _LESS_OP:
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tcmp eax, " << right->getVar() << std::endl;
        code << "\tjl @" << label->trueLabel << std::endl;
        code << "\tjmp @" << label->falseLabel << std::endl;
        break;
    case _GREATER_OP:
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tcmp eax, " << right->getVar() << std::endl;
        code << "\tjg @" << label->trueLabel << std::endl;
        code << "\tjmp @" << label->falseLabel << std::endl;
        break;
    case _LE_OP:
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tcmp eax, " << right->getVar() << std::endl;
        code << "\tjle @" << label->trueLabel << std::endl;
        code << "\tjmp @" << label->falseLabel << std::endl;
        break;
    case _GE_OP:
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tcmp eax, " << right->getVar() << std::endl;
        code << "\tjge @" << label->trueLabel << std::endl;
        code << "\tjmp @" << label->falseLabel << std::endl;
        break;
    case _EQ_OP:
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tcmp eax, " << right->getVar() << std::endl;
        code << "\tje @" << label->trueLabel << std::endl;
        code << "\tjmp @" << label->falseLabel << std::endl;
        break;
    case _NE_OP:
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tcmp eax, " << right->getVar() << std::endl;
        code << "\tjne @" << label->trueLabel << std::endl;
        code << "\tjmp @" << label->falseLabel << std::endl;
        break;
    case _AND_OP:
        code << left->getCode();
        code << "@" << left->getTrueLabel() << ":" << std::endl;
        code << right->getCode();
        break;
    case _OR_OP:
        code << left->getCode();
        code << "@" << left->getFalseLabel() << ":" << std::endl;
        code << right->getCode();
        break;
    case _ADD_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tadd eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _SUB_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tsub eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _MUL_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\timul eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _DIV_OP:
        t1 = AstNode::getTempVar();
        code << "\txor edx, edx" << std::endl;
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tidiv " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _MOD_OP:
        t1 = AstNode::getTempVar();
        code << "\txor edx, edx" << std::endl;
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tidiv " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", edx" << std::endl;
        setResult(t1);
        break;
    case _COMMA_OP:
        setResult(right->getResult());
        if (!(right->isTempVar())) {
            setNotTemp();
        }
        break;
    case _BIT_LS_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tshl eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _BIT_RS_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tshr eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _BIT_AND_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tand eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _BIT_OR_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\tor eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    case _BIT_XOR_OP:
        t1 = AstNode::getTempVar();
        code << "\tmov eax, " << left->getVar() << std::endl;
        code << "\txor eax, " << right->getVar() << std::endl;
        code << "\tmov temp" << t1 << ", eax" << std::endl;
        setResult(t1);
        break;
    }
}

void DoubleOtherAstNode::print(uint _depth) {
    DoubleAstNode::print(_depth);
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printOther(getNodeNum(), DoubleOtherAstNode::map[value], left, right, _depth);
}

void DoubleOtherAstNode::genLabel() {
    int trueLabel;
    int beginLabel;
    int nextLabel;
    int falseLabel;
    switch (value) {
    case _IF_STMT:
        this->createLabel();
        trueLabel = AstNode::getNewLabel();
        falseLabel = AstNode::getNewLabel();
        this->setTrueLabel(trueLabel);
        this->setFalseLabel(falseLabel);
        left->createLabel();
        left->setTrueLabel(trueLabel);
        left->setFalseLabel(falseLabel);
        break;
    case _WHILE_STMT:
    case _FOR_STMT:
    case _DO_WHILE_STMT:
        this->createLabel();
        AstNode::loopStack->push(label);
        trueLabel = AstNode::getNewLabel();
        beginLabel = AstNode::getNewLabel();
        nextLabel = AstNode::getNewLabel();
        this->setTrueLabel(trueLabel);
        this->setBeginLabel(beginLabel);
        this->setNextLabel(nextLabel);
        if (value == _DO_WHILE_STMT) {
            right->createLabel();
            right->setTrueLabel(trueLabel);
            right->setFalseLabel(nextLabel);
        }
        else {
            left->createLabel();
            left->setTrueLabel(trueLabel);
            left->setFalseLabel(nextLabel);
        }
        break;
    case _TWO_FOR_CONDITION:
        right->createLabel();
        right->setTrueLabel(label->trueLabel);
        right->setFalseLabel(label->falseLabel);
    }
    left->genLabel();
    right->genLabel();
    if (value == _DO_WHILE_STMT || value == _WHILE_STMT || value == _FOR_STMT) {
        AstNode::loopStack->pop();
    }
}

void DoubleOtherAstNode::genCode() {
    left->genCode();
    right->genCode();
    switch (value) {
    case _IF_STMT:
        code << left->getCode();
        code << "@" << label->trueLabel << ":" << std::endl;
        code << right->getCode();
        code << "@" << label->falseLabel << ":" << std::endl;
        break;
    case _FOR_STMT:
        if (typeid(*(left->getClassType())) == typeid(DoubleOtherAstNode)) {
            DoubleOtherAstNode *node = (DoubleOtherAstNode *)left;
            code << node->cond1.str();
            code << "@" << label->beginLabel << ":" << std::endl;
            code << node->cond2.str();
            code << "@" << label->trueLabel << ":" << std::endl;
            code << right->getCode();
            code << "\tjmp @" << label->beginLabel << std::endl;
            code << "@" << label->nextLabel << ":" << std::endl;
        }
        else {
            TripleOtherAstNode *node = (TripleOtherAstNode *)left;
            code << node->cond1.str();
            code << "@" << label->beginLabel << ":" << std::endl;
            code << node->cond2.str();
            code << "@" << label->trueLabel << ":" << std::endl;
            code << right->getCode();
            code << node->cond3.str();
            code << "\tjmp @" << label->beginLabel << std::endl;
            code << "@" << label->nextLabel << ":" << std::endl;
        }
        break;
    case _WHILE_STMT:
        code << "@" << label->beginLabel << ":" << std::endl;
        code << left->getCode();
        code << "@" << label->trueLabel << ":" << std::endl;
        code << right->getCode();
        code << "\tjmp @" << label->beginLabel << std::endl;
        code << "@" << label->nextLabel << ":" << std::endl;
        break;
    case _DO_WHILE_STMT:
        code << "@" << label->trueLabel << ":" << std::endl;
        code << left->getCode();
        code << "@" << label->beginLabel << ":" << std::endl;
        code << right->getCode();
        code << "@" << label->nextLabel << ":" << std::endl;
        break;
    case _TWO_FOR_CONDITION:
        cond1 << left->getCode();
        cond2 << right->getCode();
        break;
    }
}

void TripleAstNode::print(uint _depth) {
    left->print(_depth + 1);
    middle->print(_depth + 1);
    right->print(_depth + 1);
}

void TripleOtherAstNode::print(uint _depth) {
    TripleAstNode::print(_depth);
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printOther(getNodeNum(), TripleOtherAstNode::map[value], left, middle, right, _depth);
}

void TripleOtherAstNode::genLabel() {
    int trueLabel;
    int beginLabel;
    int nextLabel;
    int falseLabel;
    switch (value) {
    case _IF_ELSE_STMT:
        this->createLabel();
        trueLabel = AstNode::getNewLabel();
        falseLabel = AstNode::getNewLabel();
        nextLabel = AstNode::getNewLabel();
        this->setTrueLabel(trueLabel);
        this->setFalseLabel(falseLabel);
        this->setNextLabel(nextLabel);
        left->createLabel();
        left->setTrueLabel(trueLabel);
        left->setFalseLabel(falseLabel);
        break;
    case _THREE_FOR_CONDITION:
        middle->createLabel();
        middle->setTrueLabel(label->trueLabel);
        middle->setFalseLabel(label->falseLabel);
        break;
    }
    left->genLabel();
    middle->genLabel();
    right->genLabel();
}

void TripleOtherAstNode::genCode() {
    left->genCode();
    middle->genCode();
    right->genCode();
    switch (value) {
    case _IF_ELSE_STMT:
        code << left->getCode();
        code << "@" << label->trueLabel << ":" << std::endl;
        code << middle->getCode();
        code << "\tjmp @" << label->nextLabel << std::endl;
        code << "@" << label->falseLabel << ":" << std::endl;
        code << right->getCode();
        code << "@" << label->nextLabel << ":" << std::endl;
        break;
    case _THREE_FOR_CONDITION:
        cond1 << left->getCode();
        cond2 << middle->getCode();
        cond3 << right->getCode();
        break;
    }
}

MultipleAstNode * MultipleAstNode::insertChild(AstNode * _child) {
    children->push_back(_child);
    return this;
}

void MultipleAstNode::print(uint _depth) {
    for (uint i = 0; i < children->size(); ++i) {
        children->at(i)->print(_depth + 1);
    }
    setNodeNum(AstNode::nodeCnt++);
    AstNode::printOther(getNodeNum(), MultipleAstNode::map[value], *children, _depth);
}

void MultipleAstNode::genLabel() {
    for (auto ite : *children) {
        ite->genLabel();
    }
}

void MultipleAstNode::genCode() {
    for (auto ite : *children) {
        ite->genCode();
        code << ite->getCode();
    }
}

void IdentifierAstNode::genCode() {
    SymTabNode *node = getSymTabNode();
    setNotTemp();
    setResult(node->getVarNum());
}

void IntValAstNode::genCode() {
    int t1 = AstNode::getTempVar();
    code << "\tmov temp" << t1 << ", " << value << std::endl;
    setResult(t1);
}
