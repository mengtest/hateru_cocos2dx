//
//  GameEventMoveUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventMoveUnitEntity_h
#define GameEventMoveUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント 主人公移動Entity
class GameEventMoveUnitEntity final: public GameEventBaseEntity {
public:
	
	/// 移動
	vector<EventMoveType> moveTypes;
	
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

#endif /* GameEventMoveUnitEntity_h */
