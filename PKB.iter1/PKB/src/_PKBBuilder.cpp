#include "../header/_PKBBuilder.h"

PKBBuilder* PKBBuilder::_instance = NULL;

PKBBuilder::PKBBuilder() {
}

PKBBuilder* PKBBuilder::instance() {
    if (_instance == 0) { _instance = new PKBBuilder; }
    return _instance;
}

/*
 * For variable table
 */
INDEX PKBBuilder::insertVariable(const VARNAME &v) {
    return Variable::instance()->insertVariable(v);
}

/*
 * For procedure table
 */
INDEX PKBBuilder::insertProcedure( const PROCNAME &p ) {
	return Procedure::instance()->insertProcname(p);
}

/*
 * For follow table
 */
BOOLEAN PKBBuilder::insertFollow(const STATEMENT &s1, const STATEMENT &s2) {
    return Follow::instance()->insertFollow(s1, s2);
}

/*
 * For parent table
 */
BOOLEAN PKBBuilder::insertParent(const STATEMENT &s1, const STATEMENT &s2) {
    return Parent::instance()->insertParent(s1, s2);
}

/*
 * For modifies table
 */
BOOLEAN PKBBuilder::insertModifies(const STATEMENT &s, const VARNAME &v) {
    return Modifies::instance()->insertModifies(s, v);
}

/*
 * For uses table
 */
BOOLEAN PKBBuilder::insertUses(const STATEMENT &s, const VARNAME &v) {
    return Uses::instance()->insertUses(s, v);
}

/*
 * For call table
 */
BOOLEAN PKBBuilder::insertCall(const PROCNAME &s, const PROCNAME &v) {
    return Call::instance()->insertCall(s, v);
}

/*
 * For statement list
 */
void PKBBuilder::insertToStatementList(const STATEMENT &s) {
    if (this->checkStatementList(s) != -1) { return; }
	StatementList::instance()->insert(s);

	//
    // increase table sizes, required for insertion during parsing process
    Follow::instance()->verifyWithStmtListSize(s);
    Parent::instance()->verifyWithStmtListSize(s);
    Modifies::instance()->verifyWithStmtListSize(s);
    Uses::instance()->verifyWithStmtListSize(s);
    FollowStar::instance()->verifyWithStmtListSize(s);
    ParentStar::instance()->verifyWithStmtListSize(s);
}

INDEX PKBBuilder::checkStatement(const STATEMENT &s) {
	return StatementList::instance()->getIdx(s);
}

/*
 * For while list
 */
void PKBBuilder::insertToWhileStatementList(const STATEMENT &s) {
    if (this->checkWhileStatementList(s) != -1) { return; }
	WhileList::instance()->insert(s);
}

INDEX PKBBuilder::checkWhileStatement(const STATEMENT &s) {
    return WhileList::instance()->getIdx(s);
}

/*
 * For assignment list
 */
void PKBBuilder::insertToAssignmentStatementList(const STATEMENT &s) {
    if (this->checkAssignmenetStatementList(s) != -1) { return; }
    AssignList::instance()->insert(s);
}

INDEX PKBBuilder::checkAssignmenetStatement(const STATEMENT &s) {
    return AssignList::instance()->getIdx(s);
}

/*
 * For constant list
 */
void PKBBuilder::insertToConstantList(const CONSTANT &c) {
    if (this->checkConstantList(c) != -1) { return; }
	ConstantList::instance()->insert(c);
}

INDEX PKBBuilder::checkConstant(const CONSTANT &c) {
    return ConstantList::instance()->getIdx(c);
}

/*
 * For if list
 */
void PKBBuilder::insertToIfList(const STATEMENT &s) {
    if (this->checkIfList(s) != -1) { return; }
	IfList::instance()->insert(s);
}

INDEX PKBBuilder::checkIfStatement(const STATEMENT &s) {
    return IfList::instance()->getIdx(s);
}