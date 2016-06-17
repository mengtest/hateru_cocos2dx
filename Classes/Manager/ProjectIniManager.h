//
//  ProjectIniManager.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#ifndef ProjectIniManager_h
#define ProjectIniManager_h

#include "BaseManager.h"
#include "ProjectIniEntity.h"

/// Project.iniマネージャ
class ProjectIniManager final: BaseManager {
public:
	
	/**
	 *  読み込み
	 *
	 *  @return 取得データ
	 */
	static ProjectIniEntity load();
	
private:
	
	/**
	 *  コンストラクタ
	 */
	ProjectIniManager() {}
	
	/**
	 *  デストラクタ
	 */
	~ProjectIniManager() {}
};

#endif /* ProjectIniManager_h */
