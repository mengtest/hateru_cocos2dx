//
//  LocationGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef LocationGetRequestEntity_h
#define LocationGetRequestEntity_h

#include "BaseRequestEntity.h"

/// 位置情報取得パラメータリクエストEntity
class LocationGetParamsRequestEntity final: public Ref {
public:
	
	/// マップインデックス
	int32_t mapIndex;
	/// X座標
	int32_t x;
	/// Y座標
	int32_t y;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// 位置情報取得リクエストEntity
class LocationGetRequestEntity final: public BaseRequestEntity<LocationGetParamsRequestEntity> {
public:
};

#endif /* LocationGetRequestEntity_h */
