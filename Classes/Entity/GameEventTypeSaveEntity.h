//
//  GameEventTypeSaveEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeSaveEntity_h
#define GameEventTypeSaveEntity_h

#include "GameEventBaseEntity.h"

/// イベント セーブEntity
class GameEventTypeSaveEntity final: public GameEventBaseEntity<GameEventTypeSaveEntity> {
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

#endif /* GameEventTypeSaveEntity_h */
