//
//  ItemCombackResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef ItemCombackResponseEntity_h
#define ItemCombackResponseEntity_h

#include "BaseResponseEntity.h"

/// アイテム取り戻しメタレスポンスEntity
class ItemCombackMetaResponseEntity final: public Ref {
public:
	
	/// アイテム種類
	int itemKindIndex;
	/// 所持アイテムコード
	string itemCode;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// アイテム取り戻しレスポンスEntity
class ItemCombackResponseEntity final: public BaseResponseEntity<ItemCombackMetaResponseEntity> {
public:
};

#endif /* ItemCombackResponseEntity_h */
