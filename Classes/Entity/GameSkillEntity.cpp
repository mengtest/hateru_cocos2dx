//
//  GameSkillEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameSkillEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data      バイナリデータ
 */
void GameSkillEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 名前
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 種別
	skillType = (SKILL_TYPE)data[dataIndex];
	dataIndex += 1;
	// 消費MP
	costMP = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 効果範囲
	effectRange = (EFFECT_RANGE_TYPE)data[dataIndex];
	dataIndex += 1;
	// 効果量
	effectValue = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 成功率
	successRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 影響ステータス
	changeStatus = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 攻撃属性
	attackAttributeType = (AttackAttributeType)data[dataIndex];
	dataIndex += 1;
	// 状態変化
	for (int i = ConditionTypeNone;i <= ConditionTypeParray;i++) {
		changeCondition.push_back((data[dataIndex] & (1 << (i - 1))) != 0);
	}
	dataIndex += 1;
	// 変数
	changeVariable.convertData(&data[dataIndex]);
	dataIndex += 4;
	// 効果色(RGB)
	showEffectColor = (int32_t)data[dataIndex] + (int32_t)data[dataIndex + 1] * 0x100 + (int32_t)data[dataIndex + 2] * 0x10000;
	dataIndex += 3;
	// 効果初期幅
	showEffectInitValue = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 効果幅変化
	showEffectChangeValue = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 効果動作
	showEffectOperations = (int32_t)data[dataIndex];
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
GameSkillEntity GameSkillEntity::createEntity(const unsigned char *data) {
	auto entity = GameSkillEntity();
	entity.convertData(data);
	return entity;
}