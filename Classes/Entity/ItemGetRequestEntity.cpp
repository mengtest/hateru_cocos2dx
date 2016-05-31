//
//  ItemGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ItemGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("userCode", picojson::value(userCode)));
	object.insert(std::make_pair("exchangeToken", picojson::value(exchangeToken)));
	object.insert(std::make_pair("password", picojson::value(password)));
}