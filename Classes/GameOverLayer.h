#include "cocos2d.h"
#ifndef __Breakout__GameOver__
#define __Breakout__GameOver__

USING_NS_CC;
class GameOverLayer : CCLayer
{
public:
	virtual bool init(bool won);

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene(bool won);
	CCSize winSize;
	// implement the "static node()" method manually
	static	GameOverLayer* create(bool won);
	void goBack(CCNode* pSender);
};
#endif // !__Breakout__GameOver__
