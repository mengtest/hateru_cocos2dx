//
//  GameEventTypeBarEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeBarEntity_h
#define GameEventTypeBarEntity_h

#include "GameEventBaseEntity.h"

/// イベント 酒場Entity
class GameEventTypeBarEntity final: public GameEventBaseEntity<GameEventTypeBarEntity> {
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

#endif /* GameEventTypeBarEntity_h */
