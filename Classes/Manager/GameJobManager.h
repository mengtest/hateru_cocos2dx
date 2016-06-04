//
//  GameJobManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameJobManager_h
#define GameJobManager_h

#include "BaseManager.h"
#include "GameJobEntity.h"

/// ゲーム職業マネージャ
class GameJobManager final: BaseManager {
public:
	
	/**
	 *  変数読み込み
	 *
	 *  @return 変数群
	 */
	static map<string, GameJobManager> &load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameJobManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameJobManager() {}
};

#endif /* GameJobManager_h */
