//
//  PlayerEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerEntity_h
#define PlayerEntity_h

#include "cocos2d.h"

#include "picojson.h"

#include "PlayerUnitEntity.h"
#include "PlayerTeleportEntity.h"
#include "PlayerMapEntity.h"
#include "PlayerProfileEntity.h"

USING_NS_CC;
using namespace std;

/// プレイヤーEntity
class PlayerEntity: public Ref {
public:
	
	/// 有効フラグ
	bool isValid;
	
	/// ユーザID
	string id;
	/// ユーザ名
	string name;
	
	/// セーブトークン
	string saveToken;
	
	/// プロフィールEntity
	PlayerProfileEntity profile;
	
	/// 所持金
	int money;
	
	/// ユニット
	vector<PlayerUnitEntity>units;
	
	/// 現在位置
	PlayerMapEntity location;
	
	/// テレポート情報
	vector<PlayerTeleportEntity> teleports;
	
	/// エスケープ
	PlayerMapEntity escapeLocation;
	
	/// 預かり所
	vector<PlayerItemEntity> cloakrooms;
	
	/**
	 *  ユニット追加
	 *
	 *  @param unitId ユニットID
	 */
	void addUnit(int unitId);
	
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
	 *  アイテム削除
	 *
	 *  @param id 削除アイテムID
	 *
	 *  @return true: あった、false: なかった
	 */
	bool removeItem(int id);
	
	/**
	 *  預かり所追加
	 *
	 *  @param id       追加アイテムID
	 *  @param useCount 使用回数
	 *  @param itemId   アイテムID
	 */
	void addCloakrooms(int id, int useCount, string itemId);
	
	/**
	 *  預かり所削除
	 *
	 *  @param id 削除アイテムID
	 *
	 *  @return true: あった、false: なかった
	 */
	bool removeCloakrooms(int id);
	
	/**
	 *  預かり所をソート
	 */
	void sortCloakrooms();
	
	/**
	 *  コンストラクタ
	 */
	PlayerEntity();
	
	/**
	 *  デストラクタ
	 */
	~PlayerEntity();
	
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

#endif /* PlayerEntity_h */
