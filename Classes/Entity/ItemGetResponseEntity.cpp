//
//  ItemGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["itemKindIndex"].is<double>()) {
		itemKindIndex = (int32_t)object["itemKindIndex"].get<double>();
	} else {
		return false;
	}
	if (object["itemCode"].is<std::string>()) {
		itemCode = object["itemCode"].get<std::string>();
	} else {
		return false;
	}
	return true;
}