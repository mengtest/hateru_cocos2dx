//
//  SplashLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "SplashLayer.h"

#include "TokenGetFetcher.h"

/**
 *  クラス作成
 *
 *  @return クラス
 */
SplashLayer *SplashLayer::create() {
	SplashLayer *layer = new SplashLayer();
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
SplashLayer::SplashLayer() {
	
}

/**
 *  デストラクタ
 */
SplashLayer::~SplashLayer() {
	
}

/**
 *  レイヤー初期化
 */
void SplashLayer::initLayer() {
	
}

/**
 *  レイヤーメイン処理
 */
void SplashLayer::layerMain() {
	
}

