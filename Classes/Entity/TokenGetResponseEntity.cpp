//
//  TokenGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "TokenGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool TokenGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["accessToken"].is<std::string>()) {
		accessToken = object["accessToken"].get<std::string>();
	} else {
		return false;
	}
	return true;
}