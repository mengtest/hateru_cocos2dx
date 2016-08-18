//
//  SaveSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "SaveSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void SaveSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(make_pair("saveData", picojson::value(saveData)));
}

/**
 *  コンストラクタ
 */
SaveSendParamsRequestEntity::SaveSendParamsRequestEntity() {
	saveData = "";
}

/**
 *  デストラクタ
 */
SaveSendParamsRequestEntity::~SaveSendParamsRequestEntity() {
}

