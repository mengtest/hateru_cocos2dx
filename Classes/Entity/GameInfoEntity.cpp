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
 *
 *  @return Entity
 */
GameInfoEntity GameInfoEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;
	auto entity = GameInfoEntity();
	
	// 初期所持金
	entity.initMoney = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex+1];
	dataIndex += 2;
	// お金単位
	entity.moneyUnit = SJISUtil::convertUTF8(&data[dataIndex], 4);
	dataIndex += 4;
	// 初期位置マップ
	entity.initMapId = (int32_t)data[dataIndex] + 1;
	dataIndex += 1;
	// 初期位置X
	entity.initX = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 初期位置Y
	entity.initY = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 初期メンバ
	for (int i = 0;i < INIT_MEMBER_COUNT;i++) {
		entity.initMemberIds.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}
	// 船
	entity.shipUnitId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 飛行船
	entity.flyShipUnitId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、船
	entity.shipSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、飛行船
	entity.flyShipSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、宿屋
	entity.innSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、レベルアップ
	entity.levelUpSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 音楽、戦闘終了
	entity.battleEndSoundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	
	return entity;
}
