//
//  SplashScene.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#include "SplashScene.h"
#include "SplashLayer.h"
#include <mutex>

#include "FileConst.h"

#include "MapLayer.h"
#include "GameMapService.h"

/// インスタンス
SplashScene *SplashScene::instance;

/**
 *  インストラクタ
 */
SplashScene::SplashScene() {
	
	// キャッシュ
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(GAME_IMAGES_FILE_NAME);
	
	auto service = GameMapService::sharedInstance();
	service->newGame();
	
	auto layer = MapLayer::create();
	layer->setupMapLayer(service->mapEntity);
	layer->setUnitPosition(Point(60, 0));
	
//	auto layer = SplashLayer::create();
	this->addChild(layer);
}

/**
 *  デストラクタ
 */
SplashScene::~SplashScene() {
	
}

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
SplashScene *SplashScene::sharedInstance() {
	static once_flag flag;
	call_once(flag, setupInstance);
	return instance;
}

/**
 *  インスタンス設定
 */
void SplashScene::setupInstance() {
	instance = (SplashScene *)create();
}

/**
 *  更新処理
 *
 *  @param delta デルタ
 */
void SplashScene::update(float delta) {
	
}
