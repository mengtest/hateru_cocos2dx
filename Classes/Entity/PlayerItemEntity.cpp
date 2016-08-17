//
//  PlayerItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerItemEntity.h"

#include "LogConst.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerItemEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value((double)id)));
	object.insert(make_pair("useCount", picojson::value((double)useCount)));
	object.insert(make_pair("itemId", picojson::value(itemId)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerItemEntity::mapping(picojson::object &object) {
	if (object["id"].is<double>()) {
		id = (int)object["id"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "id");
		return false;
	}
	if (object["useCount"].is<double>()) {
		useCount = (int)object["useCount"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "useCount");
		return false;
	}
	if (object["itemId"].is<string>()) {
		itemId = object["itemId"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "itemId");
		return false;
	}
	return true;
}