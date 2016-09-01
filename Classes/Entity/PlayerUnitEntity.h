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
	bool addItem(const int id, const int useCount, const string itemId);
	
	/**
	 *  アイテム削除
	 *
	 *  @param id 削除アイテムID
	 *
	 *  @return true: あった、false: なかった
	 */
	bool removeItem(const int id);
	
	/**
	 *  アイテムをソート
	 */
	void sortItem();
	
	/**
	 *  装備位置を調整する
	 *
	 *  @param removeIndex 削除位置
	 */
	void updateEquipmentsIndex(const int removeIndex);
	
	/**
	 *  装備後ステータスの更新
	 */
	void updateEquippedStatus();
	
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
	bool addSkill(const int id);
	
	/**
	 *  スキルをソート
	 */
	void sortSkill();
	
	/**
	 *  テレポートスキルを所持しているか？
	 *
	 *  @return true: 所持している、false: していない
	 */
	bool hasSkillTeleport();

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
