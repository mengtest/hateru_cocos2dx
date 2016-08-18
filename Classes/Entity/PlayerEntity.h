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

USING_NS_CC;
using namespace std;

/// プレイヤーEntity
class PlayerEntity: public Ref {
public:
	
	/// 有効フラグ
	bool isValid;
	
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
