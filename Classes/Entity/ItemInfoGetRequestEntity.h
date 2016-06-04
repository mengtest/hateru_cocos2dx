//
//  ItemInfoGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemInfoGetRequestEntity_h
#define ItemInfoGetRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテム情報取得パラメータリクエストEntity
class ItemInfoGetParamsRequestEntity final: public Ref {
public:
	
	/// ユーザコード
	string userCode;
	/// 交換トークン
	string exchangeToken;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// アイテム情報取得リクエストEntity
class ItemInfoGetRequestEntity final: public BaseRequestEntity<ItemInfoGetParamsRequestEntity> {
public:
};

#endif /* ItemInfoGetRequestEntity_h */
