//
//  GameEventChangeUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeUnitEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventChangeUnitEntity::binarySize() {
	return 2;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventChangeUnitEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 画像使用
	isUseImage = data[dataIndex] != 0;
	dataIndex += 1;
	// キャラID
	charaId = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
