//
//  GameEventTypeINNEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeINNEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeINNEntity::binarySize() {
	return 4;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeINNEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 値段
	price  = (int32_t)data[dataIndex];
	dataIndex += 2;
	// 退避変数Id
	variableId  = (int32_t)data[dataIndex];
	dataIndex += 2;
	
}
