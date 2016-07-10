//
//  GameEventTypeItemShopEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeItemShopEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeItemShopEntity::binarySize() {
	return (int)itemIds.size() + 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeItemShopEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 数取得
	int count = (int)data[dataIndex];
	dataIndex += 1;
	for (auto i = 0;i < count;i++) {
		// 売りアイテムId
		itemIds.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}
	
}
