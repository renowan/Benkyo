#include "QuestScene.h"
#include "cocos-ext.h"
#include "Page1Layer.h"

using namespace cocos2d;
using namespace extension;

bool QuestScene::init()
{
    
	CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
	ccNodeLoaderLibrary->registerCCNodeLoader("Page1Layer", Page1BuilderLoader::loader());
    
	cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    
	animationManager = NULL;
    
	CCNode* node = ccbReader->readNodeGraphFromFile("ccb/Scene/BattleScene.ccbi");
    
    CCLOG ("%s \n", "Quest Scene  ");
    
	ccbReader->release();
    
	if(node != NULL)
	{
		this->addChild(node);
	}
    
	return true;
}

