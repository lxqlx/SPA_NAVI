#include "../header/List.h"

List::List() {
    statementList = new STMTLIST;
}

INDEX List::insert(const STATEMENT &s) {
    if (this->getIdx(s) != -1) {
        return this->getIdx(s);
    }

    statementList->push_back(s);

    return this->get(s);
}

SIZE List::getSize() {
    return statementList->size();
}

STATEMENT List::get(const INDEX &i) {
	if (i >= this->getSize()) {
		return -1;
	}
    return statementList->at(i);
}

INDEX List::getIdx(const STATEMENT &s) {
	for (int i = 0; i < this->getSize(); i++) {
		if (statementList->at(i) == s) {
			return i;
		}
	}
    return -1;
}

STMTLIST* List::getAll() {
    return statementList;
}
