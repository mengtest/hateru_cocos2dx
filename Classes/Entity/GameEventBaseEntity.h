//
//  GameEventBaseEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventBaseEntity_h
#define GameEventBaseEntity_h

#include "BaseGameEntity.h"

/// イベントEntity基底クラス
class GameEventBaseEntity: public BaseGameEntity {
public:
	
	/**
	 *  バイナリサイズ取得
	 *
	 *  @return バイナリサイズ
	 */
	virtual int binarySize();
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	virtual void convertData(const unsigned char *data);
	
private:
};

#endif /* GameEventBaseEntity_h */
