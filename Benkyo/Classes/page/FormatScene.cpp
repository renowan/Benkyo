//
//  FormatScene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#include "FormatScene.h"

USING_NS_CC;

CCScene* FormatScene::scene()
{
    CCScene *scene = CCScene::create();
    FormatScene *layer = FormatScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool FormatScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }

    
    return true;
    
}

