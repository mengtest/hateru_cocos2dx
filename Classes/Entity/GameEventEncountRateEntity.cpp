//
//  GameEventEncountRateEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventEncountRateEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventEncountRateEntity::binarySize() {
	return 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventEncountRateEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 敵出現率
	encoundRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
