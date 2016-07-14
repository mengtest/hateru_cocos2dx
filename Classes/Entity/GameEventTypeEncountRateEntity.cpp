//
//  GameEventTypeEncountRateEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeEncountRateEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeEncountRateEntity::binarySize() {
	return 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeEncountRateEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 敵出現率
	encoundRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
