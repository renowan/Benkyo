//
//  ModalLayer.cpp
//  Modal
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//
//

#include "PanelLayer.h"
#include <ccTypes.h>
#include "cocos2d.h"

USING_NS_CC;

bool PanelLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    CCLayerColor* cccolor = CCLayerColor::create(ccc4(255, 30, 30, 255),100,100);
    this->addChild(cccolor);
    cccolor->setPosition(ccp(0, 0));
    
    return true;
}

void PanelLayer::runLayerFunc(int value)
{
    CCLOG("runLayerFunc : %i", value);
}

