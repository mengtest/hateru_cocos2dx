//
//  SaveGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef SaveGetResponseEntity_h
#define SaveGetResponseEntity_h

#include "BaseResponseEntity.h"

/// マイアイテム情報取得メタレスポンスEntity
class SaveGetMetaResponseEntity final: public Ref {
public:
	
	/// セーブデータ
	string saveData;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// セーブデータ取得レスポンスEntity
class SaveGetResponseEntity final: public BaseResponseEntity<SaveGetMetaResponseEntity> {
public:
};

#endif /* SaveGetResponseEntity_h */
