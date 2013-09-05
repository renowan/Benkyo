//
//  Util.h
//  chaos
//
//  Created by B03744 on 13/03/27.
//  Copyright (c) 2013年 Applibot inc. All rights reserved.
//

#pragma once

#include "cocos2d.h"
#include "CCNodeLoaderLibrary.h"


#define loaderTag 100050



namespace Chaos {
	namespace CCB {
	namespace Parts {
	namespace Cell { class CCBPartsCellCard; }

    
    
namespace Util {
	//---------------------------------------------------------------------
	//	class: Util
	//---------------------------------------------------------------------
	class Util {
		//-----------------------------------------------------------------
		// 型
    private:
		//-----------------------------------------------------------------
		// 変数
		//-----------------------------------------------------------------
		// 関数
	public:
				Util	() {}			// コンストラクタ
		virtual	~Util	() {}			// デストラクタ
		
	public:
        static cocos2d::CCNode* loadParts(const char* fileName);
        static cocos2d::CCNode* loadCustomParts(const char* className, const char* fileName, cocos2d::extension::CCNodeLoader* loader);
        static cocos2d::CCNode* loadCustomParts(const char* ccbiName, cocos2d::extension::CCNodeLoader* loader);
		static void				loadScene			(const char* ccbiName, cocos2d::extension::CCNodeLoader* loader, bool cacheClear = true);
		static void				loadSceneFadeOut	(const char* ccbiName, cocos2d::extension::CCNodeLoader* loader, float fadeTime = 0.3f, bool cacheClear = true);
		static cocos2d::CCNode*	loadNode			(const char* ccbiName, cocos2d::extension::CCNodeLoader* loader);
		static void				replaceScene	(cocos2d::CCNode* node);
		static void				replaceSceneFadeOut	(cocos2d::CCNode* node, float fadeTime = 0.3f);
        

	};
}}

    }}