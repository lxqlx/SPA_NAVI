#include "FollowExtractor.h"

FollowExtractor* FollowExtractor::_instance = NULL;

FollowExtractor::FollowExtractor() {
}

FollowExtractor* FollowExtractor::instance() {
    if (_instance == 0) { _instance = new FollowExtractor; }
    return _instance;
}

/*
 * Build follow star table
 * This method assume that follow table is finished creating
 * The method will import data from follow table and generate
 * follow star table.
 * note that : follow star table include follow star follower table
 * and follow star followee table
 */
BOOLEAN FollowExtractor::buildFollowStarTable() {

    // get follow table
    FOLLOWTABLE *followTable = Follow::instance()->getFollowTable();

    SIZE followTableSize = Follow::instance()->getFollowTableSize();        // ignore dummy 

    // generate follow star table for follow relatioinship
    // table format [statement number, followee list]
    //
    for (int i = 1; i <= followTableSize; i++) {
        STATEMENT s1 = followTable->at(i);          // find s1's all followee
        if (s1 == -1) continue;
        STATEMENT s2 = i;
        FollowStar::instance()->insertFollowStarFollowee(s1, s2);
        STATEMENT s = s2;       // temp s to be new follower
        for (int j = 1; j <= followTableSize; j++) {
            if (followTable->at(j) == s) {
                s2 = j; // assign followee to s2
                FollowStar::instance()->insertFollowStarFollowee(s1, s2);
                s = s2;
                j = -1;     // restart from beginning
            }

        }
    }

    // generate follow star table for follower relatioinship
    // table format [statement number, follower list]
    for (int i = 1; i <= followTableSize; i++) {
        STATEMENT s2 = followTable->at(i);
        if (s2 == -1) continue;
        STATEMENT s1 = i;       // find s1's all follower
        FollowStar::instance()->insertFollowStarFollower(s1, s2);
        STATEMENT s = s2;       // s to be followee
        for (int j = 1; j <= followTableSize; j++) {
            if (j == s) {
                s2 = followTable->at(s);
                if (s2 == -1) break;
                FollowStar::instance()->insertFollowStarFollower(s1, s2);
                s = s2;
                j = -1;     // restart from beginning
            }

        }
    }

    return true;
}
