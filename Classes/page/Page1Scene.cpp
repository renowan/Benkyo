//
//  Page1Scene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "Page1Scene.h"

USING_NS_CC;

CCScene* Page1Scene::scene()
{
    CCScene *scene = CCScene::create();
    Page1Scene *layer = Page1Scene::create();
    scene->addChild(layer);
    
    return scene;
}

static CCLayer* layer1;

bool Page1Scene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }

    layer1 = CCLayer::create();
    
    this->addChild(layer1);
    
    CCLayer* layer2 = CCLayer::create();
    
    this->addChild(layer2);
    
    
    //-------------------------------
        
    CCSprite* mySp = CCSprite::create("image/gacha/2204401.jpg");
    CCSprite* mySp2 = CCSprite::create("image/gacha/2304402.jpg");
    
    mySp->setPosition(ccp(200, 800));
    mySp2->setPosition(ccp(400, 800));
    
    mySp->setTag(1);
    
    layer1->addChild(mySp);
    layer1->addChild(mySp2);
    
    
    // --------------------------------
    
    
    CCMenuItemImage *menuItem1 = CCMenuItemImage::create( "image/ui/btn_up.png",
                                                         "image/ui/btn_down.png",
                                                         this, menu_selector(Page1Scene::oshita));
    
 
    CCMenuItemImage *menuItem2 = CCMenuItemImage::create( "image/ui/btn_up.png",
                                                         "image/ui/btn_down.png",
                                                         this, menu_selector(Page1Scene::oshita));
    
    menuItem2->setPosition(ccp(400, 0));
    CCMenu* menuGroup = CCMenu::create(menuItem1,menuItem2, NULL);
    
    menuGroup->setPosition(ccp(150, 300));
    
    this->addChild(menuGroup);
    
    
    //------------------------------------
    
    
    return true;
    
}

void Page1Scene::oshita()
{
    CCLOG("oshita!!!!!!");
    
//    CCSprite* _mysp = (CCSprite*)this->getChildByTag(1);
//    
//    _mysp->setPosition(ccp(0, 0));
    
//    layer1->setPosition(ccp(300, 300));
    
//    CCFiniteTimeAction* move = CCMoveTo::create( 3.0f, ccp(100, 200));
//    layer1->runAction( CCMoveTo::create( 3.0f, ccp(100, 200)) );
    
    
    
    layer1->runAction(
           CCSequence::create(
                              CCDelayTime::create(3.000f),
                              CCEaseBackIn::create(CCMoveTo::create( 2.0f, ccp(100, 800))),
                              CCEaseExponentialIn::create(CCMoveTo::create( 1.0f, ccp(300, -400))),
                              CCCallFuncND::create(this,callfuncND_selector(Page1Scene::myCallBack),NULL),
                              NULL
                              )
        );
    
    
}

void Page1Scene::myCallBack()
{
    CCLOG("call back");
}


