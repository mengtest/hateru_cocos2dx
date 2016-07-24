//
//  GameEventOperateVariableEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventOperateVariableEntity_h
#define GameEventOperateVariableEntity_h

#include "GameEventBaseEntity.h"

/// イベント 変数操作Entity
class GameEventOperateVariableEntity final: public GameEventBaseEntity {
public:
	
	/// 変数ID
	int32_t variableId;
	/// 値
	int32_t value;
	/// 式
	VariableOperateType operateType;
	
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

#endif /* GameEventOperateVariableEntity_h */
