//
//  PlayerItemEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerItemEntity_h
#define PlayerItemEntity_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// プレイヤーアイテムEntity
class PlayerItemEntity final: public Ref {
public:
	
	/// アイテムID
	int Id;
	/// 使用回数
	int useCount;
	/// アイテムID
	string itemId;
	
private:
	
};

#endif /* PlayerItemEntity_h */
