//
//  GameMapService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/05.
//
//

#include "GameMapService.h"
#include "GameMapManager.h"

/**
 *  コンストラクタ
 */
GameMapService::GameMapService() {
	// 読み込み
	maps = GameMapManager::load();
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameMapService &GameMapService::getInstance() {
	static GameMapService instance;
	return instance;
}

/**
 *  名前よりデータ取得
 *
 *  @param name 名前
 *
 *  @return 対象データ (なし:nullptr)
 */
GameMapEntity *GameMapService::data(const string name) {
	if (maps.find(name) == maps.end()) {
		return nullptr;
	}
	return &maps[name];
}