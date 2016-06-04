//
//  GameJobService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameJobService_h
#define GameJobService_h

#include "BaseService.h"
#include "GameJobEntity.h"

/// ゲーム職業サービス
class GameJobService final: BaseService {
public:
	
	/**
	 *  インスタンス取得
	 *
	 *  @return インスタンス
	 */
	static GameJobService &getInstance();
	
private:
	
	/// 職業
	map<string, GameJobEntity> jobs;
	
	/**
	 *  コンストラクタ
	 */
	GameJobService();
	
};

#endif /* GameJobService_h */
