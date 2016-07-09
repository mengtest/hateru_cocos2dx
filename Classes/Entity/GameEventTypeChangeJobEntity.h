//
//  GameEventTypeChangeJobEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeChangeJobEntity_h
#define GameEventTypeChangeJobEntity_h

#include "GameEventBaseEntity.h"

/// イベント 職業変更Entity
class GameEventTypeChangeJobEntity final: public GameEventBaseEntity<GameEventTypeChangeJobEntity> {
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

#endif /* GameEventTypeChangeJobEntity_h */
