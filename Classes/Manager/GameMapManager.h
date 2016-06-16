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
	 *  @param name マップ名
	 *
	 *  @return 取得データ
	 */
	static GameMapEntity load(const string name);
	
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