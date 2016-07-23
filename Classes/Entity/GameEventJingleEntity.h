//
//  GameEventJingleEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventJingleEntity_h
#define GameEventJingleEntity_h

#include "GameEventBaseEntity.h"

/// イベント ジングルEntity
class GameEventJingleEntity final: public GameEventBaseEntity {
public:
	
	/// サウンドId
	int32_t soundId;
	/// 再生が終わるまで待つ
	bool isWait;
	
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

#endif /* GameEventJingleEntity_h */
