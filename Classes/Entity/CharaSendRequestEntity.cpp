//
//  CharaSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "CharaSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void CharaSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("statusData", picojson::value(statusData)));
}
