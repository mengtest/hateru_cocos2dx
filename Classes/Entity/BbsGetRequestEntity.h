//
//  BbsGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BbsGetRequestEntity_h
#define BbsGetRequestEntity_h

#include "BaseRequestEntity.h"

/// 掲示板取得パラメータリクエストEntity
class BbsGetParamsRequestEntity final: public Ref {
public:
	/// 掲示板コード
	string bbsCode;
	/// 取得オフセット
	int32_t offset;
	/// 取得カウント
	int32_t count;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// 掲示板取得リクエストEntity
class BbsGetRequestEntity final: public BaseRequestEntity<BbsGetParamsRequestEntity> {
public:
};

#endif /* BbsGetRequestEntity_h */
