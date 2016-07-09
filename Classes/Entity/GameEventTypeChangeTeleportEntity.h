//
//  GameEventTypeChangeTeleportEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeChangeTeleportEntity_h
#define GameEventTypeChangeTeleportEntity_h

#include "GameEventBaseEntity.h"

/// イベント テレポート禁止変更Entity
class GameEventTypeChangeTeleportEntity final: public GameEventBaseEntity<GameEventTypeChangeTeleportEntity> {
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

#endif /* GameEventTypeChangeTeleportEntity_h */
