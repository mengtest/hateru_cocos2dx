//
//  GameEventBaseEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/07/09.
//
//

#include "GameEventBaseEntity.h"

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