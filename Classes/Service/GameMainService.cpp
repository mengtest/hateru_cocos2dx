//
//  GameMainService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#include "GameMainService.h"

/**
 *  コンストラクタ
 */
GameMainService::GameMainService() {
	
}

/**
 *  インスタンス取得
 *
 *  @return インスタンス
 */
GameMainService &GameMainService::getInstance() {
	static GameMainService instance;
	return instance;
}
