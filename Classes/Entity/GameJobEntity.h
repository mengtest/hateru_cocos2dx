//
//  GameJobEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameJobEntity_h
#define GameJobEntity_h

#include "BaseGameEntity.h"
#include "GameJobSkillEntity.h"

/// 職業Entity
class GameJobEntity final: public BaseGameEntity {
public:
	
	/// ID
	int32_t id;
	/// 名前
	string name;
	/// 会心率
	int32_t criticalRate;
	/// 命中率
	int32_t hitRate;
	/// レベルアップ時のステータス
	int32_t addStatuses[ADDSTATUS_TYPE_EXP + 1][MAX_LEVEL + 1];
	/// 会得スキル情報
	vector<GameJobSkillEntity> getSkills;
	/// コメント
	string comment;
	
private:
};

#endif /* GameJobEntity_h */