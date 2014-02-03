#ifndef PKB_H_INCLUDED
#define PKB_H_INCLUDED

#include <iostream>
#include <vector>

#include "../../MyTypeDef.h"
#include "Follow.h"
#include "FollowStar.h"
#include "Parent.h"
#include "ParentStar.h"
#include "Variable.h"
#include "Modifies.h"
#include "Uses.h"

using namespace std;

class PKB {

public:
    PKB();
    ~PKB();

    static PKB* instance();

    // ****************************8
    // * for fangzhou, AST, parser
    // ****************************8
    INDEX insertVariable(const VARNAME &);
    BOOLEAN insertFollow(const STATEMENT &, const STATEMENT &);
    BOOLEAN insertParent(const STATEMENT &, const STATEMENT &);
    BOOLEAN insertModifies(const STATEMENT &, const VARNAME &);
    BOOLEAN insertUses(const STATEMENT &, const VARNAME &);

    // APIs for statement list
    void insertToStatementList(const STATEMENT &);
    INDEX checkStatementList(const STATEMENT &);                // if not found return -1

    // APIs for while list
    void insertToWhileStatementList(const STATEMENT &);
    INDEX checkWhileStatementList(const STATEMENT &);           // if not found return -1

    // APIs for assignment list
    void insertToAssignmentStatementList(const STATEMENT &);
    INDEX checkAssignmenetStatementList(const STATEMENT &);     // if not found return -1

    // APIs for constant list
    void insertToConstantList(const CONSTANT &);
    INDEX checkConstantList(const CONSTANT &);                  // if not found return -1

	// APIs for if list

    // *********************************************8
    // * for zhoubin and xiangqun, query evaluator
    // *********************************************8

    // for lists
    WHILESTMTLIST getWhilwStatementList();
    ASSIGNSTMTLIST getAssignmentStatementList();
    CONSTANTLIST getConstantList();
    STMTLIST getStatementList();
	IFLIST getIfList();

    // APIs for variable table
    VARNAMETABLE VariableAll();
    INDEX checkVariableIndex(const VARNAME &);

    // APIs for follow table
    FORMATEDLIST FollowAll();                            // case 1
    STATEMENT Follow(STATEMENT &, STATEMENT &);         // case 2, 3
    BOOLEAN FollowCheck(STATEMENT &, STATEMENT &);      // case 4

    FORMATEDLIST FollowStarAll();                       // case 1
    STMTLIST FollowStar(STATEMENT &, STATEMENT &);      // case 2, 3
    BOOLEAN FollowStarCheck(STATEMENT &, STATEMENT &);  // case 4

    // APIs for parent table
    FORMATEDLIST ParentAll();                            // case 1
    STATEMENT ParentForParent(const STATEMENT &);                    // case 2
    STMTLIST ParentForChild(const STATEMENT &);                      // case 3
    BOOLEAN ParentCheck(const STATEMENT &, const STATEMENT &);       // case 4

    FORMATEDLIST ParentStarAll();                            // case 1
    STMTLIST ParentStar(STATEMENT &, STATEMENT &);      // case 2, 3
    BOOLEAN ParentStarCheck(STATEMENT &, STATEMENT &);  // case 4

    // APIs for modify table
    MODIFIESTABLE ModifiesAll();                        // case 1
    MODIFYLIST Modifies(const STATEMENT &);             // case 2
    STMTLIST Modifies(const VARNAME &);                 // case 3
    BOOLEAN ModifiesCheck(const STATEMENT &, const VARNAME &);      // case 4

    // APIs for use table
    USESTABLE UsesAll();                                // case 1
    USELIST Uses(const STATEMENT &);                    // case 2
    STMTLIST Uses(const VARNAME &);                     // case 3
    BOOLEAN UsesCheck(const STATEMENT &, const VARNAME &);          // case 4

    // APIs for pattern
    PATTERNS Pattern(const VARNAME &, const VARNAME &);
    BOOLEAN existPattern(const PATTERNS &, const PATTERNELEMENT &);

    // --------------------------------------------------------------
    // Ignore following API, they are for testing
    PARENTTABLE ParentTableAll();                   
    FOLLOWSTARTABLE_R FollowStarFollwerTable();         
    FOLLOWSTARTABLE_E FollowStarFollweeTable();     
    PARENTSTARTABLE_P ParentStarParentTable();          
    PARENTSTARTABLE_C ParentStarChildTable();       

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
    static PKB* _instance;

    WHILESTMTLIST* whileStatementList;      // while statement list
    ASSIGNSTMTLIST* assignStatementList;    // assign statement list
    CONSTANTLIST* constantList;             // constant list
    STMTLIST* statementList;                // statement list
	IFLIST* ifList;							// if list
};
#endif
