//
//  GameEventTypeWipeEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeWipeEntity_h
#define GameEventTypeWipeEntity_h

#include "GameEventBaseEntity.h"

/// イベント ワイプEntity
class GameEventTypeWipeEntity final: public GameEventBaseEntity<GameEventTypeWipeEntity> {
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

#endif /* GameEventTypeWipeEntity_h */
