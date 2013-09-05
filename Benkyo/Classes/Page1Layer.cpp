//
//  Page1Layer.cpp
//  CCBer
//
//  Created by B02582 on 2013/07/12.
//
//

#import "CCBAnimationManager.h"
#import "CCControlButton.h"
#import "CCBReader.h"
#include "IndexPageScene.h"

#include "Page1Layer.h"

using namespace cocos2d;
using namespace extension;

bool Page1Layer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCLOG ("%s \n", "Page1 Start..");
     
    
    return true;
}





//---------------------------------------
//	テストシーンに遷移
//---------------------------------------
void Page1Layer::goNext(){
    CCLOG ("%s \n", "Page1 Oshigta string");
    
    CCScene *scene = IndexPage::scene();
    
    CCDirector::sharedDirector()->replaceScene(scene);
}

//---------------------------------------
//	Variable
//---------------------------------------
bool Page1Layer::onAssignCCBMemberVariable(CCObject *pTarget, const char *pMemberVariableName, CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "goNextBtn", CCControlButton*, this->goNextBtn);
    
    return false;
}

//---------------------------------------
//	CCMenuItem
//---------------------------------------
SEL_MenuHandler Page1Layer::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedMenuItem:", CCBDictionaryScene::menuButtonPressed);
    
    return NULL;
}

//---------------------------------------
//	CCControl
//---------------------------------------
SEL_CCControlHandler Page1Layer::onResolveCCBCCControlSelector(CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "goNext:", Page1Layer::goNext);
    
    return NULL;
}


//SEL_MenuHandler Page1Layer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, CCString * pSelectorName)
//{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "appleClicked", Page1Layer::appleClicked);
//    
//    return NULL;
//}

//void Page1Layer::appleClicked(CCObject *pSender, CCControlEvent pCCControlEvent) {
//    CCLOG("button clicked");
//}

//SEL_CCControlHandler Page1Layer::onResolveCCBCCControlSelector(CCObject *pTarget, CCString*pSelectorName) {
 //
   // return NULL;
//}