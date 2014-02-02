//
//  VaribaleTable.h
//  CS3201
//
//  Created by Yu Fangzhou on 03/11/13.
//  Copyright (c) 2013年 Yu Fangzhou. All rights reserved.
//  edit by wulong at 04/11 15:11
//

#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "MyTypeDef.h"

using namespace std;

class Variable {
public:
    Variable();
    ~Variable();

    INDEX insertVariable(const VARNAME &);
    SIZE getSize();
    VARNAME getVariableName(const INDEX &);
    INDEX getVariableIndex(const VARNAME &);

    VARNAMETABLE* getAllVariables();

    static Variable* instance();

private:
    static Variable* _instance;

    VARNAMETABLE *varTable;
};
#endif /* defined(__CS3201__VaribaleTable__) */
