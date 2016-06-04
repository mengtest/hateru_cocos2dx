//
//  SaveSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef SaveSendRequestEntity_h
#define SaveSendRequestEntity_h

#include "BaseRequestEntity.h"

/// セーブデータ送信パラメータリクエストEntity
class SaveSendParamsRequestEntity final: public Ref {
public:
	
	/// セーブデータ
	string saveData;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// セーブデータ送信リクエストEntity
class SaveSendRequestEntity final: public BaseRequestEntity<SaveSendParamsRequestEntity> {
public:
};

#endif /* SaveSendRequestEntity_h */
