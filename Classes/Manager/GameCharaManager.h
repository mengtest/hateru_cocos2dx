//
//  GameCharaManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameCharaManager_h
#define GameCharaManager_h

#include "BaseManager.h"
#include "GameCharaEntity.h"

/// ゲームキャラマネージャ
class GameCharaManager final: BaseManager {
public:
	
	/**
	 *  変数読み込み
	 *
	 *  @return 変数群
	 */
	static map<string, GameCharaManager> &load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameCharaManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameCharaManager() {}
};

#endif /* GameCharaManager_h */
