//
//  GameEventTypeFluctuateEXPEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeFluctuateEXPEntity_h
#define GameEventTypeFluctuateEXPEntity_h

#include "GameEventBaseEntity.h"

/// イベント 経験値増減Entity
class GameEventTypeFluctuateEXPEntity final: public GameEventBaseEntity<GameEventTypeFluctuateEXPEntity> {
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

#endif /* GameEventTypeFluctuateEXPEntity_h */
