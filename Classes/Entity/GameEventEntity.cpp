//
//  GameEventEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameEventEntity.h"

#include "GameEventMessageEntity.h"
#include "GameEventFluctuateHPEntity.h"
#include "GameEventFluctuateMPEntity.h"
#include "GameEventFluctuateGoldEntity.h"
#include "GameEventFluctuateEXPEntity.h"
#include "GameEventFluctuateItemEntity.h"
#include "GameEventOperateVariableEntity.h"
#include "GameEventChangeBGMEntity.h"
#include "GameEventChangeChipEntity.h"
#include "GameEventChangeUnitEntity.h"
#include "GameEventMoveLocationEntity.h"
#include "GameEventIfVariableEntity.h"
#include "GameEventSaveEntity.h"
#include "GameEventItemShopEntity.h"
#include "GameEventINNEntity.h"
#include "GameEventCloakroomEntity.h"
#include "GameEventChurchEntity.h"
#include "GameEventBattleEntity.h"
#include "GameEventFluctuateTeleportEntity.h"
#include "GameEventChangeTeleportEntity.h"
#include "GameEventChangeEscapeEntity.h"
#include "GameEventWipeEntity.h"
#include "GameEventExchangeUnitEntity.h"
#include "GameEventEndIfEntity.h"
#include "GameEventShowImageEntity.h"
#include "GameEventChangeJobEntity.h"
#include "GameEventIfStatusEntity.h"
#include "GameEventIfItemEntity.h"
#include "GameEventIfSkillEntity.h"
#include "GameEventEncountRateEntity.h"
#include "GameEventSaveEscapeLocationEntity.h"
#include "GameEventSettingShipEntity.h"
#include "GameEventExitEntity.h"
#include "GameEventSelectYesNoEntity.h"
#include "GameEventMoveMobUnitEntity.h"
#include "GameEventMoveUnitEntity.h"
#include "GameEventGettingOnOffEntity.h"
#include "GameEventMixShopEntity.h"
#include "GameEventIfTimeEntity.h"
#include "GameEventBarEntity.h"
#include "GameEventItemBazaarEntity.h"
#include "GameEventBBSEntity.h"
#include "GameEventIfTerminalEntity.h"
#include "GameEventJingleEntity.h"
#include "GameEventRandomEntity.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return 使用したオフセット数
 */
int GameEventEntity::convertData(const unsigned char *data, const string &name) {
	
	auto dataIndex = 0;
	
	// 名前
	this->name = name;
	
	// 変数による発生
	isIgnitionVariable = data[dataIndex] != 0;
	dataIndex += 1;
	// 変数Id
	variableId = (int32_t)data[dataIndex] * 0x100 + (int32_t)data[dataIndex + 1];
	dataIndex += 2;
	// 式
	formulaType = (IfFormulaType)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 開始条件
	initConditionType = (EventInitConditionType)data[dataIndex];
	dataIndex += 1;
	// 移動タイプ
	moveType = (EventDetailMoveType)data[dataIndex];
	dataIndex += 1;
	if (moveType == EventDetailMoveTypeSet) {
		// 詳細移動数
		int moveCount = (int)data[dataIndex];
		dataIndex += 1;
		// 詳細移動
		for (auto i = 0;i < moveCount;i++) {
			detailMoveTypes.push_back((EventMoveType)data[dataIndex]);
			dataIndex += 1;
		}
	}
	// キャラ使用
	isUseUnit = (int32_t)data[dataIndex] != 0;
	dataIndex += 1;
	// キャラId
	charaId = (int32_t)data[dataIndex];
	dataIndex += 1;
	// 詳細数
	int detailCount = (int)data[dataIndex];
	dataIndex += 1;
	// イベント詳細ヘッダ
	vector<int> detailSizes;
	for (auto i = 0;i < detailCount;i++) {
		// タイプ
		eventTypes.push_back((EventType)data[dataIndex]);
		dataIndex += 1;
		// 使用サイズ
		detailSizes.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	// イベント詳細
	for (auto i = 0;i < detailCount;i++) {
		GameEventBaseEntity eventEntity;
		switch (eventTypes[i]) {
			case EventTypeMessage:
				eventEntity = GameEventMessageEntity();
				break;
			case EventTypeFluctuateHP:
				eventEntity = GameEventFluctuateHPEntity();
				break;
			case EventTypeFluctuateMP:
				eventEntity = GameEventFluctuateMPEntity();
				break;
			case EventTypeFluctuateGold:
				eventEntity = GameEventFluctuateGoldEntity();
				break;
			case EventTypeFluctuateEXP:
				eventEntity = GameEventFluctuateEXPEntity();
				break;
			case EventTypeFluctuateItem:
				eventEntity = GameEventFluctuateItemEntity();
				break;
			case EventTypeOperateVariable:
				eventEntity = GameEventOperateVariableEntity();
				break;
			case EventTypeChangeBGM:
				eventEntity = GameEventChangeBGMEntity();
				break;
			case EventTypeChangeChip:
				eventEntity = GameEventChangeChipEntity();
				break;
			case EventTypeChangeUnit:
				eventEntity = GameEventChangeUnitEntity();
				break;
			case EventTypeMoveLocation:
				eventEntity = GameEventMoveLocationEntity();
				break;
			case EventTypeIfVariable:
				eventEntity = GameEventIfVariableEntity();
				break;
			case EventTypeSave:
				eventEntity = GameEventSaveEntity();
				break;
			case EventTypeItemShop:
				eventEntity = GameEventItemShopEntity();
				break;
			case EventTypeINN:
				eventEntity = GameEventINNEntity();
				break;
			case EventTypeCloakroom:
				eventEntity = GameEventCloakroomEntity();
				break;
			case EventTypeChurch:
				eventEntity = GameEventChurchEntity();
				break;
			case EventTypeBattle:
				eventEntity = GameEventBattleEntity();
				break;
			case EventTypeFluctuateTeleport:
				eventEntity = GameEventFluctuateTeleportEntity();
				break;
			case EventTypeChangeTeleport:
				eventEntity = GameEventChangeTeleportEntity();
				break;
			case EventTypeChangeEscape:
				eventEntity = GameEventChangeEscapeEntity();
				break;
			case EventTypeWipe:
				eventEntity = GameEventWipeEntity();
				break;
			case EventTypeExchangeUnit:
				eventEntity = GameEventExchangeUnitEntity();
				break;
			case EventTypeEndIf:
				eventEntity = GameEventEndIfEntity();
				break;
			case EventTypeShowImage:
				eventEntity = GameEventShowImageEntity();
				break;
			case EventTypeChangeJob:
				eventEntity = GameEventChangeJobEntity();
				break;
			case EventTypeIfStatus:
				eventEntity = GameEventIfStatusEntity();
				break;
			case EventTypeIfItem:
				eventEntity = GameEventIfItemEntity();
				break;
			case EventTypeIfSkill:
				eventEntity = GameEventIfSkillEntity();
				break;
			case EventTypeEncountRate:
				eventEntity = GameEventEncountRateEntity();
				break;
			case EventTypeSaveEscapeLocation:
				eventEntity = GameEventSaveEscapeLocationEntity();
				break;
			case EventTypeSettingShip:
				eventEntity = GameEventSettingShipEntity();
				break;
			case EventTypeExit:
				eventEntity = GameEventExitEntity();
				break;
			case EventTypeSelectYesNo:
				eventEntity = GameEventSelectYesNoEntity();
				break;
			case EventTypeMoveMobUnit:
				eventEntity = GameEventMoveMobUnitEntity();
				break;
			case EventTypeMoveUnit:
				eventEntity = GameEventMoveUnitEntity();
				break;
			case EventTypeGettingOnOff:
				eventEntity = GameEventGettingOnOffEntity();
				break;
			case EventTypeMixShop:
				eventEntity = GameEventMixShopEntity();
				break;
			case EventTypeIfTime:
				eventEntity = GameEventIfTimeEntity();
				break;
			case EventTypeBar:
				eventEntity = GameEventBarEntity();
				break;
			case EventTypeItemBazaar:
				eventEntity = GameEventItemBazaarEntity();
				break;
			case EventTypeBBS:
				eventEntity = GameEventBBSEntity();
				break;
			case EventTypeIfTerminal:
				eventEntity = GameEventIfTerminalEntity();
				break;
			case EventTypeJingle:
				eventEntity = GameEventJingleEntity();
				break;
			case EventTypeRandom:
				eventEntity = GameEventRandomEntity
				();
				break;
		}
		eventEntity.convertData(&data[dataIndex]);
		details.push_back(eventEntity);
		// サイズ加算
		dataIndex += detailSizes[i];
	}
	
	return dataIndex;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param name 名前
 *
 *  @return Entity
 */
GameEventEntity GameEventEntity::createEntity(const unsigned char *data, const string &name) {
	auto entity = GameEventEntity();
	entity.convertData(data, name);
	return entity;
}