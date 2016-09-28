//
//  GameMapManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMapManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"
#include "NamesManager.h"

/**
 *  読み込み
 *
 *  @param id マップId
 *
 *  @return 取得データ
 */
GameMapEntity GameMapManager::load(const int id) {

	auto mapId = id - 1;
	
	// 名前リスト取得
	auto namesEntity = NamesManager::load(NamesManager::typeMap);

	// ファイルデータ取得
	ostringstream ostr;
	ostr << "MapS" << setfill('0') << setw(3) << mapId << ".nmp";
	auto filePath = RES_GAME_PATH + ostr.str();
	auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
	
	auto entity = GameMapEntity::createEntity(fileData.getBytes(), namesEntity.names[mapId]);
	
	// イベントリスト名取得
	namesEntity = NamesManager::load(NamesManager::eventListName(mapId));
	
	// ファイルデータ取得
	ostr.str("");
	ostr.clear(stringstream::goodbit);
	ostr << "EventS" << setfill('0') << setw(3) << mapId << ".nmp";
	filePath = RES_GAME_PATH + ostr.str();
	fileData = FileUtils::getInstance()->getDataFromFile(filePath);
	
	entity.convertEventData(fileData.getBytes(), namesEntity.names);
	
	return entity;
}

