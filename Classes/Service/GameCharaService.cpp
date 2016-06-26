//
//  GameCharaService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameCharaService.h"
#include "GameCharaManager.h"

/**
 *  コンストラクタ
 */
GameCharaService::GameCharaService() {
	// 読み込み
//	charas = GameCharaManager::load();
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameCharaService &GameCharaService::getInstance() {
	static GameCharaService instance;
	return instance;
}

/**
 *  名前よりデータ取得
 *
 *  @param name 名前
 *
 *  @return 対象データ (なし:nullptr)
 */
GameCharaEntity *GameCharaService::data(const string name) {
	if (charas.find(name) == charas.end()) {
		return nullptr;
	}
	return &charas[name];
}