//
//  GameEventIfSkillEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventIfSkillEntity_h
#define GameEventIfSkillEntity_h

#include "GameEventBaseEntity.h"

/// イベント 特殊技能分岐Entity
class GameEventIfSkillEntity final: public GameEventBaseEntity {
public:
	
	/// 参照キャラ
	int32_t unitId;
	/// 参照スキル
	int32_t skillId;
	/// 会得
	bool isLearning;
	
	/**
	 *  バイナリサイズ取得
	 *
	 *  @return バイナリサイズ
	 */
	int binarySize();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventIfSkillEntity_h */
