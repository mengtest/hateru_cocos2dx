//
//  CharaSendResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef CharaSendResponseEntity_h
#define CharaSendResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class CharaSendMetaResponseEntity final: public Ref {
public:
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// キャラ送信レスポンスEntity
class CharaSendResponseEntity final: public BaseResponseEntity<CharaSendMetaResponseEntity> {
public:
};

#endif /* CharaSendResponseEntity_h */
