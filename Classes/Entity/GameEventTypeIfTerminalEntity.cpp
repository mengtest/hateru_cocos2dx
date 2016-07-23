//
//  GameEventTypeIfTerminalEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeIfTerminalEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeIfTerminalEntity::binarySize() {
	return 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeIfTerminalEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// キャリアタイプ
	careerType = data[dataIndex];
	dataIndex += 1;
	
}
