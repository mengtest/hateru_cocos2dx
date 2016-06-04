//
//  GameItemMixEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemMixEntity_h
#define GameItemMixEntity_h

#include "BaseGameEntity.h"

/// アイテム合成Entity
class GameItemMixEntity final: public BaseGameEntity {
public:
	
	/// アイテム名
	string itemName;
	/// 個数
	int32_t value;
	
private:
};

#endif /* GameItemMixEntity_h */
