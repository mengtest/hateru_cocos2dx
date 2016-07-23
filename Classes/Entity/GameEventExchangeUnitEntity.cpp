//
//  GameEventExchangeUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventExchangeUnitEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventExchangeUnitEntity::binarySize() {
	return 3;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventExchangeUnitEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 入替タイプ
	exchangeType = (ExchangeUnitType)data[dataIndex];
	dataIndex += 1;
	// 外すキャラId
	removeCharaId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 追加キャラId
	addCharaId = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
