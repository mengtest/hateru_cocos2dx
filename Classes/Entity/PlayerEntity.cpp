//
//  PlayerEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerEntity.h"

#include "LogConst.h"
#include "GameConst.h"
#include "GameMainService.h"

/**
 *  キャラ追加
 *
 *  @param unitId ユニットID
 */
void PlayerEntity::addUnit(int unitId) {
	
	// ユニット情報取得
	auto charaEntity = GameMainService::sharedInstance()->getChara(unitId);
	// 職業情報取得
	auto jobEntity = GameMainService::sharedInstance()->getJob(charaEntity->initJobId);
	
	PlayerUnitEntity unitEntity;
	
	// 職業情報からステータス設定
	unitEntity.unitId = unitId;
	unitEntity.statuses[UnitStatusTypeJob] = charaEntity->initJobId;
	for (int i = AddStatusTypeMaxHP;i <= AddStatusTypeSpeed;i++) {
		unitEntity.statuses[UnitStatusTypeMaxHP + i] = jobEntity->statuses[i][0];
	}
	unitEntity.statuses[UnitStatusTypeHP] = unitEntity.statuses[UnitStatusTypeMaxHP];
	unitEntity.statuses[UnitStatusTypeMP] = unitEntity.statuses[UnitStatusTypeMaxMP];
	// アイテム追加
	for (auto it = charaEntity->initItemIds.begin();it != charaEntity->initItemIds.end();it++) {
		auto itemEntity = GameMainService::sharedInstance()->getItem(*it);
		unitEntity.addItem(*it, itemEntity->useCount, "");
	}
	// スキル反映
	for (auto it = jobEntity->skills.begin();it != jobEntity->skills.end();it++) {
		if (it->level != 0) {
			continue;
		}
		unitEntity.addSkill(it->skillId);
	}
	units.push_back(unitEntity);
}

#pragma mark - 初期化

/**
 *  コンストラクタ
 */
PlayerEntity::PlayerEntity() {
	isValid = false;
	id = "";
	name = "";
	saveToken = "";
	money = 0;
	units.clear();
	teleports.clear();
	cloakrooms.clear();
}

/**
 *  デストラクタ
 */
PlayerEntity::~PlayerEntity() {
}

#pragma mark - JSON

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerEntity::serialize(picojson::object &object) {
	object.insert(make_pair("id", picojson::value(id)));
	object.insert(make_pair("name", picojson::value(name)));
	object.insert(make_pair("saveToken", picojson::value(saveToken)));
	picojson::object profileObj;
	profile.serialize(profileObj);
	object.insert(make_pair("profile", picojson::value(profileObj)));
	object.insert(make_pair("money", picojson::value((double)money)));
	picojson::array unitList;
	for (auto it = units.begin(); it != units.end(); it++) {
		picojson::object object;
		it->serialize(object);
		unitList.push_back(picojson::value(object));
	}
	object.insert(make_pair("units", picojson::value(unitList)));
	picojson::object loc;
	location.serialize(loc);
	object.insert(make_pair("location", picojson::value(loc)));
	picojson::array teleportList;
	for (auto it = teleports.begin(); it != teleports.end(); it++) {
		picojson::object object;
		it->serialize(object);
		teleportList.push_back(picojson::value(object));
	}
	object.insert(make_pair("teleports", picojson::value(teleportList)));
	picojson::object escapeLoc;
	escapeLocation.serialize(escapeLoc);
	object.insert(make_pair("escapeLocation", picojson::value(escapeLoc)));
	picojson::array cloakroomList;
	for (auto it = cloakrooms.begin(); it != cloakrooms.end(); it++) {
		picojson::object object;
		it->serialize(object);
		cloakroomList.push_back(picojson::value(object));
	}
	object.insert(make_pair("cloakrooms", picojson::value(cloakroomList)));
}

/**
 *  マッピング
 *
 *  @param object JSONオブジェクト
 *
 *  @return マッピング可否
 */
bool PlayerEntity::mapping(picojson::object &object) {
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
	if (object["saveToken"].is<string>()) {
		saveToken = object["saveToken"].get<string>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "saveToken");
		return false;
	}
	if (object["profile"].is<picojson::object>()) {
		auto profileObj = object["profile"].get<picojson::object>();
		auto isSuccess = profile.mapping(profileObj);
		if (!isSuccess) {
			return false;
		}
	}
	if (object["money"].is<double>()) {
		money = (int)object["money"].get<double>();
	} else {
		log(JSON_BAD_MAPPING_ERROR, "money");
		return false;
	}
	if (object["units"].is<picojson::array>()) {
		units.clear();
		auto unitList = object["units"].get<picojson::array>();
		for (picojson::array::iterator it = unitList.begin(); it != unitList.end(); it++) {
			auto unit = it->get<picojson::object>();
			PlayerUnitEntity unitEntity;
			auto isSuccess = unitEntity.mapping(unit);
			if (!isSuccess) {
				return false;
			}
			units.push_back(unitEntity);
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "units");
		return false;
	}
	if (object["location"].is<picojson::object>()) {
		auto loc = object["location"].get<picojson::object>();
		auto isSuccess = location.mapping(loc);
		if (!isSuccess) {
			return false;
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "location");
		return false;
	}
	if (object["teleports"].is<picojson::array>()) {
		teleports.clear();
		auto teleportList = object["teleports"].get<picojson::array>();
		for (picojson::array::iterator it = teleportList.begin(); it != teleportList.end(); it++) {
			picojson::object &teleport = it->get<picojson::object>();
			PlayerTeleportEntity teleportEntity;
			auto isSuccess = teleportEntity.mapping(teleport);
			if (!isSuccess) {
				return false;
			}
			teleports.push_back(teleportEntity);
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "teleports");
		return false;
	}
	if (object["escapeLocation"].is<picojson::object>()) {
		auto loc = object["escapeLocation"].get<picojson::object>();
		auto isSuccess = escapeLocation.mapping(loc);
		if (!isSuccess) {
			return false;
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "escapeLocation");
		return false;
	}
	if (object["cloakrooms"].is<picojson::array>()) {
		cloakrooms.clear();
		auto cloakroomList = object["cloakrooms"].get<picojson::array>();
		for (picojson::array::iterator it = cloakroomList.begin(); it != cloakroomList.end(); it++) {
			picojson::object &cloakroom = it->get<picojson::object>();
			PlayerItemEntity cloakroomEntity;
			auto isSuccess = cloakroomEntity.mapping(cloakroom);
			if (!isSuccess) {
				return false;
			}
			cloakrooms.push_back(cloakroomEntity);
		}
	} else {
		log(JSON_BAD_MAPPING_ERROR, "cloakrooms");
		return false;
	}
	return true;
}