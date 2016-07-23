//
//  GameEventBattleEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventBattleEntity_h
#define GameEventBattleEntity_h

#include "GameEventBaseEntity.h"

/// イベント 戦闘Entity
class GameEventBattleEntity final: public GameEventBaseEntity {
public:
	
	/// 結果退避変数Id
	int32_t variableId;
	/// 敵Id
	vector<int32_t> enemyIds;
	
	/**
	 *  バイナリサイズ取得
	 *
	 *  @return バイナリサイズ
	 */
	int binarySize();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventBattleEntity_h */
