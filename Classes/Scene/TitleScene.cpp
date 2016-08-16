//
//  TitleScene.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/15.
//
//

#include "TitleScene.h"
#include "TitleLayer.h"
#include <mutex>

/// インスタンス
TitleScene *TitleScene::instance;

/**
 *  インストラクタ
 */
TitleScene::TitleScene() {
	auto layer = TitleLayer::create();
	this->addChild(layer);
}

/**
 *  デストラクタ
 */
TitleScene::~TitleScene() {
	
}

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
TitleScene *TitleScene::sharedInstance() {
	static once_flag flag;
	call_once(flag, setupInstance);
	return instance;
}

/**
 *  インスタンス設定
 */
void TitleScene::setupInstance() {
	instance = (TitleScene *)create();
}

/**
 *  更新処理
 *
 *  @param delta デルタ
 */
void TitleScene::update(float delta) {
	
}

