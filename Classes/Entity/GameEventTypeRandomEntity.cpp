//
//  GameEventTypeRandomEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeRandomEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeRandomEntity::binarySize() {
	return 4;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeRandomEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 退避変数
	variableId = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// From
	from = (int32_t)data[dataIndex];
	dataIndex += 1;
	// To
	to = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
