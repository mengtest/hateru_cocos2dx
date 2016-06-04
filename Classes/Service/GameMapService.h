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
	 *  インスタンス取得
	 *
	 *  @return インスタンス
	 */
	static GameMapService &getInstance();
	
	/**
	 *  名前よりデータ取得
	 *
	 *  @param name 名前
	 *
	 *  @return 対象データ (なし:nullptr)
	 */
	GameMapEntity *data(const string name);
	
private:
	
	/// キャラリスト
	map<string, GameMapEntity> maps;
	
	/**
	 *  コンストラクタ
	 */
	GameMapService();
	
};

#endif /* GameMapService_h */
