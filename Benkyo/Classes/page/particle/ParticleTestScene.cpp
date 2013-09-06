//
//  ParticleTestScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "ParticleTestScene.h"

USING_NS_CC;

CCScene* ParticleTestScene::scene()
{
    CCScene *scene = CCScene::create();
    ParticleTestScene *layer = ParticleTestScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool ParticleTestScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMenuItemLabel *mItem1 = CCMenuItemFont::create("Particle1", this, menu_selector(ParticleTestScene::particle1));
    CCMenuItemLabel *mItem2 = CCMenuItemFont::create("再度", this, menu_selector(ParticleTestScene::oneMore));
    mItem1->setPosition(ccp(0,0));
    mItem2->setPosition(ccp(150,0));
    CCMenu* pMenu = CCMenu::create(mItem1,mItem2,NULL);
    pMenu->setPosition(ccp(100,size.height-30));
    this->addChild(pMenu, 1);
    return true;
    
}

static CCParticleSystemQuad* fire;

void ParticleTestScene::particle1()
{
    fire = CCParticleSystemQuad::create("image/particle/FormatScene.plist");
    fire->setPosition(ccp(150,200));
    this->addChild(fire);
    
    
    fire->runAction(
        CCSequence::create(
            CCDelayTime::create(0.100f),
            CCEaseExponentialInOut::create(CCMoveTo::create(1.4f, ccp(300, 500))),
            NULL
        )
    );
    
}

void ParticleTestScene::oneMore()
{
    fire->resetSystem();
}

