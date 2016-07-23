//
//  GameEventChangeTeleportEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeTeleportEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventChangeTeleportEntity::binarySize() {
	return 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventChangeTeleportEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 有効/無効
	isValid = data[dataIndex] != 0;
	dataIndex += 1;

}
