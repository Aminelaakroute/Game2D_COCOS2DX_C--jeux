
#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* GameOver::createScene()
{
    auto  scene = Scene::create();

    auto layer = GameOver::create();

    scene->addChild(layer);

    return scene;
    //return HelloWorld::create();
}


// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
       
    }
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Point  origin = Director::getInstance()->getVisibleOrigin();



        auto menuTitle =MenuItemImage::create("GameOver.png","GameOver.png");
        auto retryItem =MenuItemImage::create("Retry.png","Retry(Click).png",CC_CALLBACK_1(GameOver::GoToGameScene, this));
        auto mainMenuItem =MenuItemImage::create("Menu.png","Menu(Click).png",CC_CALLBACK_1(GameOver::GoToMainMenuScene, this));

        auto menu = Menu::create(menuTitle, retryItem, mainMenuItem,NULL);

        menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);

        this->addChild(menu);


        
        
  
    return true;
}

void GameOver::GoToGameScene(cocos2d::Ref* pSender)
{
    auto scene = GameScreen::createScene();
    
    Director::getInstance()->replaceScene(scene);
}
void GameOver::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();
    
    Director::getInstance()->replaceScene(scene);
}

   