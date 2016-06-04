//
//  GameStatusEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameStatusEntity_h
#define GameStatusEntity_h

#include "BaseGameEntity.h"

/// 職業ステータスEntity
class GameStatusEntity final: public BaseGameEntity {
public:
	
	/// ステータス種別
	STATUS_TYPE status;
	/// 変化値
	int32_t value;
	
private:
};

#endif /* GameStatusEntity_h */
