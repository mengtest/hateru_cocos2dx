//
//  ItemInfoGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemInfoGetResponseEntity.h"

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
		return false;
	}
	if (object["itemCode"].is<string>()) {
		itemCode = object["itemCode"].get<string>();
	} else {
		return false;
	}
	if (object["hopeItemKindIndex"].is<double>()) {
		hopeItemKindIndex = (int)object["hopeItemKindIndex"].get<double>();
	} else {
		return false;
	}
	if (object["exchangeStatus"].is<string>()) {
		exchangeStatus = object["exchangeStatus"].get<string>();
	} else {
		return false;
	}
	if (object["exchangeStatus"].is<bool>()) {
		hasPassowrd = object["exchangeStatus"].get<bool>();
	} else {
		return false;
	}
	return true;
}