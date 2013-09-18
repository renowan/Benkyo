//
//  BattleScene.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_BattleScene_H_
#define _RecipeBook_BattleScene_H_

#include "cocos2d.h"
#include "RecipeBase.h"
#include "PanelLayer.h"

typedef enum {
    PanelLayerTag
} BattleSceneTag;

class BattleScene : public RecipeBase
{
    
    private:
        cocos2d::CCLayer* targetLayer;
        int attackCount;
    
    public:
        virtual bool init();
        static cocos2d::CCScene* scene();
        static void attack(int targetNumber);
        static BattleScene* sharedLayer();
        PanelLayer* panelLayer();
        CREATE_FUNC(BattleScene);
        void skipAnimation(CCObject* obj);
        
    private:
        BattleScene();
        ~BattleScene();
        void monsterBtnHandler(CCObject* pSender);
        void callBackTest();
        
    
};



#endif // _RecipeBook_BattleScene_H_
