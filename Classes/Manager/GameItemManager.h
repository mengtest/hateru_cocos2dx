//
//  GameItemManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemManager_h
#define GameItemManager_h

#include "BaseManager.h"
#include "GameItemEntity.h"

/// ゲームアイテムマネージャ
class GameItemManager final: BaseManager {
public:
	
	/**
	 *  変数読み込み
	 *
	 *  @return 変数群
	 */
	static map<string, GameItemManager> &load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameItemManager() {}
	
	/**
	 *  デストラクタ
	 */
	~GameItemManager() {}
};

#endif /* GameItemManager_h */
