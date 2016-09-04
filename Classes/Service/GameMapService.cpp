//
//  GameMapService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#include "GameMapService.h"

/// インスタンス
GameMapService *GameMapService::instance;

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
GameMapService::GameMapService() {
}

/**
 *  デストラクタ
 */
GameMapService::~GameMapService() {
	instance = nullptr;
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameMapService *GameMapService::sharedInstance() {
	static once_flag flag;
	call_once(flag, GameMapService::setupInstance);
	return instance;
}

/**
 *  インスタンスセットアップ
 */
void GameMapService::setupInstance() {
	instance = new GameMapService();
	if (instance == nullptr) {
		delete instance;
		instance = nullptr;
		return;
	}
	instance->Ref::autorelease();
}

/**
 *  セットアップ
 */
void GameMapService::setup() {

}