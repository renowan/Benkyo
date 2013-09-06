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

using namespace cocos2d;
//using namespace extension;

class Page2Scene : public RecipeBase
{
    
    public:
        virtual bool init();
        static CCScene* scene();
        CREATE_FUNC(Page2Scene);
    
private:
    CCPoint positionConverter(int myX ,int myY);
    int sizeConverter(int mySize);
    
};



#endif // _RecipeBook_Page2Scene_H_
