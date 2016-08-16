//
//  SplashScene.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/10.
//
//

#ifndef SplashScene_h
#define SplashScene_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// スプラッシュシーン
class SplashScene final: public Scene {
public:
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static SplashScene *sharedInstance();
	
	/**
	 *  デストラクタ
	 */
	~SplashScene();
	
private:
	
	/// インスタンス
	static SplashScene *instance;
	
	/**
	 *  インストラクタ
	 */
	SplashScene();
	
	/**
	 *  クラス作成(autorelease)
	 */
	CREATE_FUNC(SplashScene);
	
	/**
	 *  インスタンス設定
	 */
	static void setupInstance();
	
	/**
	 *  更新処理
	 *
	 *  @param delta デルタ
	 */
	void update(float delta);
};

#endif /* SplashScene_h */
