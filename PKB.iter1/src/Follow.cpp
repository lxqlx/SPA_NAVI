#include "Follow.h"
#include <cmath>

Follow* Follow::_instance = NULL;

Follow::Follow() {
    followTable = new FOLLOWTABLE();
    STATEMENT dummy = -1;
    followTable->push_back(dummy);     // fill index 0 in follow table
}

Follow* Follow::instance() {
    if (_instance == 0) { _instance = new Follow; }
    return _instance;
}

BOOLEAN Follow::insertFollow(const STATEMENT &s1, const STATEMENT &s2) {
    // if follow table size if not large enough
    int maxSize = max(s1, s2);
    this->verifyWithStmtListSize(maxSize);

    // check statement list size

    followTable->at(s1) = s2;

    return true;
}

/*
 * This is to make sure the size of the Follow relation ship is the 
 * same as the max statement number
 */
BOOLEAN Follow::verifyWithStmtListSize(const STATEMENT &s) {
    if (followTable->size() - 1 < s) {
        int size = s - followTable->size() + 1;
        for (int i = 0; i < size; i++) {
            STATEMENT dummy = -1;
            followTable->push_back(dummy);
        }
    }
    return true;
}

/*
 * a = -1, b = 2
 * getFollow(a, b), will return a which is b's followee
 * a = 2, b = -1
 * getFollow(a, b), will return b which is a's follower
 */
STATEMENT Follow::getFollow(STATEMENT &s1, STATEMENT &s2) {
    if (s1 == -1 && s2 != -1) {
		//cout<<"I am here....................."<<endl;
		//cout<<"size: "<<followTable->size()<<endl;
        for (int i = 1; i <= followTable->size() - 1; i++) {
			//cout<<"doing looping: "<<i<<"+"<<followTable->at(i)<<endl;
            if (followTable->at(i) == s2) {
				//cout<<"in the:"<<i<<endl;
                //s1 = i;
                //break;
                return i;
            }
        }
	//cout<<"I am finishing....................."<<endl;
    } else if (s1 != -1 && s2 == -1) {
        //s2 = followTable->at(s1);
        return followTable->at(s1);
    } else if (s1 != -1 && s2 != -1) {
        if (followTable->at(s1) == s2) {
            return MYENUM::EXIST;
        }
        return MYENUM::NOTEXIST;
    } else {
        // if s1 == -1 and s2 == -1
        // get this table from evaluator 
        // and get all relationship in the table
    }
    return -1;
}

SIZE Follow::getFollowTableSize() {
    return followTable->size() - 1;
}

FOLLOWTABLE* Follow::getFollowTable() {
    return followTable;
}
