//
//  ItemGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemGetRequestEntity_h
#define ItemGetRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテム取得パラメータリクエストEntity
class ItemGetParamsRequestEntity final: public Ref {
public:
	
	/// 交換相手ユーザコード
	std::string userCode;
	/// 交換トークン
	std::string exchangeToken;
	/// 交換パスワード
	std::string password;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// マイアイテム情報取得リクエストEntity
class ItemGetRequestEntity final: public BaseRequestEntity<ItemGetParamsRequestEntity> {
public:
};

#endif /* ItemGetRequestEntity_h */
