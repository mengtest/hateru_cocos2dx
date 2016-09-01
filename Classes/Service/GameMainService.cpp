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
#include "GameMapManager.h"
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

	// 初期化
	instance->mapId = -1;
	
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

#pragma mark - Getter

/**
 *  ゲーム情報取得
 *
 *  @return ゲーム情報
 */
GameInfoEntity *GameMainService::getGameInfo() {
	return &gameInfo;
}

/**
 *  マップ取得
 *
 *  @param id ID
 *
 *  @return マップ
 */
GameMapEntity *GameMainService::getMap(const int id) {
	if (mapId != id) {
		mapId = id;
		gameMap = GameMapManager::load(id);
	}
	return &gameMap;
}

/**
 *  マップチップグループ取得
 *
 *  @param id ID
 *
 *  @return マップチップグループ
 */
GameMapChipGroupEntity *GameMainService::getMapChipGroup(const int id) {
	return &mapChipGroups[id];
}

/**
 *  敵情報取得
 *
 *  @param id ID
 *
 *  @return 敵情報
 */
GameEnemyEntity *GameMainService::getEnemy(const int id) {
	return &enemies[id];
}

/**
 *  キャラ情報取得
 *
 *  @param id ID
 *
 *  @return キャラ情報
 */
GameCharaEntity *GameMainService::getChara(const int id) {
	return &charas[id];
}

/**
 *  アイテム情報取得
 *
 *  @param id ID
 *
 *  @return アイテム情報
 */
GameItemEntity *GameMainService::getItem(const int id) {
	return &items[id];
}

/**
 *  アイテム数を取得
 *
 *  @return アイテム数
 */
int GameMainService::getItemCount() {
	return (int)items.size();
}

/**
 *  職種情報取得
 *
 *  @param id ID
 *
 *  @return 職種情報
 */
GameJobEntity *GameMainService::getJob(const int id) {
	return &jobs[id];
}

/**
 *  スキル情報取得
 *
 *  @param id ID
 *
 *  @return スキル情報
 */
GameSkillEntity *GameMainService::getSkill(const int id) {
	return &skills[id];
}

/**
 *  スキル数を取得
 *
 *  @return スキル数
 */
int GameMainService::getSkillCount() {
	return (int)skills.size();
}

/**
 *  変数情報取得
 *
 *  @param id ID
 *
 *  @return 変数情報
 */
GameVariableEntity *GameMainService::getVariable(const int id) {
	return &variables[id];
}


