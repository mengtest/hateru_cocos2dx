//
//  GameVariableService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameVariableService.h"

/**
 *  コンストラクタ
 */
GameVariableService::GameVariableService() {
	
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameVariableService &GameVariableService::getInstance() {
	static GameVariableService instance;
	return instance;
}


