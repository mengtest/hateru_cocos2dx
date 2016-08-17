//
//  SaveGetResponseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveGetResponseEntity.h"

#include "LogConst.h"

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool SaveGetMetaResponseEntity::mapping(picojson::object &object) {
	if (object["saveData"].is<string>()) {
		saveData = object["saveData"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "saveData");
		return false;
	}
	return true;
}