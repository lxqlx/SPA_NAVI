#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

//#define NDEBUG

#include <iostream>
#include <cassert>
#include "../../MyTypeDef.h"

using namespace std;

class List {
public:
    List();
    ~List();

    INDEX insert(const STATEMENT &);

    SIZE getSize();
    STATEMENT get(const INDEX &);
    INDEX getIdx(const STATEMENT &);

    STMTLIST* getAll();

private:
    STMTLIST *statementList;			// starts from index 0

};
#endif
