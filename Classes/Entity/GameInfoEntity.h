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
	int32_t shipUnitId;
	/// 飛行船キャラID
	int32_t flyShipUnitId;
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

	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);

	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameInfoEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameInfoEntity_h */
