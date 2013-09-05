//
//  Page1Scene.h
//  CCBer
//
//  Created by B02582 on 2013/07/12.
//
//

#ifndef __CCBer__GachaScene__
#define __CCBer__GachaScene__
#include "cocos2d.h"
#include "CCBAnimationManager.h"

class GachaScene :
public cocos2d::CCScene
//,
//public cocos2d::extension::CCBAnimationManagerDelegate
{
	cocos2d::extension::CCBAnimationManager *animationManager;
    
	virtual bool init();
    
	public:
		CREATE_FUNC(GachaScene);
};
#endif /* defined(__CCBer__GachaScene__) */
