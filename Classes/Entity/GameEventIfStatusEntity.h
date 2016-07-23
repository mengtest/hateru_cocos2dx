//
//  GameEventIfStatusEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventIfStatusEntity_h
#define GameEventIfStatusEntity_h

#include "GameEventBaseEntity.h"

/// イベント ステータス分岐Entity
class GameEventIfStatusEntity final: public GameEventBaseEntity {
public:
	
	/// 参照キャラ
	int32_t unitId;
	/// 参照ステータス
	UnitStatusType statusType;
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

#endif /* GameEventIfStatusEntity_h */
