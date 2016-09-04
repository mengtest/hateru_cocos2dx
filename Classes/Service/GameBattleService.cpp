//
//  GameBattleService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#include "GameBattleService.h"

#include "GameMainService.h"
#include "GameMapService.h"

/// インスタンス
GameBattleService *GameBattleService::instance;

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
GameBattleService::GameBattleService() {
}

/**
 *  デストラクタ
 */
GameBattleService::~GameBattleService() {
	instance = nullptr;
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameBattleService *GameBattleService::sharedInstance() {
	static once_flag flag;
	call_once(flag, GameBattleService::setupInstance);
	return instance;
}

/**
 *  インスタンスセットアップ
 */
void GameBattleService::setupInstance() {
	instance = new GameBattleService();
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
void GameBattleService::setup() {
	
	unitNames.clear();
	unitStatuses.clear();
	
	// プレイヤーステータス設定
	setupPlayerStatus();
}

/**
 *  プレイヤーのステータスを反映
 */
void GameBattleService::setupPlayerStatus() {
	
	auto mapService = GameMapService::sharedInstance();
	for (auto it = mapService->playerEntity.units.begin();it != mapService->playerEntity.units.end();it++) {
		// 自軍のキャラのステータス設定
		unitNames.push_back(it->name);
		auto statuses = it->battleStatuses();
		
		// 装備品からヒット数を検索
		statuses[BattleStatusTypeHit] = 0;
		for (auto itemIt = it->equipments.begin();itemIt != it->equipments.end();itemIt++) {
			if (*itemIt < 0) {
				continue;
			}
			auto itemEntity = GameMainService::sharedInstance()->getItem(*itemIt);
			if (statuses[BattleStatusTypeHit] < itemEntity->hitCount()) {
				statuses[BattleStatusTypeHit] = itemEntity->hitCount();
			}
		}
		
		unitStatuses.push_back(statuses);
	}
}


