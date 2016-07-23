//
//  GameEventFluctuateItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventFluctuateItemEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventFluctuateItemEntity::binarySize() {
	return 2;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventFluctuateItemEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 増減タイプ
	fluctuateType = (FluctuateType)data[dataIndex];
	dataIndex += 1;
	// 値
	itemId = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
