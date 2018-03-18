#include "SymTab.h"
#include <iostream>
#include "SymTabNode.h"
#include <stdlib.h>

SymTab * SymTab::currentTab = new SymTab();
SymTabNode * SymTab::currentNode = nullptr;
bool SymTab::keepTable = false;
int SymTab::varCnt = 0;

SymTab::SymTab() {
}

SymTab::SymTab(SymTab * _parent) : parent(_parent) {
}

bool SymTab::isDuplicated(std::string & _name) {
    if (table.find(_name) != table.end()) {
        return true;
    }
    if (parent) {
        return parent->isDuplicated(_name);
    }
    return false;
}

bool SymTab::isDuplicatedHere(std::string & _name) {
    if (table.find(_name) != table.end()) {
        return true;
    }
    return false;
}

SymTabNode * SymTab::getNode(std::string & _name) {
    std::unordered_map<std::string, SymTabNode * >::iterator ite = table.find(_name);
    if (ite != table.end()) {
        return ite->second;
    }
    if (parent) {
        return parent->getNode(_name);
    }
    return nullptr;
}

SymTabNode * SymTab::getNodeHere(std::string & _name) {
    std::unordered_map<std::string, SymTabNode * >::iterator ite = table.find(_name);
    if (ite != table.end()) {
        return ite->second;
    }
    return nullptr;
}

SymTab * SymTab::insertNode(std::string & _name, SymTabNode * _node) {
    table[_name] = _node;
    _node->allocVarNum();
    return this;
}

void SymTab::print() {
    for (auto ite : table) {
        std::cout << ite.first << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;
    for (auto ite : printVector) {
        ite->print();
    }
}
