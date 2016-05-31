//
//  LocationGetResponseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef LocationGetResponseEntity_h
#define LocationGetResponseEntity_h

#include "BaseResponseEntity.h"

/// 位置情報取得メタ詳細レスポンスEntity
class LocationGetMetaDetailResponseEntity final: public Ref {
public:
	
	/// 位置情報群
	std::string userCode;
	/// 位置情報群
	std::string userName;
	/// 位置情報群
	std::string message;
	/// 位置情報群
	int32_t mapIndex;
	/// 位置情報群
	int32_t x;
	/// 位置情報群
	int32_t y;
	/// 位置情報群
	std::string otherInfos;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// 位置情報取得メタレスポンスEntity
class LocationGetMetaResponseEntity final: public Ref {
public:
	
	/// 位置情報群
	std::vector<LocationGetMetaDetailResponseEntity> locations;
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
};

/// 位置情報取得レスポンスEntity
class LocationGetResponseEntity final: public BaseResponseEntity<LocationGetMetaResponseEntity> {
public:
};

#endif /* LocationGetResponseEntity_h */
