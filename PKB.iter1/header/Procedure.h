#ifndef PROCEDURE_H_INCLUDED
#define PROCEDURE_H_INCLUDED

#include "MyTypeDef.h"
#include <iostream>

using namespace std;

class Procedure {

public:
    Procedure();
    ~Procedure();

    BOOLEAN insertProcedure(const STATEMENT &);
    STATEMENT getProcedure(STATEMENT &);

    SIZE getProcedureTableSize();
    PROCEDURETABLE* getProcedureTable();
    BOOLEAN verifyWithStmtListSize(const STATEMENT &);

    static Procedure* instance();

private:
    PROCEDURETABLE *procedureTable; 
    static Procedure* _instance;

};
#endif
