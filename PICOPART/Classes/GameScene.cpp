/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"


USING_NS_CC;



Scene* GameScreen::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));
    scene->getPhysicsWorld()->setDebugDrawMask(0);

    // 'layer' is an autorelease object
    auto layer = GameScreen::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene

    return scene;
}



// on "init" you need to initialize your instance
bool GameScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
       
    }
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point origin = Director::getInstance()->getVisibleOrigin();

auto pauseItem = MenuItemImage::create("Pause.png","Pause(Click).png",CC_CALLBACK_1(GameScreen::GoToPauseScene, this));  
        pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 4) +
                                     origin.x,visibleSize.height - pauseItem->getContentSize().height +
                                    (pauseItem->getContentSize().width / 4) + origin.y));
        auto menu = Menu::create(pauseItem, NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu);

        
        //backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
        //this->addChild(backgroundSprite, -1);

//*******************************************************************************************************************
        
      

//*******************************************************************************************************************

       mySprite = Sprite::create("WASHA.png");
       mySprite->setAnchorPoint(Vec2(0.5, 0.5));
       mySprite->setPosition(Vec2(50, 60));
     //  mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
       mySprite->setScale(0.3);
       mySprite->setName("mySprite");
        this->addChild(mySprite, 2);
      

 //******************************************************************************************************************

        auto eventListener = EventListenerKeyboard::create();



        eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
            int offsetX = 0, offsetY = 0;

            switch (keyCode) {
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                offsetX = -30;

                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                offsetX = 30;
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                offsetY = 30;
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                offsetY = -30;
                break;
            }


            auto moveTo = MoveTo::create(0.3, Vec2(event->getCurrentTarget()->getPositionX() + offsetX, event->getCurrentTarget()->getPositionY() + offsetY));
            event->getCurrentTarget()->runAction(moveTo);


        };
        this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, mySprite);

 //****************************************************************************************************************

          auto physicsBody1 = PhysicsBody::createBox(mySprite->getContentSize(), PhysicsMaterial(1000.0f, 0.55f, 0.55f));
        physicsBody1->setDynamic(true);
        physicsBody1->setContactTestBitmask(1);
        physicsBody1->setRotationEnable(false);
        physicsBody1->setCollisionBitmask(1);
        mySprite->setPhysicsBody(physicsBody1);
        Vec2 force = Vec2(0, -physicsBody1->getMass() * 11.8f);
        physicsBody1->applyForce(force); 

 //******************************************************************************************************************

        auto backgroundSprite = Sprite::create("backgroundTEST.jpg");
        backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

        this->addChild(backgroundSprite, -1);
       // backgroundSprite->setAnchorPoint(Vec2(0, 0));
       // backgroundSprite->setPosition(Vec2(30, 30));
       //  backgroundSprite->setScale(1);
       //  this->addChild(backgroundSprite, 0);

//******************************************************************************************************************


        auto* floor2 = Sprite::create("CLOUD.png");
        floor2->setAnchorPoint(Vec2(0, 0));
        floor2->setPosition(Vec2(30, 25));
        floor2->setScale(0.2);
        this->addChild(floor2, 1);


        auto physicsBody_floor2 = PhysicsBody::createBox(floor2->getContentSize(), PhysicsMaterial(500.0f, 0.1f, 0.9f));
        physicsBody_floor2->setDynamic(false);
        physicsBody_floor2->setCollisionBitmask(1);
        physicsBody_floor2->setCategoryBitmask(1);


        floor2->setPhysicsBody(physicsBody_floor2);

 //******************************************************************************************************************

/*
        auto* floor3 = Sprite::create("CLOUD.png");
        floor3->setAnchorPoint(Vec2(0, 0));
        floor3->setPosition(Vec2(240, 25));
        floor3->setScale(0.23);
        this->addChild(floor3, 1);


        auto physicsBody_floor3 = PhysicsBody::createBox(floor3->getContentSize(), PhysicsMaterial(500.0f, 0.1f, 0.9f));
        physicsBody_floor3->setDynamic(false);
        physicsBody_floor3->setCollisionBitmask(1);
        physicsBody_floor3->setCategoryBitmask(1);


        floor2->setPhysicsBody(physicsBody_floor3); */

//******************************************************************************************************************

        auto* floor4 = Sprite::create("CLOUD.png");
        floor4->setAnchorPoint(Vec2(0, 0));
        floor4->setPosition(Vec2(220, 25));
        floor4->setScale(0.2);
        this->addChild(floor4, 1);


        auto physicsBody_floor4 = PhysicsBody::createBox(floor4->getContentSize(), PhysicsMaterial(1500.0f, 0.1f, 0.9f));
        physicsBody_floor4->setDynamic(false);
        physicsBody_floor4->setCollisionBitmask(1);
        physicsBody_floor4->setCategoryBitmask(1);


        floor4->setPhysicsBody(physicsBody_floor4);

 //******************************************************************************************************************

        auto* floor5 = Sprite::create("CLOUD.png");
        floor5->setAnchorPoint(Vec2(0, 0));
        floor5->setPosition(Vec2(400, 25));
        floor5->setScale(0.2);
        this->addChild(floor5, 1);


        auto physicsBody_floor5 = PhysicsBody::createBox(floor5->getContentSize(), PhysicsMaterial(0.1f, 0.1f, 0.9f));
        physicsBody_floor5->setDynamic(false);
        physicsBody_floor5->setCollisionBitmask(1);
        physicsBody_floor5->setCategoryBitmask(1);


        floor5->setPhysicsBody(physicsBody_floor5);

//******************************************************************************************************************

       


    return true;
}



void GameScreen::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene =  PauseMenu ::createScene();
    //Director::getInstance()->replaceScene(TransitionPageTurn::create(3, scene, false));
    Director::getInstance()->pushScene(scene);
}
void GameScreen::GoToGameOverScene(cocos2d::Ref* pSender)
{
    auto scene = GameOver::createScene();
    //Director::getInstance()->replaceScene(TransitionPageTurn::create(3, scene, false));
    Director::getInstance()->replaceScene(scene);
}
   