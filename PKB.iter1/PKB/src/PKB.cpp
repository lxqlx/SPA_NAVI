#include "../header/PKB.h"

PKB* PKB::_instance = NULL;

PKB::PKB() {
    whileStatementList = new WHILESTMTLIST;
    assignStatementList = new ASSIGNSTMTLIST;
    constantList = new CONSTANTLIST;
    statementList = new STMTLIST;
	ifList = new IFLIST;
}

PKB* PKB::instance() {
    if (_instance == 0) { _instance = new PKB; }
    return _instance;
}

/*
 * For variable table
 */
INDEX PKB::insertVariable(const VARNAME &v) {
    return Variable::instance()->insertVariable(v);
}

VARNAMETABLE PKB::VariableAll() {
    return *(this->getVarTable());
}

INDEX PKB::checkVariableIndex(const VARNAME &v) {
    return Variable::instance()->getVariableIndex(v);
}

/*
 * For follow table
 */
BOOLEAN PKB::insertFollow(const STATEMENT &s1, const STATEMENT &s2) {
    return Follow::instance()->insertFollow(s1, s2);
}

FORMATEDLIST PKB::FollowAll() {
    FORMATEDLIST resultList;
    for (int i = 1; i < this->getFollowTable()->size(); i++) {
        STATEMENT follower = this->getFollowTable()->at(i);
        STMTLIST newList;
        newList.push_back(i);
        newList.push_back(follower);
        resultList.push_back(newList);
    }
    return resultList;
}

STATEMENT PKB::Follow(STATEMENT &s1, STATEMENT &s2) {
    int size = statementList->size();
	cout<<"statement size:"<<size<<endl;
    if (s1 > size || s2 > size) {
        return -1;
    }
    return Follow::instance()->getFollow(s1, s2);
}

BOOLEAN PKB::FollowCheck(STATEMENT &s1, STATEMENT &s2) {
    int size = statementList->size();
    if (s1 > size || s2 > size) {
        return false;
    }

    if (Follow::instance()->getFollow(s1, s2) == MYENUM::EXIST) {
        return true;
    }

    return false;
}

FOLLOWSTARTABLE_R PKB::FollowStarFollwerTable() {
    return *(this->getFollowStarFollowerTable());
}

FOLLOWSTARTABLE_E PKB::FollowStarFollweeTable() {
    return *(this->getFollowStarFolloweeTable());
}

FORMATEDLIST PKB::FollowStarAll() {
    FORMATEDLIST resultList;
    for (int i = 1; i < this->getFollowStarFollowerTable()->size(); i++) {
        STMTLIST list = this->getFollowStarFollowerTable()->at(i);
        if (list.size() != 0) {
            for (STMTLIST::iterator it = list.begin(); it != list.end(); it++) {
                STMTLIST newList;
                newList.push_back(i);
                newList.push_back(*it);
                resultList.push_back(newList);
            }
        }
    }

    return resultList;
}

STMTLIST PKB::FollowStar(STATEMENT &s1, STATEMENT &s2) {
    int size = statementList->size();
    if (s1 > size || s2 > size) {
        STMTLIST empty;
        return empty;
    }

    if (s1 == -1 && s2 != -1) {
        STMTLIST resultList;
        FollowStar::instance()->getFollowStar(resultList, s2);
        return resultList;
    } else if (s1 != -1 && s2 == -1) {
        STMTLIST resultList;
        FollowStar::instance()->getFollowStar(s1, resultList);
        return resultList;
    }

    STMTLIST empty;
    return empty;
}

BOOLEAN PKB::FollowStarCheck(STATEMENT &s1, STATEMENT &s2) {
    return FollowStar::instance()->getFollowStar(s1, s2);
}

/*
 * For parent table
 */
BOOLEAN PKB::insertParent(const STATEMENT &s1, const STATEMENT &s2) {
    return Parent::instance()->insertParent(s1, s2);
}

PARENTTABLE PKB::ParentTableAll() {
    return *(this->getParentTable());
}

FORMATEDLIST PKB::ParentAll() {
    FORMATEDLIST resultList;
    for (int i = 1; i < this->getParentTable()->size(); i++) {
        STMTLIST list = this->getParentTable()->at(i);
        if (list.size() != 0) {
            for (STMTLIST::iterator it = list.begin(); it != list.end(); it++) {
                STMTLIST newList;
                newList.push_back(i);
                newList.push_back(*it);
                resultList.push_back(newList);
            }
        }
    }

    return resultList;
}

STATEMENT PKB::ParentForParent(const STATEMENT &s) {
    int size = statementList->size();
    if (s > size) {
        return -1;
    }
    return Parent::instance()->getParent(s);
}

STMTLIST PKB::ParentForChild(const STATEMENT &s) {
    int size = statementList->size();
    if (s > size) {
        STMTLIST empty;
        return empty;
    }
    return Parent::instance()->getChild(s);
}

BOOLEAN PKB::ParentCheck(const STATEMENT &s1, const STATEMENT &s2) {
    int size = statementList->size();
    if (s1 > size || s2 > size) {
        return false;
    }

    return Parent::instance()->getParent(s1, s2);
}

PARENTSTARTABLE_P PKB::ParentStarParentTable() {
    return *(this->getParentStarParentTable());
}

PARENTSTARTABLE_C PKB::ParentStarChildTable() {
    return *(this->getParentStarChildTable());
}

FORMATEDLIST PKB::ParentStarAll() {
    FORMATEDLIST resultList;
    for (int i = 1; i < this->getParentStarParentTable()->size(); i++) {
        STMTLIST list = this->getParentStarParentTable()->at(i);
        if (list.size() != 0) {
            for (STMTLIST::iterator it = list.begin(); it != list.end(); it++) {
                STMTLIST newList;
                newList.push_back(i);
                newList.push_back(*it);
                resultList.push_back(newList);
            }
        }
    }

    return resultList;
}

STMTLIST PKB::ParentStar(STATEMENT &s1, STATEMENT &s2) {
    int size = statementList->size();
    if (s1 > size || s2 > size) {
        STMTLIST empty;
        return empty;
    }

    if (s1 == -1 && s2 != -1) {
        STMTLIST resultList;
        ParentStar::instance()->getParentStar(resultList, s2);
        return resultList;
    } else if (s1 != -1 && s2 == -1) {
        STMTLIST resultList;
        ParentStar::instance()->getParentStar(s1, resultList);
        return resultList;
    }

    STMTLIST empty;
    return empty;
}

BOOLEAN PKB::ParentStarCheck(STATEMENT &s1, STATEMENT &s2) {
    return ParentStar::instance()->getParentStar(s1, s2);
}

/*
 * For modifies table
 */
BOOLEAN PKB::insertModifies(const STATEMENT &s, const VARNAME &v) {
    return Modifies::instance()->insertModifies(s, v);
}

MODIFIESTABLE PKB::ModifiesAll() {
    return *(this->getModifiesTable());
}

MODIFYLIST PKB::Modifies(const STATEMENT &s) {
    int size = statementList->size();
    if (s > size) {
        MODIFYLIST empty;
        return empty;
    }

    MODIFYLIST result = Modifies::instance()->getModifyList(s);
    return result;
}

STMTLIST PKB::Modifies(const VARNAME &v) {
    if (this->checkVariableIndex(v) == -1) {
        STMTLIST empty;
        return empty;
    }
    return Modifies::instance()->getStatementList(v);
}

BOOLEAN PKB::ModifiesCheck(const STATEMENT &s, const VARNAME &v) {
    int size = statementList->size();
    if ((s > size) || (this->checkVariableIndex(v) == -1)) {
        return false;
    }

    return Modifies::instance()->existModifies(s, v);
}

/*
 * For uses table
 */
BOOLEAN PKB::insertUses(const STATEMENT &s, const VARNAME &v) {
    return Uses::instance()->insertUses(s, v);
}

USESTABLE PKB::UsesAll() {
    return *(this->getUsesTable());
}

USELIST PKB::Uses(const STATEMENT &s) {
    int size = statementList->size();
    if (s > size) {
        USELIST empty;
        return empty;
    }

    USELIST result = Uses::instance()->getUseList(s);
    return result;
}

STMTLIST PKB::Uses(const VARNAME &v) {
    if (this->checkVariableIndex(v) == -1) {
        STMTLIST empty;
        return empty;
    }
    return Uses::instance()->getStatementList(v);
}

BOOLEAN PKB::UsesCheck(const STATEMENT &s, const VARNAME &v) {
    int size = statementList->size();
    if ((s > size) || (this->checkVariableIndex(v) == -1)) {
        return false;
    }

    return Uses::instance()->existUses(s, v);
}

/*
 * For pattern
 */
PATTERNS PKB::Pattern(const VARNAME &v1, const VARNAME &v2) {
    PATTERNS results;
    if (v1 == "" && v2 == "") {
        MODIFIESTABLE mTable = PKB::instance()->ModifiesAll();
        for (int i = 1; i < mTable.size(); i++) {
            if (mTable.at(i).size() != 0 && (this->checkAssignmenetStatementList(i) != -1)) {
                for (int j = 0; j < mTable.at(i).size(); j++) {
                    PATTERNELEMENT p;
                    p.s = i;
                    p.v = mTable.at(i).at(j);
                    if (!this->existPattern(results, p)) {
                        results.push_back(p);
                    }
                }
            }
        }

    } else if (v1 != "" && v2 == "") { 
        STMTLIST sList = PKB::instance()->Modifies(v1);
        for (int i = 0; i < sList.size(); i++) {
            if (this->checkAssignmenetStatementList(sList.at(i)) != -1) {
                PATTERNELEMENT p;
                p.s = sList.at(i);
                p.v = v1;
                if (!this->existPattern(results, p)) {
                    results.push_back(p);
                }
            }
        }
    } else if (v1 == "" && v2 != "") {
        STMTLIST sList = PKB::instance()->Uses(v2);
        cout << sList.size() << endl;
        for (int i = 0; i < sList.size(); i++) {
            cout << sList.at(i) << endl;
            if (this->checkAssignmenetStatementList(sList.at(i)) != -1) {
                MODIFYLIST mList = PKB::instance()->Modifies(sList.at(i));
                for (int j = 0; j < mList.size(); j++) {
                    PATTERNELEMENT p;
                    p.s = sList.at(i);
                    p.v = mList.at(j);
                    if (!this->existPattern(results, p)) {
                        results.push_back(p);
                    }
                }
            }
        }
    } else if (v1 != "" && v2 != "") {
        STMTLIST mList = PKB::instance()->Modifies(v1);
        STMTLIST uList = PKB::instance()->Uses(v2);
        for (int i = 0; i < uList.size(); i++) {
            for (int j = 0; j < mList.size(); j++) {
                if ((uList.at(i) == mList.at(j)) && (this->checkAssignmenetStatementList(uList.at(i)) != -1)) {
                    PATTERNELEMENT p;
                    p.s = uList.at(i);
                    p.v = mList.at(j);
                    if (!this->existPattern(results, p)) {
                        results.push_back(p);
                    }
                }
            }
        }

    }

    return results;
}

BOOLEAN PKB::existPattern(const PATTERNS &patterns, const PATTERNELEMENT &p) {

    for (int i = 0; i < patterns.size(); i++) {
        if ((patterns.at(i).s == p.s) && (patterns.at(i).v == p.v)) return true;
    }

    return false;
}

/*
 * For statement list
 */
void PKB::insertToStatementList(const STATEMENT &s) {
    if (this->checkStatementList(s) != -1) { return; }
    statementList->push_back(s);

    // increase table sizes
    Follow::instance()->verifyWithStmtListSize(s);
    Parent::instance()->verifyWithStmtListSize(s);
    Modifies::instance()->verifyWithStmtListSize(s);
    Uses::instance()->verifyWithStmtListSize(s);
    FollowStar::instance()->verifyWithStmtListSize(s);
    ParentStar::instance()->verifyWithStmtListSize(s);
}

INDEX PKB::checkStatementList(const STATEMENT &s) {
    for (STMTLIST::iterator it = statementList->begin(); it != statementList->end(); it++) {
        if (*it == s) { return it-statementList->begin(); }
    }
    return -1;
}

/*
 * For while list
 */
void PKB::insertToWhileStatementList(const STATEMENT &s) {
    if (this->checkWhileStatementList(s) != -1) { return; }
    whileStatementList->push_back(s);
}

INDEX PKB::checkWhileStatementList(const STATEMENT &s) {
    for (WHILESTMTLIST::iterator it = whileStatementList->begin(); it != whileStatementList->end(); it++) {
        if (*it == s) { return it-whileStatementList->begin(); }
    }
    return -1;
}

/*
 * For assignment list
 */
void PKB::insertToAssignmentStatementList(const STATEMENT &s) {
    if (this->checkAssignmenetStatementList(s) != -1) { return; }
    assignStatementList->push_back(s);
}

INDEX PKB::checkAssignmenetStatementList(const STATEMENT &s) {
    for (ASSIGNSTMTLIST::iterator it = assignStatementList->begin(); it != assignStatementList->end(); it++) {
        if (*it == s) { return it-assignStatementList->begin(); }
    }
    return -1;
}

/*
 * For constant list
 */
void PKB::insertToConstantList(const CONSTANT &c) {
    if (this->checkConstantList(c) != -1) { return; }
    constantList->push_back(c);
}

INDEX PKB::checkConstantList(const CONSTANT &c) {
    for (CONSTANTLIST::iterator it = constantList->begin(); it != constantList->end(); it++) {
        if (*it == c) { return it-constantList->begin(); }
    }
    return -1;
}

/*
 * for return requested lists
 */
WHILESTMTLIST PKB::getWhilwStatementList() {
    return *whileStatementList;
}

ASSIGNSTMTLIST PKB::getAssignmentStatementList() {
    return *assignStatementList;
}

CONSTANTLIST PKB::getConstantList() {
    return *constantList;
}

STMTLIST PKB::getStatementList() {
    return *statementList;
}

IFLIST PKB::getIfList() {
	return *ifList;
}

VARNAMETABLE* PKB::getVarTable() {
    return Variable::instance()->getAllVariables();
}

FOLLOWTABLE* PKB::getFollowTable() {
    return Follow::instance()->getFollowTable();
}

FOLLOWSTARTABLE_R* PKB::getFollowStarFollowerTable() {
    return FollowStar::instance()->getFollowStarTableForFollower();
}

FOLLOWSTARTABLE_E* PKB::getFollowStarFolloweeTable() {
    return FollowStar::instance()->getFollowStarTableForFollowee();
}

PARENTTABLE* PKB::getParentTable() {
    return Parent::instance()->getParentTable();
}

PARENTSTARTABLE_P* PKB::getParentStarParentTable() {
    return ParentStar::instance()->getParentStarTableForParent();
}

PARENTSTARTABLE_C* PKB::getParentStarChildTable() {
    return ParentStar::instance()->getParentStarTableForChild();
}

USESTABLE* PKB::getUsesTable() {
    return Uses::instance()->getUsesTable();
}

MODIFIESTABLE* PKB::getModifiesTable() {
    return Modifies::instance()->getModifiesTable();
}
