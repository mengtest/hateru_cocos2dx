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
#include "GameItemMixEntity.h"
#include "GameItemStatusEntity.h"
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
	int32_t useSkillId;
	/// 状態治療
	CONDITION_TYPE conditionTreatment;
	/// 変化ステータス
	vector<GameItemStatusEntity> changeStatus;
	/// 画像ID
	int32_t imageId;
	/// 調合<GameItemMixEntity>
	vector<GameItemMixEntity> mixings;
	/// 装備可能職業
	vector<bool> equipmentJobs;
	/// 変更職業
	int32_t changeJobId;
	/// 表示コメント
	string comment;
	/// 出品可否
	bool isExhibit;
	/// 変数変化
	GameVariableChangeEntity changeVariable;
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 */
	void convertData(const unsigned char *data);
	
	/**
	 *  バイナリデータよりEntity作成
	 *
	 *  @param data バイナリデータ
	 *
	 *  @return Entity
	 */
	static GameItemEntity createEntity(const unsigned char *data);
	
private:
};

#endif /* GameItemEntity_h */
