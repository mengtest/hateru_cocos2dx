//
//  PlayerEncryptionEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/19.
//
//

#include "PlayerEncryptEntity.h"

#include "LogConst.h"
#include "JsonUtil.h"
#include "EncryptUtil.h"

/**
 *  コンストラクタ
 */
PlayerEncryptEntity::PlayerEncryptEntity() {
	data = "";
	checkDigit = "";
}

/**
 *  デストラクタ
 */
PlayerEncryptEntity::~PlayerEncryptEntity() {
}

/**
 *  PlayerEntityを暗号化し設定する
 *
 *  @param playerEntity PlayerEntity
 */
void PlayerEncryptEntity::setPlayerEntity(PlayerEntity &playerEntity) {
	
	// JSONにシリアライズ
	picojson::object object;
	playerEntity.serialize(object);
	picojson::value val(object);

	// 値を設定
	data = val.serialize();
	
	// チェックデジット取得
	checkDigit = EncryptUtil::hash(data);
}

/**
 *  復号化しPlayerEntityにする
 *
 *  @return PlayerEntity
 */
PlayerEntity PlayerEncryptEntity::toPlayerEntity() {
	
	// 復号化
	auto decryptStr = EncryptUtil::decrypt(data);
	if (decryptStr.empty()) {
		log(DECRYPT_ERROR, data.c_str());
		return PlayerEntity();
	}
	
	// チェックデジットチェック
	if (checkDigit.compare(EncryptUtil::hash(decryptStr)) != 0) {
		log(CHECK_DIGIT_ERROR, checkDigit.c_str());
		return PlayerEntity();
	}
	
	// JSON変換
	string error;
	picojson::value jsonValue;
	JsonUtil::jsonParse(&jsonValue, &error, &decryptStr);
	if(!error.empty()){
		log(JSON_PARSE_ERROR, error.c_str());
		return PlayerEntity();
	}

	// マッピング
	PlayerEntity entity;
	auto isSuccess = entity.mapping(jsonValue.get<picojson::object>());
	if (!isSuccess) {
		return PlayerEntity();
	}
	
	// 有効フラグON
	entity.isValid = true;

	return entity;
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerEncryptEntity::serialize(picojson::object &object) {
	object.insert(make_pair("data", picojson::value(data)));
	object.insert(make_pair("checkDigit", picojson::value(checkDigit)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerEncryptEntity::mapping(picojson::object &object) {
	if (object["data"].is<string>()) {
		data = object["data"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "data");
		return false;
	}
	if (object["checkDigit"].is<string>()) {
		checkDigit = object["checkDigit"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "checkDigit");
		return false;
	}
	return true;
}