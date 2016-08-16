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
#include "GameMapChipGroupEntity.h"
#include "GameEnemyEntity.h"
#include "GameCharaEntity.h"
#include "GameItemEntity.h"
#include "GameJobEntity.h"
#include "GameSkillEntity.h"
#include "GameVariableEntity.h"

/// ゲームメインサービス
class GameMainService final: BaseService {
public:
	
	/// ゲーム情報
	GameInfoEntity gameInfo;
	/// マップチップ情報
	map<int, GameMapChipGroupEntity> mapChipGroups;
	/// 敵情報
	map<int, GameEnemyEntity> enemies;
	/// キャラ情報
	map<int, GameCharaEntity> charas;
	/// アイテム情報
	map<int, GameItemEntity> items;
	/// 職業情報
	map<int, GameJobEntity> jobs;
	/// 特技情報
	map<int, GameSkillEntity> skills;
	/// 変数情報
	map<int, GameVariableEntity> variables;
	
	/**
	 *  デストラクタ
	 */
	~GameMainService();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static GameMainService *sharedInstance();
	
private:
	
	/// インスタンス
	static GameMainService *instance;
	
	/**
	 *  コンストラクタ
	 */
	GameMainService();
	
	/**
	 *  インスタンスセットアップ
	 */
	static void setupInstance();
	
	/**
	 *  全ての情報を取得する
	 */
	void loadAll();
};

#endif /* GameMainService_h */
