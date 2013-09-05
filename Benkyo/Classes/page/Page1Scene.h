//
//  Page1Scene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_Page1Scene_H_
#define _RecipeBook_Page1Scene_H_

#include "cocos2d.h"
#include "RecipeBase.h"


class Page1Scene : public RecipeBase
{
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(Page1Scene);
        void oshita(CCObject* sender);
void myCallBack();
    
};



#endif // _RecipeBook_Page1Scene_H_
