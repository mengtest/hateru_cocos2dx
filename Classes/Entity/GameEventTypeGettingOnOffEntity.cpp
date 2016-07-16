//
//  GameEventTypeGettingOnOffEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeGettingOnOffEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeGettingOnOffEntity::binarySize() {
	return 2;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeGettingOnOffEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 乗り物タイプ
	vehicleType = (VehicleType)data[dataIndex];
	dataIndex += 1;
	// 乗り降り
	isGetOff = data[dataIndex] != 0;
	dataIndex += 1;
	
}
