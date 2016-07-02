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
 */
void GameEnemyEncountEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// マップ
	mapId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// X
	x = (int32_t)data[dataIndex];
	dataIndex += 1;
	// Y
	y = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 幅
	width = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 高さ
	height = (int32_t)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameEnemyEncountEntity GameEnemyEncountEntity::createEntity(const unsigned char *data) {
	auto entity = GameEnemyEncountEntity();
	entity.convertData(data);
	return entity;
}