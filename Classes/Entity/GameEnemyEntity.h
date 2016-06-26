//
//  GameEnemyEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#ifndef GameEnemyEntity_h
#define GameEnemyEntity_h

#include "BaseGameEntity.h"
#include "GameEnemyItemEntity.h"
#include "GameEnemyEncountEntity.h"

/// 敵Entity
class GameEnemyEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 画像
	int32_t imageId;
	/// ステータス
	vector<int32_t> statuses;
	/// 獲得アイテム
	GameEnemyItemEntity item;
	/// 攻撃パターン
	vector<int32_t> attackPattern;
	/// 出現座標
	vector<GameEnemyEncountEntity> encounts;
	/// 出現属性
	int32_t encountAttribute;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameEnemyEntity convertData(const unsigned char *data);
	
private:
};

#endif /* GameEnemyEntity_h */
