//
//  GameEnemyEncountEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#include "GameEnemyEncountEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameEnemyEncountEntity GameEnemyEncountEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;
	auto entity = GameEnemyEncountEntity();
	
	// マップ
	entity.mapId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// X
	entity.x = (int32_t)data[dataIndex];
	dataIndex += 1;
	// Y
	entity.y = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 幅
	entity.width = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 高さ
	entity.height = (int32_t)data[dataIndex];
	dataIndex += 1;
	
	return entity;
}