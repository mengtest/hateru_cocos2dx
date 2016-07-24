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
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameJobEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;
	
	// 名前
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 必殺率
	criticalRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 命中率
	hitRate = (int32_t)data[dataIndex];
	dataIndex += 1;
	// ステータス
	for (int i = AddStatusTypeMaxHP; i <= AddStatusTypeEXP; i++) {
		for (auto lv = 0; lv < MAX_LEVEL; lv++) {
			if (i == AddStatusTypeEXP) {
				statuses[i][lv] = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
				dataIndex += 2;
			} else {
				if (lv == 0) {
					statuses[i][lv] = (int32_t)data[dataIndex];
				} else {
					statuses[i][lv] = statuses[i][lv - 1] + (int32_t)data[dataIndex];
				}
				dataIndex += 1;
			}
		}
	}
	// 会得技能
	auto count = (int)data[dataIndex];
	dataIndex += 1;
	skills.clear();
	for (auto i = 0; i < count; i++) {
		skills.push_back(GameJobSkillEntity::createEntity(&data[dataIndex]));
		dataIndex += 2;
	}
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameJobEntity GameJobEntity::createEntity(const unsigned char *data) {
	auto entity = GameJobEntity();
	entity.convertData(data);
	return entity;
}

