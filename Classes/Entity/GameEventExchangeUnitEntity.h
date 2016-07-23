//
//  GameEventExchangeUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventExchangeUnitEntity_h
#define GameEventExchangeUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント メンバー入替Entity
class GameEventExchangeUnitEntity final: public GameEventBaseEntity {
public:
	
	/// 入替タイプ
	ExchangeUnitType exchangeType;
	/// 外すキャラId
	int32_t removeCharaId;
	/// 追加キャラId
	int32_t addCharaId;
	
	/**
	 *  バイナリサイズ取得
	 *
	 *  @return バイナリサイズ
	 */
	int binarySize();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventExchangeUnitEntity_h */
