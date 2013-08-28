//
//  TouchTestScene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_TouchTestScene_H_
#define _RecipeBook_TouchTestScene_H_

#include "cocos2d.h"
#include "RecipeBase.h"



class TouchTestScene : public RecipeBase
{

    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        CREATE_FUNC(TouchTestScene);
        void onEnter();
    
        bool ccTouchBegan( cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent );
        void ccTouchEnded( cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent );
        void ccTouchMoved( cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent );

    
    private:
        void changeMotion1();
        void changeMotion2();
        void removeCCC( cocos2d::CCLayerColor *pSender );
        void motion1( cocos2d::CCPoint * point );
        void motion2( cocos2d::CCPoint * point );

};



#endif // _RecipeBook_TouchTestScene_H_
