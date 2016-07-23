//
//  GameEventBattleEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventBattleEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventBattleEntity::binarySize() {
	return (int)enemyIds.size() + 2;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventBattleEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 結果退避変数Id TODO:本当は2バイトにしないといけない。
	variableId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 数取得
	int count = (int)data[dataIndex];
	dataIndex += 1;
	for (auto i = 0;i < count;i++) {
		// 敵Id
		enemyIds.push_back((int32_t)data[dataIndex]);
		dataIndex += 1;
	}
	
}
