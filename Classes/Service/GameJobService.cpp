//
//  GameJobService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameJobService.h"
#include "GameJobManager.h"

/**
 *  コンストラクタ
 */
GameJobService::GameJobService() {
	// 読み込み
	jobs = GameJobManager::load();
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameJobService &GameJobService::getInstance() {
	static GameJobService instance;
	return instance;
}

/**
 *  名前よりデータ取得
 *
 *  @param name 名前
 *
 *  @return 対象データ (なし:nullptr)
 */
GameJobEntity *GameJobService::data(const string name) {
	if (jobs.find(name) == jobs.end()) {
		return nullptr;
	}
	return &jobs[name];
}