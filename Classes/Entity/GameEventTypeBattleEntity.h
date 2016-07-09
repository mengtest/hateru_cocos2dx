//
//  GameEventTypeBattleEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeBattleEntity_h
#define GameEventTypeBattleEntity_h

#include "GameEventBaseEntity.h"

/// イベント 戦闘Entity
class GameEventTypeBattleEntity final: public GameEventBaseEntity<GameEventTypeBattleEntity> {
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

#endif /* GameEventTypeBattleEntity_h */
