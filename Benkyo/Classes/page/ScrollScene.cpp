#include "ScrollScene.h"
#include "cocos-ext.h"
#include "cocos2d.h"

USING_NS_CC;


CCScene* ScrollScene::scene()
{
    CCScene *scene = CCScene::create();
    ScrollScene *layer = ScrollScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool ScrollScene::init()
{
    
    if ( !RecipeBase::init() )
    {
        return false;
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCLayer* scrollContainer = CCLayer::create(); // Container for the scroll view
    scrollContainer->setAnchorPoint(CCPointZero); // CCScrollView does this too when it's set as the container.
    
    
    CCLayerColor* panelBg = CCLayerColor::create(ccc4(51, 51, 51, 255),640,2000);
    panelBg->setPosition(ccp(0,0));
    scrollContainer->addChild(panelBg,2);
    
    // Content for the container
    CCSprite *tallContentA = CCSprite::create("image/quest/05ev_210222.png");
    tallContentA ->setPosition(ccp(winSize.width*0.5f, 700));
    CCSprite *tallContentB = CCSprite::create("image/quest/07ev_210232.png");
    tallContentB ->setPosition(ccp(winSize.width*0.5f, 200));
    CCSprite *tallContentC = CCSprite::create("image/quest/07ev_210232.png");
    tallContentC ->setPosition(ccp(winSize.width*0.5f, 900));
    CCSprite *tallContentD = CCSprite::create("image/quest/07ev_210232.png");
    tallContentD ->setPosition(ccp(winSize.width*0.5f, 1400));
    scrollContainer->addChild(tallContentA, 2);
    scrollContainer->addChild(tallContentB, 2);
    scrollContainer->addChild(tallContentC, 2);
    scrollContainer->addChild(tallContentD, 2);
    
    float scrollContainerHeight = tallContentA->getContentSize().height + tallContentB->getContentSize().height;
    scrollContainer->setPosition(CCPointZero);
    scrollContainer->setContentSize(CCSizeMake(640, 2000));
    
    
    
    // Set up scroll view
    cocos2d::extension::CCScrollView* scrollView = cocos2d::extension::CCScrollView::create(ccp(640, 960), scrollContainer);
    scrollView->setPosition(ccp(0, 100));
    scrollView->setDirection(cocos2d::extension::kCCScrollViewDirectionVertical);
    
    // ScrollView initializes at the (left, bottom). The container also gets positioned relative to that and goes Y-up.
    // Pre-set it to the value CCScrollView::minContainerOffset will return when it's scrolled to the top
    // (note, this is a negative number, indicating the touch moving downwards, i.e. it's pre-scrolled such that the top of the content is visible when we begin)
    
    scrollView->setContentOffset(ccp(0, 0));
    CCLOG("test : %f",winSize.height-scrollContainerHeight*1.05f);
    /*
     // (StackOverflow Post Edit: This hack is not required.)
     // Hack: CCScrollView's maxContainerOffset is (0, 0) and minContainerOffset is (difference between view and content size which is negative)
     // It's designed to be (left, bottom) based and positive scrolling means showing stuff above the top of the screen.
     // Since we're using it in terms of Window coordinates ((left, top) based), we scale the scroll view
     // and it's container's children by -1 and position the children differently
     // (eg. Y position winSize.height*0.1f was changed to winSize.height*0.9f)
     // We can't just set the scroll view's Y scale to -1 because CCNode::getScale asserts that X and Y scale must be the same.
     scrollView->setScale(-1.f);
     tallContentA->setScale(-1.f);
     tallContentB->setScale(-1.f);
     */
    
    this->addChild(scrollView);
    
	return true;
}

