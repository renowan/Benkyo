//
//  SinglePage.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_SinglePage_H_
#define _RecipeBook_SinglePage_H_

#include "cocos2d.h"
#include "CCBAnimationManager.h"

class SinglePage : public cocos2d::CCLayer,public cocos2d::extension::CCBAnimationManagerDelegate
{
    
private:
    cocos2d::CCLayer* targetLayer;
    cocos2d::extension::CCBAnimationManager* animManager;
    

    
public:

    virtual bool init();
    static cocos2d::CCScene* scene();
    void setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager);
    virtual void completedAnimationSequenceNamed(const char *name);
    CREATE_FUNC(SinglePage);

};

#endif // _RecipeBook_SinglePage_H_
