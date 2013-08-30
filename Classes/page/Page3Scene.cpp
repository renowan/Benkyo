//
//  Page3Scene.cpp
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//
#include "Page3Scene.h"
#include "MySprite.h"
#include "cocos2d.h"
#include "CCJSONConverter.h"

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
    

    CCDictionary* myChild1 = CCDictionary::create();
    myChild1->setObject(CCString::create("ひより"), "名前");
    myChild1->setObject(CCString::create("120cm"), "身長");
    myChild1->setObject(CCString::create("おちゃ"), "趣味");
    
    
    CCArray *myArray1 = CCArray::create();
    
    myArray1->addObject(new CCString("その1"));
    myArray1->addObject(new CCString("その2"));
    myArray1->addObject(new CCString("その3"));
    myArray1->addObject(myChild1);
    

    
    
    CCDictionary* myDy = CCDictionary::create();
    myDy->setObject(CCString::create("37"), "年齢");
    myDy->setObject(CCString::create("M"), "性別");
    myDy->setObject(CCString::create("Renowan"), "名前");
    myDy->setObject(myArray1, "配列1");
    
    CCJSONConverter* cccon = CCJSONConverter::sharedConverter();
    
    
    cccon->ccStrFrom(myDy);
    
    CCLOG("CCBPartsGachaCardDetail setCardData %s", CCJSONConverter::sharedConverter()->ccStrFrom(myDy)->getCString());
    
    
    return true;
    
}



