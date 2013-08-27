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
    
    
    return true;
    
}

