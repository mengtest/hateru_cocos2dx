//
//  GameMapChipGroupEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapChipGroupEntity_h
#define GameMapChipGroupEntity_h

#include "BaseGameEntity.h"

/// マップチップグループEntity
class GameMapChipGroupEntity final: public BaseGameEntity {
public:
	
	/// 名前
	string name;
	/// 画像Id
	int imageId[MAPCHIP_VALUE_MAX];
	
	/**
	 *  コンストラクタ
	 */
	GameMapChipGroupEntity();
	
	/**
	 *  デストラクタ
	 */
	~GameMapChipGroupEntity();
	
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
	static GameMapChipGroupEntity createEntity(const unsigned char *data, const string &name);
	
private:
};

#endif /* GameMapChipGroupEntity_h */
