#include "../header/Procedure.h"
#include <cmath>

Procedure* Procedure::_instance = NULL;

Procedure::Procedure() {
    procedureTable = new PROCEDURETABLE();
    STATEMENT dummy = -1;
    procedureTable->push_back(dummy);     // fill index 0 in Procedure table
}

Procedure* Procedure::instance() {
    if (_instance == 0) { _instance = new Procedure; }
    return _instance;
}

BOOLEAN Procedure::insertProcedure(const STATEMENT &s) {
    // if Procedure table size if not large enough
    //int maxSize = max(s1, s2);
    this->verifyWithStmtListSize(s);

    if (!this->getProcedure(s)) {     // if not found
        procedureTable.push_back(s);
    }

    return true;
}

/*
 * This is to make sure the size of the Procedure relation ship is the 
 * same as the max statement number
 */
BOOLEAN Procedure::verifyWithStmtListSize(const STATEMENT &s) {
    if (ProcedureTable->size() - 1 < s) {
        int size = s - ProcedureTable->size() + 1;
        for (int i = 0; i < size; i++) {
            STATEMENT dummy = -1;
            ProcedureTable->push_back(dummy);
        }
    }
    return true;
}

/*
 * a = -1, b = 2
 * getProcedure(a, b), will return a which is b's Procedureee
 * a = 2, b = -1
 * getProcedure(a, b), will return b which is a's Procedureer
 */
STATEMENT Procedure::getProcedure(STATEMENT &s) {
     return ProcedureTable->at(s);
}

SIZE Procedure::getProcedureTableSize() {
    return ProcedureTable->size() - 1;
}

ProcedureTABLE* Procedure::getProcedureTable() {
    return ProcedureTable;
}
