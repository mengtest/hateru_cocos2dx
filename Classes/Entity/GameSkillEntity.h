//
//  GameSkillEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameSkillEntity_h
#define GameSkillEntity_h

#include "BaseGameEntity.h"
#include "GameStatusEntity.h"
#include "GameVariableChangeEntity.h"

/// スキルEntity
class GameSkillEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 種別
	SKILL_TYPE skillType;
	/// 消費MP
	int32_t costMP;
	/// 効果量
	int32_t effectValue;
	/// 影響ステータス
	vector<GameStatusEntity> changeStatuses;
	/// 攻撃属性
	ATTRIBUTE_TYPE attributeType;
	/// 状態変化
	CONDITION_TYPE changeCondition;
	/// 変数変化
	map<string, GameVariableChangeEntity> changeVariables;
	
	/// コメント */
	string comment;
	
private:
};

#endif /* GameSkillEntity_h */
