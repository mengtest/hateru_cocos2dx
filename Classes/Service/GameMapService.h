//
//  GameMapService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/05.
//
//

#ifndef GameMapService_h
#define GameMapService_h

#include "BaseService.h"
#include "GameMapEntity.h"

/// ゲームマップサービス
class GameMapService final: BaseService {
public:
	
	/**
	 *  コンストラクタ
	 *
	 *  @param name マップ名
	 */
	GameMapService(const string name);
	
private:
	
	/// マップ
	GameMapEntity map;
	
};

#endif /* GameMapService_h */
