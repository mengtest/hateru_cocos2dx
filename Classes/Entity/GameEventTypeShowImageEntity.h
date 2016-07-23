//
//  GameEventTypeShowImageEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeShowImageEntity_h
#define GameEventTypeShowImageEntity_h

#include "GameEventBaseEntity.h"

/// イベント 画像表示Entity
class GameEventTypeShowImageEntity final: public GameEventBaseEntity {
public:
	
	/// 表示/非表示
	bool isShow;
	/// 画像Id
	int32_t imageId;
	
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

#endif /* GameEventTypeShowImageEntity_h */
