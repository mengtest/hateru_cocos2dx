//
//  GameEventTypeIfTimeEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeIfTimeEntity_h
#define GameEventTypeIfTimeEntity_h

#include "GameEventBaseEntity.h"

/// イベント リアルタイム分岐Entity
class GameEventTypeIfTimeEntity final: public GameEventBaseEntity {
public:
	
	/// 日時時間タイプ
	vector<DateTimeType> dateTimeTypes;
	
	/**
	 *  バイナリサイズ取得
	 *
	 *  @return バイナリサイズ
	 */
	int binarySize();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventTypeIfTimeEntity_h */
