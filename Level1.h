
#ifndef __LEVEL1_H__
#define __LEVEL1_H__

#include "cocos2d.h"

class Level1 : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
   // void menuCloseCallback(cocos2d::Ref* pSender);
	void Item1CallBack(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(Level1);
};

#endif // __LEVEL1_H__
