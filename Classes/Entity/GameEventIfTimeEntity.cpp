//
//  GameEventIfTimeEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfTimeEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventIfTimeEntity::binarySize() {
	return DateTimeTypeWeek + 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventIfTimeEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 日時時間タイプ
	for (int i = DateTimeTypeMonth;i <= DateTimeTypeWeek;i++) {
		dateTimeTypes.push_back((DateTimeType)data[dataIndex]);
		dataIndex += 1;
	}
	
}
