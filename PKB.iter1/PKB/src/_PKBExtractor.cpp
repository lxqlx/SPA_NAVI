#include "../header/_PKBExtractor.h"

PKBExtractor* PKBExtractor::_instance = NULL;

PKBExtractor::PKBExtractor() {
}

PKBExtractor* PKBExtractor::instance() {
    if (_instance == 0) { _instance = new PKBExtractor; }
    return _instance;
}

WHILESTMTLIST PKBExtractor::getWhileStatementList() {
	WHILESTMTLIST *whileList = WhileList::instance()->getAll();
    return *whileList;
}

ASSIGNSTMTLIST PKBExtractor::getAssignmentStatementList() {
	ASSIGNSTMTLIST *assignList = AssignList::instance()->getAll();
    return *assignList;
}

CONSTANTLIST PKBExtractor::getConstantList() {
	CONSTANTLIST *constList = ConstantList::instance()->getAll();
    return *constList;
}

STMTLIST PKBExtractor::getStatementList() {
	STMTLIST *statementList = StatementList::instance()->getAll();
    return *statementList;
}

IFLIST PKBExtractor::getIfList() {
	IFLIST *ifList = IfList::instance()->getAll();
	return *ifList;
}

/*
 * For variable table
 */
VARNAMETABLE PKBExtractor::getVariableTable() {
     VARNAMETABLE *varTable = Variable::instance()->getAllVariables();
	 return *varTable;
}

INDEX PKBExtractor::checkVariableIndex(const VARNAME &v) {
    return Variable::instance()->getVariableIndex(v);
}

/*
 * For follow table
 */
FORMATEDLIST PKBExtractor::FollowAll() {
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

STATEMENT PKBExtractor::Follow(STATEMENT &s1, STATEMENT &s2) {
    int size = StatementList::instance()->getSize();
    if (s1 > size || s2 > size) {
        return -1;
    }
    return Follow::instance()->getFollow(s1, s2);
}

BOOLEAN PKBExtractor::FollowCheck(STATEMENT &s1, STATEMENT &s2) {
    int size = StatementList::instance()->getSize();
    if (s1 > size || s2 > size) {
        return false;
    }

    if (Follow::instance()->getFollow(s1, s2) == MYENUM::EXIST) {
        return true;
    }

    return false;
}

FORMATEDLIST PKBExtractor::FollowStarAll() {
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

STMTLIST PKBExtractor::FollowStar(STATEMENT &s1, STATEMENT &s2) {
    int size = StatementList::instance()->getSize();
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

BOOLEAN PKBExtractor::FollowStarCheck(STATEMENT &s1, STATEMENT &s2) {
    return FollowStar::instance()->getFollowStar(s1, s2);
}

/*
 * For parent table
 */
FORMATEDLIST PKBExtractor::ParentAll() {
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

STATEMENT PKBExtractor::ParentForParent(const STATEMENT &s) {
    int size = StatementList::instance()->getSize();
    if (s > size) {
        return -1;
    }
    return Parent::instance()->getParent(s);
}

STMTLIST PKBExtractor::ParentForChild(const STATEMENT &s) {
    int size = StatementList::instance()->getSize();
    if (s > size) {
        STMTLIST empty;
        return empty;
    }
    return Parent::instance()->getChild(s);
}

BOOLEAN PKBExtractor::ParentCheck(const STATEMENT &s1, const STATEMENT &s2) {
    int size = StatementList::instance()->getSize();
    if (s1 > size || s2 > size) {
        return false;
    }

    return Parent::instance()->getParent(s1, s2);
}

FORMATEDLIST PKBExtractor::ParentStarAll() {
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

STMTLIST PKBExtractor::ParentStar(STATEMENT &s1, STATEMENT &s2) {
    int size = StatementList::instance()->getSize();
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

BOOLEAN PKBExtractor::ParentStarCheck(STATEMENT &s1, STATEMENT &s2) {
    return ParentStar::instance()->getParentStar(s1, s2);
}

/*
 * For modifies table
 */
MODIFIESTABLE PKBExtractor::ModifiesAll() {
    return *(this->getModifiesTable());
}

MODIFYLIST PKBExtractor::Modifies(const STATEMENT &s) {
    int size = StatementList::instance()->getSize();
    if (s > size) {
        MODIFYLIST empty;
        return empty;
    }

    MODIFYLIST result = Modifies::instance()->getModifyList(s);
    return result;
}

STMTLIST PKBExtractor::Modifies(const VARNAME &v) {
    if (this->checkVariableIndex(v) == -1) {
        STMTLIST empty;
        return empty;
    }
    return Modifies::instance()->getStatementList(v);
}

BOOLEAN PKBExtractor::ModifiesCheck(const STATEMENT &s, const VARNAME &v) {
    int size = StatementList::instance()->getSize();
    if ((s > size) || (this->checkVariableIndex(v) == -1)) {
        return false;
    }

    return Modifies::instance()->existModifies(s, v);
}

/*
 * For uses table
 */
USESTABLE PKBExtractor::UsesAll() {
    return *(this->getUsesTable());
}

USELIST PKBExtractor::Uses(const STATEMENT &s) {
    int size = StatementList::instance()->getSize();
    if (s > size) {
        USELIST empty;
        return empty;
    }

    USELIST result = Uses::instance()->getUseList(s);
    return result;
}

STMTLIST PKBExtractor::Uses(const VARNAME &v) {
    if (this->checkVariableIndex(v) == -1) {
        STMTLIST empty;
        return empty;
    }
    return Uses::instance()->getStatementList(v);
}

BOOLEAN PKBExtractor::UsesCheck(const STATEMENT &s, const VARNAME &v) {
    int size = StatementList::instance()->getSize();
    if ((s > size) || (this->checkVariableIndex(v) == -1)) {
        return false;
    }

    return Uses::instance()->existUses(s, v);
}

/*
 * For pattern
 */
PATTERNS PKBExtractor::Pattern(const VARNAME &v1, const VARNAME &v2) {
    PATTERNS results;
    if (v1 == "" && v2 == "") {
        MODIFIESTABLE mTable = this->ModifiesAll();
        for (int i = 1; i < mTable.size(); i++) {
            if (mTable.at(i).size() != 0 && (AssignList::instance()->getIdx(i) != -1)) {
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
        STMTLIST sList = this->Modifies(v1);
        for (int i = 0; i < sList.size(); i++) {
            if (AssignList::instance()->getIdx(sList.at(i)) != -1) {
                PATTERNELEMENT p;
                p.s = sList.at(i);
                p.v = v1;
                if (!this->existPattern(results, p)) {
                    results.push_back(p);
                }
            }
        }
    } else if (v1 == "" && v2 != "") {
        STMTLIST sList = this->Uses(v2);
        cout << sList.size() << endl;
        for (int i = 0; i < sList.size(); i++) {
            cout << sList.at(i) << endl;
            if (AssignList::instance()->getIdx(sList.at(i)) != -1) {
                MODIFYLIST mList = this->Modifies(sList.at(i));
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
        STMTLIST mList = this->Modifies(v1);
        STMTLIST uList = this->Uses(v2);
        for (int i = 0; i < uList.size(); i++) {
            for (int j = 0; j < mList.size(); j++) {
                if ((uList.at(i) == mList.at(j)) && (AssignList::instance()->getIdx(uList.at(i)) != -1)) {
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

BOOLEAN PKBExtractor::existPattern(const PATTERNS &patterns, const PATTERNELEMENT &p) {

    for (int i = 0; i < patterns.size(); i++) {
        if ((patterns.at(i).s == p.s) && (patterns.at(i).v == p.v)) return true;
    }

    return false;
}

/*
* getting tables
*/
VARNAMETABLE* PKBExtractor::getVarTable() {
    return Variable::instance()->getAllVariables();
}

FOLLOWTABLE* PKBExtractor::getFollowTable() {
    return Follow::instance()->getFollowTable();
}

FOLLOWSTARTABLE_R* PKBExtractor::getFollowStarFollowerTable() {
    return FollowStar::instance()->getFollowStarTableForFollower();
}

FOLLOWSTARTABLE_E* PKBExtractor::getFollowStarFolloweeTable() {
    return FollowStar::instance()->getFollowStarTableForFollowee();
}

PARENTTABLE* PKBExtractor::getParentTable() {
    return Parent::instance()->getParentTable();
}

PARENTSTARTABLE_P* PKBExtractor::getParentStarParentTable() {
    return ParentStar::instance()->getParentStarTableForParent();
}

PARENTSTARTABLE_C* PKBExtractor::getParentStarChildTable() {
    return ParentStar::instance()->getParentStarTableForChild();
}

USESTABLE* PKBExtractor::getUsesTable() {
    return Uses::instance()->getUsesTable();
}

MODIFIESTABLE* PKBExtractor::getModifiesTable() {
    return Modifies::instance()->getModifiesTable();
}