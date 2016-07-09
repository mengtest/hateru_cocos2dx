//
//  GameEventTypeMoveUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeMoveUnitEntity_h
#define GameEventTypeMoveUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント 主人公移動Entity
class GameEventTypeMoveUnitEntity final: public GameEventBaseEntity<GameEventTypeMoveUnitEntity> {
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

#endif /* GameEventTypeMoveUnitEntity_h */
