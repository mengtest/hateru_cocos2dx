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
	int mapId;
	/// X
	int x;
	/// Y
	int y;
	/// 幅
	int width;
	/// 高さ
	int height;
	
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
