//
//  GameItemEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameItemEntity.h"

#include "GameConst.h"
#include "ProjectIniManager.h"
#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameItemEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	auto projectIniEntity = ProjectIniManager::load();
	
	// 名前
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 種別
	type = (ItemType)data[dataIndex];
	dataIndex += 1;
	// 買値
	purchasePrice = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 売値
	sellingPrice = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 調合値
	preparationPrice = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 使用回数
	useCount = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 特殊技能
	useSkillId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 状態治療
	conditionTreatment = (ConditionType)data[dataIndex];
	dataIndex += 1;
	// ステータス
	changeStatus.clear();
	for (auto i = 0;i < 5;i++) {
		changeStatus.push_back(GameItemStatusEntity::createEntity(&data[dataIndex]));
		dataIndex += 3;
	}
	// 変数変化
	changeVariable.convertData(&data[dataIndex]);
	dataIndex += 4;
	// 画像
	imageId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 調合
	mixings.clear();
	for (auto i = 0;i < 5;i++) {
		mixings.push_back(GameItemMixEntity::createEntity(&data[dataIndex]));
		dataIndex += 2;
	}
	// ？
	dataIndex += 1;
	// 装備可能職業指定
	equipmentJobs.clear();
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeJob];i++) {
		equipmentJobs.push_back(data[dataIndex] == 1);
		dataIndex += 1;
	}
	// 変更職業
	changeJobId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 出品可否
	isExhibit = data[dataIndex] == 1;
	dataIndex += 1;
	// コメント
	comment = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 40));
	dataIndex += 40;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameItemEntity GameItemEntity::createEntity(const unsigned char *data) {
	auto entity = GameItemEntity();
	entity.convertData(data);
	return entity;
}