//
//  GameEventSettingShipEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventSettingShipEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventSettingShipEntity::binarySize() {
	return 5;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventSettingShipEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 乗り物タイプ
	vehicleType = (VehicleType)data[dataIndex];
	dataIndex += 1;
	/// 表示/非表示
	isShow = data[dataIndex] != 0;
	dataIndex += 1;
	/// マップId
	mapId = (int32_t)data[dataIndex];
	dataIndex += 1;
	/// X座標
	x = (int32_t)data[dataIndex];
	dataIndex += 1;
	/// Y座標
	y = (int32_t)data[dataIndex];
	dataIndex += 1;

}
