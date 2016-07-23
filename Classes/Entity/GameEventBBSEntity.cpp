//
//  GameEventBBSEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventBBSEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventBBSEntity::binarySize() {
	return 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventBBSEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 掲示板種類 (使用していない)
	dataIndex += 1;
	
}
