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
	
	/// ID
	int32_t id;
	/// 名前
	string name;
	/// 初期職業ID
	int32_t initJobId;
	/// 画像
	vector<int32_t> images;
	/// 初期アイテム
	vector<int32_t> initItems;
	
private:
};

#endif /* GameCharaEntity_h */
