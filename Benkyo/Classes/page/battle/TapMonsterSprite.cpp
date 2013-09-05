//
//  TapMonsterSprite.cpp
//  Recipe37
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "TapMonsterSprite.h"
#include "BattleScene.h"

NS_CC_BEGIN

TapMonsterSprite* TapMonsterSprite::create(const char *pszFileName)
{
    TapMonsterSprite *pobSprite = new TapMonsterSprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void TapMonsterSprite::onEnter()
{
    CCSprite::onEnter();
    CCTouchDispatcher* dispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
    dispatcher->addTargetedDelegate(this, 0, true);
}

void TapMonsterSprite::onExit() {
    CCSprite::onExit();
    CCTouchDispatcher* dispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
    dispatcher->removeDelegate(this);
}

bool TapMonsterSprite::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    BattleScene::attack(2);
    
    
    // タッチ開始処理
    // タッチ位置を取得
    CCPoint point = pTouch->getLocation();
    // スプライトの大きさ
    CCSize size = this->getTexture()->getContentSize();
    // スプライトの範囲
    CCRect rect = CCRectMake(this->getPositionX()-size.width/2, this->getPositionY()-size.height/2, size.width, size.height);
    // タッチ位置がスプライト内ならイベント処理するのでtrueを返す
    return rect.containsPoint(point);
}

void TapMonsterSprite::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    // タッチ移動処理
    // CCPoint point = pTouch->getLocation();
    // this->setPosition(point);
}

void TapMonsterSprite::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    // タッチ終了処理
    CCLOG("TapMonsterSprite: touch ended");
}

void TapMonsterSprite::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    // タッチキャンセル処理
    CCLOG("TapMonsterSprite: touch cancelled");
}

float TapMonsterSprite::getSpPoistionX(){
//    CCLOG ("rereCharacters: %c %c \n",5, 5);
    return this->getPosition().x;
}
float TapMonsterSprite::getSpPoistionY(){
    return this->getPosition().y;
}


NS_CC_END