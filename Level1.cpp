
#include "Level1.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* Level1::createScene()
{
	return Level1::create();
}
bool Level1::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();



	return true;
}