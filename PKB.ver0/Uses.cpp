#include "Uses.h"

Uses* Uses::_instance = NULL;

Uses::Uses() {
    usesTable = new USESTABLE;
    USELIST dummy;
    usesTable->push_back(dummy);        // fill in index 0
#ifndef NDEBUG
    int size = usesTable->size() - 1;
    assert(size == 0);
    cerr << __FILE__ << endl;
#endif
}

Uses* Uses::instance() {
    if (_instance == 0) { _instance = new Uses; }
    return _instance;
}

BOOLEAN Uses::insertUses(const STATEMENT &s, const VARNAME &v) {
    // fill usesTable
    this->verifyWithStmtListSize(s);
    
    if (!existUses(s, v)) { usesTable->at(s).push_back(v); }
    return true;
}

BOOLEAN Uses::verifyWithStmtListSize(const STATEMENT &s) {
    if (usesTable->size() - 1 < s) {
        int fill = s - usesTable->size() + 1;
        for (int i = 0; i < fill; i++) {
            USELIST dummy;
            usesTable->push_back(dummy);
        }
    }
    return true;
}

BOOLEAN Uses::existUses(const STATEMENT &s, const VARNAME &v) {
    USELIST sList = usesTable->at(s);
    for (USELIST::iterator it = sList.begin(); it != sList.end(); it++) {
        if (*it == v) { return true; };
    }
    return false;
}

USESTABLE* Uses::getUsesTable() {
    return usesTable;
}

USELIST Uses::getUseList(const STATEMENT &s) {
    return usesTable->at(s);
}

STMTLIST Uses::getStatementList(const VARNAME &v) {
    STMTLIST resultList;
    for (int i = 0; i < usesTable->size(); i++) {
        USELIST list = usesTable->at(i);
        for (int j = 0; j < list.size(); j++) {
            if (list.at(j) == v) {
                resultList.push_back(i);
                break;
            }
        }
    }
    return resultList;
}
