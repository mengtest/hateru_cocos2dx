//
//  GameMapEventEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapEventEntity_h
#define GameMapEventEntity_h

#include "BaseGameEntity.h"

/// マップチップイベントEntity
class GameMapEventEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 変数による発火
	bool isIgnitionVariable;
	
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param name 名前
	 */
	void convertData(const unsigned char *data, const string &name);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *  @param name 名前
	 *
	 *  @return Entity
	 */
	static GameMapEventEntity createEntity(const unsigned char *data, const string &name);
	
private:
};

#endif /* GameMapEventEntity_h */
