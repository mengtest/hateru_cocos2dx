//
//  GameEventTypeSelectYesNoEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeSelectYesNoEntity_h
#define GameEventTypeSelectYesNoEntity_h

#include "GameEventBaseEntity.h"

/// イベント YESNO選択Entity
class GameEventTypeSelectYesNoEntity final: public GameEventBaseEntity<GameEventTypeSelectYesNoEntity> {
public:
	
	/// 返却変数Id
	int32_t variableId;
	
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

#endif /* GameEventTypeSelectYesNoEntity_h */
