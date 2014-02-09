#ifndef PKBBUILDER_H_INCLUDED
#define PKBBUILDER_H_INCLUDED

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

class PKBBuilder {

public:
    PKBBuilder();
    ~PKBBuilder();

    static PKBBuilder* instance();

    INDEX insertVariable(const VARNAME &);
    INDEX insertProcedure(const PROCNAME &);
    BOOLEAN insertFollow(const STATEMENT &, const STATEMENT &);
    BOOLEAN insertParent(const STATEMENT &, const STATEMENT &);
    BOOLEAN insertModifies(const STATEMENT &, const VARNAME &);
    BOOLEAN insertUses(const STATEMENT &, const VARNAME &);
    BOOLEAN insertCall(const PROCNAME &, const PROCNAME &);

    // APIs for statement list
    void insertToStatementList(const STATEMENT &);
    INDEX checkStatement(const STATEMENT &);                       // if not found return -1

    // APIs for while list
    void insertToWhileStatementList(const STATEMENT &);
    INDEX checkWhileStatement(const STATEMENT &);               // if not found return -1

    // APIs for assignment list
    void insertToAssignmentStatementList(const STATEMENT &);
    INDEX checkAssignmenetStatement(const STATEMENT &);     // if not found return -1

    // APIs for constant list
    void insertToConstantList(const CONSTANT &);
    INDEX checkConstant(const CONSTANT &);							// if not found return -1

	// APIs for if list
    void insertToIfList(const CONSTANT &);
    INDEX checkIfStatement(const CONSTANT &);						// if not found return -1


private:
    static PKBBuilder* _instance;
};
#endif