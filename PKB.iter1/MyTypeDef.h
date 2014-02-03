#ifndef MYTYPEDEF_H_INCLUDED
#define MYTYPEDEF_H_INCLUDED

#define NDEBUG

#include <string>
#include <vector>

/*
 * This header file include all the self define types
 *
 */

using namespace std;

namespace MYENUM {
    enum EXISTANCE {EXIST = -2, NOTEXIST = -3};
	enum STATUS {SUCCESS, FAILED, FINISHED, WAITING};
}

typedef int STATEMENT;          // statement number
typedef int SIZE;               // size of a container
typedef int INDEX;              // index number in the container
typedef bool BOOLEAN;           // boolean type 

// For var table
typedef string VARNAME;         // variable table name

// For procedure table
typedef string PROCNAME;        // procedure name

// For modify, follows, parents table
typedef int WHILESTMT;                  // while statement, <int> type
typedef int ASSIGNSTMT;                 // assignment statement, <int> type
typedef int CONSTANT;                   // constant number

typedef vector<WHILESTMT> WHILESTMTLIST;            // while statement list type
typedef vector<ASSIGNSTMT> ASSIGNSTMTLIST;          // assign statement list type
typedef vector<CONSTANT> CONSTANTLIST;              // constant list
typedef vector<STATEMENT> STMTLIST;                 // assign statement list type
typedef vector<STATEMENT> IFLIST;					// if statement list type

typedef vector<VARNAME> VARNAMETABLE;               // var name table type
typedef vector<PROCNAME> PROCNAMETABLE;				// procedure name table type

typedef vector<STMTLIST> PARENTTABLE;             // parent table stores STMTLIST
typedef vector<STMTLIST> PARENTSTARTABLE_C;       // for child 
typedef vector<STMTLIST> PARENTSTARTABLE_P;       // for parent

typedef vector<STATEMENT> FOLLOWTABLE;
typedef vector<STMTLIST> FOLLOWSTARTABLE_R;       // for follower
typedef vector<STMTLIST> FOLLOWSTARTABLE_E;       // for followee

typedef vector<VARNAME> USELIST;                  // for use list
typedef vector<USELIST> USESTABLE;                // for uses table

typedef vector<VARNAME> MODIFYLIST;               // for modify list
typedef vector<MODIFYLIST> MODIFIESTABLE;         // for modifies table

typedef vector<STMTLIST> FORMATEDLIST;            // formated list for follow star, parent star and parent return all situation

struct PATTERNELEMENT {
    STATEMENT s;
    VARNAME v;
};

typedef vector<PATTERNELEMENT> PATTERNS;

#endif
