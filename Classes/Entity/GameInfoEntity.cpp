//
//  GameInfoEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameInfoEntity.h"

#include "SJISUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameInfoEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;

	// 初期所持金
	initMoney = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex+1];
	dataIndex += 2;
	// お金単位
	moneyUnit = SJISUtil::convertUTF8(&data[dataIndex], 4);
	dataIndex += 4;
	// 初期位置マップ
	initMapId = (int32_t)data[dataIndex] + 1;
	dataIndex += 1;
	// 初期位置X
	initX = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 初期位置Y
	initY = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 初期メンバ
	for (int i = 0;i < INIT_MEMBER_COUNT;i++) {
		initMemberIds.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}
	// 船
	shipUnitId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 飛行船
	flyShipUnitId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、船
	shipSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、飛行船
	flyShipSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、宿屋
	innSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、レベルアップ
	levelUpSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、戦闘終了
	battleEndSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameInfoEntity GameInfoEntity::createEntity(const unsigned char *data) {
	auto entity = GameInfoEntity();
	entity.convertData(data);
	return entity;
}
