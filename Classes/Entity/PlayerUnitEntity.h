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

#include "picojson.h"

#include "GameConst.h"
#include "PlayerItemEntity.h"

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
	int unitId;
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

	/**
	 *  コンストラクタ
	 */
	PlayerUnitEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerUnitEntity();

	/**
	 *  シリアライズ
	 *
	 *  @param object JSONオブジェクト
	 */
	void serialize(picojson::object &object);
	
	/**
	 *  マッピング
	 *
	 *  @param object JSONオブジェクト
	 *
	 *  @return マッピング可否
	 */
	bool mapping(picojson::object &object);
	
private:
	
};

#endif /* PlayerUnitEntity_h */
