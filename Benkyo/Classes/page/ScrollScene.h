//
//  Page1Scene.h
//  CCBer
//
//  Created by B02582 on 2013/07/12.
//
//

#ifndef __CCBer__ScrollScene__
#define __CCBer__ScrollScene__
#include "cocos2d.h"
#include "RecipeBase.h"

class ScrollScene : public RecipeBase
{
    
	
    
	public:
        virtual bool init();
        static cocos2d::CCScene* scene();
		CREATE_FUNC(ScrollScene);
    

};
#endif /* defined(__CCBer__ScrollScene__) */
