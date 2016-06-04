//
//  GameSkillService.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameSkillService_h
#define GameSkillService_h

#include "BaseService.h"
#include "GameSkillEntity.h"

/// ゲームスキルサービス
class GameSkillService final: BaseService {
public:
	
	/**
	 *  インスタンス取得
	 *
	 *  @return インスタンス
	 */
	static GameSkillService &getInstance();
	
	/**
	 *  名前よりデータ取得
	 *
	 *  @param name 名前
	 *
	 *  @return 対象データ (なし:nullptr)
	 */
	GameSkillEntity *data(const string name);

private:
	
	/// スキル
	map<string, GameSkillEntity> skills;
	
	/**
	 *  コンストラクタ
	 */
	GameSkillService();
	
};

#endif /* GameSkillService_h */
