//
//  GameEventTypeSaveEscapeLocationEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeSaveEscapeLocationEntity_h
#define GameEventTypeSaveEscapeLocationEntity_h

#include "GameEventBaseEntity.h"

/// イベント エスケープで戻る位置を保存Entity
class GameEventTypeSaveEscapeLocationEntity final: public GameEventBaseEntity<GameEventTypeSaveEscapeLocationEntity> {
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

#endif /* GameEventTypeSaveEscapeLocationEntity_h */
