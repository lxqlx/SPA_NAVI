#include "../header/CallExtractor.h"

CallExtractor* CallExtractor::_instance = NULL;

CallExtractor::CallExtractor() {
    // get call table
    callTable = Call::instance()->getCallTable();
    callTableSize = Call::instance()->getCallTableSize();
}

CallExtractor* CallExtractor::instance() {
    if (_instance == 0) { _instance = new CallExtractor; }
    return _instance;
}

/*
 * Build call star table
 * This method assume that call table is finished creating
 * The method will import data from call table and generate
 * call star table.
 * note that : call star table include follow star follower table
 * and follow star callee table
 */
BOOLEAN CallExtractor::buildCallStarTable() {
    // generate call star table for callee relationship
    // table format [caller procedure, callee list]
    //
    for (int i = 0; i < callTableSize; i++) {
        CALLREL callRel = callTable->at(i);          // find all callee in index i
		PROCLIST *procList = callRel.getY();
		for (int j = 0; j < procList->size(); j++) {
			CallStar::instance()->insertToCalleeTable(callRel.getX(), procList->at(j));
			this->findCallee(callRel.getX(), procList->at(j));		// recursive call
		}
    }

    // generate call star table for caller relationship
    // table format [callee procedure, caller list]
    //
    for (int i = 0; i < callTableSize; i++) {
        CALLREL callRel = callTable->at(i);      
		PROCLIST *procList = callRel.getY();
		for (int j = 0; j < procList->size(); j++) {
			CallStar::instance()->insertToCallerTable(procList->at(j), callRel.getX());	// find all caller of procList->at(j)
			this->findCaller(procList->at(j), callRel.getX());		// recursive call
		}
    }

    return true;
}

void CallExtractor::findCallee( const PROCNAME &n, const PROCNAME &p ) {
	for (int i = 0; i < callTableSize; i++) {
		CALLREL callRel = callTable->at(i);
		PROCNAME procName = callRel.getX();
		if (procName == p) {
			PROCLIST *procList = callRel.getY();
			for (int j = 0; j < procList->size(); j++) {
				if (CallStar::instance()->insertToCalleeTable(n, procList->at(j))) {
					this->findCallee(n, procList->at(j));
				} else return;
			}
		}
	}
}


void CallExtractor::findCaller( const PROCNAME &n, const PROCNAME &p ) {
	for (int i = 0; i < callTableSize; i++) {
		CALLREL callRel = callTable->at(i);
		PROCLIST *procList = callRel.getY();
		for (int j = 0; j < procList->size(); j++) {
			if (procList->at(j) == p) {
				if (CallStar::instance()->insertToCallerTable(n, procList->at(j))) {
					this->findCaller(n, procList->at(j));
				} else return;
			}
		}
	}
}

