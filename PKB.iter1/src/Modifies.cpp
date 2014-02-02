#include "Modifies.h"

Modifies* Modifies::_instance = NULL;

Modifies::Modifies() {
    modifiesTable = new MODIFIESTABLE;
    MODIFYLIST dummy;
    modifiesTable->push_back(dummy);        // fill in index 0
#ifndef NDEBUG
    int size = modifiesTable->size() - 1;
    assert(size == 0);
    cerr << __FILE__ << endl;
#endif
}

Modifies* Modifies::instance() {
    if (_instance == 0) { _instance = new Modifies; }
    return _instance;
}

BOOLEAN Modifies::insertModifies(const STATEMENT &s, const VARNAME &v) {
    // fill modifiesTable
    this->verifyWithStmtListSize(s);
    
    if (!existModifies(s, v)) { modifiesTable->at(s).push_back(v); }
    return true;
}

BOOLEAN Modifies::verifyWithStmtListSize(const STATEMENT &s) {
    if (modifiesTable->size() - 1 < s) {
        int fill = s - modifiesTable->size() + 1;
        for (int i = 0; i < fill; i++) {
            MODIFYLIST dummy;
            modifiesTable->push_back(dummy);
        }
    }
    return true;
}

BOOLEAN Modifies::existModifies(const STATEMENT &s, const VARNAME &v) {
    MODIFYLIST sList = modifiesTable->at(s);
    for (MODIFYLIST::iterator it = sList.begin(); it != sList.end(); it++) {
        if (*it == v) { return true; };
    }
    return false;
}

MODIFIESTABLE* Modifies::getModifiesTable() {
    return modifiesTable;
}

MODIFYLIST Modifies::getModifyList(const STATEMENT &s) {
    return modifiesTable->at(s);
}

STMTLIST Modifies::getStatementList(const VARNAME &v) {
    STMTLIST resultList;
    for (int i = 0; i < modifiesTable->size(); i++) {
        MODIFYLIST list = modifiesTable->at(i);
        for (int j = 0; j < list.size(); j++) {
            if (list.at(j) == v) {
                resultList.push_back(i);
                break;
            }
        }
    }
    return resultList;
}
