#ifndef WHILELIST_H_INCLUDED
#define WHILELIST_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "../../MyTypeDef.h"
#include "List.h"

using namespace std;

class WhileList : public List {
public:
	WhileList() : List() {};
    ~WhileList();

    static WhileList* instance() {
		if (_instance == 0) { _instance = new WhileList; };
		return _instance;
	}

private:
    static WhileList* _instance;
};
#endif
