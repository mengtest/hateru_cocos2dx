//
//  GameEventService.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/01/17.
//
//

#include "GameEventService.h"

#include "PlayerEntity.h"
#include "PlayerUnitEntity.h"
#include "GameEventEntity.h"
#include "GameEventMessageEntity.h"
#include "GameEventFluctuateHPEntity.h"
#include "GameEventFluctuateMPEntity.h"
#include "GameEventFluctuateGoldEntity.h"

#pragma mark - 初期化

/**
 *  コンストラクタ
 *
 *  @param playerEntity プレイヤーデータ
 *  @param events       イベント群
 */
GameEventService::GameEventService(PlayerEntity *playerEntity, map<int, GameEventEntity> &events) {
	// 退避
	this->playerEntity = playerEntity;
	this->events = events;
	// 初期化
	executeEventIndex = -1;
	waitingEventIndexs.clear();
}

/**
 *  デストラクタ
 */
GameEventService::~GameEventService() {
}

#pragma mark - 実行

/**
 *  イベント実行
 */
void GameEventService::executeEvents() {
	
	bool isLoopEnd = false;
	
	GameEventEntity *eventEntity = &events[executeEventIndex];
	while(true) {

		switch(eventEntity->eventTypes[executeEventDetailIndex]) {
			case EventTypeMessage: {
				// 文章表示
				GameEventMessageEntity *entity = (GameEventMessageEntity *)eventEntity->details[executeEventDetailIndex];
				showMessage(entity->message);
				isLoopEnd = true;
				break;
			}
			case EventTypeFluctuateHP: {
				// ＨＰ増減
				fluctuateHP(eventEntity->details[executeEventDetailIndex]);
				break;
			}
			case EventTypeFluctuateMP: {
				// ＭＰ増減
				fluctuateMP(eventEntity->details[executeEventDetailIndex]);
				break;
			}
			case EventTypeFluctuateGold: {
				// 所持金増減
				fluctuateGold(eventEntity->details[executeEventDetailIndex]);
				break;
			}
			case EventTypeFluctuateEXP:
				// 経験値増減
				break;
			case EventTypeFluctuateItem:
				// アイテム増減
				break;
			case EventTypeOperateVariable:
				// 変数操作
				break;
			case EventTypeChangeBGM:
				break;
			case EventTypeChangeChip:
				break;
			case EventTypeChangeUnit:
				break;
			case EventTypeMoveLocation:
				break;
			case EventTypeIfVariable:
				break;
			case EventTypeSave:
				break;
			case EventTypeItemShop:
				break;
			case EventTypeINN:
				break;
			case EventTypeCloakroom:
				break;
			case EventTypeChurch:
				break;
			case EventTypeBattle:
				break;
			case EventTypeFluctuateTeleport:
				break;
			case EventTypeChangeTeleport:
				break;
			case EventTypeChangeEscape:
				break;
			case EventTypeWipe:
				break;
			case EventTypeExchangeUnit:
				break;
			case EventTypeEndIf:
				break;
			case EventTypeShowImage:
				break;
			case EventTypeChangeJob:
				break;
			case EventTypeIfStatus:
				break;
			case EventTypeIfItem:
				break;
			case EventTypeIfSkill:
				break;
			case EventTypeEncountRate:
				break;
			case EventTypeSaveEscapeLocation:
				break;
			case EventTypeSettingShip:
				break;
			case EventTypeExit:
				break;
			case EventTypeSelectYesNo:
				break;
			case EventTypeMoveMobUnit:
				break;
			case EventTypeMoveUnit:
				break;
			case EventTypeGettingOnOff:
				break;
			case EventTypeMixShop:
				break;
			case EventTypeIfTime:
				break;
			case EventTypeBar:
				break;
			case EventTypeItemBazaar:
				break;
			case EventTypeBBS:
				break;
			case EventTypeIfTerminal:
				break;
			case EventTypeJingle:
				break;
			case EventTypeRandom:
				break;
			default:
				break;
		}
		
		
	}
	
}

/**
 *  イベント指定実行
 *  @param eventIndex イベントインデックス
 */
void GameEventService::executeEvent(int eventIndex) {
	
	if (events.find(eventIndex) == events.end()){
		// 存在しない
		return;
	}
	
	GameEventEntity eventEntity = events[eventIndex];
	if (eventEntity.isEnd) {
		// すでに終了済み
		return;
	}
	runEvent(eventIndex);
}

/**
 *  イベント指定開始
 *  @param eventIndex イベントインデックス
 */
void GameEventService::runEvent(int eventIndex) {
	// 現在実行中
	if (executeEventIndex >= 0) {
		waitingEventIndexs.push_back(eventIndex);
		return;
	}
	
	// 即実行
	executeEventIndex = eventIndex;
	executeEventDetailIndex = 0;
	executeEventCount1 = 0;
	executeEventCount2 = 0;
	
	// 自動ならば実行フラグをONにする
	if (events[eventIndex].initConditionType == EventInitConditionTypeAuto) {
		events[eventIndex].isEnd = true;
	}
}

#pragma mark - メッセージ

/**
 *  メッセージ表示
 *
 *  @param message メッセージ
 */
void GameEventService::showMessage(string message) {
	
	
}

#pragma mark - ステータス増減

/**
 *  HP増減
 *
 *  @param entity イベント詳細Entity
 */
void GameEventService::fluctuateHP(GameEventBaseEntity *entity) {
	GameEventFluctuateHPEntity *detailEntity = (GameEventFluctuateHPEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateTypeIncrease ? 1 : -1);
	if (detailEntity->target == EventTargetTypeAll) {
		for (auto it = playerEntity->units.begin();it != playerEntity->units.end();it++) {
			it->fluctuateStatus(UnitStatusTypeMaxHP, UnitStatusTypeHP, value);
		}
	} else {
		int target = detailEntity->target - 1;
		if (target < playerEntity->units.size()) {
			playerEntity->units[target].fluctuateStatus(UnitStatusTypeMaxHP, UnitStatusTypeHP, value);
		}
	}
}

/**
 *  MP増減
 *
 *  @param entity イベント詳細Entity
 */
void GameEventService::fluctuateMP(GameEventBaseEntity *entity) {
	GameEventFluctuateMPEntity *detailEntity = (GameEventFluctuateMPEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateTypeIncrease ? 1 : -1);
	if (detailEntity->target == EventTargetTypeAll) {
		for (auto it = playerEntity->units.begin();it != playerEntity->units.end();it++) {
			it->fluctuateStatus(UnitStatusTypeMaxMP, UnitStatusTypeMP, value);
		}
	} else {
		int target = detailEntity->target - 1;
		if (target < playerEntity->units.size()) {
			playerEntity->units[target].fluctuateStatus(UnitStatusTypeMaxMP, UnitStatusTypeMP, value);
		}
	}
}

/**
 *  所持金増減
 *
 *  @param entity イベント詳細Entity
 */
void GameEventService::fluctuateGold(GameEventBaseEntity *entity) {
	GameEventFluctuateGoldEntity *detailEntity = (GameEventFluctuateGoldEntity *)entity;
}

