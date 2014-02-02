#ifndef MODIFIES_H_INCLUDED
#define MODIFIES_H_INCLUDED

#include "MyTypeDef.h"
#include <iostream>
#include <cassert>
//#include NDEBUG

using namespace std;

class Modifies {
public:
    Modifies();
    ~Modifies();

    BOOLEAN insertModifies(const STATEMENT &, const VARNAME &);

    MODIFIESTABLE* getModifiesTable();

    MODIFYLIST getModifyList(const STATEMENT &);
    STMTLIST getStatementList(const VARNAME &);
    BOOLEAN existModifies(const STATEMENT &, const VARNAME &);
    BOOLEAN verifyWithStmtListSize(const STATEMENT &);

    static Modifies* instance();

private:


    static Modifies* _instance;

    MODIFIESTABLE* modifiesTable;
};
#endif
