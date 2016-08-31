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
#include "UUIDUtil.h"

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
bool PlayerUnitEntity::addItem(int id, int useCount, string itemId) {
	
	// フルチェック
	if (isFullItem()) {
		return true;
	}
	
	PlayerItemEntity itemEntity;
	itemEntity.id = id;
	itemEntity.useCount = useCount;
	if (itemId.empty()) {
		itemEntity.itemId = UUIDUtil::create();
	} else {
		itemEntity.itemId = itemId;
	}
	items.push_back(itemEntity);
	
	return false;
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
bool PlayerUnitEntity::addSkill(int id) {
	
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