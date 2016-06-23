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
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameSkillEntity GameSkillEntity::convertData(const unsigned char *data) {

	auto dataIndex = 0;
	auto entity = GameSkillEntity();

	// 名前
	entity.name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 種別
	entity.skillType = (SKILL_TYPE)data[dataIndex];
	dataIndex += 1;
	// 消費MP
	entity.costMP = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 効果範囲
	entity.effectRange = (EFFECT_RANGE_TYPE)data[dataIndex];
	dataIndex += 1;
	// 効果量
	entity.effectValue = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 成功率
	entity.successRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 影響ステータス
	entity.changeStatus = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 攻撃属性
	entity.attackAttributeType = (ATTACK_ATTRIBUTE_TYPE)data[dataIndex];
	dataIndex += 1;
	// 状態変化
	for (int i = CONDITION_TYPE_NONE;i <= CONDITION_TYPE_PARRAY;i++) {
		entity.changeCondition.push_back((data[dataIndex] & (1 << (i - 1))) != 0);
	}
	dataIndex += 1;
	// 変数
	entity.changeVariable.convertData(&data[dataIndex]);
	dataIndex += 4;
	// 効果色(RGB)
	entity.showEffectColor = (int32_t)data[dataIndex] + (int32_t)data[dataIndex + 1] * 0x100 + (int32_t)data[dataIndex + 2] * 0x10000;
	dataIndex += 3;
	// 効果初期幅
	entity.showEffectInitValue = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 効果幅変化
	entity.showEffectChangeValue = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 効果動作
	entity.showEffectOperations = (int32_t)data[dataIndex];
	dataIndex += 1;
	// コメント
	entity.comment = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 40));
	dataIndex += 40;
	
	return entity;
}