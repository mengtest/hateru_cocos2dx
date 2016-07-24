//
//  GameEventINNEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventINNEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventINNEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	// 値段
	price  = (int32_t)data[dataIndex];
	dataIndex += 2;
	// 退避変数Id
	variableId  = (int32_t)data[dataIndex];
	dataIndex += 2;
	
	return dataIndex;
}
