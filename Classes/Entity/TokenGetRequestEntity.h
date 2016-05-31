//
//  TokenGetRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/18.
//
//

#ifndef TokenGetRequestEntity_h
#define TokenGetRequestEntity_h

#include "BaseRequestEntity.h"

/// トークン取得パラメータリクエストEntity
class TokenGetParamsRequestEntity final: public Ref {
public:
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// トークン取得リクエストEntity
class TokenGetRequestEntity final: public BaseRequestEntity<TokenGetParamsRequestEntity> {
public:
};

#endif /* TokenGetRequestEntity_h */
