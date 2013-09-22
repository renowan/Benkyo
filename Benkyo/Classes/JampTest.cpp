//
//  Recipe19.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "cocos2d.h"
#include "cocos-ext.h"
#include "JampTest.h"
#include "IndexPageScene.h"
#include "CCBSelectorResolver.h"
#include "CCBAnimationManager.h"


USING_NS_CC_EXT;

using namespace cocos2d;
using namespace extension;

CCScene* JampTest::scene()
{
    CCScene *scene = CCScene::create();
    JampTest *layer = JampTest::create();
    scene->addChild(layer);
    return scene;
}

bool JampTest::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    
    
    CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    lib->registerCCNodeLoader("CCTestLayer", TestBuilderLoader::loader());
    CCBReader *ccbReader = new CCBReader(lib);
    
    node = ccbReader->readNodeGraphFromFile("CCBSceneJumpGacha_1.ccbi",this);
    
//    node = ccbReader->readNodeGraphFromFile("CCBPartsGachaBigCard_v2.ccbi",this);
    
    
//    node->setPosition(ccp(130, 200));
    
    animManager = ccbReader->getAnimationManager();
    
    animManager->setDelegate(this);
    
	ccbReader->release();
    
//    animManager->runAnimationsForSequenceNamed("start_Ballin");
//    this->scheduleOnce(schedule_selector(JampTest::playStart), 2.0f);
    
	if(node != NULL)
	{
		this->addChild(node);
	}
    
    
    
    return true;
}

void JampTest::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(IndexPage::scene());
}

void JampTest::setAnimationManager(CCBAnimationManager *pAnimationManager)
{
	CC_SAFE_RELEASE_NULL(animManager);
    animManager = pAnimationManager;
    CC_SAFE_RETAIN(animManager);
	
	// Delegate設定
	animManager->setDelegate(this);
}

//---------------------------------------
//	アニメ再生終了のとき実行される関数
//---------------------------------------
void JampTest::completedAnimationSequenceNamed(const char *name)
{
    
    CCLOG("completedAnimationSequenceNamed %s",name);
    
    if(strcmp(name,"start_Ballin") == 0)
    {
        animManager->runAnimationsForSequenceNamed("shoot");
    }
    
    
    if(strcmp(name,"shoot") == 0)
    {
        animManager->runAnimationsForSequenceNamed("flying");
    }
    
    if(strcmp(name,"pushbutton") == 0)
    {
        // ここでif文で判断
        animManager->runAnimationsForSequenceNamed("cutin");
    }
    
    if(strcmp(name,"cutin") == 0)
    {
        // ここでif文で判断
        
        
        CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
        CCBReader *ccbReader = new CCBReader(lib);
        CCNode* cutinNode = ccbReader->readNodeGraphFromFile("CCBPartsGachaCutin.ccbi",this);
        node->addChild(cutinNode);
        
        CCBAnimationManager* cutinManager = ccbReader->getAnimationManager();
        cutinManager->runAnimationsForSequenceNamed("cutin_B");
        
        cutinNode->setPosition(ccp(-40, 340));
        
        this->scheduleOnce(schedule_selector(JampTest::playShot), 2.0f);
        
        
    }
    

    
    if(strcmp(name,"flying") == 0)
    {
        animManager->runAnimationsForSequenceNamed("flying chanceUp");
    }
    
    
}

void JampTest::playStart()
{
    animManager->runAnimationsForSequenceNamed("start_Ballin");
}

void JampTest::playShot()
{
    animManager->runAnimationsForSequenceNamed("shoot");
}


void JampTest::testFunc()
{
    CCLOG("testFunc testFunc testFunc.");
}


SEL_MenuHandler JampTest::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

SEL_CallFuncN JampTest::onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName)
{

//    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "myCallFunc1:", JampTest::testFunc);
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "ballmove", JampTest::testFunc);
//    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "myCallFunc3:", JampTest::testFunc);
    return NULL;
};

SEL_CCControlHandler JampTest::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

bool JampTest::onAssignCCBMemberVariable(CCObject *pTarget, const char *pMemberVariableName, CCNode *pNode)
{
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ccbGachaCutin", Parts::CCBPartsTimeLineMaster*, this->cutinMc);
//    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "ccbGachaCutin", CC, this->cutinMc);
    
    return false;
}

