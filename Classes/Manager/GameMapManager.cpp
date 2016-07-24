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

	// 名前リスト取得
	auto namesEntity = NamesManager::load(NamesManager::typeMap);

	// ファイルデータ取得
	ostringstream ostr;
	ostr << "MapS" << setfill('0') << setw(3) << id << ".nmp";
	auto filePath = FileConst::resGamePath + ostr.str();
	auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
	
	auto entity = GameMapEntity::createEntity(fileData.getBytes(), namesEntity.names[id]);
	
	// イベントリスト名取得
	namesEntity = NamesManager::load(NamesManager::eventListName(id));
	
	// ファイルデータ取得
	ostr.str("");
	ostr.clear(stringstream::goodbit);
	ostr << "EventS" << setfill('0') << setw(3) << id << ".nmp";
	filePath = FileConst::resGamePath + ostr.str();
	fileData = FileUtils::getInstance()->getDataFromFile(filePath);
	
	entity.convertEventData(fileData.getBytes(), namesEntity.names);
	
	return GameMapEntity();
}

