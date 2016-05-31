//
//  ProfileSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ProfileSendRequestEntity_h
#define ProfileSendRequestEntity_h

#include "BaseRequestEntity.h"

/// プロフィール送信パラメータリクエストEntity
class ProfileSendParamsRequestEntity final: public Ref {
public:
	
	/// プロフィールデータ
	std::string profileData;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// プロフィール送信リクエストEntity
class ProfileSendRequestEntity final: public BaseRequestEntity<ProfileSendParamsRequestEntity> {
public:
};

#endif /* ProfileSendRequestEntity_h */
