//
//  GameEventTypeIfTerminalEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeIfTerminalEntity_h
#define GameEventTypeIfTerminalEntity_h

#include "GameEventBaseEntity.h"

/// イベント 機種判別Entity
class GameEventTypeIfTerminalEntity final: public GameEventBaseEntity {
public:
	
	/// キャリアタイプ
	int32_t careerType;
	
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

#endif /* GameEventTypeIfTerminalEntity_h */
