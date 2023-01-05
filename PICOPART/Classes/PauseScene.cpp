

#include "PauseScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
    auto  scene = Scene::create();
    auto layer = PauseMenu::create();
    scene->addChild(layer);
    return scene;
    //return HelloWorld::create();
}


// on "init" you need to initialize your instance
bool PauseMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
       
    }
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point origin = Director::getInstance()->getVisibleOrigin();


        auto resumeItem =MenuItemImage::create("Resume.png",
                                               "Resume(Click).png",
                                               CC_CALLBACK_1(PauseMenu::Resume, this));
        auto retryItem =MenuItemImage::create("Retry.png",
                                              "Retry(Click).png",
                                               CC_CALLBACK_1(PauseMenu::Retry, this));
        auto mainMenuItem =MenuItemImage::create("Menu.png",
                                                 "Menu(Click).png",
                                               CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
        auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,NULL);
        menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
        this->addChild(menu);


        auto backgroundSprite = Sprite::create("Background1.jpg");
        backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
        this->addChild(backgroundSprite, -1);

    return true;
}
void PauseMenu::Resume(cocos2d::Ref *pSender)
{
    
    Director::getInstance()->popScene();
}
void PauseMenu::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
   
    Director::getInstance()->popScene();
    
    Director::getInstance()->replaceScene(scene);
   
}
void PauseMenu::Retry(cocos2d::Ref* pSender)
{
    auto scene = GameScreen::createScene();
    
    Director::getInstance()->popScene();
    
    Director::getInstance()->replaceScene(scene);
}