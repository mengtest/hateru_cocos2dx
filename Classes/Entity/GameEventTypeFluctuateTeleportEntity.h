//
//  GameEventTypeFluctuateTeleportEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeFluctuateTeleportEntity_h
#define GameEventTypeFluctuateTeleportEntity_h

#include "GameEventBaseEntity.h"

/// イベント テレポート位置増減Entity
class GameEventTypeFluctuateTeleportEntity final: public GameEventBaseEntity<GameEventTypeFluctuateTeleportEntity> {
public:
	
	/// 削除フラグ
	bool isRemove;
	/// 表示名
	string name;
	/// 対象マップId
	int32_t mapId;
	/// マップId 歩行/船/飛行船
	vector<int32_t> jumpMapIds;
	/// X座標 歩行/船/飛行船
	vector<int32_t> jumpXs;
	/// Y座標 歩行/船/飛行船
	vector<int32_t> jumpYs;
	
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

#endif /* GameEventTypeFluctuateTeleportEntity_h */
