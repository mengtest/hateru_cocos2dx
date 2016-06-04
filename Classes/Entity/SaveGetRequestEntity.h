//
//  SaveGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef SaveGetRequestEntity_h
#define SaveGetRequestEntity_h

#include "BaseRequestEntity.h"

/// セーブデータ取得パラメータリクエストEntity
class SaveGetParamsRequestEntity final: public Ref {
public:
	
	/// セーブトークン
	string saveToken;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// セーブデータ取得リクエストEntity
class SaveGetRequestEntity final: public BaseRequestEntity<SaveGetParamsRequestEntity> {
public:
};

#endif /* SaveGetRequestEntity_h */
