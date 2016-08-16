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
	width = (int)data[dataIndex];
	dataIndex += 1;
	// 高さ
	height = (int)data[dataIndex];
	dataIndex += 1;
	// 背景チップ
	backgroundImageId = (int)data[dataIndex];
	dataIndex += 1;
	// 画面制御
	mapEndType = (MapLoopType)data[dataIndex];
	dataIndex += 1;
	// 下マップチップ
	downMapChpGpId = (int)data[dataIndex];
	dataIndex += 1;
	// 読み飛ばし
	dataIndex += MAPCHIP_VALUE_MAX;
	// 上マップチップ
	upMapChpGpId = (int)data[dataIndex];
	dataIndex += 1;
	// 読み飛ばし
	dataIndex += MAPCHIP_VALUE_MAX;
	// 色の書込み
	backgroundColor = (int)data[dataIndex] * 0x10000 + (int)data[dataIndex + 1] * 0x100 + (int)data[dataIndex + 2];
	dataIndex += 3;
	// 出現率
	enemyEncountRate = (int)data[dataIndex];
	dataIndex += 1;
	// テレポート/エスケープ
	isUseTeleport = (data[dataIndex] & 0x10) != 0;
	isUseEscape = (data[dataIndex] & 0x1) != 0;
	dataIndex += 1;
	// サウンド
	soundId = (int)data[dataIndex];
	dataIndex += 1;
	// 戦闘音楽
	battleSoundId = (int)data[dataIndex];
	dataIndex += 1;
	// 戦闘背景
	battleBackgroundImageId = (int)data[dataIndex];
	dataIndex += 1;
	mapChips.clear();
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
 *  @param data  バイナリデータ
 *  @param names 名前
 */
void GameMapEntity::convertEventData(const unsigned char *data, const vector<string> names) {
	
	auto dataIndex = 0;

	// イベント数
	int count = (int)data[dataIndex];
	dataIndex += 1;
	
	events.clear();
	for (auto i = 0;i < count;i++) {
		auto entity = GameEventEntity();
		dataIndex += entity.convertData(&data[dataIndex], names[i]);
		events[i] = entity;
	}
}