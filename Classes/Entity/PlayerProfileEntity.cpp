//
//  PlayerProfileEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/29.
//
//

#include "PlayerProfileEntity.h"

#include "LogConst.h"

/**
 *  コンストラクタ
 */
PlayerProfileEntity::PlayerProfileEntity() {
	gender = 0;
	age = 0;
	address = 0;
	blood = 0;
	constellation = 0;
}

/**
 *  デストラクタ
 */
PlayerProfileEntity::~PlayerProfileEntity() {
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerProfileEntity::serialize(picojson::object &object) {
	object.insert(make_pair("gender", picojson::value((double)gender)));
	object.insert(make_pair("age", picojson::value((double)age)));
	object.insert(make_pair("address", picojson::value((double)address)));
	object.insert(make_pair("blood", picojson::value((double)blood)));
	object.insert(make_pair("constellation", picojson::value((double)constellation)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerProfileEntity::mapping(picojson::object &object) {
	if (object["gender"].is<double>()) {
		gender = (int)object["gender"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "gender");
		return false;
	}
	if (object["age"].is<double>()) {
		age = (int)object["age"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "age");
		return false;
	}
	if (object["address"].is<double>()) {
		address = (int)object["address"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "address");
		return false;
	}
	if (object["blood"].is<double>()) {
		blood = (int)object["blood"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "blood");
		return false;
	}
	if (object["constellation"].is<double>()) {
		constellation = (int)object["constellation"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "constellation");
		return false;
	}
	return true;
}
