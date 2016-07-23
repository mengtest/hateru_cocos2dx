//
//  GameEventTypeIfItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeIfItemEntity_h
#define GameEventTypeIfItemEntity_h

#include "GameEventBaseEntity.h"

/// イベントアイテム分岐Entity
class GameEventTypeIfItemEntity final: public GameEventBaseEntity {
public:
	
	/// 参照キャラ (0:全て)
	int32_t unitId;
	/// 参照アイテム
	int32_t itemId;
	/// 式
	IfFormulaType formulaType;
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

#endif /* GameEventTypeIfItemEntity_h */
