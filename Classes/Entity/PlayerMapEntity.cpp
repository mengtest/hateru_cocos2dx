//
//  PlayerMapEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/18.
//
//

#include "PlayerMapEntity.h"

#include "LogConst.h"

/**
 *  コンストラクタ
 */
PlayerMapEntity::PlayerMapEntity() {
	id = 0;
	x = 0;
	y = 0;
}

/**
 *  デストラクタ
 */
PlayerMapEntity::~PlayerMapEntity() {
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerMapEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value((double)id)));
	object.insert(make_pair("x", picojson::value((double)x)));
	object.insert(make_pair("y", picojson::value((double)y)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerMapEntity::mapping(picojson::object &object) {
	if (object["id"].is<double>()) {
		id = (int)object["id"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "id");
		return false;
	}
	if (object["x"].is<double>()) {
		x = (int)object["x"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "x");
		return false;
	}
	if (object["y"].is<double>()) {
		y = (int)object["y"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "y");
		return false;
	}
	return true;
}