//
//  ProfileSendResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ProfileSendResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ProfileSendMetaResponseEntity::mapping(picojson::object &object) {
	//	if (object["token"].is<std::string>()) {
	//		this->token = object["token"].get<std::string>();
	//	} else {
	//		return false;
	//	}
	//	if (object["preriodTime"].is<double>()) {
	//		this->preriodTime = (time_t)object["preriodTime"].get<double>();
	//	} else {
	//		return false;
	//	}
	return true;
}