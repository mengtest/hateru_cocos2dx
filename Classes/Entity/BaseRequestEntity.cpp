//
//  BaseRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "BaseRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
template<class T_PARAMS>
void BaseRequestEntity<T_PARAMS>::serialize(picojson::object &object) {
	// ステータス
	picojson::object statusObject;
	status.serialize(statusObject);
	object.insert(std::make_pair("status", picojson::value(statusObject)));
	// パラメータ
	picojson::object paramObject;
	params.serialize(paramObject);
	object.insert(std::make_pair("params", picojson::value(paramObject)));
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void BaseStatusRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("appToken", picojson::value(appToken)));
	object.insert(std::make_pair("appVersion", picojson::value(appVersion)));
	object.insert(std::make_pair("platform", picojson::value(platform)));
	object.insert(std::make_pair("userCode", picojson::value(userCode)));
	object.insert(std::make_pair("userName", picojson::value(userName)));
	object.insert(std::make_pair("accessToken", picojson::value(accessToken)));
}
