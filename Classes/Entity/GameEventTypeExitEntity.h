//
//  GameEventTypeExitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeExitEntity_h
#define GameEventTypeExitEntity_h

#include "GameEventBaseEntity.h"

/// イベント イベント終了Entity
class GameEventTypeExitEntity final: public GameEventBaseEntity<GameEventTypeExitEntity> {
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

#endif /* GameEventTypeExitEntity_h */