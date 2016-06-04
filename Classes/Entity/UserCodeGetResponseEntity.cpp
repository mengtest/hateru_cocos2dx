//
//  UserCodeGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#include "UserCodeGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool UserCodeGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["userCode"].is<string>()) {
		userCode = object["userCode"].get<string>();
	} else {
		return false;
	}
	return true;
}