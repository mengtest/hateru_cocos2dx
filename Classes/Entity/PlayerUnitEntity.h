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
	 *  持ちアイテムがフルか？
	 *
	 *  @return true: フル、false: まだまだ
	 */
	bool isFullItem();
	
	/**
	 *  アイテム追加
	 *
	 *  @param id       追加アイテムID
	 *  @param useCount 使用回数
	 *  @param itemId   アイテムID
	 *
	 *  @return true: フル、false: まだまだ
	 */
	bool addItem(int id, int useCount, string itemId);
	
	/**
	 *  持ちスキルがフルか？
	 *
	 *  @return true: フル、false: まだまだ
	 */
	bool isFullSkill();

	/**
	 *  スキル追加
	 *
	 *  @param id       追加スキルID
	 *
	 *  @return true: フル、false: まだまだ
	 */
	bool addSkill(int id);

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
