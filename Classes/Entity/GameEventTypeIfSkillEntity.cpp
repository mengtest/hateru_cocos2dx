//
//  GameEventTypeIfSkillEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeIfSkillEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeIfSkillEntity::binarySize() {
	return 3;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeIfSkillEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 参照キャラ
	unitId = (int32_t)data[dataIndex];
	dataIndex += 1;
	/// 参照スキル
	skillId = (int32_t)data[dataIndex];
	dataIndex += 1;
	/// 会得
	isLearning = data[dataIndex] != 0;
	dataIndex += 1;
	
}
