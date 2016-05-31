//
//  ItemSendResponseEntity.hpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef ItemSendResponseEntity_h
#define ItemSendResponseEntity_h

#include "BaseResponseEntity.h"

/// アイテム送信メタレスポンスEntity
class ItemSendMetaResponseEntity final: public Ref {
public:
	
	/// 交換トークン
	std::string exchangeToken;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// アイテム送信レスポンスEntity
class ItemSendResponseEntity final: public BaseResponseEntity<ItemSendMetaResponseEntity> {
public:
};

#endif /* ItemSendResponseEntity_h */
