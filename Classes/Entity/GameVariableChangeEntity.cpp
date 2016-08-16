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
	variableId = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// 式
	operateType = (VariableOperateType)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int)data[dataIndex];
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameVariableChangeEntity GameVariableChangeEntity::createEntity(const unsigned char *data) {
	auto entity = GameVariableChangeEntity();
	entity.convertData(data);
	return entity;
}