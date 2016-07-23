//
//  GameEventMoveLocationEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventMoveLocationEntity_h
#define GameEventMoveLocationEntity_h

#include "GameEventBaseEntity.h"

/// イベント 場所移動Entity
class GameEventMoveLocationEntity final: public GameEventBaseEntity {
public:
	
	/// マップID
	int32_t mapId;
	/// X座標
	int32_t x;
	/// Y座標
	int32_t y;
	
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

#endif /* GameEventMoveLocationEntity_h */
