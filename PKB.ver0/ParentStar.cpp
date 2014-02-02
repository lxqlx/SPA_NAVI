#include "ParentStar.h"
#include <cmath>

ParentStar* ParentStar::_instance = NULL;

ParentStar::ParentStar() {
    parentStarTableForChild = new PARENTSTARTABLE_C();
    STMTLIST dummy1;
    parentStarTableForChild->push_back(dummy1);       // fill index 0 in parent table for child

    parentStarTableForParent = new PARENTSTARTABLE_P();
    STMTLIST dummy2;
    parentStarTableForParent->push_back(dummy2);      // fill index 0 in parent table for parent
}

ParentStar* ParentStar::instance() {
    if (_instance == 0) { _instance = new ParentStar; }
    return _instance;
}

/*
 * Parent list
 * s1 is statement, s1 is s2's parent
 * s1 is child
 * s2 is parent
 */
BOOLEAN ParentStar::insertParentStarParent(const STATEMENT &s1, const STATEMENT &s2) {
    int maxSize = max(s1, s2);
    this->verifyWithStmtListSize(maxSize);

    if(!this->getParentStarForParentTable(s1, s2)) {
        parentStarTableForParent->at(s1).push_back(s2);
    }
    return true;
}

/*
 * Child list
 * s1 is statement, s2 is s1's child
 * s1 is parent
 * s2 is child
 */
BOOLEAN ParentStar::insertParentStarChild(const STATEMENT &s1, const STATEMENT &s2) {
    int maxSize = max(s1, s2);
    this->verifyWithStmtListSize(maxSize);

    if (!this->getParentStarForChildTable(s1, s2)) {
        parentStarTableForChild->at(s1).push_back(s2);
    }

    return true;
}

BOOLEAN ParentStar::verifyWithStmtListSize(const STATEMENT &s) {
    if (parentStarTableForChild->size() - 1 < s) {
        int size = s - parentStarTableForChild->size() + 1;
        for (int i = 0; i < size; i++) {
            STMTLIST dummy;
            parentStarTableForChild->push_back(dummy);
        }
    }

    if (parentStarTableForParent->size() - 1 < s) {
        int size = s - parentStarTableForParent->size() + 1;
        for (int i = 0; i < size; i++) {
            STMTLIST dummy;
            parentStarTableForParent->push_back(dummy);
        }
    }
    return true;
}

void ParentStar::getParentStar(STMTLIST &sl, STATEMENT &s) {
    sl = parentStarTableForParent->at(s);
}

void ParentStar::getParentStar(STATEMENT &s, STMTLIST &sl) {
    sl = parentStarTableForChild->at(s);
}

BOOLEAN ParentStar::getParentStar(const STATEMENT &s1, const STATEMENT &s2) {
    // return all the relation ship in the parent star table
    // should retreive in evaluator
    return this->getParentStarForChildTable(s1, s2);
}

BOOLEAN ParentStar::getParentStarForChildTable(const STATEMENT &s1, const STATEMENT &s2) {
    STMTLIST list = parentStarTableForChild->at(s1);
    for (STMTLIST::iterator it = list.begin(); it != list.end(); it++) {
        if (*it == s2) {
            return true;
        }
    }

    return false;
}

BOOLEAN ParentStar::getParentStarForParentTable(const STATEMENT &s1, const STATEMENT &s2) {
    STMTLIST list = parentStarTableForParent->at(s1);
    for (STMTLIST::iterator it = list.begin(); it != list.end(); it++) {
        if (*it == s2) {
            return true;
        }
    }

    return false;
}

PARENTSTARTABLE_C* ParentStar::getParentStarTableForChild() {
    return parentStarTableForChild;
}

PARENTSTARTABLE_P* ParentStar::getParentStarTableForParent() {
    return parentStarTableForParent;
}
