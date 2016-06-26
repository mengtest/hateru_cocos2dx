//
//  GameEnemyItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#include "GameEnemyItemEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEnemyItemEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 獲得フラグ
	isWon = (data[dataIndex] == 1);
	dataIndex += 1;
	// 獲得率
	rate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 獲得アイテム
	itemId = (int32_t)data[dataIndex];
	dataIndex += 1;
}