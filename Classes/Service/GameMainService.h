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
#include "GameMapEntity.h"
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
	
	/**
	 *  ゲーム情報取得
	 *
	 *  @return ゲーム情報
	 */
	GameInfoEntity *getGameInfo();

	/**
	 *  マップ取得
	 *
	 *  @param id ID
	 *
	 *  @return マップ
	 */
	GameMapEntity *getMap(const int id);
	
	/**
	 *  マップチップグループ取得
	 *
	 *  @param id ID
	 *
	 *  @return マップチップグループ
	 */
	GameMapChipGroupEntity *getMapChipGroup(const int id);
	
	/**
	 *  敵情報取得
	 *
	 *  @param id ID
	 *
	 *  @return 敵情報
	 */
	GameEnemyEntity *getEnemy(const int id);
	
	/**
	 *  キャラ情報取得
	 *
	 *  @param id ID
	 *
	 *  @return キャラ情報
	 */
	GameCharaEntity *getChara(const int id);

	/**
	 *  アイテム情報取得
	 *
	 *  @param id ID
	 *
	 *  @return アイテム情報
	 */
	GameItemEntity *getItem(const int id);

	/**
	 *  職種情報取得
	 *
	 *  @param id ID
	 *
	 *  @return 職種情報
	 */
	GameJobEntity *getJob(const int id);

	/**
	 *  スキル情報取得
	 *
	 *  @param id ID
	 *
	 *  @return スキル情報
	 */
	GameSkillEntity *getSkill(const int id);

	/**
	 *  変数情報取得
	 *
	 *  @param id ID
	 *
	 *  @return 変数情報
	 */
	GameVariableEntity *getVariable(const int id);

private:
	
	/// インスタンス
	static GameMainService *instance;
	
	/// ゲーム情報
	GameInfoEntity gameInfo;
	/// マップ情報
	int mapId;
	GameMapEntity gameMap;
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
