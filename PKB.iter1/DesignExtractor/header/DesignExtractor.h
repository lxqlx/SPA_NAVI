#ifndef DESIGNEXTRACTOR_H_INCLUDED
#define DESIGNEXTRACTOR_H_INCLUDED

#include "../../MyTypeDef.h"

// include follow extractor header
#include "FollowExtractor.h"
// include parent extractor header
#include "ParentExtractor.h"
// include call extractor header
#include "CallExtractor.h"

#include <iostream>

using namespace std;

class DesignExtractor {
public:
    DesignExtractor();
    ~DesignExtractor();

    BOOLEAN extractPKBInfo();		// extract follow star relationship, call star rel and parent star relationship

private:

};
#endif