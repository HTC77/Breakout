#include "GameOverLayer.h"
#include "HelloWorldScene.h"


CCScene* GameOverLayer::scene(bool won)
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameOverLayer *layer = GameOverLayer::create(won);

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
GameOverLayer* GameOverLayer::create(bool won)
{
	GameOverLayer* gamover = new GameOverLayer();
	if (gamover && gamover->init(won))
	{
		gamover->autorelease();
		return gamover;
	}
	CC_SAFE_DELETE(gamover);
	return NULL;
}

// on "init" you need to initialize your instance
bool GameOverLayer::init(bool won)
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}


	winSize = CCDirector::sharedDirector()->getWinSize();
	/*if ((this == CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)))) 
	{*/

	CCString * message;
	if (won) {
		message = CCString::create("You Won!");
	}
	else {
		message = CCString::create("You Lose :[");
	}
	CCLabelTTF* label = CCLabelTTF::create(message->getCString(), "Arial", 32);

	label->setColor(ccc3(won ? 255, 0, 0 : 255,255,255));
	label->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->addChild(label);
	CCCallFuncN* gbCall = CCCallFuncN::create(label, callfuncN_selector(GameOverLayer::goBack));

	this->runAction(CCSequence::create(
		CCDelayTime::create(3),
		gbCall,NULL));
	return true;
}

void GameOverLayer::goBack(CCNode* pSender)
{
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

