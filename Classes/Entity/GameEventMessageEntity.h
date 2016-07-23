//
//  GameEventMessageEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventMessageEntity_h
#define GameEventMessageEntity_h

#include "GameEventBaseEntity.h"

/// イベント メッセージ表示Entity
class GameEventMessageEntity final: public GameEventBaseEntity {
public:
	
	/// メッセージ
	string message;
	
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

#endif /* GameEventMessageEntity_h */
