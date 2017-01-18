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
#include "GameEventFluctuateItemEntity.h"
#include "GameEventOperateVariableEntity.h"

#include "GameDataService.h"
#include "UUIDUtil.h"

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
				isLoopEnd = fluctuateGold(eventEntity->details[executeEventDetailIndex]);
				break;
			}
			case EventTypeFluctuateEXP:
				// 経験値増減
				break;
			case EventTypeFluctuateItem:
				// アイテム増減
				isLoopEnd = fluctuateItem(eventEntity->details[executeEventDetailIndex]);
				break;
			case EventTypeOperateVariable:
				// 変数操作
				operateVariable(eventEntity->details[executeEventDetailIndex]);
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
 *  ステータス増減
 *
 *  @param target           ターゲット
 *  @param maxStatusType    最大ステータスタイプ
 *  @param changeStatusType 変化ステータスタイプ
 *  @param value            値
 */
void GameEventService::fluctuateStatus(int target, int maxStatusType, int changeStatusType, int value) {
	if (target == EventTargetTypeAll) {
		for (auto it = playerEntity->units.begin();it != playerEntity->units.end();it++) {
			it->fluctuateStatus(maxStatusType, changeStatusType, value);
		}
	} else {
		target -= 1;
		if (target < playerEntity->units.size()) {
			playerEntity->units[target].fluctuateStatus(maxStatusType, changeStatusType, value);
		}
	}
}

/**
 *  HP増減
 *
 *  @param entity イベント詳細Entity
 */
void GameEventService::fluctuateHP(GameEventBaseEntity *entity) {
	GameEventFluctuateMPEntity *detailEntity = (GameEventFluctuateMPEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateTypeIncrease ? 1 : -1);
	fluctuateStatus(detailEntity->target, UnitStatusTypeMaxHP, UnitStatusTypeHP, value);
}

/**
 *  MP増減
 *
 *  @param entity イベント詳細Entity
 */
void GameEventService::fluctuateMP(GameEventBaseEntity *entity) {
	GameEventFluctuateMPEntity *detailEntity = (GameEventFluctuateMPEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateTypeIncrease ? 1 : -1);
	fluctuateStatus(detailEntity->target, UnitStatusTypeMaxMP, UnitStatusTypeMP, value);
}

/**
 *  所持金増減
 *
 *  @param entity イベント詳細Entity
 * 
 *  @return 終了フラグ
 */
bool GameEventService::fluctuateGold(GameEventBaseEntity *entity) {
	GameEventFluctuateGoldEntity *detailEntity = (GameEventFluctuateGoldEntity *)entity;
	int value = detailEntity->value * (detailEntity->fluctuateType == FluctuateTypeIncrease ? 1 : -1);
	playerEntity->money += value;
	if (playerEntity->money <= 0) {
		playerEntity->money = 0;
	}
	if (value > 0) {
		// +の場合はメッセージを表示
		showMessage(StringUtils::format("%d%sを手に入れた！", value, GameDataService::sharedInstance()->gameInfo.moneyUnit.c_str()));
		return true;
	}
	return false;
}

/**
 *  アイテム増減
 *
 *  @param entity イベント詳細Entity
 *
 *  @return 終了フラグ
 */
bool GameEventService::fluctuateItem(GameEventBaseEntity *entity) {
	GameEventFluctuateItemEntity *detailEntity = (GameEventFluctuateItemEntity *)entity;
	GameItemEntity itemEntity = GameDataService::sharedInstance()->items[detailEntity->itemId];
	
	if (detailEntity->fluctuateType == FluctuateTypeIncrease) {
		// アイテム増イベント
		switch (executeEventCount1) {
			case 0: {
				// メッセージのみ
				showMessage(StringUtils::format("%sを手に入れた！", itemEntity.name.c_str()));
				executeEventCount1 += 1;
				break;
			}
			case 1: {
				// 実際アイテムを追加する
				auto isFull = playerEntity->addItem(detailEntity->itemId, itemEntity.useCount, "");
				if (isFull) {
					showMessage("荷物がいっぱいです\nどれを捨てますか？");
					executeEventCount1 += 1;
				} else {
					// 次のイベントへ
					executeEventDetailIndex += 1;
				}
				break;
			}
			case 2: {
				// TODO:キャラ選択メニュー表示
				
				executeEventCount1 += 1;
				break;
			}
			case 3: {
				// TODO:キャラ選択
				
				break;
			}
			case 4: {
				// TODO:捨てるアイテムを選択
				
				break;
			}
			case 5: {
				// TODO:捨てる確認
				
				break;
			}
		}

		// イベントを前に戻す
		executeEventDetailIndex -= 1;

		return true;
	}
	
	// アイテム減イベント
	auto isExist = playerEntity->removeItem(detailEntity->itemId);
	if (isExist) {
		showMessage(StringUtils::format("%sを手渡した", itemEntity.name.c_str()));
		return true;
	}
	return false;
}

#pragma mark - 変数操作

/**
 *  変数操作
 *
 *  @param entity イベント詳細Entity
 */
void GameEventService::operateVariable(GameEventBaseEntity *entity) {
	GameEventOperateVariableEntity *detailEntity = (GameEventOperateVariableEntity *)entity;
	
	switch (detailEntity->operateType) {
		case VariableOperateTypeAssignment:
			playerEntity->variables[detailEntity->variableId] = detailEntity->value;
			break;
		case VariableOperateTypeIncrease:
			playerEntity->variables[detailEntity->variableId] += detailEntity->value;
			break;
		case VariableOperateTypeDecline:
			playerEntity->variables[detailEntity->variableId] -= detailEntity->value;
			break;
	}
	playerEntity->variables[detailEntity->variableId] &= 0xff;
	
	// イベント
	for (auto it = events.begin();it != events.end();it++) {
		// 有効ではない
		if (it->second.workStatus == EventWorkStatusNoMap) {
			continue;
		}
		it->second.workStatus = EventWorkStatusInvalid;
		// 変数チェック
		if (it->second.isIgnitionVariable) {
			// TODO: SubSetNum
		}
		// ステータス設定
		
	}
}


