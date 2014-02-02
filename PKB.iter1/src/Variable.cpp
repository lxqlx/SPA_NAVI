//
//  VaribaleTable.cpp
//  CS3201
//
//  Created by Yu Fangzhou on 03/11/13.
//  Copyright (c) 2013年 Yu Fangzhou. All rights reserved.
//  edit by wulong at 04/11 15:11
//

#include "Variable.h"

Variable* Variable::_instance = NULL;

Variable::Variable() {
    varTable = new VARNAMETABLE;
    VARNAME dummy = "";         // fill in index 0, varTable will start from index 1
    varTable->push_back(dummy);

#ifndef NDEBUG
    varTable->push_back("a");
    varTable->push_back("b");
    int size = varTable->size() - 1;
    assert(size == 2);
#endif
}

Variable* Variable::instance() {
    if (_instance == 0) { _instance = new Variable; };
    return _instance;
}

INDEX Variable::insertVariable(const VARNAME &varName) {
    if (this->getVariableIndex(varName) != -1) {
        return this->getVariableIndex(varName);
    }

    varTable->push_back(varName);

    return this->getVariableIndex(varName);
}

SIZE Variable::getSize() {
    return varTable->size() - 1;
}

VARNAME Variable::getVariableName(const INDEX &i) {
    return varTable->at(i);
}

INDEX Variable::getVariableIndex(const VARNAME &v) {
    for (VARNAMETABLE::iterator it = varTable->begin(); it != varTable->end(); it++) {
        if (*it == v) {
            return distance(varTable->begin(), it);
        }
    }
    return -1;
}

VARNAMETABLE* Variable::getAllVariables() {
    return varTable;
}
