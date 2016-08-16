//
//  MainScene.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "MainScene.h"

#include <mutex>

/// メインシーンインスタンス
MainScene *MainScene::mainSceneInstance = nullptr;

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
 *  コンストラクタ
 */
MainScene::MainScene() {
}

/**
 *  デストラクタ
 */
MainScene::~MainScene() {
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
