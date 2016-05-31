//
//  ItemListGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemListGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ItemListGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("exchangeType", picojson::value(exchangeType)));
	object.insert(std::make_pair("itemKindIndex", picojson::value((double)itemKindIndex)));
	object.insert(std::make_pair("hopeItemKindIndex", picojson::value((double)hopeItemKindIndex)));
	object.insert(std::make_pair("offset", picojson::value((double)offset)));
	object.insert(std::make_pair("count", picojson::value((double)count)));
}