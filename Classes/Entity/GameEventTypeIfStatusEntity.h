//
//  GameEventTypeIfStatusEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeIfStatusEntity_h
#define GameEventTypeIfStatusEntity_h

#include "GameEventBaseEntity.h"

/// イベント ステータス分岐Entity
class GameEventTypeIfStatusEntity final: public GameEventBaseEntity<GameEventTypeIfStatusEntity> {
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

#endif /* GameEventTypeIfStatusEntity_h */
