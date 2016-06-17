//
//  GameInfoManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameInfoManager.h"

#include "FileConst.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
GameInfoEntity GameInfoManager::load() {
	
	// ファイルデータ取得
	auto filePath = FileConst::resGamePath + "Game.nmp";
	auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
	
	auto entity = GameInfoEntity::convertData(fileData.getBytes());
	
	return entity;
}
