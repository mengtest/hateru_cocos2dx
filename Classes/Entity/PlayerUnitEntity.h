//
//  PlayerUnitEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerUnitEntity_h
#define PlayerUnitEntity_h

#include "cocos2d.h"

#include "GameConst.h"
#include "PlayerItemEntity.h"
#include "PlayerTeleportEntity.h"

USING_NS_CC;
using namespace std;

/// プレイヤーユニットEntity
class PlayerUnitEntity final: public Ref {
public:
	
	/// ユニットID
	string id;
	/// 名前
	string name;
	/// 種類
	int unitType;
	/// 状態
	int config;
	/// ステータス
	vector<int> statuses;
	/// 装備
	vector<int> equipments;
	/// スキル
	vector<int> skills;
	/// アイテム
	vector<PlayerItemEntity> items;

	/// テレポート情報
	vector<PlayerTeleportEntity> teleports;

	/// エスケープマップ情報
	int escapeMapId;
	/// エスケープX情報
	int escapeMapX;
	/// エスケープY情報
	int escapeMapY;
	
	/// 預かり所
	vector<PlayerItemEntity> cloakrooms;
	
	
private:
	
};

#endif /* PlayerUnitEntity_h */
