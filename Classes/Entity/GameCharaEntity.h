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
	/// 初期職業名
	string initJobName;
	/// 画像
	vector<string> images;
	/// 初期アイテム
	vector<string> initItems;
	
private:
};

#endif /* GameCharaEntity_h */
