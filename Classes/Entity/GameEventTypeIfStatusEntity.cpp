//
//  GameEventTypeIfStatusEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeIfStatusEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeIfStatusEntity::binarySize() {
	return 5;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeIfStatusEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 参照キャラ
	unitId = (int32_t)data[dataIndex];
	dataIndex += 1;
	/// 参照ステータス
	statusType = (UnitStatusType)data[dataIndex];
	dataIndex += 1;
	/// 式
	formulaType = (IfFormulaType)data[dataIndex];
	dataIndex += 1;
	/// 値
	value = (int32_t)data[dataIndex] * 0x100 + data[dataIndex + 1];
	dataIndex += 2;
	
}
