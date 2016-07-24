//
//  GameEventFluctuateHPEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventFluctuateHPEntity_h
#define GameEventFluctuateHPEntity_h

#include "GameEventBaseEntity.h"

/// イベント HP増減Entity
class GameEventFluctuateHPEntity final: public GameEventBaseEntity {
public:
	
	/// 対象
	int32_t target;
	/// 増減タイプ
	FluctuateType fluctuateType;
	/// 値
	int32_t value;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return 使用サイズ
	 */
	int convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventFluctuateHPEntity_h */
