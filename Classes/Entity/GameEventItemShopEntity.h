//
//  GameEventItemShopEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventItemShopEntity_h
#define GameEventItemShopEntity_h

#include "GameEventBaseEntity.h"

/// イベント 道具屋Entity
class GameEventItemShopEntity final: public GameEventBaseEntity {
public:
	
	// 売りアイテムID
	vector<int32_t> itemIds;
	
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

#endif /* GameEventItemShopEntity_h */
