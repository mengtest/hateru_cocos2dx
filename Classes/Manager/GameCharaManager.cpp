//
//  GameCharaManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameCharaManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "ProjectIniManager.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
map<int32_t, GameCharaEntity> GameCharaManager::load() {
	
	auto projectIniEntity = ProjectIniManager::load();
	auto charas = map<int32_t, GameCharaEntity>();
	
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeUnit];i++) {
		// ファイルデータ取得
		ostringstream ostr;
		ostr << "Chara" << setfill('0') << setw(3) << i << ".nmp";
		auto filePath = FileConst::resGamePath + ostr.str();
		auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
		
		auto entity = GameCharaEntity::convertData(fileData.getBytes());
		
		charas[i] = entity;
	}
	
	return charas;
}
