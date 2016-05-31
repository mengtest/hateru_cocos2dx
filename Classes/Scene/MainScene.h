//
//  MainScene.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "cocos2d.h"

USING_NS_CC;

class MainScene: public Scene {
	
public:

	/**
	 *  デストラクタ
	 */
	~MainScene();
	
	/**
	 *  インスタンスシェア
	 *
	 *  @return インスタンス
	 */
	static MainScene* sharedInstance();
	
	/**
	 *  ゲームスタート
	 */
	void startGame();

	/**
	 *  クラス作成(autorelease)
	 */
	CREATE_FUNC(MainScene);

private:
	
	/**
	 *  コンストラクタ
	 */
	MainScene();
	
	/**
	 *  更新処理
	 *
	 *  @param delta デルタ
	 */
	virtual void update(float delta);

};


#endif /* MainScene_h */
