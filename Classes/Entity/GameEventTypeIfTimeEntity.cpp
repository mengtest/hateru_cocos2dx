//
//  GameEventTypeIfTimeEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventTypeIfTimeEntity.h"

/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
int GameEventTypeIfTimeEntity::binarySize() {
	return DateTimeTypeWeek + 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEventTypeIfTimeEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 日時時間タイプ
	for (int i = DateTimeTypeMonth;i <= DateTimeTypeWeek;i++) {
		dateTimeTypes.push_back((DateTimeType)data[dataIndex]);
		dataIndex += 1;
	}
	
}
