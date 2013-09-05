//
//  ParticleTestScene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_ParticleTestScene_H_
#define _RecipeBook_ParticleTestScene_H_

#include "cocos2d.h"
#include "RecipeBase.h"


class ParticleTestScene : public RecipeBase
{
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(ParticleTestScene);
    
private:
    void particle1();
    void oneMore();
    
};



#endif // _RecipeBook_ParticleTestScene_H_
