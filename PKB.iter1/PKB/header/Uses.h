#ifndef USES_H_INCLUDED
#define USES_H_INCLUDED

#include "../../MyTypeDef.h"
#include <iostream>
#include <cassert>
//#include NDEBUG

using namespace std;

class Uses {
public:
    Uses();
    ~Uses();

    BOOLEAN insertUses(const STATEMENT &, const VARNAME &);

    USESTABLE* getUsesTable();

    USELIST getUseList(const STATEMENT &);
    STMTLIST getStatementList(const VARNAME &);
    BOOLEAN existUses(const STATEMENT &, const VARNAME &);
    BOOLEAN verifyWithStmtListSize(const STATEMENT &);

    static Uses* instance();

private:


    static Uses* _instance;

    USESTABLE* usesTable;
};
#endif
