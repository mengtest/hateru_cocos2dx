//
//  GameEventChangeEscapeEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeEscapeEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventChangeEscapeEntity::binarySize() {
	return 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventChangeEscapeEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 有効/無効
	isValid = data[dataIndex] != 0;
	dataIndex += 1;
	
}
