//
//  GameEventMoveLocationEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventMoveLocationEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventMoveLocationEntity::binarySize() {
	return 3;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventMoveLocationEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// マップID
	mapId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// X座標
	x = (int32_t)data[dataIndex];
	dataIndex += 1;
	// Y座標
	y = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
