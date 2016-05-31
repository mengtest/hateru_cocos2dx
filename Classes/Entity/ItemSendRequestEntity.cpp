//
//  ItemSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#include "ItemSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ItemSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("itemKindIndex", picojson::value((double)itemKindIndex)));
	object.insert(std::make_pair("itemCode", picojson::value(itemCode)));
	object.insert(std::make_pair("hopeItemKindIndex", picojson::value((double)hopeItemKindIndex)));
	object.insert(std::make_pair("partnerUserCode", picojson::value(partnerUserCode)));
	object.insert(std::make_pair("password", picojson::value(password)));
}