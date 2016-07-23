//
//  GameEventChangeBGMEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventChangeBGMEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventChangeBGMEntity::binarySize() {
	return 3;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventChangeBGMEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 変数ID
	play = data[dataIndex] != 0;
	dataIndex += 1;
	// 値
	soundId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 操作タイプ
	fieldType = (SoundFieldType)data[dataIndex];
	dataIndex += 1;
	
}
