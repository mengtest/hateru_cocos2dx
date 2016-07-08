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
#include "GameVariableChangeEntity.h"

/// スキルEntity
class GameSkillEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 種別
	SkillType skillType;
	/// 消費MP
	int32_t costMP;
	/// 効果範囲
	EffectRangeType effectRange;
	/// 効果量
	int32_t effectValue;
	/// 成功率
	int32_t successRate;
	/// 影響ステータス
	int32_t changeStatus;
	/// 攻撃属性
	AttackAttributeType attackAttributeType;
	/// 状態変化
	vector<bool> changeCondition;
	/// 変数変化
	GameVariableChangeEntity changeVariable;
	/// 効果色
	int32_t showEffectColor;
	/// 効果初期幅
	int32_t showEffectInitValue;
	/// 効果変化幅
	int32_t showEffectChangeValue;
	/// 効果動作
	int32_t showEffectOperations;
	/// コメント
	string comment;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameSkillEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameSkillEntity_h */
