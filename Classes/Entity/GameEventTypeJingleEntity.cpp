//
//  GameEventTypeJingleEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeJingleEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeJingleEntity::binarySize() {
	return 2;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeJingleEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// サウンドId
	soundId = data[dataIndex];
	dataIndex += 1;
	// ウエイト/スルー
	isWait = data[dataIndex] != 0;
	dataIndex += 1;
	
}
