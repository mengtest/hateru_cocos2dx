//
//  GameEventTypeRandomEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeRandomEntity_h
#define GameEventTypeRandomEntity_h

#include "GameEventBaseEntity.h"

/// イベント 乱数Entity
class GameEventTypeRandomEntity final: public GameEventBaseEntity<GameEventTypeRandomEntity> {
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

#endif /* GameEventTypeRandomEntity_h */
