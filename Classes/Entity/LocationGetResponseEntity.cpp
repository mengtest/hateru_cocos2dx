//
//  LocationGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "LocationGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool LocationGetMetaDetailResponseEntity::mapping(picojson::object &object) {
	if (object["userCode"].is<string>()) {
		userCode = object["userCode"].get<string>();
	} else {
		return false;
	}
	if (object["userName"].is<string>()) {
		userName = object["userName"].get<string>();
	} else {
		return false;
	}
	if (object["message"].is<string>()) {
		message = object["message"].get<string>();
	} else {
		return false;
	}
	if (object["mapIndex"].is<double>()) {
		mapIndex = (int)object["mapIndex"].get<double>();
	} else {
		return false;
	}
	if (object["x"].is<double>()) {
		x = (int)object["x"].get<double>();
	} else {
		return false;
	}
	if (object["y"].is<double>()) {
		y = (int)object["y"].get<double>();
	} else {
		return false;
	}
	if (object["otherInfos"].is<string>()) {
		otherInfos = object["otherInfos"].get<string>();
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
bool LocationGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["locations"].is<picojson::array>()) {
		locations.clear();
		auto locationArray = object["locations"].get<picojson::array>();
		for (picojson::array::iterator it = locationArray.begin(); it != locationArray.end(); it++) {
			picojson::object& location = it->get<picojson::object>();
			LocationGetMetaDetailResponseEntity locationEntity;
			auto isSuccess = locationEntity.mapping(location);
			if (!isSuccess) {
				return false;
			}
			locations.push_back(locationEntity);
		}
	} else {
		return false;
	}
	return true;
}

