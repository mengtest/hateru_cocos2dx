//
//  GameCharaEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameCharaEntity_h
#define GameCharaEntity_h

#include "BaseGameEntity.h"

/// キャラEntity
class GameCharaEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 初期職業ID
	int32_t initJobId;
	/// 画像
	vector<int32_t> imageIds;
	/// 初期アイテム
	vector<int32_t> initItemIds;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameCharaEntity convertData(const unsigned char *data);
	
private:
};

#endif /* GameCharaEntity_h */
