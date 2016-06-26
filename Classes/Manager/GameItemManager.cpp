//
//  GameItemManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "ProjectIniManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int32_t, GameItemEntity> GameItemManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	auto items = map<int32_t, GameItemEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeSkill];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << "Item" << setfill('0') << setw(3) << i << ".nmp";
		auto filePath = FileConst::resGamePath + ostr.str();
		auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
		
		auto entity = GameItemEntity::convertData(fileData.getBytes());
		
		items[i] = entity;
	}
	
	return items;
}
