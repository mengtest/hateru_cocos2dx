//
//  BbsGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BbsGetResponseEntity_h
#define BbsGetResponseEntity_h

#include "BaseResponseEntity.h"

/// 掲示板取得詳細レスポンスEntity
class BbsGetDetailResponseEntity final: public Ref {
public:
	
	/// ユーザコード
	std::string userCode;
	/// ユーザ名
	std::string userName;
	/// メッセージコード
	std::string messageCode;
	/// メッセージタイプ
	std::string messageType;
	/// メッセージデータ
	std::string messageData;
	/// 追加日時
	std::string createAt;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// 掲示板取得メタレスポンスEntity
class BbsGetMetaResponseEntity final: public Ref {
public:
	
	/// 掲示板コード
	std::string bbsCode;
	/// メッセージ
	std::vector<BbsGetDetailResponseEntity> messages;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// 掲示板取得レスポンスEntity
class BbsGetResponseEntity final: public BaseResponseEntity<BbsGetMetaResponseEntity> {
public:
};

#endif /* BbsGetResponseEntity_h */
