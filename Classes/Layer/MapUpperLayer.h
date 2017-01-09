//
//  MapUpperLayer.h
//  hateru
//
//  Created by HaraKazunari on 2017/01/09.
//
//

#ifndef MapUpperLayer_h
#define MapUpperLayer_h

#include "BaseLayer.h"

class GameMapEntity;
class GameMapChipEntity;
class GameMapAutoEntity;

/// マップ上レイヤー
class MapUpperLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	MapUpperLayer();
	
	/**
	 *  デストラクタ
	 */
	~MapUpperLayer();
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static MapUpperLayer *create();
	
	/**
	 *  セットアップ
	 *
	 *  @param mapEntity マップEntity
	 */
	void setupMapUpperLayer(const GameMapEntity *mapEntity);
	
	/**
	 *  ユニットのポジション設定
	 *
	 *  @param position ポジション
	 */
	void setUnitPosition(Point position);
	
private:
	
	/// 幅
	int width;
	/// 高さ
	int height;
	
	/// チップ
	Sprite **chips;
	
	/// 画面のセンターX座標
	float centerX;
	/// 画面のセンターY座標
	float centerY;
	
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
	/**
	 *  SpriteFrame取得
	 *
	 *  @param imageId 画像ID
	 *
	 *  @return SpriteFrame
	 */
	SpriteFrame *getSpriteFrame(const int imageId);
	
	/**
	 *  スプライト情報解放
	 */
	void freeSprites();
};

#endif /* MapUpperLayer_h */
