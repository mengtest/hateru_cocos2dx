//
//  GameCharaEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameCharaEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameCharaEntity GameCharaEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;
	auto entity = GameCharaEntity();
	
	// 名前
	entity.name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 初期職業
	entity.initJobId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 画像
	for (auto i = 0;i < 8;i++) {
		entity.imageIds.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}
	// 初期所持アイテム
	auto count = (int)data[dataIndex];
	dataIndex += 1;
	for (auto i = 0;i < count;i++) {
		entity.initItemIds.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}

	
	return entity;
}