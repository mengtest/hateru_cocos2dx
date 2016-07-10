//
//  GameEventTypeFluctuateTeleportEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeFluctuateTeleportEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeFluctuateTeleportEntity::binarySize() {
	return 2 + 3 * 3 + 16;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeFluctuateTeleportEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 追加削除
	isRemove = data[dataIndex] != 0;
	dataIndex += 1;
	// 対象マップId
	mapId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 飛ぶ位置
	for (auto i = (int)MoveTypeWalk;i <= (int)MoveTypeFlyShip;i++) {
		// マップId
		jumpMapIds.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
		// X座標
		jumpXs.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
		// Y座標
		jumpYs.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}
	// 表示名
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
}