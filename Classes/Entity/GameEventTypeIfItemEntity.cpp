//
//  GameEventTypeIfItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeIfItemEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeIfItemEntity::binarySize() {
	return 4;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeIfItemEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 参照キャラ
	unitId = (int32_t)data[dataIndex];
	dataIndex += 1;
	/// 参照ステータス
	itemId = (int32_t)data[dataIndex];
	dataIndex += 1;
	/// 式
	formulaType = (IfFormulaType)data[dataIndex];
	dataIndex += 1;
	/// 値
	value = (int32_t)data[dataIndex];
	dataIndex += 1;
	
}
