//
//  GameEventBaseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventBaseEntity.h"


/**
 *  バイナリサイズ取得
 *
 *  @return バイナリサイズ
 */
template <class T_ENTITY>
int GameEventBaseEntity<T_ENTITY>::binarySize() {
	return 0;
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 */
template <class T_ENTITY>
void GameEventBaseEntity<T_ENTITY>::convertData(const unsigned char *data) {
	
}

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *
 *  @return Entity
 */
template <class T_ENTITY>
T_ENTITY GameEventBaseEntity<T_ENTITY>::createEntity(const unsigned char *data) {
	auto entity = T_ENTITY();
	entity.convertData(data);
	return entity;
}