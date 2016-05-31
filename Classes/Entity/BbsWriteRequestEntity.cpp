//
//  BbsWriteRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "BbsWriteRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void BbsWriteParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("bbsCode", picojson::value(bbsCode)));
	object.insert(std::make_pair("messageCode", picojson::value(messageCode)));
	object.insert(std::make_pair("messageType", picojson::value(messageType)));
	object.insert(std::make_pair("messageData", picojson::value(messageData)));
}
