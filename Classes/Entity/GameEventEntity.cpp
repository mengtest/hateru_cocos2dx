//
//  GameEventEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameEventEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 */
void GameEventEntity::convertData(const unsigned char *data, const string &name) {
	
	auto dataIndex = 0;
	
	// 名前
	this->name = name;
	
	// イベント数
	int count = (int)data[dataIndex];
	dataIndex += 1;
	
	for (auto i = 0;i < count;i++) {
		// 変数による発生
		dataIndex += 1;
		// 変数Id
		dataIndex += 2;
		// 式
		dataIndex += 1;
		// 値
		dataIndex += 1;
		// 開始条件
		dataIndex += 1;
		// 移動タイプ
		dataIndex += 1;
			// 詳細移動数
			int moveCount = (int)data[dataIndex];
			dataIndex += 1;
			// 詳細移動
			for (auto j = 0;j < moveCount;j++) {
				
				dataIndex += 1;
			}
		// キャラ使用
		dataIndex += 1;
		// キャラId
		dataIndex += 1;
		// 詳細数
		int detailCount = (int)data[dataIndex];
		dataIndex += 1;
		// イベント詳細ヘッダ
		for (auto j = 0;j < detailCount;j++) {
			// タイプ
			
			dataIndex += 1;
			// 使用サイズ
			
			dataIndex += 1;
		}
		// イベント詳細
		for (auto j = 0;j < detailCount;j++) {
		}
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return Entity
 */
GameEventEntity GameEventEntity::createEntity(const unsigned char *data, const string &name) {
	auto entity = GameEventEntity();
	entity.convertData(data, name);
	return entity;
}