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
	std::string message;
	/// マップインデックス
	int32_t mapIndex;
	/// X座標
	int32_t x;
	/// Y座標
	int32_t y;
	/// その他情報
	std::string otherInfos;
	
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
