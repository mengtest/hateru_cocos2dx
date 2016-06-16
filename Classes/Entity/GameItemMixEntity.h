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
	
	/// アイテムID
	int32_t itemId;
	/// 個数
	int32_t value;
	
private:
};

#endif /* GameItemMixEntity_h */
