//
//  GameMapService.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/05.
//
//

#include "GameMapService.h"
#include "GameMapManager.h"

/**
 *  コンストラクタ
 *
 *  @param name マップ名
 */
GameMapService::GameMapService(const string name) {
	// 読み込み
	map = GameMapManager::load(name);
}
