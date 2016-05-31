//
//  ItemSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef ItemSendRequestEntity_h
#define ItemSendRequestEntity_h

#include "BaseRequestEntity.h"

/// アイテム送信パラメータリクエストEntity
class ItemSendParamsRequestEntity final: public Ref {
public:
	
	/// アイテム種類
	int32_t itemKindIndex;
	/// 所持アイテムコード
	std::string itemCode;
	/// 交換希望アイテム種別
	int32_t hopeItemKindIndex;
	/// 交換相手ユーザコード
	std::string partnerUserCode;
	/// 交換パスワード
	std::string password;

	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// アイテム送信リクエストEntity
class ItemSendRequestEntity final: public BaseRequestEntity<ItemSendParamsRequestEntity> {
public:
};

#endif /* ItemSendRequestEntity_h */
