//
//  PlayerItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerItemEntity.h"

#include "LogConst.h"
#include "UUIDUtil.h"
#include "GameDataService.h"
#include "PlayerUnitEntity.h"

/**
 *  アイテムEntity作成
 *
 *  @param id       ID
 *  @param useCount 使用回数
 *  @param itemId   アイテムID
 *
 *  @return PlayerItemEntity
 */
PlayerItemEntity PlayerItemEntity::createEntity(const int id, const int useCount, const string itemId) {
	
	PlayerItemEntity itemEntity;
	itemEntity.id = id;
	itemEntity.useCount = useCount;
	if (itemId.empty()) {
		itemEntity.itemId = UUIDUtil::create();
	} else {
		itemEntity.itemId = itemId;
	}

	return itemEntity;
}

/**
 *  装備可能か
 *
 *  @param unitEntity ユニットEntity
 *
 *  @return true: 装備可能、false: 装備不可
 */
bool PlayerItemEntity::isCanEquipped(const PlayerUnitEntity &unitEntity) {
	// アイテム情報取得
	auto itemEntity = GameDataService::sharedInstance()->items[id];
	// 装備可能　＆　職業別に装備可能
	return itemEntity.isCanEquipped && itemEntity.equipmentJobs[unitEntity.statuses[UnitStatusTypeJob] - 1];
}

/**
 *  コンストラクタ
 */
PlayerItemEntity::PlayerItemEntity() {
	id = 0;
	useCount = 0;
	itemId = "";
}

/**
 *  デストラクタ
 */
PlayerItemEntity::~PlayerItemEntity() {
}

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerItemEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value((double)id)));
	object.insert(make_pair("useCount", picojson::value((double)useCount)));
	object.insert(make_pair("itemId", picojson::value(itemId)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerItemEntity::mapping(picojson::object &object) {
	if (object["id"].is<double>()) {
		id = (int)object["id"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "id");
		return false;
	}
	if (object["useCount"].is<double>()) {
		useCount = (int)object["useCount"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "useCount");
		return false;
	}
	if (object["itemId"].is<string>()) {
		itemId = object["itemId"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "itemId");
		return false;
	}
	return true;
}
