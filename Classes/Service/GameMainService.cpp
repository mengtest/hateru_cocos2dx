//
//  GameMainService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMainService.h"

#include <mutex>

#include "GameInfoManager.h"
#include "GameMapChipGroupManager.h"
#include "GameEnemyManager.h"
#include "GameCharaManager.h"
#include "GameItemManager.h"
#include "GameJobManager.h"
#include "GameSkillManager.h"
#include "GameVariableManager.h"

/// インスタンス
GameMainService *GameMainService::instance;

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
GameMainService::GameMainService() {
}

/**
 *  デストラクタ
 */
GameMainService::~GameMainService() {
	instance = nullptr;
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameMainService *GameMainService::sharedInstance() {
	static once_flag flag;
	call_once(flag, GameMainService::setupInstance);
	return instance;
}

/**
 *  インスタンスセットアップ
 */
void GameMainService::setupInstance() {
	instance = new GameMainService();
	if (instance == nullptr) {
		delete instance;
		instance = nullptr;
		return;
	}
	
	instance->Ref::autorelease();

	// ゲーム情報取得
	instance->loadAll();
}

#pragma mark - 読み込み

/**
 *  全ての情報を取得する
 */
void GameMainService::loadAll() {
	// ゲーム情報
	gameInfo = GameInfoManager::load();
	// マップチップグループ情報
	mapChipGroups = GameMapChipGroupManager::load();
	/// 敵情報
	enemies = GameEnemyManager::load();
	/// キャラ情報
	charas = GameCharaManager::load();
	/// アイテム情報
	items = GameItemManager::load();
	/// 職業情報
	jobs = GameJobManager::load();
	/// 特技情報
	skills = GameSkillManager::load();
	/// 変数情報
	variables = GameVariableManager::load();
}


