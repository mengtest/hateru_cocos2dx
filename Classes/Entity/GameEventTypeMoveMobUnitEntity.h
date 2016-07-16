//
//  GameEventTypeMoveMobUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeMoveMobUnitEntity_h
#define GameEventTypeMoveMobUnitEntity_h

#include "GameEventBaseEntity.h"

/// イベント キャラ移動Entity
class GameEventTypeMoveMobUnitEntity final: public GameEventBaseEntity<GameEventTypeMoveMobUnitEntity> {
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

#endif /* GameEventTypeMoveMobUnitEntity_h */
