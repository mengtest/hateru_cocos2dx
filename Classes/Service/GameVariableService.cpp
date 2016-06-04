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
 *  @param name 名前
 *
 *  @return 対象データ (なし:nullptr)
 */
GameVariableEntity *GameVariableService::data(const string name) {
	if (variables.find(name) == variables.end()) {
		return nullptr;
	}
	return &variables[name];
}

