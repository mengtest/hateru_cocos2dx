//
//  GameEventTypeINNEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeINNEntity_h
#define GameEventTypeINNEntity_h

#include "GameEventBaseEntity.h"

/// イベント 宿屋Entity
class GameEventTypeINNEntity final: public GameEventBaseEntity<GameEventTypeINNEntity> {
public:
	
	/// 値段
	int32_t price;
	/// 変数退避Id
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

#endif /* GameEventTypeINNEntity_h */
