#pragma once
#include "SymTabNode.h"
#include <string>
#include <unordered_map>

typedef unsigned int uint;

class SymTabNode;
enum SpecifierType;

class SymTab {
private:
    uint anonyName = 0;
    std::unordered_map<std::string, SymTabNode * > table;
public:
    static SymTab *currentTab;
    static SymTabNode *currentNode;
    static bool keepTable;
    static int varCnt;
    SymTab *parent = nullptr;
    SymTab();
    SymTab(SymTab *_parent);
    bool isDuplicated(std::string &_name);
    bool isDuplicatedHere(std::string &_name);
    SymTabNode * getNode(std::string &_name);
    SymTabNode * getNodeHere(std::string &_name);
    SymTab * insertNode(std::string &_name, SymTabNode * _node);
    std::vector<SymTab *> printVector;
    void print();
};
