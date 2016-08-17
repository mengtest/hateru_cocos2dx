//
//  ProfileGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ProfileGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ProfileGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["userCode"].is<string>()) {
		userCode = object["userCode"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "userCode");
		return false;
	}
	if (object["userName"].is<string>()) {
		userName = object["userName"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "userName");
		return false;
	}
	if (object["profileData"].is<string>()) {
		profileData = object["profileData"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "profileData");
		return false;
	}
	return true;
}