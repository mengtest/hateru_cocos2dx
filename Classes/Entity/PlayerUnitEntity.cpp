//
//  PlayerUnitEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerUnitEntity.h"

#include "LogConst.h"
#include "GameConst.h"
#include "GameMainService.h"

#pragma mark - アイテム

/**
 *  持ちアイテムがフルか？
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::isFullItem() {
	return items.size() >= MAX_UNIT_ITEM;
}

/**
 *  アイテム追加
 *
 *  @param id       追加アイテムID
 *  @param useCount 使用回数
 *  @param itemId   アイテムID
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::addItem(const int id, const int useCount, const string itemId) {
	
	// フルチェック
	if (isFullItem()) {
		return true;
	}
	
	auto itemEntity = PlayerItemEntity::create(id, useCount, itemId);
	items.push_back(itemEntity);
	
	return false;
}

/**
 *  アイテム削除
 *
 *  @param id 削除アイテムID
 *
 *  @return true: あった、false: なかった
 */
bool PlayerUnitEntity::removeItem(const int id) {
	
	// 検索
	auto it = find_if(begin(items), end(items),
						 [id] (PlayerItemEntity itemEntity) {
							 return itemEntity.id == id;
						 });
	if (it == end(items)) {
		return false;
	}
	
	// 装備位置を調整
	updateEquipmentsIndex((int)(it - items.begin()));
	
	// 削除
	items.erase(it);
	
	return true;
}

/**
 *  アイテムをソート
 */
void PlayerUnitEntity::sortItem() {

	// 退避
	auto itemsBackup = items;
	
	items.clear();
	
	// 地図
	for (auto it = itemsBackup.begin();it != itemsBackup.end();it++) {
		auto itemEntity = GameMainService::sharedInstance()->getItem(it->id);
		if (itemEntity->type == ItemTypeMap){
			// アイテム追加
			items.push_back(*it);
			// 初期化
			it->id = 0;
		}
	}
	
	// 装備品
	for (int i = EquipmentTypeWeapon;i <= EquipmentTypeAccessory;i++) {
		auto index = equipments[i];
		if (index < 0) {
			continue;
		}
		items.push_back(itemsBackup[index]);
		// 位置を再設定
		equipments[i] = (int)items.size() - 1;
		// 初期化
		itemsBackup[index].id = 0;
	}
	
	// 武器、鎧、盾、兜、装飾品、回復、種の順
	for (int type = ItemTypeWeapon;type <= ItemTypeSeed;type++) {
		for (auto it = itemsBackup.begin();it != itemsBackup.end();it++) {
			if (it->id == 0) {
				continue;
			}
			auto itemEntity = GameMainService::sharedInstance()->getItem(it->id);
			if (itemEntity->type == type) {
				// アイテム追加
				items.push_back(*it);
				// 初期化
				it->id = 0;
			}
		}
	}
	
}

/**
 *  装備位置を調整する
 *
 *  @param removeIndex 削除位置
 */
void PlayerUnitEntity::updateEquipmentsIndex(const int removeIndex) {

	auto isRemoveEquipment = false;
	
	for (int i = EquipmentTypeWeapon;i <= EquipmentTypeAccessory;i++) {
		if (equipments[i] < 0) {
			continue;
		}
		if (equipments[i] == removeIndex) {
			// 装備を捨てた
			equipments[i] = -1;
			// フラグON
			isRemoveEquipment = true;
		} else if (equipments[i] > removeIndex) {
			// 装備品より後のものを削除した
			equipments[i]--;
		}
	}
	
	// TODO:ステータスを再調整
	if (isRemoveEquipment) {
		
	}
}

#pragma mark - スキル

/**
 *  持ちスキルがフルか？
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::isFullSkill() {
	return skills.size() >= MAX_UNIT_SKILL;
}

/**
 *  スキル追加
 *
 *  @param id       追加スキルID
 *
 *  @return true: フル、false: まだまだ
 */
bool PlayerUnitEntity::addSkill(const int id) {
	
	// フルチェック
	if (isFullSkill()) {
		return true;
	}
	
	skills.push_back(id);
	
	return false;
}

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
PlayerUnitEntity::PlayerUnitEntity() {
	id = "";
	name = "";
	unitId = 0;
	config = 0;
	statuses.clear();
	for (int i = UnitStatusTypeLv;i <= UnitStatusTypeDirection;i++) {
		statuses.push_back(0);
	}
	equipments.clear();
	for (int i = EquipmentTypeWeapon;i <= EquipmentTypeAccessory;i++) {
		equipments.push_back(-1);
	}
	skills.clear();
	items.clear();
}

/**
 *  デストラクタ
 */
PlayerUnitEntity::~PlayerUnitEntity() {
}

#pragma mark - JSON

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerUnitEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value(id)));
	object.insert(make_pair("name", picojson::value(name)));
	object.insert(make_pair("unitId", picojson::value((double)unitId)));
	object.insert(make_pair("config", picojson::value((double)config)));
	picojson::array statuseList;
	for (auto it = statuses.begin(); it != statuses.end(); it++) {
		statuseList.push_back(picojson::value((double)*it));
	}
	object.insert(make_pair("statuses", picojson::value(statuseList)));
	picojson::array equipmentList;
	for (auto it = equipments.begin(); it != equipments.end(); it++) {
		statuseList.push_back(picojson::value((double)*it));
	}
	object.insert(make_pair("equipments", picojson::value(equipmentList)));
	picojson::array skillList;
	for (auto it = skills.begin(); it != skills.end(); it++) {
		skillList.push_back(picojson::value((double)*it));
	}
	object.insert(make_pair("skills", picojson::value(skillList)));
	picojson::array itemList;
	for (auto it = items.begin(); it != items.end(); it++) {
		picojson::object object;
		it->serialize(object);
		itemList.push_back(picojson::value(object));
	}
	object.insert(make_pair("items", picojson::value(itemList)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerUnitEntity::mapping(picojson::object &object) {
	if (object["id"].is<string>()) {
		id = object["id"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "id");
		return false;
	}
	if (object["name"].is<string>()) {
		name = object["name"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "name");
		return false;
	}
	if (object["unitId"].is<double>()) {
		unitId = (int)object["unitId"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "unitId");
		return false;
	}
	if (object["config"].is<double>()) {
		config = (int)object["config"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "money");
		return false;
	}
	if (object["statuses"].is<picojson::array>()) {
		statuses.clear();
		auto statusList = object["statuses"].get<picojson::array>();
		for (picojson::array::iterator it = statusList.begin(); it != statusList.end(); it++) {
			if (it->is<double>()) {
				auto status = (int)it->get<double>();
				statuses.push_back(status);
			} else {
				log(JSON_BAD_MAPPING_ERROR, "statuses");
				return false;
			}
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "statuses");
		return false;
	}
	if (object["equipments"].is<picojson::array>()) {
		equipments.clear();
		auto equipmentList = object["equipments"].get<picojson::array>();
		for (picojson::array::iterator it = equipmentList.begin(); it != equipmentList.end(); it++) {
			if (it->is<double>()) {
				auto equipment = (int)it->get<double>();
				equipments.push_back(equipment);
			} else {
				log(JSON_BAD_MAPPING_ERROR, "equipments");
				return false;
			}
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "equipments");
		return false;
	}
	if (object["skills"].is<picojson::array>()) {
		skills.clear();
		auto skillList = object["skills"].get<picojson::array>();
		for (picojson::array::iterator it = skillList.begin(); it != skillList.end(); it++) {
			if (it->is<double>()) {
				auto skill = (int)it->get<double>();
				skills.push_back(skill);
			} else {
				log(JSON_BAD_MAPPING_ERROR, "skills");
				return false;
			}
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "skills");
		return false;
	}
	if (object["items"].is<picojson::array>()) {
		items.clear();
		auto itemList = object["items"].get<picojson::array>();
		for (picojson::array::iterator it = itemList.begin(); it != itemList.end(); it++) {
			picojson::object &item = it->get<picojson::object>();
			PlayerItemEntity itemEntity;
			auto isSuccess = itemEntity.mapping(item);
			if (!isSuccess) {
				return false;
			}
			items.push_back(itemEntity);
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "items");
		return false;
	}
	return true;
}