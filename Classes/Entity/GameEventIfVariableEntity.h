//
//  GameEventIfVariableEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventIfVariableEntity_h
#define GameEventIfVariableEntity_h

#include "GameEventBaseEntity.h"

/// イベント 変数分岐Entity
class GameEventIfVariableEntity final: public GameEventBaseEntity {
public:
	
	/// 変数ID
	int32_t variableId;
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

#endif /* GameEventIfVariableEntity_h */
