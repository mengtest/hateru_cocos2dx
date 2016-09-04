//
//  GameBattleService.h
//  hateru
//
//  Created by HaraKazunari on 2016/09/04.
//
//

#ifndef GameBattleService_h
#define GameBattleService_h

#include "BaseService.h"

/// ゲームバトルサービス
class GameBattleService final: BaseService {
public:
	
	/**
	 *  デストラクタ
	 */
	~GameBattleService();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static GameBattleService *sharedInstance();

	/**
	 *  セットアップ
	 */
	void setup();
	
private:
	
	/// インスタンス
	static GameBattleService *instance;

	/// 名前
	vector<string> unitNames;
	/// ステータス
	vector<vector<int>> unitStatuses;
	
	/**
	 *  コンストラクタ
	 */
	GameBattleService();
	
	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
	
	/**
	 *  プレイヤーのステータスを反映
	 */
	void setupPlayerStatus();
	
};

#endif /* GameBattleService_h */
