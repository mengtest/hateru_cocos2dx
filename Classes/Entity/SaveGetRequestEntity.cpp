//
//  SaveGetRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveGetRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void SaveGetParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("saveToken", picojson::value(saveToken)));
}