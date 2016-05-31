//
//  ProfileDeleteResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ProfileDeleteResponseEntity_h
#define ProfileDeleteResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class ProfileDeleteMetaResponseEntity final: public Ref {
public:
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// プロフィール削除レスポンスEntity
class ProfileDeleteResponseEntity final: public BaseResponseEntity<ProfileDeleteMetaResponseEntity> {
public:
};

#endif /* ProfileDeleteResponseEntity_h */
