//
//  GameVariableManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableManager_h
#define GameVariableManager_h

#include "BaseManager.h"
#include "GameVariableEntity.h"

/// ゲーム変数マネージャ
class GameVariableManager final: BaseManager {
public:

	/**
	 *  変数読み込み
	 *
	 *  @return 変数群
	 */
	static map<string, GameVariableEntity> &load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameVariableManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameVariableManager() {}
};

#endif /* GameVariableManager_h */
