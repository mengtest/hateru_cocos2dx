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
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static map<string, GameMapEntity> load();
	
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
