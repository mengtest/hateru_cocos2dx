//
//  CharaGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "CharaGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool CharaGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["userCode"].is<std::string>()) {
		userCode = object["userCode"].get<std::string>();
	} else {
		return false;
	}
	if (object["userName"].is<std::string>()) {
		userName = object["userName"].get<std::string>();
	} else {
		return false;
	}
	if (object["statusData"].is<std::string>()) {
		statusData = object["statusData"].get<std::string>();
	} else {
		return false;
	}
	return true;
}