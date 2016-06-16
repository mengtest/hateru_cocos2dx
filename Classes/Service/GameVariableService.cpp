//
//  GameVariableService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameVariableService.h"
#include "GameVariableManager.h"

/**
 *  コンストラクタ
 */
GameVariableService::GameVariableService() {
	// 読み込み
	variables = GameVariableManager::load();
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameVariableService &GameVariableService::getInstance() {
	static GameVariableService instance;
	return instance;
}

/**
 *  名前よりデータ取得
 *
 *  @param id ID
 *
 *  @return 対象データ (なし:nullptr)
 */
GameVariableEntity *GameVariableService::data(int32_t id) {
	if (variables.find(id) == variables.end()) {
		return nullptr;
	}
	return &variables[id];
}

