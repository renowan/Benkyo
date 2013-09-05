//
//  Page1Scene.h
//  CCBer
//
//  Created by B02582 on 2013/07/12.
//
//

#ifndef __CCBer__QuestScene__
#define __CCBer__QuestScene__
#include "cocos2d.h"
#include "CCBAnimationManager.h"

class QuestScene :
public cocos2d::CCScene
//,
//public cocos2d::extension::CCBAnimationManagerDelegate
{
	cocos2d::extension::CCBAnimationManager *animationManager;
    
	virtual bool init();
//	virtual void completedAnimationSequenceNamed(const char *name);
    
//	void setBlendFuncToAllChildren(CCNode* node, const cocos2d::ccBlendFunc& blend);
    
//	~Page1Scene();
    
public:
	CREATE_FUNC(QuestScene);
};
#endif /* defined(__CCBer__QuestScene__) */
