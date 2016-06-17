//
//  StringUtil.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#ifndef StringUtil_h
#define StringUtil_h

#include <stdio.h>

using namespace std;

/// 文字ユーティリティ
class StringUtil final {
public:
	
	/**
	 *  文字分割
	 *
	 *  @param result    分割文字
	 *  @param inStr     入力文字列
	 *  @param delimiter デリミタ
	 */
	static void split(vector<string> &result, const string &inStr, const string &delimiter);
	
	/**
	 *  バッファから文字列作成
	 *
	 *  @param data データ
	 *  @param len  データ長
	 *
	 *  @return コピー後文字列
	 */
	static string copyBuff(const unsigned char *data, size_t len);
	
private:
	
	/**
	 *  コンストラクタ
	 */
	StringUtil() {}
	
	/**
	 *  デストラクタ
	 */
	~StringUtil() {}
};

#endif /* StringUtil_h */
