//
//  NamesManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "NamesManager.h"

#include <iostream>
#include <iomanip>

#include "FileConst.h"

/// マップチップ
const string NamesManager::typeChipGroup = "ChipGpList.nmp";
/// マップ
const string NamesManager::typeMap = "MapList.nmp";
/// サウンド
const string NamesManager::typeSound = "SoundList.nmp";
/// 変数
const string NamesManager::typeVariable = "NumList.nmp";

/**
 *  読み込み
 *
 *  @param fileName ファイル名
 *
 *  @return 取得データ
 */
NamesEntity NamesManager::load(const string &fileName) {
	
	// ファイルデータ取得
	auto filePath = RES_GAME_PATH + fileName;
	auto fileData = FileUtils::getInstance()->getDataFromFile(filePath);
	
	auto entity = NamesEntity::createEntity(fileData.getBytes(), (size_t)fileData.getSize());
	
	return entity;
}


/**
 *  イベントリストファイル名を取得する
 *
 *  @param eventId イベントID
 *
 *  @return イベントリストファイル名
 */
string NamesManager::eventListName(const int id) {
	// ファイルデータ取得
	ostringstream ostr;
	ostr << "EventList" << setfill('0') << setw(3) << id << ".nmp";
	return ostr.str();
}
