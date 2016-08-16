//
//  GameMainService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMainService_h
#define GameMainService_h

#include "BaseService.h"
#include "GameInfoEntity.h"

/// ゲームメインサービス
class GameMainService final: BaseService {
public:
	
	/**
	 *  インスタンス取得
	 *
	 *  @return インスタンス
	 */
	static GameMainService &getInstance();
	
	/**
	 *  デストラクタ
	 */
	~GameMainService();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	GameMainService();
	
};

#endif /* GameMainService_h */
