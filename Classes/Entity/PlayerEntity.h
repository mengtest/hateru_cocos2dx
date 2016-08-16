//
//  PlayerEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerEntity_h
#define PlayerEntity_h

#include "cocos2d.h"

#include "PlayerUnitEntity.h"

USING_NS_CC;
using namespace std;

/// プレイヤーEntity
class PlayerEntity: public Ref {
public:
	
	/// 所持金
	int money;
	
	/// ユニット
	vector<PlayerUnitEntity *>units;
	
	/// マップId
	int mapId;
	/// X座標
	int mapX;
	/// Y座標
	int mapY;
	
	/// テレポート情報
	
	
	
private:
	
};

#endif /* PlayerEntity_h */
