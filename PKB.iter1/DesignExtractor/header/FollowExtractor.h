#ifndef FOLLOWEXTRACTOR_H_INCLUDED
#define FOLLOWEXTRACTOR_H_INCLUDED

#include "../../MyTypeDef.h"

// include follow header
#include "../../PKB/header/Follow.h"

// include follow star header
#include "../../PKB/header/FollowStar.h"

#include <iostream>

using namespace std;

class FollowExtractor {
public:
    FollowExtractor();
    ~FollowExtractor();

    BOOLEAN buildFollowStarTable();

    static FollowExtractor* instance();

private:

    static FollowExtractor* _instance;

};
#endif
