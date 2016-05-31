//
//  ProfileGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ProfileGetResponseEntity_h
#define ProfileGetResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class ProfileGetMetaResponseEntity final: public Ref {
public:
	
	/// ユーザコード
	std::string userCode;
	/// ユーザ名
	std::string userName;
	/// プロフィールデータ
	std::string profileData;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// プロフィール取得レスポンスEntity
class ProfileGetResponseEntity final: public BaseResponseEntity<ProfileGetMetaResponseEntity> {
public:
};


#endif /* ProfileGetResponseEntity_h */
