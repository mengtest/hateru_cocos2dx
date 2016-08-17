//
//  PlayerManager.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/18.
//
//

#include "PlayerManager.h"

#include "picojson.h"

#include "LogConst.h"
#include "FileConst.h"
#include "JsonUtil.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
PlayerEntity PlayerManager::load() {

	PlayerEntity entity;
	
	// パス取得
	auto path = FileUtils::getInstance()->getWritablePath();
	
	// 文字列として読み込む
	auto saveData = FileUtils::getInstance()->getStringFromFile(path + SAVE_FILE_NAME);
	if (saveData.empty()) {
		return entity;
	}

	// JSON変換
	string error;
	picojson::value jsonValue;
	JsonUtil::jsonParse(&jsonValue, &error, &saveData);
	if(!error.empty()){
		log(JSON_PARSE_ERROR, error.c_str());
		return entity;
	}
	
	// マッピング
	auto isSuccess = entity.mapping(jsonValue.get<picojson::object>());
	if (!isSuccess) {
		return PlayerEntity();
	}
	
	return entity;
}

/**
 *  保存
 *
 *  @param entity プレイヤー情報
 */
void PlayerManager::save(PlayerEntity &entity) {
	
	// パス取得
	auto path = FileUtils::getInstance()->getWritablePath();

	// JSONにシリアライズ
	picojson::object object;
	entity.serialize(object);
	picojson::value val(object);
	
	FileUtils::getInstance()->writeStringToFile(val.serialize(), path + SAVE_FILE_NAME);
}