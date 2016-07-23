//
//  GameEventTypeRandomEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeRandomEntity_h
#define GameEventTypeRandomEntity_h

#include "GameEventBaseEntity.h"

/// イベント 乱数Entity
class GameEventTypeRandomEntity final: public GameEventBaseEntity {
public:
	
	/// 退避変数
	int32_t variableId;
	/// 範囲From
	int32_t from;
	/// 範囲To
	int32_t to;
	
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

#endif /* GameEventTypeRandomEntity_h */
