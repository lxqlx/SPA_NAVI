#ifndef PARENTSTAR_H_INCLUDED
#define PARENTSTAR_H_INCLUDED

#include "MyTypeDef.h"
#include <iostream>

using namespace std;

class ParentStar {

public:
    ParentStar();
    ~ParentStar();

    BOOLEAN insertParentStarParent(const STATEMENT &, const STATEMENT &);
    BOOLEAN insertParentStarChild(const STATEMENT &, const STATEMENT &);
    void getParentStar( STMTLIST &, STATEMENT &);
    void getParentStar( STATEMENT &, STMTLIST &);
    BOOLEAN getParentStar(const STATEMENT &, const STATEMENT &);
    BOOLEAN verifyWithStmtListSize(const STATEMENT &);

    PARENTSTARTABLE_P* getParentStarTableForParent();
    PARENTSTARTABLE_C* getParentStarTableForChild();

    static ParentStar* instance();

protected:
    BOOLEAN getParentStarForChildTable(const STATEMENT &, const STATEMENT &);
    BOOLEAN getParentStarForParentTable(const STATEMENT &, const STATEMENT &);

private:
    PARENTSTARTABLE_C *parentStarTableForChild;
    PARENTSTARTABLE_P *parentStarTableForParent;

    static ParentStar* _instance;

};
#endif
