//
//  GameEventBBSEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventBBSEntity_h
#define GameEventBBSEntity_h

#include "GameEventBaseEntity.h"

/// イベント 掲示板Entity
class GameEventBBSEntity final: public GameEventBaseEntity {
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

#endif /* GameEventBBSEntity_h */
