#include "../header/DesignExtractor.h"

DesignExtractor::DesignExtractor() {
	status = STATUS.WAITING;
}

/* 
 * Extract follow star relationship and parent star relationship
 */
BOOLEAN DesignExtractor::extractPKBInfo() {
	if (status != STATUS.WAITING) {
		return false;
	}

    if(!FollowExtractor::instance()->buildFollowStarTable()) {
		return false;
	}

    if(!ParentExtractor::instance()->buildParentStarTable()) {
		return false;
	}

	return true;
}

//************************************
// Method:    setFinishedParsingSignal
// FullName:  DesignExtractor::setFinishedParsingSignal
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: STATUS
// Usage: Set prepare to extract signal to finished when parser stops working
//************************************
void DesignExtractor::setFinishedParsingSignal(STATUS s) {
	status = s;
}