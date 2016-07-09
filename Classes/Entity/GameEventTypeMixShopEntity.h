//
//  GameEventTypeMixShopEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeMixShopEntity_h
#define GameEventTypeMixShopEntity_h

#include "GameEventBaseEntity.h"

/// イベント 調合屋Entity
class GameEventTypeMixShopEntity final: public GameEventBaseEntity<GameEventTypeMixShopEntity> {
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

#endif /* GameEventTypeMixShopEntity_h */
