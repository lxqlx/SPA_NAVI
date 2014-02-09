#include "../header/DesignExtractor.h"

DesignExtractor::DesignExtractor() {
}

/* 
 * Extract follow star relationship, call star rel and parent star relationship
 */
BOOLEAN DesignExtractor::extractPKBInfo() {
    if(!FollowExtractor::instance()->buildFollowStarTable()) {
		return false;
	}

    if(!ParentExtractor::instance()->buildParentStarTable()) {
		return false;
	}

    if(!CallExtractor::instance()->buildCallStarTable()) {
		return false;
	}

	return true;
}