#ifndef STMTLIST_H_INCLUDED
#define STMTLIST_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "../../MyTypeDef.h"
#include "List.h"

using namespace std;

class StatementList : public List {
public:
	StatementList() : List() {};
    ~StatementList();

    static StatementList* instance() {
		if (_instance == 0) { _instance = new StatementList; };
		return _instance;
	}

private:
    static StatementList* _instance;
};
#endif
