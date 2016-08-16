//
//  MapLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#include "MapLayer.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
MapLayer *MapLayer::create() {
	auto layer = new MapLayer();
	if(layer && layer->init()){
		layer->Layer::autorelease();
		return layer;
	}else {
		delete layer;
		layer = nullptr;
		return nullptr;
	}
}

/**
 *  コンストラクタ
 */
MapLayer::MapLayer() {
	
}

/**
 *  デストラクタ
 */
MapLayer::~MapLayer() {
	
}

/**
 *  レイヤー初期化
 */
void MapLayer::initLayer() {
	
}

/**
 *  レイヤーメイン処理
 */
void MapLayer::layerMain() {
	
}
