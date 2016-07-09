//
//  GameEventTypeMoveLocationEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeMoveLocationEntity_h
#define GameEventTypeMoveLocationEntity_h

#include "GameEventBaseEntity.h"

/// イベント 場所移動Entity
class GameEventTypeMoveLocationEntity final: public GameEventBaseEntity<GameEventTypeMoveLocationEntity> {
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

#endif /* GameEventTypeMoveLocationEntity_h */
