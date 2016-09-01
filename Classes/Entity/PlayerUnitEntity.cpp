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
	
	auto itemEntity = PlayerItemEntity::createEntity(id, useCount, itemId);
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
		updateEquippedStatus();
	}
}

/**
 *  装備後ステータスの更新
 */
void PlayerUnitEntity::updateEquippedStatus() {

	// HPから機敏さまで
	for (int i = 0;i < 6;i++) {
		statuses[UnitStatusTypeHPEq + i] = statuses[UnitStatusTypeMaxHP + 1];
	}
	// 名声から道徳心
	for (int i = 0;i < 2;i++) {
		statuses[UnitStatusTypeFameEq + i] = statuses[UnitStatusTypeFame + 1];
	}
	// 炎属性から毒属性を初期化
	for (int i = 0;i < 4;i++) {
		statuses[UnitStatusTypeFireEq + i] = 0;
	}
	// 命中率、必殺率
	auto jobEntity = GameMainService::sharedInstance()->getJob(statuses[UnitStatusTypeJob]);
	statuses[UnitStatusTypeHitRate] = jobEntity->hitRate;
	statuses[UnitStatusTypeCriticalRate] = jobEntity->criticalRate;

	// ステータス振り分け
	for (int i = EquipmentTypeWeapon;i <= EquipmentTypeAccessory;i++) {
		if (equipments[i] < 0) {
			continue;
		}
		// アイテム情報取得
		auto itemEntity = GameMainService::sharedInstance()->getItem(items[equipments[i]].id);
		for (auto it = itemEntity->changeStatus.begin();it != itemEntity->changeStatus.end();it++) {
			if (it->status == ItemStatusTypeNothing) {
				continue;
			}
			if (it->status >= ItemStatusTypeHP && it->status <= ItemStatusTypePoison) {
				// HPから毒属性
				statuses[UnitStatusTypeHPEq + (it->status - ItemStatusTypeHP)] += it->value;
			} else if (it->status >= ItemStatusTypeFame && it->status <= ItemStatusTypeCriticalRate) {
				// 名声から必殺率
				statuses[UnitStatusTypeFameEq + (it->status - ItemStatusTypeFame)] += it->value;
			}
			
		}
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

/**
 *  スキルをソート
 */
void PlayerUnitEntity::sortSkill() {
	
	auto skillsBackup = skills;
	
	auto maxId = GameMainService::sharedInstance()->getSkillCount();
	
	skills.clear();
	for (auto it = skillsBackup.begin();it != skillsBackup.end();it++) {
		for (int id = 1;id <= maxId;id++) {
			if (*it == id) {
				skills.push_back(*it);
			}
		}
	}
}

/**
 *  テレポートスキルを所持しているか？
 *
 *  @return true: 所持している、false: していない
 */
bool PlayerUnitEntity::hasSkillTeleport() {
	// 検索
	auto it = find_if(begin(skills), end(skills),
						 [] (int skillId) {
							 auto skillEntity = GameMainService::sharedInstance()->getSkill(skillId);
							 return skillEntity->skillType == SkillTypeTeleport;
						 });
	if (it == end(skills)) {
		return false;
	}
	return true;
}

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
PlayerUnitEntity::PlayerUnitEntity() {
	id = "";
	name = "";
	unitId = 0;
	condition = 0;
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
	object.insert(make_pair("condition", picojson::value((double)condition)));
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
	if (object["condition"].is<double>()) {
		condition = (int)object["condition"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "condition");
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