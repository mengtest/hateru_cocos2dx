//
//  CharaDeleteResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef CharaDeleteResponseEntity_h
#define CharaDeleteResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class CharaDeleteMetaResponseEntity final: public Ref {
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

/// キャラ削除レスポンスEntity
class CharaDeleteResponseEntity final: public BaseResponseEntity<CharaDeleteMetaResponseEntity> {
public:
};

#endif /* CharaDeleteResponseEntity_h */
