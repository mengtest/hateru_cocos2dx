//
//  GameEventTypeIfVariableEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeIfVariableEntity_h
#define GameEventTypeIfVariableEntity_h

#include "GameEventBaseEntity.h"

/// イベント 変数分岐Entity
class GameEventTypeIfVariableEntity final: public GameEventBaseEntity<GameEventTypeIfVariableEntity> {
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

#endif /* GameEventTypeIfVariableEntity_h */
