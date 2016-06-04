//
//  GameVariableService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableService_h
#define GameVariableService_h

#include "BaseService.h"
#include "GameVariableEntity.h"

/// ゲームメインサービス
class GameVariableService final: BaseService {
public:

	/**
	 *  インスタンス取得
	 *
	 *  @return インスタンス
	 */
	static GameVariableService &getInstance();
	
private:

	/// 変数
	map<string, GameVariableEntity> variables;
	
	/**
	 *  コンストラクタ
	 */
	GameVariableService();
	
};

#endif /* GameVariableService_h */
