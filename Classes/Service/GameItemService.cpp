//
//  GameItemService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemService.h"
#include "GameItemManager.h"

/**
 *  コンストラクタ
 */
GameItemService::GameItemService() {
	// 読み込み
	items = GameItemManager::load();
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameItemService &GameItemService::getInstance() {
	static GameItemService instance;
	return instance;
}

/**
 *  名前よりデータ取得
 *
 *  @param name 名前
 *
 *  @return 対象データ (なし:nullptr)
 */
GameItemEntity *GameItemService::data(const string name) {
	if (items.find(name) == items.end()) {
		return nullptr;
	}
	return &items[name];
}