//
//  GameSkillService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameSkillService.h"
#include "GameSkillManager.h"

/**
 *  コンストラクタ
 */
GameSkillService::GameSkillService() {
	// 読み込み
	skills = GameSkillManager::load();
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameSkillService &GameSkillService::getInstance() {
	static GameSkillService instance;
	return instance;
}

/**
 *  名前よりデータ取得
 *
 *  @param name 名前
 *
 *  @return 対象データ (なし:nullptr)
 */
GameSkillEntity *GameSkillService::data(const string name) {
	if (skills.find(name) == skills.end()) {
		return nullptr;
	}
	return &skills[name];
}