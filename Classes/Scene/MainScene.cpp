//
//  MainScene.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "MainScene.h"
#include "MapLayer.h"

#include <mutex>

/// メインシーンインスタンス
MainScene *MainScene::mainSceneInstance = nullptr;

/**
 *  コンストラクタ
 */
MainScene::MainScene() {
	auto layer = MapLayer::create();
	this->addChild(layer);
}

/**
 *  デストラクタ
 */
MainScene::~MainScene() {
}

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
MainScene *MainScene::sharedInstance() {
	static once_flag flag;
	call_once(flag, setupInstance);
	return mainSceneInstance;
}

/**
 *  インスタンス設定
 */
void MainScene::setupInstance() {
	mainSceneInstance = (MainScene *)create();
}

/**
 *  ゲームスタート
 */
void MainScene::startGame() {
	this->scheduleUpdate();
}

// 初期化
void MainScene::initMode(
						 MainSceneGameMode mode,
						 int updateFlag
						 )
{
	// モード退避
	gameModeBefore = gameMode;
	gameMode = mode;
	
	switch(mode){
		case MainSceneGameModeSplash:
			break;
		default:
			break;
	}
}

/**
 *  更新処理
 *
 *  @param delta デルタ
 */
void MainScene::update(float delta) {
	
}
