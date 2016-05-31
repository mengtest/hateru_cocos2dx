//
//  ItemListGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemListGetRequestEntity_h
#define ItemListGetRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテムリスト取得パラメータリクエストEntity
class ItemListGetParamsRequestEntity final: public Ref {
public:
	
	/// 交換タイプ
	std::string exchangeType;
	/// アイテム種類
	int32_t itemKindIndex;
	/// 希望アイテム種類
	int32_t hopeItemKindIndex;
	/// 取得オフセット
	int32_t offset;
	/// 取得数
	int32_t count;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// マイアイテム情報取得リクエストEntity
class ItemListGetRequestEntity final: public BaseRequestEntity<ItemListGetParamsRequestEntity> {
public:
};

#endif /* ItemListGetRequestEntity_h */
