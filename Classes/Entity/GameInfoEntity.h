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
	/// 初期X座標
	int32_t initX;
	/// 初期Y座標
	int32_t initY;
	/// 初期メンバー名
	vector<string> initMemberNemes;
	/// 船キャラ名
	string shipCharaName;
	/// 飛行船キャラ名
	string flyShipCharaName;
	/// 船サウンド名
	string shipSoundName;
	/// 飛行船サウンド名
	string flyShipSoundName;
	/// 宿屋サウンド名
	string innSoundName;
	/// レベルアップサウンド名
	string levelUpSoundName;
	/// 戦闘終了サウンド名
	string battleEndSoundName;
	
private:
};

#endif /* GameInfoEntity_h */
