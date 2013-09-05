//
//  SceneChanger.h
//  Benkyo
//
//  Created by B02582 on 2013/09/04.
//
//

#ifndef __Benkyo__SceneChanger__
#define __Benkyo__SceneChanger__

#include <iostream>

#include "cocos2d.h"
#include "CCNodeLoaderLibrary.h"


class SceneChanger{
    
    static cocos2d::CCNode* loadParts(const char* fileName);
    static cocos2d::CCNode* loadCustomParts(const char* className, const char* fileName, cocos2d::extension::CCNodeLoader* loader);
};


#endif /* defined(__Benkyo__SceneChanger__) */
