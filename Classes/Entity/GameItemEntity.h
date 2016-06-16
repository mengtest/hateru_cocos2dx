//
//  GameItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameItemEntity_h
#define GameItemEntity_h

#include "BaseGameEntity.h"
#include "GameStatusEntity.h"
#include "GameItemMixEntity.h"
#include "GameVariableChangeEntity.h"

/// アイテムEntity
class GameItemEntity final: public BaseGameEntity {
public:
	
	/// ID
	int32_t id;
	/// 名前
	string name;
	/// 種類
	ITEM_TYPE type;
	/// 買値
	int32_t purchasePrice;
	/// 売値
	int32_t sellingPrice;
	/// 調合値
	int32_t preparationPrice;
	/// 使用回数
	int32_t useCount;
	/// 使用時、特殊技能と同一効果になる nilは無効
	string useSkillId;
	/// 状態治療
	CONDITION_TYPE conditionTreatment;
	/// 変化ステータス
	vector<GameStatusEntity> changeStatus;
	/// 装備可能職業
	vector<bool> equipmentJobs;
	/// 追加特技
	string addSkillId;
	/// 変更職業
	string changeJobId;
	/// 調合<GameItemMixEntity>
	vector<GameItemMixEntity> mixings;
	/// 表示コメント
	string comment;
	/// 変数変化
	map<string, GameVariableChangeEntity> changeVariables;
	
private:
};

#endif /* GameItemEntity_h */
