//
//  GameItemMixEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemMixEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 *
 *  @return Entity
 */
GameItemMixEntity GameItemMixEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	auto entity = GameItemMixEntity();
	
	// アイテムID
	entity.itemId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 値
	entity.value = (int32_t)data[dataIndex];
	dataIndex += 1;
	
	return entity;
}