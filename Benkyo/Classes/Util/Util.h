//
//  Util.h
//  Benkyo
//
//  Created by B02582 on 2013/09/04.
//
//

#ifndef __Benkyo__Util__
#define __Benkyo__Util__

#include <iostream>

#include "cocos2d.h"
#include "CCNodeLoaderLibrary.h"

using namespace cocos2d;
using namespace extension;

class Util{
    
    static CCNode* loadParts(const char* fileName);
    static CCNode* loadCustomParts(const char* className, const char* fileName, extension::CCNodeLoader* loader);
};


#endif /* defined(__Benkyo__Util__) */
