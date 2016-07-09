//
//  GameEventTypeItemBazaarEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeItemBazaarEntity_h
#define GameEventTypeItemBazaarEntity_h

#include "GameEventBaseEntity.h"

/// イベント バザーEntity
class GameEventTypeItemBazaarEntity final: public GameEventBaseEntity<GameEventTypeItemBazaarEntity> {
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

#endif /* GameEventTypeItemBazaarEntity_h */
