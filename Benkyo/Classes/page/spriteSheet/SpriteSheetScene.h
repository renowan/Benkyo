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
#include "RecipeBase.h"


class SpriteSheetScene : public RecipeBase
{
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(SpriteSheetScene);
    
};



#endif // _RecipeBook_SpriteSheetScene_H_
