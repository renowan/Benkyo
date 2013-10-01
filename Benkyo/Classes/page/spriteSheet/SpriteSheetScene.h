//
//  SpriteSheetScene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_SpriteSheetScene_H_
#define _RecipeBook_SpriteSheetScene_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "RecipeBase.h"


using namespace cocos2d;
using namespace extension;

class SpriteSheetScene : public RecipeBase
, public CCBAnimationManagerDelegate
{
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(SpriteSheetScene);
    
    
    private :
    void setAnimationManager(CCBAnimationManager *pAnimationManager);
    virtual void completedAnimationSequenceNamed(const char *name);
    CCNode*                 body;
    CCBAnimationManager*    boyManager;
    void attackMotion();
    
};





#endif // _RecipeBook_SpriteSheetScene_H_
