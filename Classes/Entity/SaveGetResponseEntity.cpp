//
//  SaveGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveGetResponseEntity.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool SaveGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["saveData"].is<std::string>()) {
		saveData = object["saveData"].get<std::string>();
	} else {
		return false;
	}
	return true;
}