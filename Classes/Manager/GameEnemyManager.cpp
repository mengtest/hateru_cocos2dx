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
map<int32_t, GameEnemyEntity> GameEnemyManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	auto enemies = map<int32_t, GameEnemyEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeEnemy];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << "Enemy" << setfill('0') << setw(3) << i << ".nmp";
		auto filePath = FileConst::resGamePath + ostr.str();
		auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
		
		auto entity = GameEnemyEntity::convertData(fileData.getBytes());
		
		enemies[i] = entity;
	}
	
	return enemies;
}
