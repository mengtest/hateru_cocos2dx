//
//  GameEventTypeChangeChipEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeChangeChipEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeChangeChipEntity::binarySize() {
	return 7;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeChangeChipEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 通行禁止
	isNotPassWalk = data[dataIndex] != 0;
	dataIndex += 1;
	// 上下チップ
	isUpChip = data[dataIndex] != 0;
	dataIndex += 1;
	// チップ
	chipId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// X座標
	x = (int32_t)data[dataIndex];
	dataIndex += 1;
	// Y座標
	y = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 船通行禁止
	isNotPassShip = data[dataIndex] != 0;
	dataIndex += 1;
	// 飛行通行禁止
	isNotPassFlyShip = data[dataIndex] != 0;
	dataIndex += 1;
	
}
