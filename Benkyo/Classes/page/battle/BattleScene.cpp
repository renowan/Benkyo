//
//  BattleScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "BattleScene.h"
#include "TapSprite.h"
#include "TapMonsterSprite.h"
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
int myStamina = 100;
int damage = 15;

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
    
    myStamina = 100;
    
    battleSceneLayerInstance = this;
    
    targetLayer = CCLayer::create();
    this->addChild(targetLayer);
    
    
    //---------------------------------------
    //	モンスター ボタン
    //---------------------------------------
    
    CCMenuItemImage *monster3 = CCMenuItemImage::create(
                                                        "image/quest/07ev_210232.png",
                                                        "image/quest/07ev_210232.png",
                                                        this,
                                                        menu_selector(BattleScene::monsterBtnHandler));
    
    CCMenu* monster3btn = CCMenu::create(monster3, NULL);
    monster3->setTag(3);
    monster3->setScale(0.55);
    monster3btn->setPosition(ccp(350,850));
    monster3btn->setTag(30);
    targetLayer->addChild(monster3btn);
    

    
    CCMenuItemImage *monster2 = CCMenuItemImage::create(
                                                        "image/quest/05ev_210222.png",
                                                        "image/quest/05ev_210222.png",
                                                        this,
                                                        menu_selector(BattleScene::monsterBtnHandler));
    
    CCMenu* monster2btn = CCMenu::create(monster2, NULL);
    monster2->setTag(2);
    monster2btn->setPosition(ccp(500,850));
    monster2btn->setTag(20);
    targetLayer->addChild(monster2btn);
    
    
    CCMenuItemImage *monster1 = CCMenuItemImage::create(
                                                        "image/quest/04ev_210181.png",
                                                        "image/quest/04ev_210181.png",
                                                        this,
                                                        menu_selector(BattleScene::monsterBtnHandler));
    
    CCMenu* monster1btn = CCMenu::create(monster1, NULL);
    monster1->setTag(1);
    monster1->setScale(1.7);
    monster1btn->setPosition(ccp(220,850));
    monster1btn->setTag(10);
    targetLayer->addChild(monster1btn);
    
    
    targetLayer->setPosition(150,0);
    targetLayer->setScale(1);
    
    
    //------------------------------------------
    // レイヤー追加　コントロールパネル
    //------------------------------------------
    PanelLayer* panelLayer = PanelLayer::create();
//    panelLayer->setTag(500);
    this->addChild(panelLayer,0,PanelLayerTag);
    
    
    return true;
    
}

void BattleScene::attack( int targetNumber )
{
    CCLOG("target To: %i \n",targetNumber);
}

void BattleScene::monsterBtnHandler(CCObject* pSender)
{
    
    CCMenu* pMenuItem = (CCMenu *)(pSender);
    int tag = pMenuItem->getTag();
//    pMenuItem->setEnabled(false);
    CCLOG("my tag: %d",tag);
    
    attackCount++;
    
    CCLOG("my count : %d",attackCount);
    
    int btnTag = tag * 10;
    CCMenu* targetMenuBtn = (CCMenu *)targetLayer->getChildByTag(btnTag);
    targetMenuBtn->setEnabled(false);
    
    
    //-------------
    //  アニメ
    //-------------
    
    targetMenuBtn->runAction(CCEaseBounceOut::create(CCFadeTo::create( 0.4f, 0)));
    
    int targetLayerX = 0;
    int targetLayerY = -200;
    float targetLayerS = 1;
    
    if( attackCount == 1 ){
        targetLayerX = -250;
        targetLayerY = -200;
        targetLayerS = 1.5;
    }else if( attackCount == 2 ){
        targetLayerX = -80;
        targetLayerY = -500;
        targetLayerS = 2.4;
    }else if(attackCount == 3){
        targetLayerX = 30;
//        targetLayerY = 50;
        targetLayerS = 1;
    }
    
    if( attackCount < 4 ){
        
        targetLayer->runAction(
           CCSequence::create(
              CCDelayTime::create(0.500f),
              CCEaseExponentialInOut::create(CCMoveTo::create(0.3f, ccp(targetLayerX, targetLayerY))),
              NULL
           )
        );
        
        targetLayer->runAction(
           CCSequence::create(
              CCDelayTime::create(0.500f),
              CCEaseExponentialInOut::create(CCScaleTo::create( 0.3f , targetLayerS )),
              CCCallFuncND::create(this,callfuncND_selector(BattleScene::callBackTest),NULL),
              NULL
           )
        );
        
        myStamina = myStamina - damage;
        BattleScene::sharedLayer()->panelLayer()->setExBar(myStamina);
        
        
    }
    
    
}

void BattleScene::callBackTest()
{
    CCLOG("Testing Callback");
    if( attackCount == 3 ){
        CCLabelTTF *text = CCLabelTTF::create("End Battle", "arial", 80);
        text->setPosition(CCPointMake(320, 630));
        this->addChild(text);
    }
    
}

