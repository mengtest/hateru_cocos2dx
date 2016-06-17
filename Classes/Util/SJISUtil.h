//
//  SJISUtil.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/17.
//
//

#ifndef SJISUtil_h
#define SJISUtil_h

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/// SJISユーティリティ
class SJISUtil final: public Ref {
public:
	
	/**
	 *  SJISをUTF8に変換
	 *
	 *  @param buff     入力バッファ
	 *  @param buffLen  入力長
	 *
	 *  @return 変換後文字
	 */
	static string convertUTF8(const unsigned char *buff, const size_t buffLen);
	
private:
	
};

#endif /* SJISUtil_h */
