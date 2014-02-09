#include "../header/CallStar.h"

CallStar* CallStar::_instance = NULL;

CallStar::CallStar() {
    callerTable = new CALLERTABLE();
    callerTable = new CALLEETABLE();
}

CallStar* CallStar::instance() {
    if (_instance == 0) { _instance = new CallStar; }
    return _instance;
}

BOOLEAN CallStar::insertToCallerTable( const PROCNAME &n1, const PROCNAME &n2 ) {
	if (this->isInCallerTable(n1, n2)) {
		return false;		// already exist in the table
	}

	PROCLIST* searchResult = this->getCaller(n1);
	if (searchResult != NULL) {
		searchResult->push_back(n2);
		return true;
	}

	PROCLIST* newList = new PROCLIST();
	newList->push_back(n2);
	CALLREL newCaller(n1, newList);
	callerTable->push_back(newCaller);
	return true;
}

BOOLEAN CallStar::insertToCalleeTable( const PROCNAME &n1, const PROCNAME &n2 ) {
	if (this->isInCalleeTable(n1, n2)) {
		return false;		// already exist in the table
	}

	PROCLIST* searchResult = this->getCallee(n1);
	if (searchResult != NULL) {
		searchResult->push_back(n2);
		return true;
	}

	PROCLIST* newList = new PROCLIST();
	newList->push_back(n2);
	CALLREL newCallee(n1, newList);
	calleeTable->push_back(newCallee);
	return true;
}


BOOLEAN CallStar::isInCallerTable( const PROCNAME &n1, const PROCNAME &n2) {
	PROCLIST* searchResult = NULL;
	searchResult = this->getCaller(n1);

	if (searchResult == NULL) {
		return false;
	}

	for (int i = 0; i < searchResult->size(); i++) {
		if (searchResult->at(i) == n2) {
			return true;
		}
	}
	return false;
}

BOOLEAN CallStar::isInCalleeTable( const PROCNAME &n1, const PROCNAME &n2) {
	PROCLIST* searchResult = NULL;
	searchResult = this->getCallee(n1);

	if (searchResult == NULL) {
		return false;
	}

	for (int i = 0; i < searchResult->size(); i++) {
		if (searchResult->at(i) == n2) {
			return true;
		}
	}
	return false;
}

//************************************
// Method:    getCaller
// FullName:  CallStar::getCaller
// Access:    public static 
// Returns:   PROCLIST*
// Qualifier:
// Parameter: static PROCNAME &
//************************************
PROCLIST* CallStar::getCaller( const PROCNAME & n) {
	PROCLIST* searchResult = NULL;
	for (int i = 0; i < callerTable->size(); i++) {
		if (callerTable->at(i).getX() == n) {
			return callerTable->at(i).getY();
		}
	}
	return searchResult;
}

//************************************
// Method:    getCallee
// FullName:  CallStar::getCallee
// Access:    public static 
// Returns:   PROCLIST*
// Qualifier:
// Parameter: static PROCNAME &
//************************************
PROCLIST* CallStar::getCallee( const PROCNAME &n) {
	PROCLIST* searchResult = NULL;
	for (int i = 0; i < callerTable->size(); i++) {
		if (calleeTable->at(i).getX() == n) {
			return calleeTable->at(i).getY();
		}
	}
	return searchResult;
}

CALLERTABLE* CallStar::getCallerTable() {
	return callerTable;
}

CALLEETABLE* CallStar::getCalleeTable() {
	return calleeTable;
}

