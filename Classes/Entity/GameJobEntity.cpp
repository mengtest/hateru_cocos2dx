//
//  GameJobEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameJobEntity.h"

#include "GameConst.h"
#include "SJISUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameJobEntity GameJobEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	auto entity = GameJobEntity();
	
	// 名前
	entity.name = SJISUtil::convertUTF8(&data[dataIndex], 16);
	dataIndex += 16;
	// 必殺率
	entity.criticalRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 命中率
	entity.hitRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// ステータス
	for (auto i = 0; i <= ADDSTATUS_TYPE_EXP; i++) {
		for (auto j = 0; j <= MAX_LEVEL; j++) {
			if (i == ADDSTATUS_TYPE_EXP) {
				entity.statuses[i][j] = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
				dataIndex += 2;
			} else {
				if (j == 0) {
					entity.statuses[i][j] = (int32_t)data[dataIndex];
				} else {
					entity.statuses[i][j] = entity.statuses[i][j - 1] + (int32_t)data[dataIndex];
				}
				dataIndex += 1;
			}
		}
	}
	// 会得技能
	auto count = (int)data[dataIndex];
	dataIndex += 1;
	for (auto i = 0; i < count; i++) {
		auto skillEntity = GameJobSkillEntity();
		// 会得レベル
		skillEntity.level = (int32_t)data[dataIndex];
		dataIndex += 1;
		// 会得スキル
		skillEntity.skillId = (int32_t)data[dataIndex];
		dataIndex += 1;
		entity.skills.push_back(skillEntity);
	}
	
	return entity;
}

