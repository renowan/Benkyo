//
//  Recipe26.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_Recipe26_H_
#define _RecipeBook_Recipe26_H_

#include "cocos2d.h"
#include "RecipeBase.h"

class Recipe26 : public RecipeBase
{
    
private:
    cocos2d::CCLayer* targetLayer;
    
public:
    virtual bool init();
    
    
    static cocos2d::CCScene* scene();
    CREATE_FUNC(Recipe26);
    
    

    
private:
    void testBtn1Handler(CCObject* pSender);
};



#endif // _RecipeBook_Recipe26_H_
