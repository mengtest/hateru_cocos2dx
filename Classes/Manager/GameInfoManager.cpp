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
	auto filePath = RES_GAME_PATH"Game.nmp";
	auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
	
	auto entity = GameInfoEntity::createEntity(fileData.getBytes());
	
	return entity;
}
