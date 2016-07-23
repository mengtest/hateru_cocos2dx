//
//  GameMapEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMapEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 */
void GameMapEntity::convertData(const unsigned char *data, const string &name) {
	
	auto dataIndex = 0;
	
	// 名前
	this->name = name;
	// 種類
	mapType = (MapType)data[dataIndex];
	dataIndex += 1;
	// 幅
	width = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 高さ
	height = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 背景チップ
	backgroundImageId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 画面制御
	mapEndType = (MapLoopType)data[dataIndex];
	dataIndex += 1;
	// 下マップチップ
	downMapChpGpId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 読み飛ばし
	dataIndex += MAPCHIP_VALUE_MAX;
	// 上マップチップ
	upMapChpGpId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 読み飛ばし
	dataIndex += MAPCHIP_VALUE_MAX;
	// 色の書込み
	backgroundColor = (int32_t)data[dataIndex] * 0x10000 + (int32_t)data[dataIndex + 1] * 0x100 + (int32_t)data[dataIndex + 2];
	dataIndex += 3;
	// 出現率
	enemyEncountRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// テレポート/エスケープ
	isUseTeleport = (data[dataIndex] & 0x10) != 0;
	isUseEscape = (data[dataIndex] & 0x1) != 0;
	dataIndex += 1;
	// サウンド
	soundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 戦闘音楽
	battleSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 戦闘背景
	battleBackgroundImageId = (int32_t)data[dataIndex];
	dataIndex += 1;
	if (mapType == MapTypeNormal) {
		// 通常マップ
		for (auto y = 0;y < height;y++) {
			for (auto x = 0;x < width;x++) {
				mapChips.push_back(GameMapChipEntity::createEntity(&data[dataIndex]));
				dataIndex += 3;
			}
		}
	} else {
		// 自動マップ
		autoMap.convertData(&data[dataIndex]);
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return Entity
 */
GameMapEntity GameMapEntity::createEntity(const unsigned char *data, const string &name) {
	auto entity = GameMapEntity();
	entity.convertData(data, name);
	return entity;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 */
void GameMapEntity::convertEventData(const unsigned char *data) {
	
	auto dataIndex = 0;

	// イベント数
	int count = (int)data[dataIndex];
	dataIndex += 1;
	
	for (auto i = 0;i < count;i++) {
//		events
	}
}
