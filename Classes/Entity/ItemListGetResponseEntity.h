//
//  ItemListGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemListGetResponseEntity_h
#define ItemListGetResponseEntity_h

#include "BaseResponseEntity.h"
#include "ItemInfoGetResponseEntity.h"

/// アイテムリスト取得メタレスポンスEntity
class ItemListGetMetaResponseEntity final: public Ref {
public:

	/// アイテム情報
	std::vector<ItemInfoGetMetaResponseEntity> items;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// アイテムリスト取得レスポンスEntity
class ItemListGetResponseEntity final: public BaseResponseEntity<ItemListGetMetaResponseEntity> {
public:
};

#endif /* ItemListGetResponseEntity_h */
