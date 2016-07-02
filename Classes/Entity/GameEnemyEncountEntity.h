//
//  GameEnemyEncountEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#ifndef GameEnemyEncountEntity_h
#define GameEnemyEncountEntity_h

#include "BaseGameEntity.h"

/// 敵 遭遇Entity
class GameEnemyEncountEntity final: public BaseGameEntity {
public:
	
	/// マップ
	int32_t mapId;
	/// X
	int32_t x;
	/// Y
	int32_t y;
	/// 幅
	int32_t width;
	/// 高さ
	int32_t height;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameEnemyEncountEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameEnemyEncountEntity_h */
