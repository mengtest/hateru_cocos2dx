//
//  GameEventTypeExchangeUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeExchangeUnitEntity_h
#define GameEventTypeExchangeUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント メンバー入替Entity
class GameEventTypeExchangeUnitEntity final: public GameEventBaseEntity<GameEventTypeExchangeUnitEntity> {
public:
	
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

#endif /* GameEventTypeExchangeUnitEntity_h */
