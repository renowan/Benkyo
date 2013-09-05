//
//  TapMonsterSprite.h
//  Recipe37
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//

#ifndef _Recipe37_TapMonsterSprite_H_
#define _Recipe37_TapMonsterSprite_H_

#include "cocos2d.h"

NS_CC_BEGIN

class TapMonsterSprite : public CCSprite, public CCTargetedTouchDelegate
{
    
    private:
        int myEx;
    
    public:
        static TapMonsterSprite* create(const char *pszFileName);
        virtual void onEnter();
        virtual void onExit();
        virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
        virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
        virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
        virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
        virtual float getSpPoistionX();
        virtual float getSpPoistionY();
};

NS_CC_END

#endif // _Recipe37_TapMonsterSprite_H_
