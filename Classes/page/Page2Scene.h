//
//  Page2Scene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_Page2Scene_H_
#define _RecipeBook_Page2Scene_H_

#include "cocos2d.h"
#include "RecipeBase.h"


class Page2Scene : public RecipeBase
{
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(Page2Scene);
    
};



#endif // _RecipeBook_Page2Scene_H_
