//
//  PlayerTeleportEntity.h
//  hateru
//
//  Created by HaraKazunari on 2016/08/16.
//
//

#ifndef PlayerTeleportEntity_h
#define PlayerTeleportEntity_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// プレイヤーテレポートEntity
class PlayerTeleportEntity final: public Ref {
public:
	
	/// 名前
	string name;
	/// マップId
	int mapId;
	/// 設置マップId
	vector<int> mapIds;
	/// 設置マップX
	vector<int> mapXs;
	/// 設置マップY
	vector<int> mapYs;
	
private:
	
};

#endif /* PlayerTeleportEntity_h */
