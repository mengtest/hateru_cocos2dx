//
//  GameMapEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapEntity_h
#define GameMapEntity_h

#include "BaseGameEntity.h"
#include "GameMapChipEntity.h"
#include "GameMapEventEntity.h"

/// マップEntity
class GameMapEntity final: public BaseGameEntity {
public:
	
	/// ID
	int32_t id;
	/// マップ名
	string name;
	/// 幅
	int32_t width;
	/// 高さ
	int32_t height;
	/// マップ端制御
	MAP_END_TYPE mapEndType;
	/// 背景色
	int32_t backgroundColor;
	/// 背景画像
	int32_t backgroundImageId;
	/// サウンド
	string soundName;
	/// テレポート可不可
	bool isUseTeleport;
	/// エスケープ可不可
	bool isUseEscape;
	/// 背景マップチップグループ名
	int32_t backgroundMapChpGpId;
	/// 上マップチップグループ名
	int32_t upMapChpGpId;
	/// 下マップチップグループ名
	int32_t downMapChpGpId;
	/// マップチップ情報
	vector<GameMapChipEntity> mapChips;
	/// イベント情報
	map<string, GameMapEventEntity> events;

private:
};

#endif /* GameMapEntity_h */