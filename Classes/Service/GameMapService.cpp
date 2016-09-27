//
//  GameMapService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#include "GameMapService.h"

#include "GameMainService.h"

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
 *  ニューゲーム
 */
void GameMapService::newGame() {

	auto service = GameMainService::sharedInstance();
	auto gameInfo = service->getGameInfo();
	
	// プレイヤーEntity初期化
	playerEntity.initialize();
	// お金
	playerEntity.money = gameInfo->initMoney;
	// メンバー
	for (auto it = gameInfo->initMemberIds.begin(); it != gameInfo->initMemberIds.end(); it++) {
		playerEntity.addUnit(*it);
	}
	// 変数
	playerEntity.variables = service->getVariableInitValues();
}

/**
 *  遭遇敵情報取得
 *
 *  @param playerEntity プレイヤー情報
 *
 *  @return 遭遇敵情報
 */
vector<GameEnemyEntity> GameMapService::encoundEnemies() {
	return GameMainService::sharedInstance()->encoundEnemies(playerEntity);
}

/**
 *  敵に遭遇か
 *
 *  @return true: 遭遇、false: いない
 */
bool GameMapService::isEncount() {
	// レート
	if (mapEntity.enemyEncountRate <= (rand() % 100)) {
		return false;
	}
	// 敵
	return encoundEnemies().size() > 0;
}
