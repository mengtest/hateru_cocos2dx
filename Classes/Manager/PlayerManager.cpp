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
#include "PlayerEncryptEntity.h"

/**
 *  読み込み
 *
 *  @return 取得データ
 */
PlayerEntity PlayerManager::load() {

	// マッピング
	PlayerEncryptEntity encryptEntity = loadEncrypt();
	if (!encryptEntity.isValid) {
		return PlayerEntity();
	}
	
	return encryptEntity.toPlayerEntity();
}


/**
 *  暗号化データを読み込み
 *
 *  @return 取得データ
 */
PlayerEncryptEntity PlayerManager::loadEncrypt() {
	
	PlayerEncryptEntity encryptEntity;
	
	// パス取得
	auto path = FileUtils::getInstance()->getWritablePath();
	
	// 文字列として読み込む
	auto saveData = FileUtils::getInstance()->getStringFromFile(path + SAVE_FILE_NAME);
	if (saveData.empty()) {
		return encryptEntity;
	}
	
	// JSON変換
	string error;
	picojson::value jsonValue;
	JsonUtil::jsonParse(&jsonValue, &error, &saveData);
	if(!error.empty()){
		log(JSON_PARSE_ERROR, error.c_str());
		return encryptEntity;
	}
	
	// マッピング
	auto isSuccess = encryptEntity.mapping(jsonValue.get<picojson::object>());
	if (!isSuccess) {
		return PlayerEncryptEntity();
	}

	// 有効フラグON
	encryptEntity.isValid = true;

	return encryptEntity;
}

/**
 *  保存
 *
 *  @param entity プレイヤー情報
 */
void PlayerManager::save(PlayerEntity &entity) {
	
	// パス取得
	auto path = FileUtils::getInstance()->getWritablePath();

	// 暗号化
	PlayerEncryptEntity encryptEntity;
	encryptEntity.setPlayerEntity(entity);
	
	// JSONにシリアライズ
	picojson::object object;
	encryptEntity.serialize(object);
	picojson::value val(object);
	
	FileUtils::getInstance()->writeStringToFile(val.serialize(), path + SAVE_FILE_NAME);
}

