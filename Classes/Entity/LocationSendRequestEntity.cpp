//
//  LocationSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "LocationSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void LocationSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("message", picojson::value(message)));
	object.insert(std::make_pair("mapIndex", picojson::value((double)mapIndex)));
	object.insert(std::make_pair("x", picojson::value((double)x)));
	object.insert(std::make_pair("y", picojson::value((double)y)));
	object.insert(std::make_pair("otherInfos", picojson::value(otherInfos)));
}