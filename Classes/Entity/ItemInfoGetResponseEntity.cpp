//
//  ItemInfoGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemInfoGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemInfoGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["itemKindIndex"].is<double>()) {
		itemKindIndex = (int)object["itemKindIndex"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "itemKindIndex");
		return false;
	}
	if (object["itemCode"].is<string>()) {
		itemCode = object["itemCode"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "itemCode");
		return false;
	}
	if (object["hopeItemKindIndex"].is<double>()) {
		hopeItemKindIndex = (int)object["hopeItemKindIndex"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "hopeItemKindIndex");
		return false;
	}
	if (object["exchangeStatus"].is<string>()) {
		exchangeStatus = object["exchangeStatus"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "exchangeStatus");
		return false;
	}
	if (object["hasPassowrd"].is<bool>()) {
		hasPassowrd = object["hasPassowrd"].get<bool>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "hasPassowrd");
		return false;
	}
	return true;
}

/**
 *  コンストラクタ
 */
ItemInfoGetMetaResponseEntity::ItemInfoGetMetaResponseEntity() {
	itemKindIndex = 0;
	itemCode = "";
	hopeItemKindIndex = 0;
	exchangeStatus = "";
	hasPassowrd = "";
}

/**
 *  デストラクタ
 */
ItemInfoGetMetaResponseEntity::~ItemInfoGetMetaResponseEntity() {
}
