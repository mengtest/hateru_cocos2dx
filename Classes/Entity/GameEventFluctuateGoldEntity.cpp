//
//  GameEventFluctuateGoldEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventFluctuateGoldEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventFluctuateGoldEntity::binarySize() {
	return 3;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventFluctuateGoldEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 増減タイプ
	fluctuateType = (FluctuateType)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	
}
