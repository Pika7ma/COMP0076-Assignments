#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
#include "SymTab.h"
#include "SymTabNode.h"
#include <sstream>
typedef unsigned int uint;

struct Label {
    int nextLabel = -1;
    int beginLabel = -1;
    int trueLabel = -1;
    int falseLabel = -1;
};

class AstNode {

private:
    static uint lineCnt;
    static uint colCnt;
    static int labelCnt;
    static int tempVarCnt;

protected:
    static std::stack<Label * > * loopStack;
    static uint nodeCnt;
    uint nodeNum = 0;
    uint lineNum = 1;
    uint colNum  = 1;
    SymTabNode *node = nullptr;
    Label* label = nullptr;
    std::stringstream code;
    int result = -1;
    bool isTemp = true;

public:
    AstNode() : lineNum(AstNode::lineCnt), colNum(AstNode::colCnt) {
    }
    static int getTempVarCnt() {
        return AstNode::tempVarCnt;
    }
    std::string getCode() {
        return code.str();
    }
    std::string getVar() {
        std::stringstream temp;
        if (isTemp) {
            temp << "temp" << result;
        }
        else {
            temp << "var" << result;
        }
        return temp.str();
    }
    bool isTempVar() {
        return isTemp;
    }
    void setResult(int result_) {
        result = result_;
    }
    void setNotTemp() {
        isTemp = false;
    }
    int getResult() {
        return result;
    }
    void setSymTabNode(SymTabNode *_node) {
        node = _node;
    }
    int getNextLabel() {
        if (label) {
            return label->nextLabel;
        }
    }
    int getBeginLabel() {
        if (label) {
            return label->beginLabel;
        }
    }
    int getTrueLabel() {
        if (label) {
            return label->trueLabel;
        }
    }
    int getFalseLabel() {
        if (label) {
            return label->falseLabel;
        }
    }
    void setNextLabel(int _label) {
        if (label) {
            label->nextLabel = _label;
        }
    }
    void setBeginLabel(int _label) {
        if (label) {
            label->beginLabel = _label;
        }
    }
    void setTrueLabel(int _label) {
        if (label) {
            label->trueLabel = _label;
        }
    }
    void setFalseLabel(int _label) {
        if (label) {
            label->falseLabel = _label;
        }
    }
    virtual void genLabel() = 0;
    SymTabNode * getSymTabNode() {
        return node;
    }
    uint getNodeNum() {
        return nodeNum;
    }
    void setNodeNum(uint _nodeNum) {
        nodeNum = _nodeNum;
    }
    static void incLineCnt() {
        AstNode::lineCnt++;
        AstNode::colCnt = 1;
    }
    static void moveForward(uint len) {
        AstNode::colCnt += len;
    }
    static uint getLineCnt() {
        return AstNode::lineCnt;
    }
    static uint getColCnt() {
        return AstNode::colCnt;
    }
    static int getNewLabel() {
        return AstNode::labelCnt++;
    }
    static int getTempVar() {
        return AstNode::tempVarCnt++;
    }
    void createLabel() {
        label = new Label();
    }
    virtual AstNode * getClassType() = 0;
    virtual void print(uint _depth) = 0;
    virtual void genCode() = 0;
    static void printIndent(uint _depth);
    static void printExpr(uint _no, std::string &_type, std::string &_op, AstNode *_child, uint _depth);
    static void printExpr(uint _no, std::string &_type, std::string &_op, AstNode *_left, AstNode *_right, uint _depth);
    static void printExpr(uint _no, std::string &_type, std::string &_op, AstNode *_left, AstNode *_middle, AstNode *_rightNo, uint _depth);
    static void printOther(uint _no, std::string &_type, uint _depth);
    static void printOther(uint _no, std::string &_type, AstNode *_child, uint _depth);
    static void printOther(uint _no, std::string &_type, AstNode *_left, AstNode *_right, uint _depth);
    static void printOther(uint _no, std::string &_type, AstNode *_left, AstNode *_middle, AstNode *_right, uint _depth);
    static void printOther(uint _no, std::string &_type, std::vector<AstNode *> &_children, uint _depth);
    static void printIdentifier(uint _no, std::string &_name, uint _depth);
    static void printChar(uint _no, std::string &_literalValue, uint _depth);
    static void printBool(uint _no, bool _value, uint _depth);
    static void printString(uint _no, std::string &_literalValue, uint _depth);
    static void printInt(uint _no, int _value, uint _depth);
    static void printFloat(uint _no, float _value, uint _depth);
    static void error(char const * _msg, const uint _line, const uint _col) {
        std::cout << "Line " << _line << ", Column " << _col << ": " << _msg << std::endl;
        exit(0);
    }
};

class NoneAstNode : public AstNode {
public:
    NoneAstNode() {
    }
    virtual NoneAstNode * getClassType() = 0;
    virtual void print(uint _depth) = 0;
    virtual void genLabel() = 0;
    virtual void genCode() = 0;
};

typedef enum {
    _CHAR,     // char
    _INT,      // int
} TypeType;

class TypeAstNode : public NoneAstNode {
private:
    TypeType value;
    static std::vector<std::string> map;
public:
    TypeAstNode(TypeType _value) : value(_value) {
    }
    TypeAstNode * getClassType() {
        return this;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

typedef enum {
    _BLANK_COMPOUND,    // {}
    _BLANK_STMT,        // ;
    _CONTINUE_STMT,     // continue;
    _BREAK_STMT,        // break;
} OtherNoneType;

class OtherNoneAstNode : public NoneAstNode {
private:
    OtherNoneType value;
    static std::vector<std::string> map;
public:
    OtherNoneAstNode(OtherNoneType _value) : value(_value) {
    }
    OtherNoneAstNode * getClassType() {
        return this;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

class SingleAstNode : public AstNode {
protected:
    AstNode *child;
public:
    SingleAstNode(AstNode *_child) : child(_child) {
    }
    virtual SingleAstNode * getClassType() = 0;
    virtual void print(uint _depth);
    virtual void genLabel() = 0;
    virtual void genCode() = 0;
};

typedef enum {
    _POS_OP,          // +a
    _NEG_OP,          // -a
    _BIT_NOT_OP,      // ~a
    _NOT_OP,          // !a
    _POST_INC,        // i++
    _INC,             // ++i
    _POST_DEC,        // i--
    _DEC,             // --i
} UnaryExprType;

class UnaryExprAstNode : public SingleAstNode {
private:
    UnaryExprType value;
    static std::vector<std::string> map;
public:
    UnaryExprAstNode(UnaryExprType _value, AstNode *_child) : SingleAstNode(_child), value(_value) {
    }
    UnaryExprAstNode * getClassType() {
        return this;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

typedef enum {
    _COMPOUND,        // {a}
    _EXPR_STMT,       // 1;
    _MAIN_FUNC,       // main() {...}
    _PRINT,           // print()
    _INPUT,           // input()
} SingleOtherType;

class SingleOtherAstNode : public SingleAstNode {
private:
    SingleOtherType value;
    static std::vector<std::string> map;
public:
    SingleOtherAstNode(SingleOtherType _value, AstNode *_child) : SingleAstNode(_child), value(_value) {
    }
    SingleOtherAstNode * getClassType() {
        return this;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

class DoubleAstNode : public AstNode {
protected:
    AstNode *left;
    AstNode *right;
public:
    DoubleAstNode(AstNode *_left, AstNode *_right) : left(_left), right(_right) {
    }
    virtual DoubleAstNode * getClassType() = 0;
    virtual void print(uint _depth);
    virtual void genLabel() = 0;
    virtual void genCode() = 0;
};

typedef enum {
    _EQ_ASGN,    // =
    _SUB_ASGN,   // -=
    _LS_ASGN,    // <<=
    _RS_ASGN,    // >>=
    _AND_ASGN,   // &=
    _XOR_ASGN,   // ^=
    _OR_ASGN,    // |=
    _MUL_ASGN,   // *=
    _DIV_ASGN,   // /=
    _MOD_ASGN,   // %=
    _ADD_ASGN,   // +=
    _LESS_OP,    // <
    _GREATER_OP, // >
    _LE_OP,      // <=
    _GE_OP,      // >=
    _EQ_OP,      // ==
    _NE_OP,      // !=
    _AND_OP,     // &&
    _OR_OP,      // ||
    _ADD_OP,     // +
    _SUB_OP,     // -
    _MUL_OP,     // *
    _DIV_OP,     // /
    _MOD_OP,     // %
    _COMMA_OP,   // ,
    _BIT_LS_OP,  // <<
    _BIT_RS_OP,  // >>
    _BIT_AND_OP, // &
    _BIT_OR_OP,  // |
    _BIT_XOR_OP, // ^
} BinaryExprType;

class BinaryExprAstNode : public DoubleAstNode {
private:
    BinaryExprType value;
    static std::vector<std::string> map;
public:
    BinaryExprAstNode(BinaryExprType _value, AstNode *_left, AstNode *_right) : DoubleAstNode(_left, _right), value(_value) {
    }
    BinaryExprAstNode * getClassType() {
        return this;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

typedef enum {
    _INIT_DECLARE,      // (const A) (b, c, e);
    _IF_STMT,           // if (a) b
    _WHILE_STMT,        // while (a) b
    _DO_WHILE_STMT,     // do a while (b);
    _FOR_STMT,          // for (a) b
    _TWO_FOR_CONDITION, // a; b;
} DoubleOtherType;

class DoubleOtherAstNode : public DoubleAstNode {
private:
    DoubleOtherType value;
    static std::vector<std::string> map;
public:
    std::stringstream cond1, cond2;
    DoubleOtherAstNode(DoubleOtherType _value, AstNode *_left, AstNode *_right) : DoubleAstNode(_left, _right), value(_value) {
    }
    DoubleOtherAstNode * getClassType() {
        return this;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

class TripleAstNode : public AstNode {
protected:
    AstNode *left;
    AstNode *middle;
    AstNode *right;
public:
    TripleAstNode(AstNode *_left, AstNode *_middle, AstNode *_right) : left(_left), middle(_middle), right(_right) {
    }
    virtual TripleAstNode * getClassType() = 0;
    virtual void print(uint _depth);
    virtual void genLabel() = 0;
    virtual void genCode() = 0;
};

typedef enum {
    _IF_ELSE_STMT,        // if (a) b else c
    _THREE_FOR_CONDITION, // /* in condition of for */ (a; b; c)
} TripleOtherType;

class TripleOtherAstNode : public TripleAstNode {
private:
    TripleOtherType value;
    static std::vector<std::string> map;
public:
    std::stringstream cond1, cond2, cond3;
    TripleOtherAstNode(TripleOtherType _value, AstNode *_left, AstNode *_middle, AstNode *_right) : TripleAstNode(_left, _middle, _right), value(_value) {
    }
    TripleOtherAstNode * getClassType() {
        return this;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

typedef enum {
    _INIT_DECLARATOR_LIST,       // a = 1, b = {1}, ...
    _DECLARE_STMT_LIST,          // declare, stmt, ...
    _PROGRAM,                    // func declare func ...
} MultipleType;

class MultipleAstNode : public AstNode {
private:
    MultipleType value;
    std::vector<AstNode *> *children;
    std::vector<VarSymTabNode * > *memberList = nullptr;
    static std::vector<std::string> map;
public:
    MultipleAstNode(MultipleType _value) : value(_value), children(new std::vector<AstNode *>()) {
    }
    MultipleAstNode * insertChild(AstNode *_child);
    MultipleAstNode * getClassType() {
        return this;
    }
    void addMember(VarSymTabNode * _node) {
        if (!memberList) {
            memberList = new std::vector<VarSymTabNode * >();
        }
        memberList->push_back(_node);
    }
    std::vector<VarSymTabNode * > * getMemberList() {
        return memberList;
    }
    void print(uint _depth);
    void genLabel();
    void genCode();
};

class CharValAstNode : public AstNode {
private:
    char value;
    std::string literalValue;
public:
    CharValAstNode(char _value, char *_literalValue) : value(_value), literalValue(_literalValue) {
    }
    CharValAstNode * getClassType() {
        return this;
    }
    void print(uint _depth) {
        setNodeNum(AstNode::nodeCnt++);
        AstNode::printChar(getNodeNum(), literalValue, _depth);
    }
    void genLabel() {}
    void genCode() {}
};

class StringValAstNode : public AstNode {
private:
    std::string value;
    std::string literalValue;
public:
    StringValAstNode(char *_value, char *_literalValue): value(_value), literalValue(_literalValue) {
    }
    StringValAstNode * getClassType() {
        return this;
    }
    void print(uint _depth) {
        setNodeNum(AstNode::nodeCnt++);
        AstNode::printString(getNodeNum(), literalValue, _depth);
    }
    void genLabel() {}
    void genCode() {}
};

class IdentifierAstNode : public AstNode {
private:
    std::string value;
public:
    IdentifierAstNode(char *_value, SymTabNode *_node) : value(_value) {
        setSymTabNode(_node);
    }
    IdentifierAstNode * getClassType() {
        return this;
    }
    SymTabNode * getSymTabNode() {
        return node;
    }
    std::string getValue() {
        return value;
    }
    void print(uint _depth) {
        setNodeNum(AstNode::nodeCnt++);
        AstNode::printIdentifier(getNodeNum(), value, _depth);
    }
    void genLabel() {}
    void genCode();
};

class IntValAstNode : public AstNode {
private:
    int value;
public:
    IntValAstNode(int _value) : value(_value) {
    }
    IntValAstNode * getClassType() {
        return this;
    }
    void print(uint _depth) {
        setNodeNum(AstNode::nodeCnt++);
        AstNode::printInt(getNodeNum(), value, _depth);
    }
    void genLabel() {}
    void genCode();
};

class FloatValAstNode : public AstNode {
private:
    float value;
public:
    FloatValAstNode(float _value) : value(_value) {
    }
    FloatValAstNode * getClassType() {
        return this;
    }
    void print(uint _depth) {
        setNodeNum(AstNode::nodeCnt++);
        AstNode::printFloat(getNodeNum(), value, _depth);
    }
    void genLabel() {}
};

class BoolValAstNode : public AstNode {
private:
    bool value;
public:
    BoolValAstNode(bool _value) : value(_value) {
    }
    BoolValAstNode * getClassType() {
        return this;
    }
    void print(uint _depth) {
        setNodeNum(AstNode::nodeCnt++);
        AstNode::printBool(getNodeNum(), value, _depth);
    }
    void genLabel() {}
};
