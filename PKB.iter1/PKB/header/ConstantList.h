#ifndef CONSTLIST_H_INCLUDED
#define CONSTLIST_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "../../MyTypeDef.h"
#include "List.h"

using namespace std;

class ConstantList : public List {
public:
	ConstantList() : List() {};
    ~ConstantList();

    static ConstantList* instance() {
		if (_instance == 0) { _instance = new ConstantList; };
		return _instance;
	}

private:
    static ConstantList* _instance;
};
#endif
