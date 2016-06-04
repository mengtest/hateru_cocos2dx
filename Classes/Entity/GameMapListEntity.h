//
//  GameMapListEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameMapListEntity_h
#define GameMapListEntity_h

#include "BaseGameEntity.h"
#include "GameMapEntity.h"

/// マップリストEntity
class GameMapListEntity final: public BaseGameEntity {
public:
	
	/// マップリスト
	vector<GameMapEntity> maps;
	
private:
};

#endif /* GameMapListEntity_h */
