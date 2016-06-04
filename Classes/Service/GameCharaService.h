//
//  GameCharaService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameCharaService_h
#define GameCharaService_h

#include "BaseService.h"
#include "GameCharaEntity.h"

/// ゲームキャラサービス
class GameCharaService final: BaseService {
public:
	
	/**
	 *  インスタンス取得
	 *
	 *  @return インスタンス
	 */
	static GameCharaService &getInstance();
	
	/**
	 *  名前よりデータ取得
	 *
	 *  @param name 名前
	 *
	 *  @return 対象データ (なし:nullptr)
	 */
	GameCharaEntity *data(const string name);
	
private:
	
	/// キャラリスト
	map<string, GameCharaEntity> charas;
	
	/**
	 *  コンストラクタ
	 */
	GameCharaService();
	
};

#endif /* GameCharaService_h */
