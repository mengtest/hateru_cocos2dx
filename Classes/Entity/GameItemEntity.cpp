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
 *
 *  @return Entity
 */
GameItemEntity GameItemEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;
	auto entity = GameItemEntity();
	auto projectIniEntity = ProjectIniManager::load();

	// 名前
	entity.name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 種別
	entity.type = (ITEM_TYPE)data[dataIndex];
	dataIndex += 1;
	// 買値
	entity.purchasePrice = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 売値
	entity.sellingPrice = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 調合値
	entity.preparationPrice = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 使用回数
	entity.useCount = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 特殊技能
	entity.useSkillId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 状態治療
	entity.conditionTreatment = (CONDITION_TYPE)data[dataIndex];
	dataIndex += 1;
	// ステータス
	for (auto i = 0;i < 5;i++) {
		entity.changeStatus.push_back(GameItemStatusEntity::convertData(&data[dataIndex]));
		dataIndex += 3;
	}
	// 変数変化
	entity.changeVariable.convertData(&data[dataIndex]);
	dataIndex += 4;
	// 画像
	entity.imageId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 調合
	for (auto i = 0;i < 5;i++) {
		entity.mixings.push_back(GameItemMixEntity::convertData(&data[dataIndex]));
		dataIndex += 2;
	}
	// ？
	dataIndex += 1;
	// 装備可能職業指定
	for (auto i = 0;i < projectIniEntity.counts[ProjectIniEntity::typeJob];i++) {
		entity.equipmentJobs.push_back(data[dataIndex] == 1);
		dataIndex += 1;
	}
	// 変更職業
	entity.changeJobId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 出品可否
	entity.isExhibit = data[dataIndex] == 1;
	dataIndex += 1;
	// コメント
	entity.comment = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 40));
	dataIndex += 40;
	
	return entity;
}