//
//  GameMapEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapEntity_h
#define GameMapEntity_h

#include "BaseGameEntity.h"
#include "GameMapChipEntity.h"
#include "GameMapAutoEntity.h"
#include "GameMapEventEntity.h"

/// マップEntity
class GameMapEntity final: public BaseGameEntity {
public:
	
	/// マップ名
	string name;
	/// マップタイプ
	MAP_TYPE mapType;
	/// 幅
	int32_t width;
	/// 高さ
	int32_t height;
	/// 背景画像
	int32_t backgroundImageId;
	/// 画面制御
	MAP_LOOP_TYPE mapEndType;
	/// 上マップチップグループID
	int32_t upMapChpGpId;
	/// 下マップチップグループID
	int32_t downMapChpGpId;
	/// 背景色
	int32_t backgroundColor;
	/// 出現率
	int32_t enemyEncountRate;
	/// テレポート可不可
	bool isUseTeleport;
	/// エスケープ可不可
	bool isUseEscape;
	/// サウンド
	int32_t soundId;
	/// 戦闘音楽
	int32_t battleSoundId;
	/// 戦闘背景
	int32_t battleBackgroundImageId;
	/// マップチップ情報
	vector<GameMapChipEntity> mapChips;
	/// 自動マップ情報
	GameMapAutoEntity autoMap;
	/// イベント情報
	map<string, GameMapEventEntity> events;

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
	static GameMapEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameMapEntity_h */
