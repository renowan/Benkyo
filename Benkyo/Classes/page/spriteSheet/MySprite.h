//
//  MySprite.h
//  CCBer
//
//  Created by B02582 on 2013/08/28.
//
//

#include "cocos2d.h"

#ifndef __CCBer__MySprite__
#define __CCBer__MySprite__

#include <iostream>

class MySprite:public cocos2d::CCSprite
{
    public:
        virtual bool init();
        CREATE_FUNC(MySprite);
};

#endif /* defined(__CCBer__MySprite__) */
