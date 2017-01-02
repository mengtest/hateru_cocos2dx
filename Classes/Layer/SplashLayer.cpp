//
//  SplashLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "SplashLayer.h"

#include "TokenGetFetcher.h"

#include "GameDataService.h"
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
	
	setBackgroundColor(Color4B(255, 255, 255, 255));
	
	// スプラッシュ設定
	auto unitSprite = UnitSprite::create(GameDataService::sharedInstance()->charas[5]);
	unitSprite->setScale(4);
	unitSprite->setPosition(Vec2(0, 0));
	addChild(unitSprite);
}

/**
 *  レイヤーメイン処理
 */
void SplashLayer::layerMain() {
	
}

