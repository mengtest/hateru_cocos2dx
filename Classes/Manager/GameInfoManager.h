//
//  GameInfoManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameInfoManager_h
#define GameInfoManager_h

#include "BaseManager.h"
#include "GameInfoEntity.h"

/// ゲーム情報マネージャ
class GameInfoManager final: BaseManager {
public:
	
	/**
	 *  変数読み込み
	 *
	 *  @return 変数群
	 */
	static GameInfoManager &load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameInfoManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameInfoManager() {}
};

#endif /* GameInfoManager_h */
