//
//  GameEnemyEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/27.
//
//

#include "GameEnemyEntity.h"

#include "GameConst.h"
#include "SJISUtil.h"
#include "StringUtil.h"
#include "PlayerEntity.h"

/**
 *  遭遇チェック
 *
 *  @param playerEntity プレイヤーEntity
 *
 *  @return true: 遭遇、false: 遭遇なし
 */
bool GameEnemyEntity::isEncount(const PlayerEntity &playerEntity) {

	// 属性チェック
	if (!isEncountType[playerEntity.moveType]) {
		return false;
	}
	
	// 範囲チェック
	for (auto it = encounts.begin();it != encounts.end();it++) {
		if (it->isInRange(playerEntity.location)) {
			return true;
		}
	}
	return false;
}


/**
 *  バトルステータス取得
 *
 *  @return バトルステータス
 */
vector<int> GameEnemyEntity::battleStatues() {
	
	vector<int> battleStatuses;
	
	for (int i = 0;i < BattleStatusTypeMax;i++) {
		if (i <= BattleStatusTypeMaxSpeed) {
			battleStatuses.push_back(statuses[i]);
		} else if (i <= BattleStatusTypeMP) {
			battleStatuses.push_back(statuses[EnemyStatusTypeMaxHP + (i - BattleStatusTypeHP)]);
		} else if (i < BattleStatusTypeCondition) {
			battleStatuses.push_back(statuses[EnemyStatusTypeAttack + (i - BattleStatusTypeAttack)]);
		} else {
			battleStatuses.push_back(0);
		}
	}
	return battleStatuses;
}

/**
 *  コンストラクタ
 */
GameEnemyEntity::GameEnemyEntity() {
	name = "";
	imageId = 0;
	statuses.clear();
	attackPattern.clear();
	encounts.clear();
	isEncountType.clear();
	for (int i = MoveTypeWalk;i <= MoveTypeFlyShip;i++) {
		isEncountType.push_back(false);
	}
}

/**
 *  デストラクタ
 */
GameEnemyEntity::~GameEnemyEntity() {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
void GameEnemyEntity::convertData(const unsigned char *data) {
	
	auto dataIndex = 0;

	// 名前
	name = StringUtil::trim(SJISUtil::convertUTF8(&data[dataIndex], 16));
	dataIndex += 16;
	// 画像
	imageId = (int)data[dataIndex];
	dataIndex += 1;
	// ステータス
	statuses.clear();
	for (auto i = 0;i < 14;i++) {
		statuses.push_back((int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1]);
		dataIndex += 2;
	}
	// 獲得アイテム
	item.convertData(&data[dataIndex]);
	dataIndex += 3;
	// 攻撃パターン
	attackPattern.clear();
	for (auto i = 0;i < 7;i++) {
		attackPattern.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	// 出現座標数
	encounts.clear();
	auto count = (int)data[dataIndex];
	for (auto i = 0;i < count;i++) {
		encounts.push_back(GameEnemyEncountEntity::createEntity(&data[dataIndex]));
		dataIndex += 5;
	}
	// 出現場所
	for (int i = MoveTypeWalk;i <= MoveTypeFlyShip;i++) {
		isEncountType[i] = (data[dataIndex] & (1 << i));
	}
	dataIndex += 1;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
GameEnemyEntity GameEnemyEntity::createEntity(const unsigned char *data) {
	auto entity = GameEnemyEntity();
	entity.convertData(data);
	return entity;
}