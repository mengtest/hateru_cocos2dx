//
//  GameEventIfTimeEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventIfTimeEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return 使用サイズ
 */
int GameEventIfTimeEntity::convertData(const unsigned char *data) {
	
	int dataIndex = 0;
	
	/// 日時時間タイプ
	dateTimeTypes.clear();
	for (int i = DateTimeTypeMonth;i <= DateTimeTypeWeek;i++) {
		dateTimeTypes.push_back((DateTimeType)data[dataIndex]);
		dataIndex += 1;
	}
	
	return dataIndex;
}
