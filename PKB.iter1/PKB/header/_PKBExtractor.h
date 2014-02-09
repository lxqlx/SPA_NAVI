#ifndef PKBEXTRACTOR_H_INCLUDED
#define PKBEXTRACTOR_H_INCLUDED

#include <iostream>
#include <vector>

#include "../../MyTypeDef.h"
#include "Follow.h"
#include "Parent.h"
#include "Variable.h"
#include "Procedure.h"
#include "Modifies.h"
#include "Uses.h"
#include "Call.h"

#include "FollowStar.h"
#include "ParentStar.h"

#include "AssignList.h"
#include "StatementList.h"
#include "WhileList.h"
#include "IfList.h"
#include "ConstantList.h"

using namespace std;

class PKBExtractor {

public:
    PKBExtractor();
    ~PKBExtractor();

    static PKBExtractor* instance();

    // *********************************************
    // * for zhoubin and xiangqun, query evaluator
    // *********************************************

    // getting lists
    WHILESTMTLIST getWhileStatementList();
    ASSIGNSTMTLIST getAssignmentStatementList();
    CONSTANTLIST getConstantList();
    STMTLIST getStatementList();
	IFLIST getIfList();

    // APIs for variable table
    VARNAMETABLE getVariableTable();
    INDEX checkVariableIndex(const VARNAME &);

    // APIs for follow table
    FORMATEDLIST FollowAll();																	// case 1
    STATEMENT Follow(STATEMENT &, STATEMENT &);								// case 2, 3
    BOOLEAN FollowCheck(STATEMENT &, STATEMENT &);							// case 4

    FORMATEDLIST FollowStarAll();															// case 1
    STMTLIST FollowStar(STATEMENT &, STATEMENT &);							// case 2, 3
    BOOLEAN FollowStarCheck(STATEMENT &, STATEMENT &);						// case 4

    // APIs for parent table
    FORMATEDLIST ParentAll();																	// case 1
    STATEMENT ParentForParent(const STATEMENT &);								// case 2
    STMTLIST ParentForChild(const STATEMENT &);									// case 3
    BOOLEAN ParentCheck(const STATEMENT &, const STATEMENT &);			// case 4

    FORMATEDLIST ParentStarAll();														// case 1
    STMTLIST ParentStar(STATEMENT &, STATEMENT &);						// case 2, 3
    BOOLEAN ParentStarCheck(STATEMENT &, STATEMENT &);				// case 4

    // APIs for modify table
    MODIFIESTABLE ModifiesAll();															// case 1
    MODIFYLIST Modifies(const STATEMENT &);										// case 2
    STMTLIST Modifies(const VARNAME &);												// case 3
    BOOLEAN ModifiesCheck(const STATEMENT &, const VARNAME &);      // case 4

    // APIs for use table
    USESTABLE UsesAll();																		// case 1
    USELIST Uses(const STATEMENT &);													// case 2
    STMTLIST Uses(const VARNAME &);													// case 3
    BOOLEAN UsesCheck(const STATEMENT &, const VARNAME &);           // case 4

    // APIs for pattern
    PATTERNS Pattern(const VARNAME &, const VARNAME &);
    BOOLEAN existPattern(const PATTERNS &, const PATTERNELEMENT &);

protected:
    // for tables
    VARNAMETABLE* getVarTable();
    FOLLOWTABLE* getFollowTable();
    FOLLOWSTARTABLE_R* getFollowStarFollowerTable();
    FOLLOWSTARTABLE_E* getFollowStarFolloweeTable();
    PARENTTABLE* getParentTable();
    PARENTSTARTABLE_P* getParentStarParentTable();
    PARENTSTARTABLE_C* getParentStarChildTable();
    USESTABLE* getUsesTable();
    MODIFIESTABLE* getModifiesTable();

private:
    static PKBExtractor* _instance;
};
#endif