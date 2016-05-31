//
//  ItemSendResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "ItemSendResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemSendMetaResponseEntity::mapping(picojson::object &object) {
	if (object["exchangeToken"].is<std::string>()) {
		exchangeToken = object["exchangeToken"].get<std::string>();
	} else {
		return false;
	}
	return true;
}