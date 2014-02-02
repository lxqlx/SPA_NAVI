#ifndef PARENTEXTRACTOR_H_INCLUDED
#define PARENTEXTRACTOR_H_INCLUDED

#include "MyTypeDef.h"

// include parent header
#include "Parent.h"

// include parent star header
#include "ParentStar.h"

#include <iostream>

using namespace std;

class ParentExtractor {
public:
    ParentExtractor();
    ~ParentExtractor();

    BOOLEAN buildParentStarTable();

    static ParentExtractor* instance();

protected:
    void checkChild(STATEMENT s, STMTLIST list);

private:
    static ParentExtractor* _instance;

    PARENTTABLE *parentTable;
    SIZE parentTableSize;

};
#endif
