//
//  BbsGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "BbsGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool BbsGetDetailResponseEntity::mapping(picojson::object &object) {
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
	if (object["messageCode"].is<string>()) {
		messageCode = object["messageCode"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "messageCode");
		return false;
	}
	if (object["messageType"].is<string>()) {
		messageType = object["messageType"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "messageType");
		return false;
	}
	if (object["messageData"].is<string>()) {
		messageType = object["messageData"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "messageData");
		return false;
	}
	if (object["createAt"].is<string>()) {
		createAt = object["createAt"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "createAt");
		return false;
	}
	return true;
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool BbsGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["messages"].is<picojson::array>()) {
		messages.clear();
		auto locationArray = object["messages"].get<picojson::array>();
		for (picojson::array::iterator it = locationArray.begin(); it != locationArray.end(); it++) {
			auto location = it->get<picojson::object>();
			BbsGetDetailResponseEntity bbsEntity;
			auto isSuccess = bbsEntity.mapping(location);
			if (!isSuccess) {
				return false;
			}
			messages.push_back(bbsEntity);
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "messages");
		return false;
	}
	return true;
}