//
//  GachaLayer.cpp
//  CCBer
//
//  Created by B02582 on 2013/07/12.
//
//

#import "CCBAnimationManager.h"
#import "CCControlButton.h"
#import "CCBReader.h"
#include "IndexPageScene.h"

#include "GachaLayer.h"

using namespace cocos2d;
using namespace extension;

bool GachaLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCLOG ("%s \n", "Gahca Layer  Start");
     
    
    return true;
}





//---------------------------------------
//	テストシーンに遷移
//---------------------------------------
void GachaLayer::goNext(){
    CCLOG ("%s \n", "Gacha Oshigta string");
    
    CCScene *scene = IndexPage::scene();
    
    CCDirector::sharedDirector()->replaceScene(scene);
}

//---------------------------------------
//	Variable
//---------------------------------------
bool GachaLayer::onAssignCCBMemberVariable(CCObject *pTarget, const char *pMemberVariableName, CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "goNextBtn", CCControlButton*, this->goNextBtn);
    
    return false;
}

//---------------------------------------
//	CCMenuItem
//---------------------------------------
SEL_MenuHandler GachaLayer::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedMenuItem:", CCBDictionaryScene::menuButtonPressed);
    
    return NULL;
}

//---------------------------------------
//	CCControl
//---------------------------------------
SEL_CCControlHandler GachaLayer::onResolveCCBCCControlSelector(CCObject *pTarget, const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "goNext:", GachaLayer::goNext);
    
    return NULL;
}


//SEL_MenuHandler GachaLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, CCString * pSelectorName)
//{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "appleClicked", GachaLayer::appleClicked);
//    
//    return NULL;
//}

//void GachaLayer::appleClicked(CCObject *pSender, CCControlEvent pCCControlEvent) {
//    CCLOG("button clicked");
//}

//SEL_CCControlHandler GachaLayer::onResolveCCBCCControlSelector(CCObject *pTarget, CCString*pSelectorName) {
 //
   // return NULL;
//}