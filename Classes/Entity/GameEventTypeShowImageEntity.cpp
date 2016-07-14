//
//  GameEventTypeShowImageEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeShowImageEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeShowImageEntity::binarySize() {
	return 2;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeShowImageEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 表示/非表示
	isShow = data[dataIndex] != 0;
	dataIndex += 1;
	// 画像Id
	imageId = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
