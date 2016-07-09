//
//  GameEventTypeEncountRateEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeEncountRateEntity_h
#define GameEventTypeEncountRateEntity_h

#include "GameEventBaseEntity.h"

/// イベント 敵出現率Entity
class GameEventTypeEncountRateEntity final: public GameEventBaseEntity<GameEventTypeEncountRateEntity> {
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

#endif /* GameEventTypeEncountRateEntity_h */
