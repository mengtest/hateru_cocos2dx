//
//  GameMapManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapManager_h
#define GameMapManager_h

#include "BaseManager.h"
#include "GameMapEntity.h"

/// ゲームマップマネージャ
class GameMapManager final: BaseManager {
public:
	
	/**
	 *  変数読み込み
	 *
	 *  @return 変数群
	 */
	static map<string, GameMapManager> &load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameMapManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameMapManager() {}
};

#endif /* GameMapManager_h */
