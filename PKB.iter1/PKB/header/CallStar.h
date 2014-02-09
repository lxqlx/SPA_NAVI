#ifndef CALLSTAR_H_INCLUDED
#define CALLSTAR_H_INCLUDED

#include "../../MyTypeDef.h"
#include <iostream>

using namespace std;

class CallStar {

public:
    CallStar();
    ~CallStar();

    BOOLEAN insertToCallerTable(const PROCNAME &, const PROCNAME &);
    BOOLEAN insertToCalleeTable(const PROCNAME &, const PROCNAME &);

    PROCLIST* getCaller(const PROCNAME &);
    PROCLIST* getCallee(const PROCNAME &);

    CALLERTABLE* getCallerTable();
    CALLEETABLE* getCalleeTable();

    static CallStar* instance();

protected:
    BOOLEAN isInCallerTable(const PROCNAME &, const PROCNAME &);
    BOOLEAN isInCalleeTable(const PROCNAME &, const PROCNAME &);

private:
    CALLERTABLE *callerTable;
    CALLEETABLE *calleeTable;

    static CallStar* _instance;

};
#endif
