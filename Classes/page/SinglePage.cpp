//
//  Recipe19.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "SinglePage.h"

USING_NS_CC;

CCScene* SinglePage::scene()
{
    CCScene *scene = CCScene::create();
    SinglePage *layer = SinglePage::create();
    scene->addChild(layer);
    return scene;
}

bool SinglePage::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
        
    CCLOG("this is single page");
    return true;
}

//---------------------------------------
//	アニメ再生終了のとき実行される関数
//---------------------------------------
void SinglePage::completedAnimationSequenceNamed(const char *name)
{
	CCLOG("animCallBack animCallBack111");
    
    CCLOG("%s",name);
    
    if(strcmp(name,"Default Timeline") == 0)
    {
        animManager->runAnimations("attack");
    }
    
    
}

void SinglePage::setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager)
{
	CC_SAFE_RELEASE_NULL(animManager);
    animManager = pAnimationManager;
    CC_SAFE_RETAIN(animManager);
	
	// Delegate設定
	animManager->setDelegate(this);
}