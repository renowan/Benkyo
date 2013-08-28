//
//  TouchTestScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "TouchTestScene.h"


USING_NS_CC;

CCScene* TouchTestScene::scene()
{
    CCScene *scene = CCScene::create();
    TouchTestScene *layer = TouchTestScene::create();
    scene->addChild(layer);
    
    return scene;
}

static TouchTestScene* layerInstance;
static int colorMode = 1;

static bool dirFlg = false;
static int color1 = 0;
static int color2 = 83;
static int color3 = 166;

bool TouchTestScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    this->setTouchMode(kCCTouchesAllAtOnce);
    // シングルタッチモード
    // this->setTouchMode(kCCTouchesOneByOne);
    
    // タッチを有効にする
    this->setTouchEnabled(true);
    
    layerInstance = this;
    
    
    colorMode = 1;
    
    CCMenuItemLabel *mItem1 = CCMenuItemFont::create("Motion1", this, menu_selector(TouchTestScene::changeMotion1));
    CCMenuItemLabel *mItem2 = CCMenuItemFont::create("Motion2", this, menu_selector(TouchTestScene::changeMotion2));
    
    
    mItem1->setPosition(ccp(0,0));
    mItem2->setPosition(ccp(180,0));
    
    CCMenu* pMenu = CCMenu::create(mItem1,mItem2,NULL);
    pMenu->setPosition(ccp(150,1050));
    this->addChild(pMenu, 1);
    
    return true;
    
}

void TouchTestScene::changeMotion1()
{
    colorMode = 1;
}

void TouchTestScene::changeMotion2()
{
    colorMode = 2;
}

void TouchTestScene::onEnter()
{
    CCLayer::onEnter();
    CCTouchDispatcher* dispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
    dispatcher->addTargetedDelegate(this, 0, true);
}



bool TouchTestScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLOG("TapSprite: touch ccTouchBegan");
    return true;
}

void TouchTestScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    // タッチ移動処理
    CCPoint point = pTouch->getLocation();
    
    switch (colorMode) {
        case 1:
            TouchTestScene::motion1(&point);
            break;
        case 2:
            TouchTestScene::motion2(&point);
            break;
        default:
            break;
    }
    
    
    
    CCLOG("TapSprite: touch moved");
}



void TouchTestScene::motion1( cocos2d::CCPoint* point )
{
    
    CCLayerColor* cccolor = CCLayerColor::create(ccc4(255, 30, 30, 255),30,30);
    cccolor->setPosition(*point);
    this->addChild(cccolor);
    
    ccBezierConfig bezier;
    bezier.controlPoint_1 = ccp(30, 50);
    bezier.controlPoint_2 = ccp(250, 850);
    bezier.endPosition = *point;
    
    CCActionInterval* action;
    
    action = CCBezierTo::create(3.5f, bezier);
    cccolor->runAction(CCSequence::create(action, NULL, NULL));
    
    
    cccolor->runAction(
       CCSequence::create(
          CCEaseExponentialInOut::create(CCScaleTo::create( 0.7f , 4.8 )),
          CCEaseExponentialInOut::create(CCScaleTo::create( 0.7f , 0.2 )),
          CCDelayTime::create(2.00f),
          CCEaseExponentialIn::create(CCScaleTo::create( 0.4f , 3.0 )),
         CCEaseExponentialOut::create(CCScaleTo::create( 0.4f , 0.1 )),
//          CCEaseExponentialInOut::create(CCFadeOut::create( 0.1f )),
          CCCallFuncN::create(this, callfuncN_selector(TouchTestScene::removeCCC)),
          NULL
       )
    );
}



void TouchTestScene::motion2( cocos2d::CCPoint * point )
{
    
    CCPoint myPoint = *point;
    
    int b1X = 0;
    int b2X = 0;
    
    int bkan = 1100;
    
    if( dirFlg ){
        b1X = myPoint.x + bkan;
        b2X = myPoint.x - bkan;
    }else{
        b1X = myPoint.x - bkan;
        b2X = myPoint.x + bkan;
    }
    
    color1 +=10;
    color2 +=30;
    color3 +=50;
    
    if( color1 > 255 ) color1 = 0;
    if( color2 > 255 ) color2 = 0;
    if( color3 > 255 ) color3 = 0;
    
    dirFlg = !dirFlg;
    
    CCLayerColor* cccolor = CCLayerColor::create(ccc4(color1, color2, color3, 255),30,30);
    cccolor->setPosition(*point);
    this->addChild(cccolor);
    
    ccBezierConfig bezier;
    bezier.controlPoint_1 = ccp(b1X, myPoint.y);
    bezier.controlPoint_2 = ccp(300, 800);
    bezier.endPosition = *point;
    
    CCActionInterval* action;
    
    action = CCBezierTo::create(1.0f, bezier);
    cccolor->runAction(CCSequence::create(action, NULL, NULL));
    
    
    cccolor->runAction(
       CCSequence::create(
          CCEaseExponentialInOut::create(CCScaleTo::create( 0.5f , 2.8 )),
          CCEaseExponentialInOut::create(CCScaleTo::create( 0.5f , 0.2 )),
          CCDelayTime::create(0.30f),
          CCEaseExponentialIn::create(CCScaleTo::create( 0.4f , 2.0 )),
         CCEaseExponentialOut::create(CCScaleTo::create( 0.4f , 0.1 )),
          CCCallFuncN::create(this, callfuncN_selector(TouchTestScene::removeCCC)),
          NULL
       )
    );
}

void TouchTestScene::removeCCC( cocos2d::CCLayerColor *pSender )
{
    this->removeChild(pSender);
}





void TouchTestScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    // タッチ終了処理
    CCLOG("TapSprite: touch ended");
}

