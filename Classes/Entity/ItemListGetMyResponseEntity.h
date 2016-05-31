//
//  ItemListGetMyResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef ItemListGetMyResponseEntity_h
#define ItemListGetMyResponseEntity_h

#include "BaseResponseEntity.h"
#include "ItemInfoGetResponseEntity.h"

/// 自分向けアイテムリスト取得メタレスポンスEntity
class ItemListGetMyMetaResponseEntity final: public Ref {
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

/// 自分向けアイテムリスト取得レスポンスEntity
class ItemListGetMyResponseEntity final: public BaseResponseEntity<ItemListGetMyMetaResponseEntity> {
public:
};

#endif /* ItemListGetMyResponseEntity_h */
