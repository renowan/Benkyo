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

using namespace cocos2d;

class SinglePage : public cocos2d::CCLayer
{
    
    public:
        SinglePage();
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(SinglePage);
        
    private:
        CCPoint positionConverter(int myX ,int myY);
        int sizeConverter(int mySize);
};

#endif // _RecipeBook_SinglePage_H_
