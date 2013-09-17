//
//  ReadCcbiScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "ReadCcbiScene.h"
#include "cocos-ext.h"


USING_NS_CC;

using namespace cocos2d;
using namespace extension;

CCScene* ReadCcbiScene::scene()
{
    CCScene *scene = CCScene::create();
    ReadCcbiScene *layer = ReadCcbiScene::create();
    scene->addChild(layer);
    
    return scene;
}


bool ReadCcbiScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    CCSize mySize = CCDirector::sharedDirector()->getVisibleSize();
    
        
    CCMenuItemLabel *mItem1 = CCMenuItemFont::create("ccbi読込む", this, menu_selector(ReadCcbiScene::readccbi1));
    CCMenuItemLabel *mItem2 = CCMenuItemFont::create("画像追加", this, menu_selector(ReadCcbiScene::readccbi2));
    CCMenuItemLabel *mItem3 = CCMenuItemFont::create("全部消す", this, menu_selector(ReadCcbiScene::readccbi3));
    
    CCMenuItemLabel *mItem4 = CCMenuItemFont::create("切り替え", this, menu_selector(ReadCcbiScene::changeTimeLine));
    CCMenuItemLabel *mItem5 = CCMenuItemFont::create("止める", this, menu_selector(ReadCcbiScene::stopTimeLine));
    CCMenuItemLabel *mItem6 = CCMenuItemFont::create("再開", this, menu_selector(ReadCcbiScene::playTimeLine));
    
    
    mItem1->setPosition(ccp(0,0));
    mItem2->setPosition(ccp(200,0));
    mItem3->setPosition(ccp(400,0));
    mItem4->setPosition(ccp(0,-50));
    mItem5->setPosition(ccp(200,-50));
    mItem6->setPosition(ccp(400,-50));
    
    CCMenu* pMenu = CCMenu::create(mItem1,mItem2,mItem3,mItem4,mItem5,mItem6,NULL);
    pMenu->setPosition(ccp(100,mySize.height-30));
    this->addChild(pMenu, 1);
    
    return true;
    
}

static CCNode * node;
//static CCBAnimationManager* animManager;

void ReadCcbiScene::readccbi1()
{
    
    CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(lib);
    node = ccbReader->readNodeGraphFromFile("ccb/Scene/ccbiTest.ccbi");
    
    animManager = ccbReader->getAnimationManager();

    animManager->setDelegate(this);
	ccbReader->release();
    
	if(node != NULL)
	{
		this->addChild(node);
	}
}

void ReadCcbiScene::readccbi2()
{
    CCLOG("22222");

    if(node != NULL)
    {
        CCSize size = CCDirector::sharedDirector()->getVisibleSize();
        CCSprite* sprite = CCSprite::create("image/gacha/bg.jpg");
        CCLayer* layer =  (CCLayer*)node -> getChildByTag(999);
        sprite -> setPosition(ccp(size.width/2,size.height/2-150));
        layer -> addChild(sprite);
    }

}

void ReadCcbiScene::readccbi3()
{
    
    if(node != NULL)
	{
        this->removeChild(node);
	}
}

void ReadCcbiScene::changeTimeLine()
{
//    animManager->runAnimationsForSequenceNamedTweenDuration("kankan", 5);
    animManager->runAnimations("attack");
    animManager->runAnimationsForSequenceNamed("attack");
}


//---------------------------------------
//	アニメ再生終了のとき実行される関数
//---------------------------------------
void ReadCcbiScene::completedAnimationSequenceNamed(const char *name)
{
	CCLOG("animCallBack animCallBack111");
    
    CCLOG("%s",name);
    
    if(strcmp(name,"Default Timeline") == 0)
    {
        animManager->runAnimations("attack");
    }
    
    
}

void ReadCcbiScene::setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager)
{
	CC_SAFE_RELEASE_NULL(animManager);
    animManager = pAnimationManager;
    CC_SAFE_RETAIN(animManager);
	
	// Delegate設定
	animManager->setDelegate(this);
}

void ReadCcbiScene::stopTimeLine()
{
    node->stopAllActions();
}

void ReadCcbiScene::playTimeLine()
{
    node->transform();
}