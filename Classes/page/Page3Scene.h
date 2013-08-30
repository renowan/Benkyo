//
//  Page3Scene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_Page3Scene_H_
#define _RecipeBook_Page3Scene_H_

#include "cocos2d.h"
#include "RecipeBase.h"


class Page3Scene : public RecipeBase
{
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        void outputObject(CCObject* obj, const char* key, int level);
        CREATE_FUNC(Page3Scene);
        
    
};



#endif // _RecipeBook_Page3Scene_H_
