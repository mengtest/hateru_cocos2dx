//
//  GameEventTypeFluctuateEXPEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeFluctuateEXPEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeFluctuateEXPEntity::binarySize() {
	return 4;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeFluctuateEXPEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// ターゲット
	target = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 増減タイプ
	fluctuateType = (FluctuateType)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	
}
