//
//  GameInfoEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameInfoEntity_h
#define GameInfoEntity_h

#include "BaseGameEntity.h"

/// ゲームEntity
class GameInfoEntity final: public BaseGameEntity {
public:
	
	/// 初期所持金
	int32_t initMoney;
	/// 初期所持金
	string moneyUnit;
	/// 初期マップ
	string initMapName;
	
private:
};

#endif /* GameInfoEntity_h */
