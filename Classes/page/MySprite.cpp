//
//  MySprite.cpp
//  Benkyo
//
//  Created by temp on 2013/08/28.
//
//

#include "MySprite.h"

bool MySprite::init()
{
    if ( !CCSprite::init() ) {
        return false;
    }
    
    
//    this->setTouchMode(kCCTouchesAllAtOnce);
//    this->setTouchEnabled(true);
    
    CCSprite* _sp1 = CCSprite::create("image/gacha/2204401.jpg");

    
    CCSprite* _sp2 = CCSprite::create("image/gacha/2304402.jpg");
    
    this->addChild(_sp1);
    this->addChild(_sp2);
    
    _sp2->setPosition(ccp(100, 300));

    
    
    return true;
}
