//
//  GameEventTypeChangeEscapeEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeChangeEscapeEntity_h
#define GameEventTypeChangeEscapeEntity_h

#include "GameEventBaseEntity.h"

/// イベント エスケープ禁止変更Entity
class GameEventTypeChangeEscapeEntity final: public GameEventBaseEntity<GameEventTypeChangeEscapeEntity> {
public:
	
	/// 有効/無効
	bool isValid;
	
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

#endif /* GameEventTypeChangeEscapeEntity_h */
