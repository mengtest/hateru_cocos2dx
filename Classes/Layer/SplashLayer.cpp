//
//  SplashLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "SplashLayer.h"

#include "TokenGetFetcher.h"

#include "GameMainService.h"
#include "UnitSprite.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
SplashLayer *SplashLayer::create() {
	auto layer = new SplashLayer();
	if(layer && layer->init()){
		layer->Layer::autorelease();
		layer->initLayer();
		return layer;
	}else {
		delete layer;	
		layer = nullptr;
		return nullptr;
	}
}

/**
 *  コンストラクタ
 */
SplashLayer::SplashLayer() {
	
}

/**
 *  デストラクタ
 */
SplashLayer::~SplashLayer() {
	
}

/**
 *  レイヤー初期化
 */
void SplashLayer::initLayer() {
	
//	this->set(Color3B(255, 255, 255));
	
	
	// スプラッシュ設定
	auto unitSprite = UnitSprite::create(GameMainService::sharedInstance()->charas[1]);
	unitSprite->setScale(4);
	unitSprite->setPosition(Vec2(300,200));
	addChild(unitSprite);
	
//	auto spriteSplash = Sprite::create("game/Chara/000.png");
//	spriteSplash->setScale(4);
//	spriteSplash->setPosition(Vec2(300,200));
//	auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("004.png");
//	spriteSplash->setSpriteFrame(frame);
//
//	this->addChild(spriteSplash);
	
	
}

/**
 *  レイヤーメイン処理
 */
void SplashLayer::layerMain() {
	
}

