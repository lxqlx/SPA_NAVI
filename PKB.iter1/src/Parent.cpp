#include "Parent.h"
#include <cmath>

Parent* Parent::_instance = NULL;

Parent::Parent() {
    parentTable = new PARENTTABLE();
    STMTLIST dummy;
    parentTable->push_back(dummy);     // fill index 0 in parent table
}

Parent* Parent::instance() {
    if (_instance == 0) { _instance = new Parent; }
    return _instance;
}

BOOLEAN Parent::insertParent(const STATEMENT &s1, const STATEMENT &s2) {
    // if parent table size if not large enough
    int maxSize = max(s1, s2);
    this->verifyWithStmtListSize(maxSize);

    if (!this->getParent(s1, s2)) {     // if not found
        parentTable->at(s1).push_back(s2);
    }

    return true;
}

BOOLEAN Parent::verifyWithStmtListSize(const STATEMENT &s) {
    if (parentTable->size() - 1 < s) {
        int size = s - parentTable->size() + 1;
        for (int i = 0; i < size; i++) {
            STMTLIST dummy;
            parentTable->push_back(dummy);
        }
    }
    return true;
}

/*
 * getPrent(b), will return a which is b's parent
 */
STATEMENT Parent::getParent(const STATEMENT &s) {
    for (int i = 1; i <= parentTable->size() - 1; i++) {
        STMTLIST list = parentTable->at(i);
        for (int j = 0; j < list.size(); j++) {
            if (list.at(j) == s) { return i; }
        }
    }
    return -1;
}

/*
 * getChild(a), will return b which is a's child
 */
STMTLIST Parent::getChild(const STATEMENT &s) {
    return parentTable->at(s);
}

BOOLEAN Parent::getParent(const STATEMENT &s1, const STATEMENT &s2) {
    STMTLIST list = parentTable->at(s1);
    for (int i = 0; i < list.size(); i++) {
        if (list.at(i) == s2) { return true; }
    }
    return false;
}

SIZE Parent::getParentTableSize() {
    return parentTable->size() - 1;
}

PARENTTABLE* Parent::getParentTable() {
    return parentTable;
}
