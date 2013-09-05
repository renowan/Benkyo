//
//  Recipe26.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "Recipe26.h"
#include "TapSprite.h"

USING_NS_CC;

CCScene* Recipe26::scene()
{
    CCScene *scene = CCScene::create();
    Recipe26 *layer = Recipe26::create();
    scene->addChild(layer);
    
    return scene;
}

bool Recipe26::init()
{
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    
    CCLayerColor* panelBg = CCLayerColor::create(ccc4(51, 51, 51, 255),640,1150);
    panelBg->setPosition(ccp(0,0));
    this->addChild(panelBg);
    
    targetLayer = CCLayer::create();
    this->addChild(targetLayer);
    
    // 画面の幅を取得
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    // 画像ファイルとrectを指定してスプライトを作成
    CCSprite *player = CCSprite::create("image/quest/shuriken_m_avatar_skillpg_18.png", CCRectMake(0, 0, 100, 100) );
    // スプライトの位置を設定
    player->setPosition(ccp(player->getContentSize().width*3/2, winSize.height/2));
    // 後で識別できるようにタグを設定
    player->setTag(1);
    // スプライトをレイヤに追加
    targetLayer->addChild(player);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    TapSprite* sprite = (TapSprite*)TapSprite::create("image/quest/shuriken_m_avatar_skillpg_18.png");
    sprite->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    sprite->setTag(2);
    targetLayer->addChild(sprite);
    
    
    // クリック用のボタン
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "image/ui/common_ui_mainButton_up.png",
                                                          "image/ui/common_ui_mainButton_down.png",
                                                          this,
                                                          menu_selector(Recipe26::testBtn1Handler));
    
    // 表示位置を指定
    pCloseItem->setPosition(ccp(winSize.width - pCloseItem->getContentSize().width / 2 ,
                                pCloseItem->getContentSize().height / 2));
    // CCMenuItemImage から CCMenuを作成
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    // CCMenuとしての位置は(0,0)を指定
    pMenu->setPosition(-150,130);
    
    this->addChild(pMenu);
    
    
    //---------------------------
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite* pSprite = CCSprite::create("image/gacha/2204401.jpg");
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    
    CCSprite* pMask = CCSprite::create("image/quest/mask_star.png");
    pMask->setPosition(ccp(size.width/2, size.height/2));
    
    CCClippingNode* pClip = CCClippingNode::create();
    pClip->setStencil(pMask);
    pClip->setAlphaThreshold(0.05f);
    pClip->addChild(pSprite);
    targetLayer->addChild(pClip);
    
    CCMoveTo *actionMove = CCMoveTo::create(1.7f, ccp(200, 500));
    pClip->runAction(CCEaseExponentialInOut::create(actionMove));
    
    
    
    
    //---------------------------
    // 配列のテスト
    //---------------------------
    
    int arrN[] = {5,6,9,4};
    int iSize = sizeof(arrN) / sizeof(arrN[0]);
    
    for ( int i = 0 ; i < iSize ; i++ ) {
        CCLOG("ffgff : %i" , arrN[i]);
    }
    
    
    return true;
}

void Recipe26::testBtn1Handler(CCObject* pSender){
    
    CCSprite *targetSprite = (CCSprite *)targetLayer->getChildByTag(2);
    
    CCSprite *pic1 = (CCSprite *)targetLayer->getChildByTag(1);
    
    CCLOG ("Characters: %f %f \n", targetSprite->getPositionX(),targetSprite->getPositionY());
    
    int _myx = targetSprite->getPositionX();
    int _myy = targetSprite->getPositionY();
    
    CCMoveTo *actionMove = CCMoveTo::create(0.7f, ccp(_myx, _myy));
    
    
    pic1->runAction(CCEaseExponentialInOut::create(actionMove));
    
    
}