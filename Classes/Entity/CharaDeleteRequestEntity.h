//
//  CharaDeleteRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef CharaDeleteRequestEntity_h
#define CharaDeleteRequestEntity_h

#include "BaseRequestEntity.h"

/// キャラ削除パラメータリクエストEntity
class CharaDeleteParamsRequestEntity final: public Ref {
public:
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// キャラ削除リクエストEntity
class CharaDeleteRequestEntity final: public BaseRequestEntity<CharaDeleteParamsRequestEntity> {
public:
};

#endif /* CharaDeleteRequestEntity_h */
