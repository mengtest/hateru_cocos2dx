//
//  GameMapService.h
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#ifndef GameMapService_h
#define GameMapService_h

#include "BaseService.h"

#include "PlayerEntity.h"
#include "GameMapEntity.h"
#include "GameEnemyEntity.h"

/// ゲームマップサービス
class GameMapService final: BaseService {
public:
	
	/// プレイヤーEntity
	PlayerEntity playerEntity;
	
	/// マップEntity
	GameMapEntity mapEntity;
	
	/**
	 *  デストラクタ
	 */
	~GameMapService();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static GameMapService *sharedInstance();
	
	/**
	 *  ニューゲーム
	 */
	void newGame();
	
private:
	
	/// インスタンス
	static GameMapService *instance;
	
	/// ステータス
	vector<vector<int>> statuses;
	
	/**
	 *  コンストラクタ
	 */
	GameMapService();
	
	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
	
	/**
	 *  遭遇敵情報取得
	 *
	 *  @return 遭遇敵情報
	 */
	vector<GameEnemyEntity> encoundEnemies();
	
	/**
	 *  敵に遭遇か
	 *
	 *  @return true: 遭遇、false: いない
	 */
	bool isEncount();
	
};

#endif /* GameMapService_h */
