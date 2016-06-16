//
//  GameVariableEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableEntity_h
#define GameVariableEntity_h

#include "BaseGameEntity.h"

/// 変数Entity
class GameVariableEntity final: public BaseGameEntity {
public:
	
	/// ID
	int32_t id;
	/// 名前
	string name;
	/// 初期値
	int32_t initValue;
	/// 説明
	string guide;
	
private:
};

#endif /* GameVariableEntity_h */
