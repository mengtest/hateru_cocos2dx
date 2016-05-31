//
//  ProfileSendRequestEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#include "ProfileSendRequestEntity.h"

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void ProfileSendParamsRequestEntity::serialize(picojson::object &object) {
	object.insert(std::make_pair("profileData", picojson::value(profileData)));
}