#ifndef ASSIGNLIST_H_INCLUDED
#define ASSIGNLIST_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "../../MyTypeDef.h"
#include "List.h"

using namespace std;

class AssignList : public List {
public:
	AssignList() : List() {};
    ~AssignList();

    static AssignList* instance() {
		if (_instance == 0) { _instance = new AssignList; };
		return _instance;
	}

private:
    static AssignList* _instance;
};
#endif
