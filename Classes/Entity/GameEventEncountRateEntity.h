//
//  GameEventEncountRateEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventEncountRateEntity_h
#define GameEventEncountRateEntity_h

#include "GameEventBaseEntity.h"

/// イベント 敵出現率Entity
class GameEventEncountRateEntity final: public GameEventBaseEntity {
public:
	
	/// 敵出現率
	int32_t encoundRate;
	
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

#endif /* GameEventEncountRateEntity_h */
