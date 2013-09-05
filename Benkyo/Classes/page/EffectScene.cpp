//
//  EffectScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "EffectScene.h"

USING_NS_CC;

CCScene* EffectScene::scene()
{
    CCScene *scene = CCScene::create();
    EffectScene *layer = EffectScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool EffectScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* testSp1 = CCSprite::create("image/quest/04ev_210181.png");
    testSp1->setPosition(ccp(180, size.height-(220*1)));
    this->addChild(testSp1);
    
    CCActionInterval* shaky3D=CCShaky3D::create(15,CCSizeMake(55,80),10,false);
    testSp1->runAction(shaky3D);
    
    
    
    
    CCSprite* testSp2 = CCSprite::create("image/quest/04ev_210181.png");
    testSp2->setPosition(ccp(480, size.height-(220*1)));
    this->addChild(testSp2);
    
    CCActionInterval* shakyTiles3D = CCShakyTiles3D::create(15, CCSizeMake(15,10), 4,true);
    testSp2->runAction(shakyTiles3D);
    
    
    
    CCSprite* testSp3 = CCSprite::create("image/quest/04ev_210181.png");
    testSp3->setPosition(ccp(180, size.height-(220*2)));
    this->addChild(testSp3);
    
//    CCActionInterval* lens3D =CCLens3D::create(CCPointMake(size.width/2,size.height/2), 240, ccg(15,10), 2);
//    testSp3->runAction(lens3D);

    
    return true;
    
}

