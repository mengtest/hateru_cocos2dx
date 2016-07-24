//
//  GameEventIfItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventIfItemEntity_h
#define GameEventIfItemEntity_h

#include "GameEventBaseEntity.h"

/// イベントアイテム分岐Entity
class GameEventIfItemEntity final: public GameEventBaseEntity {
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
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return 使用サイズ
	 */
	int convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventIfItemEntity_h */
