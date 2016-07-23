//
//  GameEventChangeChipEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventChangeChipEntity_h
#define GameEventChangeChipEntity_h

#include "GameEventBaseEntity.h"

/// イベント マップチップ変更Entity
class GameEventChangeChipEntity final: public GameEventBaseEntity {
public:

	/// 通行禁止
	bool isNotPassWalk;
	/// 上チップ/下チップ
	bool isUpChip;
	/// チップID
	int32_t chipId;
	/// X座標
	int32_t x;
	/// Y座標
	int32_t y;
	/// 船通行禁止
	bool isNotPassShip;
	/// 飛行通行禁止
	bool isNotPassFlyShip;
	
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

#endif /* GameEventChangeChipEntity_h */
