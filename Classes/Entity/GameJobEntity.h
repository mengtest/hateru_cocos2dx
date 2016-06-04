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
	
	/// 名前
	string name;
	/// クリティカル
	int32_t critical;
	/// レベルアップ時のステータス
	int32_t addStatuses[ADDSTATUS_TYPE_EXP + 1][MAX_LEVEL + 1];
	/// 会得スキル情報
	vector<GameJobSkillEntity> getSkills;
	/// コメント
	string comment;
	
private:
};

#endif /* GameJobEntity_h */
