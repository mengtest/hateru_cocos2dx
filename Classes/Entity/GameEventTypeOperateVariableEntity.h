//
//  GameEventTypeOperateVariableEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeOperateVariableEntity_h
#define GameEventTypeOperateVariableEntity_h

#include "GameEventBaseEntity.h"

/// イベント 変数操作Entity
class GameEventTypeOperateVariableEntity final: public GameEventBaseEntity<GameEventTypeOperateVariableEntity> {
public:
	
	/// 変数ID
	int32_t variableId;
	/// 値
	int32_t value;
	/// 式
	VariableOperateType operateType;
	
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

#endif /* GameEventTypeOperateVariableEntity_h */
