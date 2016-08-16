//
//  MapLayer.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#ifndef MapLayer_h
#define MapLayer_h

#include "BaseLayer.h"

/// マップレイヤー
class MapLayer final: public BaseLayer {
public:
	
	/**
	 *  コンストラクタ
	 */
	MapLayer();
	
	/**
	 *  デストラクタ
	 */
	~MapLayer();
	
	
private:
	
	/**
	 *  クラス作成
	 *
	 *  @return クラス
	 */
	static MapLayer *create();
	
	/**
	 *  レイヤー初期化
	 */
	virtual void initLayer() override;
	
	/**
	 *  レイヤーメイン処理
	 */
	virtual void layerMain() override;
	
};

#endif /* MapLayer_h */
