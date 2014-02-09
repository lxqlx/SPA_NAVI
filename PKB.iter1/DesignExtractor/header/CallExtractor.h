#ifndef CALLEXTRACTOR_H_INCLUDED
#define CALLEXTRACTOR_H_INCLUDED

#include "../../MyTypeDef.h"

// include call header
#include "../../PKB/header/Call.h"

// include call star header
#include "../../PKB/header/CallStar.h"

#include <iostream>

using namespace std;

class CallExtractor {
public:
    CallExtractor();
    ~CallExtractor();

    BOOLEAN buildCallStarTable();

    static CallExtractor* instance();

protected:
	void findCaller(const PROCNAME &, const PROCNAME &);
	void findCallee(const PROCNAME &, const PROCNAME &);

private:
    static CallExtractor* _instance;
	CALLTABLE *callTable;
	SIZE callTableSize;

};
#endif