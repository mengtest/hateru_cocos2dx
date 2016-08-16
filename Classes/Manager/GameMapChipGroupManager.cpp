//
//  GameMapChipGroupManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/07.
//
//

#include "GameMapChipGroupManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "ProjectIniManager.h"
#include "NamesManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int, GameMapChipGroupEntity> GameMapChipGroupManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	// 名前リスト取得
	auto namesEntity = NamesManager::load(NamesManager::typeChipGroup);

	auto chipGroups = map<int, GameMapChipGroupEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeChipGroup];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << "ChipGp" << setfill('0') << setw(3) << i << ".nmp";
		auto filePath = FileConst::resGamePath + ostr.str();
		auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
		
		auto chipGroup = GameMapChipGroupEntity::createEntity(fileData.getBytes(), namesEntity.names[i]);
		
		chipGroups[i] = chipGroup;
	}
	
	return chipGroups;
}
