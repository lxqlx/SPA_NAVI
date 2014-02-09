#ifndef CALL_H_INCLUDED
#define CALL_H_INCLUDED

#include "../../MyTypeDef.h"
#include <iostream>

using namespace std;

class Call {

public:
    Call();
    ~Call();

    BOOLEAN insertCall(const PROCNAME &, const PROCNAME &);
    PROCLIST getCallRel(const PROCNAME &, const PROCNAME &);

    SIZE getCallTableSize();
    CALLTABLE* getCallTable();

    static Call* instance();

protected:
	PROCNAME getCaller(const PROCNAME &);
	PROCLIST* getCallee(const PROCNAME &);

private:
    CALLTABLE *callTable;			// call table starts from index 0
    static Call* _instance;

};
#endif