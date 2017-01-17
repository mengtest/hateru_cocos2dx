//
//  GameEventService.h
//  hateru
//
//  Created by HaraKazunari on 2017/01/17.
//
//

#ifndef GameEventService_h
#define GameEventService_h

#include "BaseService.h"

class PlayerEntity;
class GameEventEntity;
class GameEventBaseEntity;

/// ゲームイベントサービス
class GameEventService final: public BaseService {
public:
	
	/**
	 *  コンストラクタ
	 *
	 *  @param playerEntity プレイヤーデータ
	 *  @param events       イベント群
	 */
	GameEventService(PlayerEntity *playerEntity, map<int, GameEventEntity> &events);

	/**
	 *  デストラクタ
	 */
	~GameEventService();

	/**
	 *  イベント実行
	 */
	void executeEvents();

	/**
	 *  イベント指定実行
	 *
	 *  @param eventIndex イベントインデックス
	 */
	void executeEvent(int eventIndex);

private:
	
	/// プレイヤー情報
	PlayerEntity *playerEntity;
	/// イベント情報
	map<int, GameEventEntity> events;
	
	/// 現在実行中のイベントインデックス
	int executeEventIndex;
	/// 詳細実行中インデックス
	int executeEventDetailIndex;
	/// 作業用カウント1
	int executeEventCount1;
	/// 作業用カウント2
	int executeEventCount2;
	
	/// 順番待ちのイベント
	vector<int> waitingEventIndexs;

	/**
	 *  イベント指定開始
	 *
	 *  @param eventIndex イベントインデックス
	 */
	void runEvent(int eventIndex);
	
#pragma mark - メッセージ
	
	/**
	 *  メッセージ表示
	 *
	 *  @param message メッセージ
	 */
	void showMessage(string message);
	
#pragma mark - ステータス増減

	/**
	 *  HP増減
	 *
	 *  @param entity イベント詳細Entity
	 */
	void fluctuateHP(GameEventBaseEntity *entity);

	/**
	 *  MP増減
	 *
	 *  @param entity イベント詳細Entity
	 */
	void fluctuateMP(GameEventBaseEntity *entity);
	
	/**
	 *  所持金増減
	 *
	 *  @param entity イベント詳細Entity
	 */
	void fluctuateGold(GameEventBaseEntity *entity);
};


#endif /* GameEventService_h */
