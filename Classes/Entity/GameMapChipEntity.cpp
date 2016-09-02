//
//  GameMapChipEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMapChipEntity.h"

/**
 *  コンストラクタ
 */
GameMapChipEntity::GameMapChipEntity() {
	downChipId = 0;
	upChipId = 0;
	eventId = 0;
	isNotPassWalk = false;
	isNotPassShip = false;
	isNotPassFlyShip = false;
	isUpChipClear = false;
}

/**
 *  デストラクタ
 */
GameMapChipEntity::~GameMapChipEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameMapChipEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;

	// 下チップ
	downChipId = (int)data[dataIndex + 2] & 0x3f;
	// 上チップ
	upChipId = (int)data[dataIndex + 2] / 0x40;
	upChipId += (((int)data[dataIndex + 1] & 0xf) * 0x4);
	// イベント
	eventId = (int)data[dataIndex + 1] / 0x10;
	eventId += (((int)data[dataIndex] & 0x3) * 0x10);
	// 通行禁止
	isNotPassWalk = (data[dataIndex] & 0x4) != 0;
	// 船通行禁止
	isNotPassShip = (data[dataIndex] & 0x8) != 0;
	// 飛行通行禁止
	isNotPassFlyShip = (data[dataIndex] & 0x10) != 0;
	// 透過情報
	isUpChipClear = (data[dataIndex] & 0x20) != 0;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameMapChipEntity GameMapChipEntity::createEntity(const unsigned char *data) {
	auto entity = GameMapChipEntity();
	entity.convertData(data);
	return entity;
}