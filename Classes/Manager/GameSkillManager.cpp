//
//  GameSkillManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameSkillManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "ProjectIniManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int, GameSkillEntity> GameSkillManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	auto skills = map<int, GameSkillEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeSkill];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << "Waza" << setfill('0') << setw(3) << i << ".nmp";
		auto filePath = RES_GAME_PATH + ostr.str();
		auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
		
		auto entity = GameSkillEntity::createEntity(fileData.getBytes());
		
		skills[i] = entity;
	}
	
	return skills;
}
