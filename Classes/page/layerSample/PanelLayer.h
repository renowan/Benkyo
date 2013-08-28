//
//  ModalScene.h
//  Modal
//
//  Created by Akihiro Matsuura on 5/22/13.
//  Copyright 2013 Syuhari, Inc. All rights reserved.
//
//

#ifndef __Modal__ModalScene__
#define __Modal__ModalScene__

#include "cocos2d.h"

class PanelLayer : public cocos2d::CCLayer
{
    
public:
    virtual bool init();
    void runLayerFunc( int value );
    CREATE_FUNC(PanelLayer);


};

#endif /* defined(__Modal__ModalScene__) */
