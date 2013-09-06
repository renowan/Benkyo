//
//  Page2Scene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "Page2Scene.h"

USING_NS_CC;

CCScene* Page2Scene::scene()
{
    CCScene *scene = CCScene::create();
    Page2Scene *layer = Page2Scene::create();
    scene->addChild(layer);
    
    return scene;
}

bool Page2Scene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    // ここで画像を入れてみた、サイズも自動的に調整してくれることが確認できたい
//    CCSprite* testSp1 = CCSprite::create("image/quest/04ev_210181.png");
//    testSp1->setPosition(ccp(320, 480));
//    this->addChild(testSp1);
    
    CCLayerColor* myLc = CCLayerColor::create(ccc4(250, 0, 0, 255),sizeConverter(320),(100));
    this->addChild(myLc);
    
    myLc->setPosition(ccp(0, 0));
    
    myLc->runAction(
        CCSequence::create(
            CCDelayTime::create(0.500f),
            CCEaseExponentialInOut::create(CCMoveTo::create(0.8f, Page2Scene::positionConverter(0,0))),
            CCEaseExponentialInOut::create(CCMoveTo::create(0.8f, Page2Scene::positionConverter(0,860))),
            CCEaseExponentialInOut::create(CCMoveTo::create(0.8f, Page2Scene::positionConverter(540,860))),
            NULL
        )
    );
    
    
    
    return true;
    
}


// 変換関数を作ろうと思ったけど、いらないみたい
CCPoint Page2Scene::positionConverter(int myX ,int myY)
{
//    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
//    if( size.width < 640 ){
//        myX = int(myX / 2);
//        myY = int(myY / 2);
//    }
    
    return ccp(myX,myY);
}

int Page2Scene::sizeConverter(int mySize)
{
//    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
//    if( size.width < 640 ){
//        mySize = int(mySize / 2);
//    }
    
    return mySize;
}

