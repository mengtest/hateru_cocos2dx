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
 *  コンストラクタ
 */
GameEventEntity::GameEventEntity() {
	name = "";
	isIgnitionVariable = false;
	variableId = 0;
	formulaType = IfFormulaTypeEqual;
	value = 0;
	initConditionType = EventInitConditionTypeKey;
	moveType = EventDetailMoveTypeNoMove;
	detailMoveTypes.clear();
	isUseUnit = false;
	charaId = 0;
	eventTypes.clear();
	details.clear();
	isEnd = false;
	workStatus = EventWorkStatusNoMap;
}

/**
 *  デストラクタ
 */
GameEventEntity::~GameEventEntity() {
	
}

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
	variableId = (int)data[dataIndex] * 0x100 + (int)data[dataIndex + 1];
	dataIndex += 2;
	// 式
	formulaType = (IfFormulaType)data[dataIndex];
	dataIndex += 1;
	// 値
	value = (int)data[dataIndex];
	dataIndex += 1;
	// 開始条件
	initConditionType = (EventInitConditionType)data[dataIndex];
	dataIndex += 1;
	// 移動タイプ
	moveType = (EventDetailMoveType)data[dataIndex];
	dataIndex += 1;
	detailMoveTypes.clear();
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
	isUseUnit = (int)data[dataIndex] != 0;
	dataIndex += 1;
	// キャラId
	charaId = (int)data[dataIndex];
	dataIndex += 1;
	// 詳細数
	int detailCount = (int)data[dataIndex];
	dataIndex += 1;
	// イベント詳細ヘッダ
	eventTypes.clear();
	vector<int> detailSizes;
	for (auto i = 0;i < detailCount;i++) {
		// タイプ
		eventTypes.push_back((EventType)data[dataIndex]);
		dataIndex += 1;
		// 使用サイズ (不正確)
		detailSizes.push_back((int)data[dataIndex]);
		dataIndex += 1;
	}
	// イベント詳細
	details.clear();
	for (auto i = 0;i < detailCount;i++) {
		switch (eventTypes[i]) {
			case EventTypeMessage: {
				auto eventEntity = GameEventMessageEntity();
				eventEntity.messageLen = detailSizes[i];
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeFluctuateHP: {
				auto eventEntity = GameEventFluctuateHPEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeFluctuateMP: {
				auto eventEntity = GameEventFluctuateMPEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeFluctuateGold: {
				auto eventEntity = GameEventFluctuateGoldEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeFluctuateEXP: {
				auto eventEntity = GameEventFluctuateEXPEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeFluctuateItem: {
				auto eventEntity = GameEventFluctuateItemEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeOperateVariable: {
				auto eventEntity = GameEventOperateVariableEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeChangeBGM: {
				auto eventEntity = GameEventChangeBGMEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeChangeChip: {
				auto eventEntity = GameEventChangeChipEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeChangeUnit: {
				auto eventEntity = GameEventChangeUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeMoveLocation: {
				auto eventEntity = GameEventMoveLocationEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeIfVariable: {
				auto eventEntity = GameEventIfVariableEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeSave: {
				auto eventEntity = GameEventSaveEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeItemShop: {
				auto eventEntity = GameEventItemShopEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeINN: {
				auto eventEntity = GameEventINNEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeCloakroom: {
				auto eventEntity = GameEventCloakroomEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeChurch: {
				auto eventEntity = GameEventChurchEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeBattle: {
				auto eventEntity = GameEventBattleEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeFluctuateTeleport: {
				auto eventEntity = GameEventFluctuateTeleportEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeChangeTeleport: {
				auto eventEntity = GameEventChangeTeleportEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeChangeEscape: {
				auto eventEntity = GameEventChangeEscapeEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeWipe: {
				auto eventEntity = GameEventWipeEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeExchangeUnit: {
				auto eventEntity = GameEventExchangeUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeEndIf: {
				auto eventEntity = GameEventEndIfEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeShowImage: {
				auto eventEntity = GameEventShowImageEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeChangeJob: {
				auto eventEntity = GameEventChangeJobEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeIfStatus: {
				auto eventEntity = GameEventIfStatusEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeIfItem: {
				auto eventEntity = GameEventIfItemEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeIfSkill: {
				auto eventEntity = GameEventIfSkillEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeEncountRate: {
				auto eventEntity = GameEventEncountRateEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeSaveEscapeLocation: {
				auto eventEntity = GameEventSaveEscapeLocationEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeSettingShip: {
				auto eventEntity = GameEventSettingShipEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeExit: {
				auto eventEntity = GameEventExitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeSelectYesNo: {
				auto eventEntity = GameEventSelectYesNoEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeMoveMobUnit: {
				auto eventEntity = GameEventMoveMobUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeMoveUnit: {
				auto eventEntity = GameEventMoveUnitEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeGettingOnOff: {
				auto eventEntity = GameEventGettingOnOffEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeMixShop: {
				auto eventEntity = GameEventMixShopEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeIfTime: {
				auto eventEntity = GameEventIfTimeEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeBar: {
				auto eventEntity = GameEventBarEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeItemBazaar: {
				auto eventEntity = GameEventItemBazaarEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeBBS: {
				auto eventEntity = GameEventBBSEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeIfTerminal: {
				auto eventEntity = GameEventIfTerminalEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeJingle: {
				auto eventEntity = GameEventJingleEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
			case EventTypeRandom: {
				auto eventEntity = GameEventRandomEntity();
				dataIndex += eventEntity.convertData(&data[dataIndex]);
				details.push_back(&eventEntity);
				break;
			}
		}
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
