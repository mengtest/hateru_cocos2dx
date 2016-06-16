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
	/// 初期マップID
	string initMapId;
	/// 初期X座標
	int32_t initX;
	/// 初期Y座標
	int32_t initY;
	/// 初期メンバーID
	vector<int32_t> initMemberIds;
	/// 船キャラID
	int32_t shipCharaId;
	/// 飛行船キャラID
	int32_t flyShipCharaId;
	/// 船サウンドID
	int32_t shipSoundId;
	/// 飛行船サウンドID
	int32_t flyShipSoundId;
	/// 宿屋サウンドID
	int32_t innSoundId;
	/// レベルアップサウンドID
	int32_t levelUpSoundId;
	/// 戦闘終了サウンドID
	int32_t battleEndSoundId;
	
	static GameInfoEntity convertData(const char *data);
	
private:
};

#endif /* GameInfoEntity_h */
