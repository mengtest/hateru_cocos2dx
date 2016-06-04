//
//  ItemInfoGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemInfoGetResponseEntity_h
#define ItemInfoGetResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class ItemInfoGetMetaResponseEntity final: public Ref {
public:
	
	/// アイテム種類
	int32_t itemKindIndex;
	/// アイテムコード
	string itemCode;
	/// 交換希望アイテム種類
	int32_t hopeItemKindIndex;
	/// 交換ステータス
	string exchangeStatus;
	/// パスワードあり
	bool hasPassowrd;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// アイテム情報取得レスポンスEntity
class ItemInfoGetResponseEntity final: public BaseResponseEntity<ItemInfoGetMetaResponseEntity> {
public:
};

#endif /* ItemInfoGetResponseEntity_h */
