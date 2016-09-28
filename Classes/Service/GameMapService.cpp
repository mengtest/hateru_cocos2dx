//
//  GameMapService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#include "GameMapService.h"

#include "GameDataService.h"
#include "PlayerManager.h"

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

#pragma mark - 初期化

/**
 *  ニューゲーム
 */
void GameMapService::newGame() {

	auto service = GameDataService::sharedInstance();
	
	// プレイヤーEntity初期化
	playerEntity.initialize();
	// お金
	playerEntity.money = service->gameInfo.initMoney;
	// メンバー
	for (auto it = service->gameInfo.initMemberIds.begin(); it != service->gameInfo.initMemberIds.end(); it++) {
		if (*it != 0) {
			playerEntity.addUnit(*it);
		}
	}
	// 初期位置
	playerEntity.location.id = service->gameInfo.initMapId;
	playerEntity.location.x = service->gameInfo.initX;
	playerEntity.location.y = service->gameInfo.initY;
	// 移動タイプ
	playerEntity.moveType = MoveTypeWalk;
	// 変数
	playerEntity.variables = service->getVariableInitValues();
	
	// マップ取得
	mapEntity = service->getMap(playerEntity.location.id);
}

/**
 *  コンティニューゲーム
 */
void GameMapService::continueGame() {
	
	// プレイヤーEntity初期化
	playerEntity.initialize();
	
	// 読み込み
	playerEntity = PlayerManager::load();

	// マップ取得
	mapEntity = GameDataService::sharedInstance()->getMap(playerEntity.location.id);
}

#pragma mark - 敵

/**
 *  遭遇敵情報取得
 *
 *  @param playerEntity プレイヤー情報
 *
 *  @return 遭遇敵情報
 */
vector<GameEnemyEntity> GameMapService::encoundEnemies() {
	return GameDataService::sharedInstance()->encoundEnemies(playerEntity);
}

/**
 *  敵に遭遇か
 *
 *  @return true: 遭遇、false: いない
 */
bool GameMapService::isEncount() {
	// レート
	if (mapEntity->enemyEncountRate <= (rand() % 100)) {
		return false;
	}
	// 敵
	return encoundEnemies().size() > 0;
}
