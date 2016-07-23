//
//  GameEventWipeEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventWipeEntity_h
#define GameEventWipeEntity_h

#include "GameEventBaseEntity.h"

/// イベント ワイプEntity
class GameEventWipeEntity final: public GameEventBaseEntity {
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

#endif /* GameEventWipeEntity_h */
