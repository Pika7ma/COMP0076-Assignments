#include "SymTabNode.h"
#include "SymTab.h"

SymTabNode::SymTabNode(SymTab * _table) : table(_table) {
}

SymTab * SymTabNode::getTable() {
    return table;
}

void SymTabNode::allocVarNum() {
    varNum = SymTab::varCnt++;
}

VarSymTabNode::VarSymTabNode(SymTab * _table) : SymTabNode(_table) {
}

VarSymTabNode * VarSymTabNode::getClassType() {
    return this;
}

bool VarSymTabNode::setSpecifier(SpecifierType _type) {
    if (specifier == _S_DEFAULT_INT) {
        specifier = _type;
        return false;
    }
    return true;
}

SpecifierType VarSymTabNode::getSpecifier() {
    return specifier;
}
