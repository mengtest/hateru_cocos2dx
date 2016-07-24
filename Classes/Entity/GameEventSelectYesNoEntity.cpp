//
//  GameEventSelectYesNoEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventSelectYesNoEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventSelectYesNoEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 乗り物タイプ
	variableId = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	
	return dataIndex;
}
