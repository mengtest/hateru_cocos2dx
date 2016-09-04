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

/// ゲームマップサービス
class GameMapService final: BaseService {
public:
	
	/// プレイヤーEntity
	PlayerEntity playerEntity;
	
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
	 *  セットアップ
	 */
	void setup();
	
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
	
};

#endif /* GameMapService_h */
