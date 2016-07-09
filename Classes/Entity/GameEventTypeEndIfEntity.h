//
//  GameEventTypeEndIfEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeEndIfEntity_h
#define GameEventTypeEndIfEntity_h

#include "GameEventBaseEntity.h"

/// イベント 変数分岐終了Entity
class GameEventTypeEndIfEntity final: public GameEventBaseEntity<GameEventTypeEndIfEntity> {
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

#endif /* GameEventTypeEndIfEntity_h */
