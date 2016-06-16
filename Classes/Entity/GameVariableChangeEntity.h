//
//  GameVariableChangeEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameVariableChangeEntity_h
#define GameVariableChangeEntity_h

#include "BaseGameEntity.h"

/// 変数変化Entity
class GameVariableChangeEntity final: public BaseGameEntity {
public:
	
	/// 変数名
	int32_t variableId;
	/// 式
	VARIABLE_ZG_TYPE expression;
	/// 値
	int32_t value;

	/**
	 *  値の整合性チェック
	 *
	 *  @return 生合成チェック可否
	 */
	bool isValid();
	
private:
};

#endif /* GameVariableChangeEntity_h */
