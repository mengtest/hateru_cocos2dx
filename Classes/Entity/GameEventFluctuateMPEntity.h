//
//  GameEventFluctuateMPEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventFluctuateMPEntity_h
#define GameEventFluctuateMPEntity_h

#include "GameEventBaseEntity.h"

/// イベント MP増減Entity
class GameEventFluctuateMPEntity final: public GameEventBaseEntity<GameEventFluctuateMPEntity> {
public:
	
	/// 対象
	int32_t target;
	/// 増減タイプ
	FluctuateType fluctuateType;
	/// 値
	int32_t value;
	
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

#endif /* GameEventFluctuateMPEntity_h */
