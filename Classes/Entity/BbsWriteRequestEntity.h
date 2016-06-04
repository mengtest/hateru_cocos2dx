//
//  BbsWriteRequestEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/22.
//
//

#ifndef BbsWriteRequestEntity_h
#define BbsWriteRequestEntity_h

#include "BaseRequestEntity.h"

/// 掲示板書き込みパラメータリクエストEntity
class BbsWriteParamsRequestEntity final: public Ref {
public:
	
	/// 掲示板コード
	string bbsCode;
	/// メッセージコード
	string messageCode;
	/// メッセージタイプ
	string messageType;
	/// メッセージデータ
	string messageData;
	
	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
};

/// 掲示板書き込みリクエストEntity
class BbsWriteRequestEntity final: public BaseRequestEntity<BbsWriteParamsRequestEntity> {
public:
};

#endif /* BbsWriteRequestEntity_h */
