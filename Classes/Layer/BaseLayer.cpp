//
//  BaseLayer.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/16.
//
//

#include "BaseLayer.h"

/**
 *  初期化
 *
 *  @return 作成可否
 */
bool BaseLayer::init() {
	return Layer::init();
}

/**
 *  コンストラクタ
 */
BaseLayer::BaseLayer() {
	
	// 画面タッチを有効にする
	EventListenerTouchOneByOne *touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(BaseLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(BaseLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(BaseLayer::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	// キーパッドを有効にする
//	setKeypadEnabled(true);
}

/**
 *  デストラクタ
 */
BaseLayer::~BaseLayer() {
	
}

// レイヤー破棄
void BaseLayer::deallocLayer() {
	// タッチ登録解除
	unregisterWithTouchDispatcher();
}

#pragma mark - キー

/**
 *  キープレス
 *
 *  @param keyCode キーコード
 *  @param event   イベント情報
 */
void BaseLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	
}

/**
 *  キーリリース
 *
 *  @param keyCode キーコード
 *  @param event   イベント情報
 */
void BaseLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	
}

#pragma mark - タッチ

/**
 *  タッチ削除
 */
void BaseLayer::unregisterWithTouchDispatcher() {
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->removeEventListener(this);
}

/**
 *  タッチダウンイベント
 *
 *  @param pTouch タッチ情報
 *  @param pEvent イベント情報
 *
 *  @return 処理可否
 */
bool BaseLayer::onTouchBegan(Touch *pTouch, Event *pEvent) {
	return true;
}

/**
 *  タッチ移動イベント
 *
 *  @param pTouch タッチ情報
 *  @param pEvent イベント情報
 */
void BaseLayer::onTouchMoved(Touch *pTouch, Event *pEvent) {
	
}

/**
 *  タッチアップイベント
 *
 *  @param pTouch タッチ情報
 *  @param pEvent イベント情報
 */
void BaseLayer::onTouchEnded(Touch *pTouch, Event *pEvent) {
	
}


#pragma mark - EventListener

/**
 *  リスナーが使用可能かどうかをチェックします。
 *
 *  @return 使用可否
 */
bool BaseLayer::checkAvailable() {
	return true;
}

/**
 *  クローンリスナーは、そのサブクラスではこのメソッドをオーバーライドする必要があります。
 *
 *  @return イベントリスナー
 */
EventListener* BaseLayer::clone() {
	return this;
}


