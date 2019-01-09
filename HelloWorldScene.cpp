
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Level1.h"
#include "Level2.h"
#include <vector>
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		//origin.y + visibleSize.height - label->getContentSize().height));

	Label* Title = Label::createWithTTF("I AM MENU EXAMPLE", "fonts/Marker Felt.ttf", 35);

	Label* item1Label = Label::createWithTTF("Item 1", "fonts/Marker Felt.ttf", 24);
	Label* item2Label = Label::createWithTTF("Item 2", "fonts/Marker Felt.ttf", 24);


	item1Label->setTextColor(Color4B::WHITE);
	item2Label->setTextColor(Color4B::WHITE);

	MenuItemLabel * item1 = MenuItemLabel::create(item1Label, CC_CALLBACK_1( HelloWorld::Item1CallBack, this));
	MenuItemLabel * item2 = MenuItemLabel::create(item2Label, CC_CALLBACK_1(HelloWorld::Item2CallBack, this));




	item1->setPosition(Vec2(origin.x, origin.y));

	item2->setPosition(Vec2(origin.x, origin.y - item1->getContentSize().height));

	Title->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - Title->getContentSize().height));

	Menu* myMainMenu = Menu::create();

	myMainMenu->addChild(item1,0);
	myMainMenu->addChild(item2, 0);

	this->addChild(myMainMenu);

	this->addChild(Title);
	
    return true;
}

void HelloWorld::Item1CallBack(cocos2d::Ref * pSender)
{
	auto scene = Level1::createScene();
	//GameScene::setScene(&scene);
	//Director::getInstance()->runWithScene(scene);
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

void HelloWorld::Item2CallBack(cocos2d::Ref * pSender)
{
	auto scene = Level2::createScene();
	//GameScene::setScene(&scene);
	//Director::getInstance()->runWithScene(scene);
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}




