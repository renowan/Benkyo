//
//  SpriteSheetScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "cocos2d.h"
#include "cocos-ext.h"
#include "SpriteSheetScene.h"

USING_NS_CC;

using namespace cocos2d;
using namespace extension;

CCScene* SpriteSheetScene::scene()
{
    CCScene *scene = CCScene::create();
    SpriteSheetScene *layer = SpriteSheetScene::create();
    scene->addChild(layer);
    
    return scene;
}


bool SpriteSheetScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    //---------------------------------------
    //	攻撃ボタン
    //---------------------------------------
    CCMenuItemImage *attackBtn = CCMenuItemImage::create(
                                                          "image/ui/common_ui_mainButton_down.png",
                                                          "image/ui/common_ui_mainButton_down.png",
                                                          this,
                                                          menu_selector(SpriteSheetScene::attackMotion) );
    attackBtn->setPosition( ccp(300,400) );
    CCMenu* pMenu = CCMenu::create(attackBtn, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    
    //---------------------------------------
    //	ccbiの読み込み
    //---------------------------------------
    CCNodeLoaderLibrary *lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    CCBReader *ccbReader = new CCBReader(lib);
    body = ccbReader->readNodeGraphFromFile("ccb/Scene/spriteSheet.ccbi");
    
    boyManager = ccbReader->getAnimationManager();
    
    boyManager->setDelegate(this);
	ccbReader->release();
    
	if(body != NULL)
	{
		this->addChild(body);
        
	}
    
    
//    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/TestBone0.png", "armature/TestBone0.plist", "armature/TestBone.json"); 
    
//    CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("ActionEditor/Cowboy0.png", "ActionEditor/Cowboy0.plist","ActionEditor/Cowboy.ExportJson");
    
    
    
    
    return true;
    
}

void SpriteSheetScene::attackMotion()
{
    // クリックしたらタイムライン「attack」が再生
    boyManager->runAnimationsForSequenceNamed("attack");
}

//---------------------------------------
//	アニメ再生終了のとき実行される関数
//---------------------------------------
void SpriteSheetScene::completedAnimationSequenceNamed(const char *name)
{
    
    
}

void SpriteSheetScene::setAnimationManager(CCBAnimationManager *pAnimationManager)
{
	CC_SAFE_RELEASE_NULL(boyManager);
    boyManager = pAnimationManager;
    CC_SAFE_RETAIN(boyManager);
	
	// Delegate設定
	boyManager->setDelegate(this);
}

