//
//  MySprite.h
//  Benkyo
//
//  Created by temp on 2013/08/28.
//
//

#ifndef __Benkyo__MySprite__
#define __Benkyo__MySprite__

#include <iostream>
#include "cocos2d.h"


class MySprite:public cocos2d::CCSprite
{
    
public:
    virtual bool init();
    CREATE_FUNC(MySprite);
    
    
};


#endif /* defined(__Benkyo__MySprite__) */
