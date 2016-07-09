//
//  GameEventTypeChangeChipEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeChangeChipEntity_h
#define GameEventTypeChangeChipEntity_h

#include "GameEventBaseEntity.h"

/// イベント マップチップ変更Entity
class GameEventTypeChangeChipEntity final: public GameEventBaseEntity<GameEventTypeChangeChipEntity> {
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

#endif /* GameEventTypeChangeChipEntity_h */
