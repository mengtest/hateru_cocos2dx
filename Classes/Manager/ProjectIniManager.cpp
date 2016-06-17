//
//  ProjectIniManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "ProjectIniManager.h"

#include "FileConst.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
ProjectIniEntity ProjectIniManager::load() {
	
	// ファイルデータ取得
	auto fileName = FileConst::resGamePath + "Project.ini";
	auto fileData = FileUtils::getInstance()->getDataFromFile(fileName);
	
	auto entity = ProjectIniEntity::convertData(fileData.getBytes(), (size_t)fileData.getSize());
	
	return entity;
}