//
//  GameEnemyEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#include "GameEnemyEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameEnemyEntity GameEnemyEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	auto entity = GameEnemyEntity();

	// 名前
	entity.name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 画像
	entity.imageId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// ステータス
	for (auto i = 0;i < 14;i++) {
		entity.statuses.push_back((int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1]);
		dataIndex += 2;
	}
	// 獲得アイテム
	entity.item.convertData(&data[dataIndex]);
	dataIndex += 3;
	// 攻撃パターン
	for (auto i = 0;i < 7;i++) {
		entity.attackPattern.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}
	// 出現座標数
	auto count = (int)data[dataIndex];
	for (auto i = 0;i < count;i++) {
		entity.encounts.push_back(GameEnemyEncountEntity::convertData(&data[dataIndex]));
		dataIndex += 5;
	}
	// 出現場所
	entity.encountAttribute = (int32_t)data[dataIndex];
	dataIndex += 1;
	
	return entity;
}