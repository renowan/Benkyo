//
//  MySprite.cpp
//  CCBer
//
//  Created by B02582 on 2013/08/28.
//
//

#include "MySprite.h"


bool MySprite::init()
{
    if ( !CCSprite::init() )
    {
        return false;
    }
    
    
    
    CCSprite* mysp = CCSprite::create("image/quest/04ev_210181.png");
    
    this->addChild(mysp);
    
    return true;
    
}