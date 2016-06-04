//
//  GameItemService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemService_h
#define GameItemService_h

#include "BaseService.h"
#include "GameItemEntity.h"

/// ゲームアイテムサービス
class GameItemService final: BaseService {
public:
	
	/**
	 *  インスタンス取得
	 *
	 *  @return インスタンス
	 */
	static GameItemService &getInstance();
	
private:
	
	/// アイテム
	map<string, GameItemEntity> items;
	
	/**
	 *  コンストラクタ
	 */
	GameItemService();
	
};

#endif /* GameItemService_h */
