//
//  GameEventTypeCloakroomEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#ifndef GameEventTypeCloakroomEntity_h
#define GameEventTypeCloakroomEntity_h

#include "GameEventBaseEntity.h"

/// イベント 預り所Entity
class GameEventTypeCloakroomEntity final: public GameEventBaseEntity<GameEventTypeCloakroomEntity> {
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

#endif /* GameEventTypeCloakroomEntity_h */
