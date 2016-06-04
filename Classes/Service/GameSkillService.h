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
	
private:
	
	/// スキル
	map<string, GameSkillEntity> skills;
	
	/**
	 *  コンストラクタ
	 */
	GameSkillService();
	
};

#endif /* GameSkillService_h */
