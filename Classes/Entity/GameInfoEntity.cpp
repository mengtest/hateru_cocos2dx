//
//  GameInfoEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameInfoEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameInfoEntity GameInfoEntity::convertData(const char *data) {

	auto dataIndex = 0;
	auto entity = GameInfoEntity();
	
	// 初期所持金
	entity.initMoney = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex+1];
	dataIndex += 2;
	// お金単位

	// 初期位置マップ

	// 初期位置X

	// 初期位置Y

	// 初期メンバ

	// 船

	// 飛行船

	// 音楽、船

	// 音楽、飛行船

	// 音楽、宿屋

	// 音楽、レベルアップ
	
	// 音楽、戦闘終了

	
	return entity;
}
