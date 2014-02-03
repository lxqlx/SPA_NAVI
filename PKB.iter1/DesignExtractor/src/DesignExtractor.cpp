#include "../header/DesignExtractor.h"

DesignExtractor::DesignExtractor() {
}

/* 
 * Extract follow star relationship and parent star relationship
 */
BOOLEAN DesignExtractor::extractPKBInfo() {
    if(!FollowExtractor::instance()->buildFollowStarTable()) {
		return false;
	}

    if(!ParentExtractor::instance()->buildParentStarTable()) {
		return false;
	}

	return true;
}