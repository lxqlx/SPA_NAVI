#ifndef IFLIST_H_INCLUDED
#define IFLIST_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "../../MyTypeDef.h"
#include "List.h"

using namespace std;

class IfList : public List {
public:
	IfList() : List() {};
    ~IfList();

    static IfList* instance() {
		if (_instance == 0) { _instance = new IfList; };
		return _instance;
	}

private:
    static IfList* _instance;
};
#endif
