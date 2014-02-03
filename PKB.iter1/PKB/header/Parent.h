#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include "../../MyTypeDef.h"
//#include "Vector2d.h"
#include <iostream>

using namespace std;

class Parent {

public:
    Parent();
    ~Parent();

    BOOLEAN insertParent(const STATEMENT &, const STATEMENT &);
    STATEMENT getParent(const STATEMENT &);
    STMTLIST getChild(const STATEMENT &);
    BOOLEAN getParent(const STATEMENT &, const STATEMENT &);

    SIZE getParentTableSize();
    PARENTTABLE* getParentTable();
    BOOLEAN verifyWithStmtListSize(const STATEMENT &);

    static Parent* instance();

private:
    PARENTTABLE *parentTable; 
    static Parent* _instance;

};
#endif
