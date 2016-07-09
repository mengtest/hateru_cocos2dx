//
//  GameEventTypeGettingOnOffEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeGettingOnOffEntity_h
#define GameEventTypeGettingOnOffEntity_h

#include "GameEventBaseEntity.h"

/// イベント 船乗降りEntity
class GameEventTypeGettingOnOffEntity final: public GameEventBaseEntity<GameEventTypeGettingOnOffEntity> {
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

#endif /* GameEventTypeGettingOnOffEntity_h */
