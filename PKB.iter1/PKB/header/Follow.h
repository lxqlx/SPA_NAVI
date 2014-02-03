#ifndef FOLLOW_H_INCLUDED
#define FOLLOW_H_INCLUDED

#include "../../MyTypeDef.h"
#include <iostream>

using namespace std;

class Follow {

public:
    Follow();
    ~Follow();

    BOOLEAN insertFollow(const STATEMENT &, const STATEMENT &);
    STATEMENT getFollow(STATEMENT &, STATEMENT &);

    SIZE getFollowTableSize();
    FOLLOWTABLE* getFollowTable();
    BOOLEAN verifyWithStmtListSize(const STATEMENT &);

    static Follow* instance();

private:
    FOLLOWTABLE *followTable; 
    static Follow* _instance;

};
#endif
