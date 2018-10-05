#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "Box2D\Box2D.h"
#define PTM_RATIO 32.0
#include "cocos2d.h"
#include "MyContactListener.h"
USING_NS_CC;
class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
	CCSize winSize;
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	b2World* _world;
	b2Body* _groundBody;
	b2Fixture* _bottomFixture;
	b2Fixture* _ballFixture;
	void tick(float dt);
	~HelloWorld();
	void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
	void ccTouchesMoved(CCSet* pTouches, CCEvent* event);
	void ccTouchesEnded(CCSet* pTouches, CCEvent* event);
	void ccTouchesCanceled(CCSet* pTouches, CCEvent* event);
	b2Body * ballBody;
	b2BodyDef ballBodyDef;

	b2Body *_paddleBody;
	b2Fixture *_paddleFixture;

	b2MouseJoint *_mouseJoint;
	bool onPaddle;

	MyContactListener *_contactListener;	
};

#endif // __HELLOWORLD_SCENE_H__
