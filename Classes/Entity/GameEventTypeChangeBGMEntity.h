//
//  GameEventTypeChangeBGMEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeChangeBGMEntity_h
#define GameEventTypeChangeBGMEntity_h

#include "GameEventBaseEntity.h"

/// イベント BGM変更Entity
class GameEventTypeChangeBGMEntity final: public GameEventBaseEntity {
public:
	
	/// 再生
	bool play;
	/// サウンドID
	int32_t soundId;
	/// マップ/戦闘
	SoundFieldType fieldType;
	
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

#endif /* GameEventTypeChangeBGMEntity_h */
