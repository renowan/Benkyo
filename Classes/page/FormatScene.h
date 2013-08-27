//
//  FormatScene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_FormatScene_H_
#define _RecipeBook_FormatScene_H_

#include "cocos2d.h"
#include "RecipeBase.h"


class FormatScene : public RecipeBase
{
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(FormatScene);
    
};



#endif // _RecipeBook_FormatScene_H_
