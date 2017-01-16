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

#include "GameEventEntity.h"

/// ゲームイベントサービス
class GameEventService final: BaseService {
public:
	
	/**
	 *  コンストラクタ
	 *  @param events イベント
	 */
	GameEventService(map<int, GameEventEntity> &events);

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
	 *  @param eventIndex イベントインデックス
	 */
	void executeEvent(int eventIndex);

private:
	
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
	 *  @param eventIndex イベントインデックス
	 */
	void runEvent(int eventIndex);
};

#endif /* GameEventService_h */
