//
//  SceneChanger.cpp
//  Benkyo
//
//  Created by B02582 on 2013/09/04.
//
//

#include "SceneChanger.h"
#include "CCBReader.h"
#include <CommonCrypto/CommonCrypto.h>

using namespace cocos2d;
using namespace extension;

//---------------------------------------
//	パーツの取得
//---------------------------------------
CCNode* SceneChanger::loadParts(const char* fileName)
{
    CCNodeLoaderLibrary * ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    extension::CCBReader* ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    CCString* file = cocos2d::CCString::createWithFormat("%s.ccbi", fileName);
    CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
    
    ccbReader->release();
    return node;
};


//---------------------------------------
//	カスタムクラスのパーツの取得(クラス名指定あり)
//---------------------------------------
CCNode* SceneChanger::loadCustomParts(const char* className, const char* fileName, CCNodeLoader* loader) {
    CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader(className, loader);
    CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
    CCString* file = CCString::createWithFormat("%s.ccbi", fileName);
    CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
    ccbReader->release();
    return node;
}