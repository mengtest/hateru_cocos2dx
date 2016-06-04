//
//  GameSkillManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameSkillManager_h
#define GameSkillManager_h

#include "BaseManager.h"
#include "GameSkillEntity.h"

/// ゲームスキルマネージャ
class GameSkillManager final: BaseManager {
public:
	
	/**
	 *  変数読み込み
	 *
	 *  @return 変数群
	 */
	static map<string, GameSkillManager> &load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameSkillManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameSkillManager() {}
};

#endif /* GameSkillManager_h */
