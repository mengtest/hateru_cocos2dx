//
//  GameEnemyManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#include "GameEnemyManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "ProjectIniManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int, GameEnemyEntity> GameEnemyManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	auto enemies = map<int, GameEnemyEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeEnemy];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << "Enemy" << setfill('0') << setw(3) << i << ".nmp";
		auto filePath = RES_GAME_PATH + ostr.str();
		auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
		
		auto entity = GameEnemyEntity::createEntity(fileData.getBytes());
		
		enemies[i] = entity;
	}
	
	return enemies;
}
