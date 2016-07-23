//
//  GameEventTypeFluctuateItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeFluctuateItemEntity_h
#define GameEventTypeFluctuateItemEntity_h

#include "GameEventBaseEntity.h"

/// イベント アイテム増減Entity
class GameEventTypeFluctuateItemEntity final: public GameEventBaseEntity {
public:
	
	/// 増減タイプ
	FluctuateType fluctuateType;
	/// アイテムID
	int32_t itemId;
	
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

#endif /* GameEventTypeFluctuateItemEntity_h */
