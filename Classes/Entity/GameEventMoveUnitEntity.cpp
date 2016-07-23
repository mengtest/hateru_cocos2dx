//
//  GameEventMoveUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventMoveUnitEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventMoveUnitEntity::binarySize() {
	return (int)moveTypes.size() + 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventMoveUnitEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 移動
	int count = (int)data[dataIndex];
	dataIndex += 1;
	for (auto i = 0;i < count;i++) {
		moveTypes.push_back((EventMoveType)data[dataIndex]);
		dataIndex += 1;
	}
	
}
