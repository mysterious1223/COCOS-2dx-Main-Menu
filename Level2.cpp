
#include "Level2.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Level2::createScene()
{
	return Level2::create();
}
bool Level2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto win_size = Director::getInstance()->getWinSize();

	auto bksprite = Sprite::create("Background.png");


	if (bksprite == nullptr)
	{
		printf("failed to load");

	}
	else
	{
		bksprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		bksprite->setContentSize(win_size);
		this->addChild(bksprite);
	}


	auto item1_l = Sprite::create("Ball.png");
	auto item2_l = Sprite::create("Ball.png");
	if (item1_l == nullptr && item2_l == nullptr)
	{
		printf("failed to load");
		return false;
	}
	else
	{
		item1_l->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		item1_l->setScale(2);
		item2_l->setPosition(Point(item1_l->getPositionX() , item1_l->getPositionY() - item1_l->getContentSize().height * 2)); 
		//item1_l->setContentSize(win_size);
	
		item2_l->setScale(2);
		this->addChild(item1_l);
		this->addChild(item2_l);
	}




	return true;
}