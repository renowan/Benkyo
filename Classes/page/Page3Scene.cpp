//
//  Page3Scene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "Page3Scene.h"
#include "MySprite.h"

USING_NS_CC;

CCScene* Page3Scene::scene()
{
    CCScene *scene = CCScene::create();
    Page3Scene *layer = Page3Scene::create();
    scene->addChild(layer);
    
    return scene;
}

bool Page3Scene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }

//    MySprite* mysp = MySprite::create();
//    this->addChild(mysp);
    
    
    
    
    
    
    return true;
    
}

