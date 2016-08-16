//
//  TitleScene.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/15.
//
//

#ifndef TitleScene_h
#define TitleScene_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// タイトルシーン
class TitleScene final: public Scene {
public:
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static TitleScene *sharedInstance();
	
	/**
	 *  デストラクタ
	 */
	~TitleScene();
	
private:
	
	/// インスタンス
	static TitleScene *instance;
	
	/**
	 *  インストラクタ
	 */
	TitleScene();
	
	/**
	 *  クラス作成(autorelease)
	 */
	CREATE_FUNC(TitleScene);
	
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


#endif /* TitleScene_h */