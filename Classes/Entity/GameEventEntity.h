//
//  GameEventEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameEventEntity_h
#define GameEventEntity_h

#include "BaseGameEntity.h"
#include "GameEventBaseEntity.h"

/// マップイベントEntity
class GameEventEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 変数による発火
	bool isIgnitionVariable;
	/// 変数
	int32_t variableId;
	/// 式
	IfFormulaType formulaType;
	/// 値
	int32_t value;
	/// 開始条件
	EventInitConditionType initConditionType;
	/// 移動タイプ
	EventDetailMoveType moveType;
	/// 詳細移動
	vector<EventMoveType> detailMoveTypes;
	/// キャラ使用
	bool isUseUnit;
	/// キャラId
	int32_t charaId;
	/// イベントタイプ
	vector<EventType> eventTypes;
	/// イベント詳細
	vector<GameEventBaseEntity> details;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param name 名前
	 *
	 *  @return 使用したオフセット数
	 */
	int convertData(const unsigned char *data, const string &name);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param name 名前
	 *
	 *  @return Entity
	 */
	static GameEventEntity createEntity(const unsigned char *data, const string &name);
	
private:
};

#endif /* GameEventEntity_h */
