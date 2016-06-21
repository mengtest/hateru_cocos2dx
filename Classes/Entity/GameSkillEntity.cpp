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
	entity.costMP = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 効果量
	entity.effectValue = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 成功率
	dataIndex += 1;
	// 影響ステータス
	dataIndex += 1;
	// 攻撃属性
	dataIndex += 1;
	// 状態変化
	for (auto i = 0;i <= 6;i++) {
		dataIndex += 1;
	}
	// 変数
	entity.changeVariable.convertData(&data[dataIndex]);
	dataIndex += 4;
	// 効果色(RGB)
	
	dataIndex += 3;
	// 効果初期幅
	dataIndex += 1;
	
	// 効果幅変化
	dataIndex += 1;
	// 効果動作
	dataIndex += 1;
	// コメント
	entity.comment = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 40));
	dataIndex += 40;
	
	return entity;
}