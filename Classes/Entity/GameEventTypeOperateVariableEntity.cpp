//
//  GameEventTypeOperateVariableEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeOperateVariableEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeOperateVariableEntity::binarySize() {
	return 4;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeOperateVariableEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 変数ID
	variableId = (int32_t)data[dataIndex + 1] * 0x100 + (int32_t)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 操作タイプ
	operateType = (VariableOperateType)data[dataIndex];
	dataIndex += 1;
	
}
