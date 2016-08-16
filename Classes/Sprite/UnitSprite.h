//
//  UnitSprite.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/15.
//
//

#ifndef UnitSprite_h
#define UnitSprite_h

#include "cocos2d.h"
#include "GameCharaEntity.h"

USING_NS_CC;
using namespace std;

/// キャラの方向
typedef enum {
	/** 上向き */
	DirectionTypeUp = 0,
	/** 右向き */
	DirectionTypeRight,
	/** 下向き */
	DirectionTypeDown,
	/** 左向き */
	DirectionTypeLeft,
} DirectionType;

/// ユニットスプライト
class UnitSprite final: public Sprite {
public:
	
	/**
	 *  コンストラクタ
	 */
	UnitSprite();
	
	/**
	 *  デストラクタ
	 */
	~UnitSprite();
	
	/**
	 *  クラス作成
	 *
	 *  @param entity キャラEntity
	 *
	 *  @return クラス
	 */
	static UnitSprite *create(const GameCharaEntity &entity);
	
	/**
	 *  向きを設定
	 *
	 *  @param direction 向きタイプ
	 */
	void setDirectionType(DirectionType directionType);
	
	/**
	 *  向きを取得
	 *
	 *  @return 向きタイプ
	 */
	DirectionType getDirectionType();

	/**
	 *  歩きストップ設定
	 *
	 *  @param isStopWalk 歩きストップフラグ
	 */
	void setStopWalk(bool isStopWalk);
	
private:
	
	/// キャラEntity
	GameCharaEntity entity;
	
	/// キャラの向き
	DirectionType directionType;
	
	/// 歩きカウント
	int walkCount;
	
	/// スケジュールカウント
	int scheduleCount;
	
	/// 歩きストップフラグ
	bool isStopWalk;
	
	/**
	 *  セットアップ
	 *
	 *  @param entity キャラEntity
	 */
	void setup(const GameCharaEntity &entity);

	/**
	 *  スケジュール更新
	 *
	 *  @param delta delta
	 */
	void update(float delta) override;
	
	/**
	 *  画像Id取得
	 *
	 *  @param directionType 向き
	 *
	 *  @return 画像インデックス
	 */
	int getImageId(DirectionType directionType);
	
	/**
	 *  SpriteFrame取得
	 *
	 *  @return SpriteFrame
	 */
	SpriteFrame *getSpriteFrame();
	
};

#endif /* UnitSprite_h */
