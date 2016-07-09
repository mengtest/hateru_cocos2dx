//
//  GameEventTypeBBSEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeBBSEntity_h
#define GameEventTypeBBSEntity_h

#include "GameEventBaseEntity.h"

/// イベント 掲示板Entity
class GameEventTypeBBSEntity final: public GameEventBaseEntity<GameEventTypeBBSEntity> {
public:
	
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

#endif /* GameEventTypeBBSEntity_h */
