//
//  MainScene.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "MainScene.h"

/** メインシーンインスタンス */
static MainScene *mainSceneInstance = NULL;

/**
 *  インスタンスシェア
 *
 *  @return インスタンス
 */
MainScene* MainScene::sharedInstance() {
	if (mainSceneInstance == NULL){
		mainSceneInstance = (MainScene*)MainScene::create();
	}
	return mainSceneInstance;
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

/**
 *  更新処理
 *
 *  @param delta デルタ
 */
void MainScene::update(float delta) {
	
}
