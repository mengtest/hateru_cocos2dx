//
//  GameEventTypeChurchEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeChurchEntity_h
#define GameEventTypeChurchEntity_h

#include "GameEventBaseEntity.h"

/// イベント 教会Entity
class GameEventTypeChurchEntity final: public GameEventBaseEntity<GameEventTypeChurchEntity> {
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

#endif /* GameEventTypeChurchEntity_h */