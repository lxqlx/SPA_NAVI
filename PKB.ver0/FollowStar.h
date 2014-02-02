#ifndef FOLLOWSTAR_H_INCLUDED
#define FOLLOWSTAR_H_INCLUDED

#include "MyTypeDef.h"
#include <iostream>

using namespace std;

class FollowStar {

public:
    FollowStar();
    ~FollowStar();

    BOOLEAN insertFollowStarFollowee(const STATEMENT &, const STATEMENT &);
    BOOLEAN insertFollowStarFollower(const STATEMENT &, const STATEMENT &);
    void getFollowStar(STMTLIST &, STATEMENT &);
    void getFollowStar(STATEMENT &, STMTLIST &);
    BOOLEAN getFollowStar(const STATEMENT &, const STATEMENT &);
    BOOLEAN verifyWithStmtListSize(const STATEMENT &);

    FOLLOWSTARTABLE_R* getFollowStarTableForFollower();
    FOLLOWSTARTABLE_E* getFollowStarTableForFollowee();

    static FollowStar* instance();

protected:
    BOOLEAN getFollowStarForFollowerTable(const STATEMENT &, const STATEMENT &);
    BOOLEAN getFollowStarForFolloweeTable(const STATEMENT &, const STATEMENT &);

private:
    FOLLOWSTARTABLE_R *followStarTableForFollower;
    FOLLOWSTARTABLE_E *followStarTableForFollowee;

    static FollowStar* _instance;

};
#endif
