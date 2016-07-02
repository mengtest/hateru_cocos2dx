//
//  GameMapEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMapEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameMapEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 名前
	// 種類
	mapType = (MAP_TYPE)data[dataIndex];
	dataIndex += 1;
	// 幅
	width = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 高さ
	height = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 背景チップ
	height = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 画面制御
	
	dataIndex += 1;
	// 下マップチップ
	
	dataIndex += 1;
	// 読み飛ばし
	for (auto i = 0;i < MAPCHIP_VALUE_MAX;i++) {
		
		dataIndex += 1;
	}
	// 上マップチップ
	
	dataIndex += 1;
	// 読み飛ばし
	for (auto i = 0;i < MAPCHIP_VALUE_MAX;i++) {
		
		dataIndex += 1;
	}
	// 色の書込み
	
	dataIndex += 3;
	// 出現率
	
	dataIndex += 1;
	// テレポート/エスケープ
	
	dataIndex += 1;
	// サウンド
	
	dataIndex += 1;
	// 戦闘音楽
	
	dataIndex += 1;
	// 戦闘背景
	
	dataIndex += 1;
	if (mapType == MAP_TYPE_NORMAL) {
		// 通常マップ
		for (auto y = 0;y < height;y++) {
			for (auto x = 0;x < width;x++) {
				
				
				dataIndex += 3;
			}
		}
	} else {
		// 自動マップ
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameMapEntity GameMapEntity::createEntity(const unsigned char *data) {
	auto entity = GameMapEntity();
	entity.convertData(data);
	return entity;
}