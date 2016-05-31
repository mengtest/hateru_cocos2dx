//
//  UserCodeGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#ifndef UserCodeGetResponseEntity_h
#define UserCodeGetResponseEntity_h

#include <time.h>
#include "BaseResponseEntity.h"

/// ユーザコード取得メタレスポンスEntity
class UserCodeGetMetaResponseEntity final: public Ref {
public:
	
	/// ユーザコード
	std::string userCode;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// トークン取得レスポンスEntity
class UserCodeGetResponseEntity final: public BaseResponseEntity<UserCodeGetMetaResponseEntity> {
public:
};
#endif /* UserCodeGetResponseEntity_h */
