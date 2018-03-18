#pragma once
#include "SymTab.h"
#include <string>
#include <vector>

typedef unsigned int uint;

class SymTab;
class VarSymTabNode;

enum SpecifierType {
    _S_DEFAULT_INT = 0x0,
    _S_INT = 0x1,
    _S_CHAR = 0x2,
};

class SymTabNode {
protected:
    SymTab *table = nullptr;
    int varNum = 0;
public:
    SymTabNode(SymTab *_table);
    SymTab * getTable();
    void allocVarNum();
    int getVarNum() { return varNum; }
    virtual SymTabNode * getClassType() = 0;
};

class VarSymTabNode : public SymTabNode {
private:
    SpecifierType specifier = _S_DEFAULT_INT;

public:
    VarSymTabNode(SymTab *_table);
    VarSymTabNode * getClassType();
    bool setSpecifier(SpecifierType _type);
    SpecifierType getSpecifier();
};