#include "../header/Procedure.h"

Procedure* Procedure::_instance = NULL;

Procedure::Procedure() {
    procTable = new PROCNAMETABLE;
    PROCNAME dummy = "";         // fill in index 0, procTable will start from index 1
    procTable->push_back(dummy);

#ifndef NDEBUG
    procTable->push_back("a");
    procTable->push_back("b");
    int size = procTable->size() - 1;
    assert(size == 2);
#endif
}

Procedure* Procedure::instance() {
    if (_instance == 0) { _instance = new Procedure; };
    return _instance;
}

INDEX Procedure::insertProcname(const VARNAME &procName) {
    if (this->getProcIndex(procName) != -1) {
        return this->getProcIndex(procName);
    }

    procTable->push_back(procName);

    return this->getProcIndex(procName);
}

SIZE Procedure::getSize() {
    return procTable->size() - 1;
}

PROCNAME Procedure::getProcName(const INDEX &i) {
    return procTable->at(i);
}

INDEX Procedure::getProcIndex(const PROCNAME &v) {
    for (PROCNAMETABLE::iterator it = procTable->begin(); it != procTable->end(); it++) {
        if (*it == v) {
            return distance(procTable->begin(), it);
        }
    }
    return -1;
}

PROCNAMETABLE* Procedure::getAllProcdures() {
    return procTable;
}
