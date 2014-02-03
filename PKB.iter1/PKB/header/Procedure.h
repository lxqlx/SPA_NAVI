#ifndef PROCEDURE_H_INCLUDED
#define PROCEDURE_H_INCLUDED

//#define NDEBUG

#include "../../MyTypeDef.h"
#include <iostream>
#include <cassert>

using namespace std;

class Procedure {
public:
    Procedure();
    ~Procedure();

    INDEX insertProcname(const PROCNAME &);
    SIZE getSize();
    PROCNAME getProcName(const INDEX &);
    INDEX getProcIndex(const PROCNAME &);

    PROCNAMETABLE* getAllProcdures();

    static Procedure* instance();

private:
    static Procedure* _instance;

    PROCNAMETABLE *procTable;
};
#endif
