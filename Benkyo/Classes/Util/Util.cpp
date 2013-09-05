//
//  Util.cpp
//  chaos
//
//  Created by B03744 on 13/03/27.
//  Copyright (c) 2013年 Applibot inc. All rights reserved.
//

#include "Util.h"
#include <sstream>
#include <iomanip>
#include <zlib.h>

#ifdef iOS
#include <CommonCrypto/CommonCrypto.h>
#endif
#include <fstream>


using namespace cocos2d;
using namespace extension;
//using namespace CocosDenshion;

namespace Chaos {
    namespace Util {
        
        //---------------------------------------
        //	パーツの取得
        //---------------------------------------
        CCNode* Util::loadParts(const char* fileName) {
            CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
            CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
            CCString* file = CCString::createWithFormat("%s.ccbi", fileName);
            CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
            ccbReader->release();
            return node;
        }
        
        //---------------------------------------
        //	カスタムクラスのパーツの取得(クラス名指定あり)
        //---------------------------------------
        CCNode* Util::loadCustomParts(const char* className, const char* fileName, CCNodeLoader* loader) {
            CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
            ccNodeLoaderLibrary->registerCCNodeLoader(className, loader);
            CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
            CCString* file = CCString::createWithFormat("%s.ccbi", fileName);
            CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
            ccbReader->release();
            return node;
        }
        
        //---------------------------------------
        //	カスタムクラスのパーツの取得(クラス名指定なし)
        //---------------------------------------
        CCNode* Util::loadCustomParts(const char* ccbiName, CCNodeLoader* loader) {
            CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
            ccNodeLoaderLibrary->registerCCNodeLoader(ccbiName, loader);
            CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
            CCString* file = CCString::createWithFormat("%s.ccbi", ccbiName);
            CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
            ccbReader->release();
            return node;
        }
        
        
        //---------------------------------------
        //	シーン読み込み
        //---------------------------------------
        void Util::loadScene(const char* ccbiName, CCNodeLoader* loader, bool cacheClear) {
            

            
            CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
            ccNodeLoaderLibrary->registerCCNodeLoader(ccbiName, loader);
            CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
            CCString* file = CCString::createWithFormat("%s.ccbi", ccbiName);
            CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
            CCScene* scene = CCScene::create();
            if(node != NULL) {
                scene->addChild(node);
            }
            ccbReader->release();
            CCDirector::sharedDirector()->replaceScene(scene);
            
            if(cacheClear)
            {
                CCTextureCache::sharedTextureCache()->removeUnusedTextures();
            }
        }
        
        //---------------------------------------
        //	シーン読み込み フェードアウト
        //---------------------------------------
        void Util::loadSceneFadeOut(const char* ccbiName, CCNodeLoader* loader, float fadeTime, bool cacheClear) {
            
            
            CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
            ccNodeLoaderLibrary->registerCCNodeLoader(ccbiName, loader);
            CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
            CCString* file = CCString::createWithFormat("%s.ccbi", ccbiName);
            CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
            CCScene* scene = CCScene::create();
            if(node != NULL) {
                scene->addChild(node);
            }
            ccbReader->release();
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(fadeTime, scene, ccc3(0, 0, 0)));
            
            if(cacheClear)
            {
                CCTextureCache::sharedTextureCache()->removeUnusedTextures();
            }
        }
        
        //---------------------------------------
        //	ノード読み込み
        //---------------------------------------
        CCNode* Util::loadNode(const char* ccbiName, CCNodeLoader* loader) {
            CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
            ccNodeLoaderLibrary->registerCCNodeLoader(ccbiName, loader);
            CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
            CCString* file = CCString::createWithFormat("%s.ccbi", ccbiName);
            CCNode* node = ccbReader->readNodeGraphFromFile(file->getCString());
            ccbReader->release();
            
            return node;
        }
        
        //---------------------------------------
        //	シーン読み込み (Nodeから)
        //---------------------------------------
        void Util::replaceScene(CCNode* node) {
            CCScene* scene = CCScene::create();
            if(node != NULL) {
                scene->addChild(node);
            }
            CCDirector::sharedDirector()->replaceScene(scene);
        }
        //---------------------------------------
        //	シーン読み込み フェードアウト(Nodeから)
        //---------------------------------------
        void Util::replaceSceneFadeOut(CCNode* node , float fadeTime ) {
            CCScene* scene = CCScene::create();
            if(node != NULL) {
                scene->addChild(node);
            }
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(fadeTime, scene, ccc3(0, 0, 0)));
        }
        
        



        
    }}
