//
//  StringUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "StringUtil.h"

/**
 *  文字分割
 *
 *  @param result    分割文字
 *  @param inStr     入力文字列
 *  @param delimiter デリミタ
 */
void StringUtil::split(vector<string> &result, const string &inStr, const string &delim) {
	
	result.clear();
	
	using string = std::string;
	string::size_type pos = 0;
	
	while (pos != string::npos) {
		string::size_type p = inStr.find(delim, pos);
		
		if (p == string::npos) {
			result.push_back(inStr.substr(pos));
			break;
		} else {
			result.push_back(inStr.substr(pos, p - pos));
		}
		pos = p + delim.size();
	}
}

/**
 *  バッファから文字列作成
 *
 *  @param data データ
 *  @param len  データ長
 *
 *  @return コピー後文字列
 */
string StringUtil::copyBuff(const unsigned char *data, size_t len) {
	char *buff = (char*)malloc(len + 1);
	memset(buff, 0x00, len + 1);
	memcpy(buff, data, len);
	string inStr = buff;
	free(buff);
	return inStr;
}
