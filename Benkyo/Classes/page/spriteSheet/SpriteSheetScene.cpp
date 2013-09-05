//
//  SpriteSheetScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "SpriteSheetScene.h"

USING_NS_CC;

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
    
    
    
//    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
//    cache->addSpriteFramesWithFile("image/koma/koma.plist","image/koma/koma.png");
//    CCSprite *m_pTest = CCSprite::createWithSpriteFrameName("player_m_action_attack_44_flip_001.png");
//
//    cache->spriteFrameByName("player_m_action_attack_44_flip_001.png");
//
//    //CCSpriteBatchNodeと組み合わせることもできます
//    CCTexture2D *pTexture2D = CCTextureCache::sharedTextureCache()->addImage("image/koma/koma.png");
//    CCSpriteBatchNode *batchNode = CCSpriteBatchNode::createWithTexture(pTexture2D);
//    CCSprite *m_pTest2 = CCSprite::createWithSpriteFrameName("player_m_action_attack_44_flip_001.png");
//    batchNode->addChild(m_pTest2);
//
//    m_pTest->setPosition(ccp(250, 500));
//    
//    this->addChild(m_pTest);
    
    
    
    //--------------------------------------
    // アニメーション再生
    //--------------------------------------
    // load and cache the texture and sprite frames
    auto cacher = CCSpriteFrameCache::sharedSpriteFrameCache();
    cacher->addSpriteFramesWithFile("image/koma/koma.plist","image/koma/koma.png");
    
    CCSprite* someSprite = new CCSprite;
    someSprite->initWithSpriteFrameName("player_m_action_attack_44_flip_002.png");
    
    someSprite->setPosition(ccp(200, 500));
    this->addChild(someSprite);
    
//    // get the sprite frame
//    CCSpriteFrame* frame = cacher->spriteFrameByName("player_m_action_attack_44_flip_002.png");
//    
//    // set someSprite's display frame
//    someSprite->setDisplayFrame(frame);
    
    
    
    
    // load all the animation frames into an array
    const int kNumberOfFrames = 3;
    CCArray* frames = new CCArray;
    frames->initWithCapacity(kNumberOfFrames);
    for( int i = 0; i < kNumberOfFrames; i++ )
    {
        CCString* filename = CCString::createWithFormat("player_m_action_attack_44_flip_00%i.png", i);
        frames->addObject(cacher->spriteFrameByName(filename->getCString()));
        CCLOG("player_m_action_attack_44_flip_00%i.png",i);
    }

    // play the animation
    CCAnimation* anim = new CCAnimation;
    anim->initWithSpriteFrames(frames);
    

    someSprite->runAction(CCAnimate::create(anim));
    
    
    return true;
    
}

