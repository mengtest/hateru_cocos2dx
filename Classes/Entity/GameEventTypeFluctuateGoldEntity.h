//
//  GameEventTypeFluctuateGoldEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeFluctuateGoldEntity_h
#define GameEventTypeFluctuateGoldEntity_h

#include "GameEventBaseEntity.h"

/// イベント 所持金増減Entity
class GameEventTypeFluctuateGoldEntity final: public GameEventBaseEntity {
public:
	
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

#endif /* GameEventTypeFluctuateGoldEntity_h */
