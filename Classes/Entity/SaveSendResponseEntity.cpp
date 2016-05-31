//
//  SaveSendResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveSendResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool SaveSendMetaResponseEntity::mapping(picojson::object &object) {
	if (object["saveToken"].is<std::string>()) {
		saveToken = object["saveToken"].get<std::string>();
	} else {
		return false;
	}
	return true;
}