#include "FollowStar.h"
#include <cmath>

FollowStar* FollowStar::_instance = NULL;

FollowStar::FollowStar() {
    followStarTableForFollower = new FOLLOWSTARTABLE_R();
    STMTLIST dummy1;
    followStarTableForFollower->push_back(dummy1);       // fill index 0 in follow star table for Follower

    followStarTableForFollowee = new FOLLOWSTARTABLE_E();
    STMTLIST dummy2;
    followStarTableForFollowee->push_back(dummy2);      // fill index 0 in follow star table for followee
}

FollowStar* FollowStar::instance() {
    if (_instance == 0) { _instance = new FollowStar; }
    return _instance;
}

/*
 * Followee list
 * s1 is statement, s1 is s2's follower
 * s1 is follower
 * s2 is followee
 */
BOOLEAN FollowStar::insertFollowStarFollowee(const STATEMENT &s1, const STATEMENT &s2) {
    int maxSize = max(s1, s2);
    this->verifyWithStmtListSize(maxSize);

    if (!this->getFollowStarForFolloweeTable(s1, s2)) {
        followStarTableForFollowee->at(s1).push_back(s2);
    }
    return true;
}

/*
 * Follower list
 * s1 is statement, s2 is s1's follower
 * s1 is followee
 * s2 is follower
 */
BOOLEAN FollowStar::insertFollowStarFollower(const STATEMENT &s1, const STATEMENT &s2) {
    int maxSize = max(s1, s2);
    this->verifyWithStmtListSize(maxSize);

    if (!this->getFollowStarForFollowerTable(s1, s2)) {
        followStarTableForFollower->at(s1).push_back(s2);
    }
    return true;
}

BOOLEAN FollowStar::verifyWithStmtListSize(const STATEMENT &s) {
    if (followStarTableForFollowee->size() - 1 < s) {
        int size = s - followStarTableForFollowee->size() + 1;
        for (int i = 0; i < size; i++) {
            STMTLIST dummy;
            followStarTableForFollowee->push_back(dummy);
        }
    }

    if (followStarTableForFollower->size() - 1 < s) {
        int size = s - followStarTableForFollower->size() + 1;
        for (int i = 0; i < size; i++) {
            STMTLIST dummy;
            followStarTableForFollower->push_back(dummy);
        }
    }
    return true;
}

void FollowStar::getFollowStar(STMTLIST &sl, STATEMENT &s) {
    int size = followStarTableForFollowee->size(); 
    if (s >= size) {
        cout << "Second parameter s is out of range : " << s << endl;
        STMTLIST empty;
        sl = empty;
        return;
    }
    sl = followStarTableForFollowee->at(s);
}

void FollowStar::getFollowStar(STATEMENT &s, STMTLIST &sl) {
    int size = followStarTableForFollower->size();
    if (s >= size) {
        cout << "First parameter s is out of range : " << s << endl;
        STMTLIST empty;
        sl = empty;
        return;
    }
    sl = followStarTableForFollower->at(s);
}

BOOLEAN FollowStar::getFollowStar(const STATEMENT &s1, const STATEMENT &s2) {
    // return all the relation ship in the follow star table
    // should retreive in evaluator
    return this->getFollowStarForFollowerTable(s1, s2);
}

BOOLEAN FollowStar::getFollowStarForFollowerTable(const STATEMENT &s1, const STATEMENT &s2) {
    STMTLIST list = followStarTableForFollower->at(s1);
    for (STMTLIST::iterator it = list.begin(); it != list.end(); it++) {
        if (*it == s2) {
            return true;
        }
    }
    return false;
}

BOOLEAN FollowStar::getFollowStarForFolloweeTable(const STATEMENT &s1, const STATEMENT &s2) {
    STMTLIST list = followStarTableForFollowee->at(s1);
    for (STMTLIST::iterator it = list.begin(); it != list.end(); it++) {
        if (*it == s2) {
            return true;
        }
    }
    return false;
}

FOLLOWSTARTABLE_R* FollowStar::getFollowStarTableForFollower() {
    return followStarTableForFollower;
}

FOLLOWSTARTABLE_E* FollowStar::getFollowStarTableForFollowee() {
    return followStarTableForFollowee;
}
