//
//  GameMapAutoEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/06.
//
//

#ifndef GameMapAutoEntity_h
#define GameMapAutoEntity_h

#include "BaseGameEntity.h"

/// 自動マップEntity
class GameMapAutoEntity final: public BaseGameEntity {
public:
	
	/// 階層
	int32_t stratum;
	/// 下チップID
	vector<int32_t> downChipIds;
	/// 上チップID
	vector<int32_t> upChipIds;
	/// 敵情報
	map<int32_t, int32_t> enemyIds;
	/// 宝情報
	map<int32_t, int32_t> itemIds;
	
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
	static GameMapAutoEntity createEntity(const unsigned char *data);
	
private:
};


#endif /* GameMapAutoEntity_h */
