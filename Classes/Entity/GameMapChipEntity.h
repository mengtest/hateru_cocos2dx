//
//  GameMapChipEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapChipEntity_h
#define GameMapChipEntity_h

#include "BaseGameEntity.h"

/// マップチップEntity
class GameMapChipEntity final: public BaseGameEntity {
public:
	
	/// 背景 チップインデックス
	int32_t backgroundIndex;
	/// 上チップインデックス
	int32_t upIndex;
	/// 下チップインデックス
	int32_t downIndex;
	/// イベント名
	string eventName;
	/// 透過
	bool isUpChipClear;
	/// 重力があるキャラの上からの通行を禁止
	bool isGravityNoPassUp;
	/// 重力があるキャラの下からの通行を禁止
	bool isGravityNoPassDown;
	/// 重力があるキャラの左からの通行を禁止
	bool isGravityNoPassLeft;
	/// 重力があるキャラの右からの通行を禁止
	bool isGravityNoPassRight;
	/// 重力がないキャラの上からの通行を禁止
	bool isAntiGravityNoPassUp;
	/// 重力がないキャラの下からの通行を禁止
	bool isAntiGravityNoPassDown;
	/// 重力がないキャラの左からの通行を禁止
	bool isAntiGravityNoPassLeft;
	/// 重力がないキャラの右からの通行を禁止
	bool isAntiGravityNoPassRight;
	
	
private:
};

#endif /* GameMapChipEntity_h */
