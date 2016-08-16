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

/// インスタンス
SplashScene *SplashScene::instance;

/**
 *  インストラクタ
 */
SplashScene::SplashScene() {
	
	// キャッシュ
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images.plist");
	
	auto layer = SplashLayer::create();
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
