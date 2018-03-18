#include "Ast.h"
#include "AstNode.h"

Ast *ast;
extern std::ofstream myOut;

void Ast::genHeader() {
    sout << "\t.486" << std::endl;
    sout << "\t.model flat, stdcall" << std::endl;
    sout << "\toption casemap :none" << std::endl;
    sout << std::endl;

    sout << "\tinclude \\masm32\\include\\windows.inc" << std::endl;
    sout << "\tinclude \\masm32\\macros\\macros.asm" << std::endl;
    sout << std::endl;

    sout << "\tinclude \\masm32\\include\\masm32.inc" << std::endl;
    sout << "\tinclude \\masm32\\include\\gdi32.inc" << std::endl;
    sout << "\tinclude \\masm32\\include\\user32.inc" << std::endl;
    sout << "\tinclude \\masm32\\include\\kernel32.inc" << std::endl;
    sout << "\tinclude \\masm32\\include\\msvcrt.inc" << std::endl;
    sout << std::endl;

    sout << "\tincludelib \\masm32\\lib\\masm32.lib" << std::endl;
    sout << "\tincludelib \\masm32\\lib\\gdi32.lib" << std::endl;
    sout << "\tincludelib \\masm32\\lib\\user32.lib" << std::endl;
    sout << "\tincludelib \\masm32\\lib\\kernel32.lib" << std::endl;
    sout << "\tincludelib \\masm32\\lib\\msvcrt.lib" << std::endl;
    sout << std::endl;
}

void Ast::genAsm() {
    genHeader();
    genLabel();
    genCode();
    sout << "\t.data" << std::endl;
    for (int i = 0; i < AstNode::getTempVarCnt(); ++i) {
        sout << "\t temp" << i << " DD ?" << std::endl;
    }
    sout << std::endl;
    sout << "\t.code" << std::endl;
    sout << "start:" << std::endl;
    sout << "\tcall main" << std::endl;
    sout << "\texit" << std::endl;
    sout << "main proc" << std::endl;
    for (int i = 0; i < SymTab::varCnt; ++i) {
        sout << "\tLOCAL var" << i << " :DWORD" << std::endl;
    }
    sout << root->getCode();
    sout << "\tret" << std::endl;
    sout << "main endp" << std::endl;
    sout << "end start" << std::endl;
    myOut << sout.str();
}

void Ast::genLabel() {
    root->genLabel();
}

void Ast::genCode() {
    root->genCode();
}
