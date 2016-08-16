//
//  LocationSendRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef LocationSendRequestEntity_h
#define LocationSendRequestEntity_h

#include "BaseRequestEntity.h"

/// 位置情報送信パラメータリクエストEntity
class LocationSendParamsRequestEntity final: public Ref {
public:
	
	/// メッセージ
	string message;
	/// マップインデックス
	int mapIndex;
	/// X座標
	int x;
	/// Y座標
	int y;
	/// その他情報
	string otherInfos;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// 位置情報送信リクエストEntity
class LocationSendRequestEntity final: public BaseRequestEntity<LocationSendParamsRequestEntity> {
public:
};

#endif /* LocationSendRequestEntity_h */
