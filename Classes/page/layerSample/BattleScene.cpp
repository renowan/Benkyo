//
//  BattleScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "BattleScene.h"
#include "PanelLayer.h"

USING_NS_CC;

CCScene* BattleScene::scene()
{
    CCScene *scene = CCScene::create();
    BattleScene *layer = BattleScene::create();
    scene->addChild(layer);
    
    return scene;
}

static BattleScene* battleSceneLayerInstance;

BattleScene* BattleScene::sharedLayer()
{
    return battleSceneLayerInstance;
}

PanelLayer* BattleScene::panelLayer()
{
    cocos2d::CCNode* layer = this->getChildByTag(PanelLayerTag);
    return (PanelLayer *)layer;
}

bool BattleScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    CCLOG("Battle scene!!!!!");
    
    CCMenuItemImage* myBtn = CCMenuItemImage::create(
                                                          "image/ui/btn_up.png",
                                                          "image/ui/btn_up.png",
                                                          this,
                                                          menu_selector(BattleScene::monsterBtnHandler));
    

    
    CCMenu* myGroup = CCMenu::create(myBtn, NULL);
    
    this->addChild(myGroup);
    myGroup->setPosition(ccp(200, 400));
    
    battleSceneLayerInstance = this;
    
    //------------------------------------------
    // レイヤー追加　コントロールパネル
    //------------------------------------------
    PanelLayer* panelLayer = PanelLayer::create();
    this->addChild(panelLayer,0,PanelLayerTag);
    
    return true;
    
}


void BattleScene::monsterBtnHandler(CCObject* pSender)
{
    CCLOG("Oshita!");
	BattleScene::sharedLayer()->panelLayer()->runLayerFunc(1);
}


