//
//  GameEventService.cpp
//  hateru
//
//  Created by HaraKazunari on 2017/01/17.
//
//

#include "GameEventService.h"

#pragma mark - 初期化

/**
 *  コンストラクタ
 *  @param events イベント
 */
GameEventService::GameEventService(map<int, GameEventEntity> &events) {
	// 退避
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
	
	GameEventEntity *eventEntity = &events[executeEventIndex];
	while(true) {

		switch(eventEntity->eventTypes[executeEventDetailIndex]) {
			case EventTypeMessage:
				break;
			case EventTypeFluctuateHP:
				break;
			case EventTypeFluctuateMP:
				break;
			case EventTypeFluctuateGold:
				break;
			case EventTypeFluctuateEXP:
				break;
			case EventTypeFluctuateItem:
				break;
			case EventTypeOperateVariable:
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


