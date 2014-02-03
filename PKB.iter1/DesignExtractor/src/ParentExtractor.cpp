#include "../header/ParentExtractor.h"

ParentExtractor* ParentExtractor::_instance = NULL;

ParentExtractor::ParentExtractor() {
    // get parent table
    parentTable = Parent::instance()->getParentTable();

    parentTableSize = Parent::instance()->getParentTableSize();        // ignore dummy 

}

ParentExtractor* ParentExtractor::instance() {
    if (_instance == 0) { _instance = new ParentExtractor; }
    return _instance;
}

/*
 * Build parent star table
 * This method assume that parent table is finished creating
 * The method will import data from parent table and generate
 * parent star table.
 * note that : parent star table include parent star parent table
 * and parent star child table
 */
BOOLEAN ParentExtractor::buildParentStarTable() {

    // generate parent star table for parent relatioinship
    // table format [statement number, parent list]
    for (int i = 1; i <= parentTableSize; i++) {
        STATEMENT s = i;                 // find s's all parent
        STATEMENT st = s;               // temp child
        for (int j = 1; j <= parentTableSize; j++) {
            STMTLIST list = parentTable->at(j);
            for (int z = 0; z < list.size(); z++) {
                if (list.at(z) == st) {
                    ParentStar::instance()->insertParentStarParent(s, j);
                    st = j;
                    j = -1;     // restart from beginning
                    break;
                }

            }
        }
    }

    // generate parent star table for child relatioinship
    // table format [statement number, child list]
    for (int i = 1; i <= parentTableSize; i++) {
        STATEMENT s = i;                        // find s's all child
        STMTLIST st = parentTable->at(s);       // temp parent list
        this->checkChild(i, st);
    }

    return true;
}

/*
 * Recursively find child
 */
void ParentExtractor::checkChild(STATEMENT s, STMTLIST list) {
    if (list.size() == 0) { return; }

    for (int j = 0; j < list.size(); j++) {
        ParentStar::instance()->insertParentStarChild(s, list.at(j));
        checkChild(s, parentTable->at(list.at(j)));
    }
}
