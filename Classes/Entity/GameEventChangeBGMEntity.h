//
//  GameEventChangeBGMEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventChangeBGMEntity_h
#define GameEventChangeBGMEntity_h

#include "GameEventBaseEntity.h"

/// イベント BGM変更Entity
class GameEventChangeBGMEntity final: public GameEventBaseEntity {
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

#endif /* GameEventChangeBGMEntity_h */
