//
//  GameEventTypeFluctuateTeleportEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeFluctuateTeleportEntity_h
#define GameEventTypeFluctuateTeleportEntity_h

#include "GameEventBaseEntity.h"

/// イベント テレポート位置増減Entity
class GameEventTypeFluctuateTeleportEntity final: public GameEventBaseEntity<GameEventTypeFluctuateTeleportEntity> {
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

#endif /* GameEventTypeFluctuateTeleportEntity_h */
