//
//  GameJobSkillEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameJobSkillEntity_h
#define GameJobSkillEntity_h

#include "BaseGameEntity.h"

/// 職業スキルEntity
class GameJobSkillEntity final: public BaseGameEntity {
public:
	
	/// 会得レベル
	int32_t level;
	/// 特殊技能名
	int32_t skillId;
	
private:
};

#endif /* GameJobSkillEntity_h */
