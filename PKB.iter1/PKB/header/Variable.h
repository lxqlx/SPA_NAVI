#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "../../MyTypeDef.h"

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
#endif
