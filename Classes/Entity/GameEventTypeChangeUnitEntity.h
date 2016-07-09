//
//  GameEventTypeChangeUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeChangeUnitEntity_h
#define GameEventTypeChangeUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント キャラ変更Entity
class GameEventTypeChangeUnitEntity final: public GameEventBaseEntity<GameEventTypeChangeUnitEntity> {
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

#endif /* GameEventTypeChangeUnitEntity_h */
