//
//  ItemInfoGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemInfoGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ItemInfoGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("userCode", picojson::value(userCode)));
	object.insert(std::make_pair("exchangeToken", picojson::value(exchangeToken)));
}