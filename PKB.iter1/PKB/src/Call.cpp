#include "../header/Call.h"
#include <cmath>

Call* Call::_instance = NULL;

Call::Call() {
    callTable = new CALLTABLE();
}

Call* Call::instance() {
    if (_instance == 0) { _instance = new Call; }
    return _instance;
}

BOOLEAN Call::insertCall(const PROCNAME &n1, const PROCNAME &n2) {
	// check existance in the table
	PROCNAME matchedProc = this->getCaller(n2);
	if (matchedProc != "")  return false;		// n2 exist in the table

	// check if n1 exist in the table, insert n2 to n1's list
	PROCLIST* matchedList = this->getCallee(n1);
	if (matchedList != NULL) {
		matchedList->push_back(n2);
		return true;
	}

	// if n1 not exist in the table, create new call relationship
	PROCLIST* procList = new PROCLIST;
	procList->push_back(n2);
	CALLREL newCallRel(n1, procList);
    callTable->push_back(newCallRel);
    return true;
}

/*
 * a = "", b = "B" 
 * getCall(a, b), will return a which is b's caller
 * a = "A", b = "" 
 * getCall(a, b), will return b which is a's callee
 * return a vector for both single value or multiple values
 */
PROCLIST Call::getCallRel(const PROCNAME &n1, const PROCNAME &n2) {
	PROCLIST searchResult;
    if (n1 == "" && n2 != "") {
		PROCNAME matchedResult = this->getCaller(n2);
		if (matchedResult != "") {
			searchResult.push_back(matchedResult);
		}
    } else if (n1 != "" && n2 == "") {
		PROCLIST* matchedList = this->getCallee(n1);
		if (matchedList != NULL) {
			searchResult = *matchedList; 
		}
    }
	return searchResult;
}

PROCNAME Call::getCaller(const PROCNAME &n2) {
	for (int i = 0; i < callTable->size(); i++) {
		CALLREL callRel = callTable->at(i);
		PROCLIST* tempList = callRel.getY();
		for (int j = 0; j < tempList->size(); j++) {
			if (tempList->at(j) == n2) return callRel.getX();
		}
	}
	// if no matched result, return empty string
	return "";
}

PROCLIST* Call::getCallee(const PROCNAME &n1) {
	PROCLIST *searchResult = NULL;
	for (int i = 1; i <= callTable->size(); i++) {
		CALLREL callRel = callTable->at(i);
		if (callRel.getX() == n1) {
			searchResult = callRel.getY();
			return searchResult;
		}
	}
	// if no matched result, return empty list
	return searchResult;
}

SIZE Call::getCallTableSize() {
    return callTable->size();
}

CALLTABLE* Call::getCallTable() {
    return callTable;
}
