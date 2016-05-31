//
//  BaseRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BaseRequestEntity_h
#define BaseRequestEntity_h

#include "cocos2d.h"
#include "picojson.h"

USING_NS_CC;

/// ベースステータスリクエストEntity
class BaseStatusRequestEntity final: public Ref {
public:
	
	/// アプリトークン
	std::string appToken;
	/// アプリバージョン
	std::string appVersion;
	/// プラットフォーム
	std::string platform;
	/// ユーザコード
	std::string userCode;
	/// ユーザ名
	std::string userName;
	/// アクセストークン
	std::string accessToken;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);

};

/// ベースリクエストEntity
template<class T_PARAMS>
class BaseRequestEntity: public Ref {
public:
	
	/// ステータス
	BaseStatusRequestEntity status;
	
	// パラメータ
	T_PARAMS params;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

#endif /* BaseRequestEntity_h */
