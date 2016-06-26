//
//  GameEnemyItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#ifndef GameEnemyItemEntity_h
#define GameEnemyItemEntity_h

#include "BaseGameEntity.h"

/// 敵 獲得アイテムEntity
class GameEnemyItemEntity final: public BaseGameEntity {
public:
	
	/// 獲得フラグ
	bool isWon;
	/// 獲得率
	int32_t rate;
	/// 獲得アイテム
	int32_t itemId;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
private:
};

#endif /* GameEnemyItemEntity_h */
