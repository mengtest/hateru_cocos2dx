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
	
	/**
	 *  IDよりデータ取得
	 *
	 *  @param id ID
	 *
	 *  @return 対象データ (なし:nullptr)
	 */
	GameVariableEntity *data(int32_t id);
	
private:

	/// 変数
	map<int32_t, GameVariableEntity> variables;
	
	/**
	 *  コンストラクタ
	 */
	GameVariableService();
	
};

#endif /* GameVariableService_h */
