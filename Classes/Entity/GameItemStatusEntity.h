//
//  GameItemStatusEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemStatusEntity_h
#define GameItemStatusEntity_h

#include "BaseGameEntity.h"

/// アイテムステータスEntity
class GameItemStatusEntity final: public BaseGameEntity {
public:
	
	/// ステータス種別
	ITEM_STATUS_TYPE status;
	/// 変化値
	int32_t value;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data      バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameItemStatusEntity convertData(const unsigned char *data);
	
private:
};

#endif /* GameItemStatusEntity_h */