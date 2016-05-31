//
//  BbsGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "BbsGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool BbsGetDetailResponseEntity::mapping(picojson::object &object) {
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
	if (object["messageCode"].is<std::string>()) {
		messageCode = object["messageCode"].get<std::string>();
	} else {
		return false;
	}
	if (object["messageType"].is<std::string>()) {
		messageType = object["messageType"].get<std::string>();
	} else {
		return false;
	}
	if (object["messageData"].is<std::string>()) {
		messageType = object["messageData"].get<std::string>();
	} else {
		return false;
	}
	if (object["createAt"].is<std::string>()) {
		createAt = object["createAt"].get<std::string>();
	} else {
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
			picojson::object& location = it->get<picojson::object>();
			BbsGetDetailResponseEntity bbsEntity;
			auto isSuccess = bbsEntity.mapping(location);
			if (!isSuccess) {
				return false;
			}
			messages.push_back(bbsEntity);
		}
	} else {
		return false;
	}
	return true;
}