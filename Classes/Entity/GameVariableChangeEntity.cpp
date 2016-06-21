//
//  GameVariableChangeEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameVariableChangeEntity.h"

/**
 *  値の整合性チェック
 *
 *  @return 生合成チェック可否
 */
bool GameVariableChangeEntity::isValid() {
	
	return true;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 */
void GameVariableChangeEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;
	
	// 変数Id
	variableId = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 式
	expression = (VARIABLE_ZG_TYPE)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int32_t)data[dataIndex];
	dataIndex += 1;
}