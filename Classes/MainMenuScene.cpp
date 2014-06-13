#include "MainMenuScene.h"
#include "GameplayScene.h"
#include "GAFPrecompiled.h"
#include "GAFAnimatedObject.h"

USING_NS_CC;


bool MainMenuScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();

    GAFAnimatedObject* logo = GAFAnimatedObject::createAndRun("logo/logo.gaf", false);
    logo->setPosition(0, visibleSize.height);
    addChild(logo);

    MenuItem* startButton = MenuItemSprite::create(
        Sprite::create("button_logo_idle.png"),
        Sprite::create("button_logo_selected.png"),
        CC_CALLBACK_1(MainMenuScene::advanceToGame, this));
    Menu* menu = Menu::create(startButton, NULL);

    startButton->setPosition(visibleSize.width / 2, 50);
    menu->setPosition(Vec2::ZERO);
    addChild(menu, 1);

    return true;
}


void MainMenuScene::advanceToGame(cocos2d::Ref* pSender)
{
    Scene* gameplay = GameplayScene::create();
    Director::getInstance()->pushScene(gameplay);
}

