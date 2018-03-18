#pragma once
#include "AstNode.h"
#include <sstream>

extern std::ofstream myOut;

class Ast {
private:
    MultipleAstNode *root = nullptr;
    std::stringstream sout;
public:
    Ast() : root(new MultipleAstNode(_PROGRAM)) {
    }
    MultipleAstNode * getRoot() {
        return root;
    }
    void genHeader();
    void genAsm();
    void genLabel();
    void genCode();
};
