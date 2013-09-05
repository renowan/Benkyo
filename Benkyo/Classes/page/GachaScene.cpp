#include "GachaScene.h"
#include "cocos-ext.h"
#include "GachaLayer.h"

using namespace cocos2d;
using namespace extension;

bool GachaScene::init()
{
	CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
	ccNodeLoaderLibrary->registerCCNodeLoader("Page1Layer", GachaBuilderLoader::loader());
    
	cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    
	animationManager = NULL;
    
	CCNode* node = ccbReader->readNodeGraphFromFile("page/gacha.ccbi");
    
    CCLOG ("%s \n", "Gahca Scene  ");
    
	ccbReader->release();
    
	if(node != NULL)
	{
		this->addChild(node);
	}
    
    
	return true;
}

