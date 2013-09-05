//
//  ReadCcbiScene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_ReadCcbiScene_H_
#define _RecipeBook_ReadCcbiScene_H_

#include "cocos2d.h"
#include "RecipeBase.h"
#include "CCBAnimationManager.h"

class ReadCcbiScene : public RecipeBase,public cocos2d::extension::CCBAnimationManagerDelegate
{
    
    
    private:
        cocos2d::CCLayer* targetLayer;
        cocos2d::extension::CCBAnimationManager* animManager;
        void setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager);
        int attackCount;
        
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        virtual void completedAnimationSequenceNamed(const char *name);
        CREATE_FUNC(ReadCcbiScene);
        void readccbi1();
        void readccbi2();
        void readccbi3();
        void changeTimeLine();
        void animCallBack();
        void stopTimeLine();
        void playTimeLine();
    

};



#endif // _RecipeBook_ReadCcbiScene_H_
