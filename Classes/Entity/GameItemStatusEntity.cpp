//
//  GameItemStatusEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemStatusEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 *
 *  @return Entity
 */
GameItemStatusEntity GameItemStatusEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	auto entity = GameItemStatusEntity();
	
	// ステータス
	entity.status = (ITEM_STATUS_TYPE)data[dataIndex];
	dataIndex += 1;
	// 値
	entity.value = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	entity.value -= 30000;
	dataIndex += 2;
	
	return entity;
}
