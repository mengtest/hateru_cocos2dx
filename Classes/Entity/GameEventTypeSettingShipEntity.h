//
//  GameEventTypeSettingShipEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeSettingShipEntity_h
#define GameEventTypeSettingShipEntity_h

#include "GameEventBaseEntity.h"

/// イベント 船設定Entity
class GameEventTypeSettingShipEntity final: public GameEventBaseEntity<GameEventTypeSettingShipEntity> {
public:
	
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

#endif /* GameEventTypeSettingShipEntity_h */
