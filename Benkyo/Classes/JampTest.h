//
//  JampTest.h
//  RecipeBook
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _RecipeBook_JampTest_H_
#define _RecipeBook_JampTest_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCBSelectorResolver.h"
#include "CCBAnimationManager.h"

using namespace cocos2d;
using namespace extension;



namespace Parts {
    class CCBPartsTimeLineMaster;
}

class JampTest
: public cocos2d::CCLayer
, public CCBSelectorResolver
, public CCBMemberVariableAssigner
, public CCBAnimationManagerDelegate
{

    CCNode *node;
    
    private:
        CCBAnimationManager* animManager;
        void setAnimationManager(cocos2d::extension::CCBAnimationManager *pAnimationManager);
        CCBAnimationManager* cutinMc;
    
    public:
        virtual bool init();
        static CCScene* scene();
        /* CCB Connector */
        virtual void completedAnimationSequenceNamed(const char *name);
        virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
        virtual SEL_CallFuncN onResolveCCBCCCallFuncSelector(CCObject * pTarget, const char* pSelectorName);
        virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
        virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
        void testFunc();
        CREATE_FUNC(JampTest);
    
    
    private:
        void menuCloseCallback(CCObject* pSender);
        void playStart();
        void playShot();
    
    //タイムラインパーツ
    private :
//      CCBPartsTimeLineMaster*				ccbGachaCutin_;

};


class TestBuilderLoader : public CCLayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TestBuilderLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(JampTest);
};

class CutinLoader : public CCLayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CutinLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(JampTest);
};
 

#endif // _RecipeBook_JampTest_H_
