//
//  PlayerEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#include "PlayerEntity.h"

#include "LogConst.h"

/**
 *  コンストラクタ
 */
PlayerEntity::PlayerEntity() {
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

/**
 *  シリアライズ
 *
 *  @param object JSONオブジェクト
 */
void PlayerEntity::serialize(picojson::object &object) {
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
		location.mapping(loc);
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
		escapeLocation.mapping(loc);
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