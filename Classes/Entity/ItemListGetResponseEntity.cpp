//
//  ItemListGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ItemListGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool ItemListGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["items"].is<picojson::array>()) {
		picojson::array array = object["items"].get<picojson::array>();
		for (picojson::array::iterator it = array.begin(); it != array.end(); it++) {
			auto item = new ItemInfoGetMetaResponseEntity();
			item->mapping(it->get<picojson::object>());
			items.push_back(*item);
		}
	} else {
		return false;
	}
	return true;
}