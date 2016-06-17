//
//  NamesEntity.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/18.
//
//

#include "NamesEntity.h"

#include "SJISUtil.h"
#include "StringUtil.h"

/**
 *  バイナリデータよりEntity作成
 *
 *  @param data バイナリデータ
 *  @param len  データ長
 *
 *  @return Entity
 */
NamesEntity NamesEntity::convertData(const unsigned char *data, size_t len) {
	
	auto entity = NamesEntity();
	
	// UTF8に変換
	string inStr = SJISUtil::convertUTF8(data, len);

	// 分割
	vector<string> line;
	StringUtil::split(line, inStr, "\r\n");
	for (auto it = line.begin(); it != line.end(); it++) {
		if (it->length() <= 0) {
			continue;
		}
//		auto utf8Str = SJISUtil::convertUTF8((unsigned char *)it->c_str(), it->length());
		entity.names.push_back(*it);
	}
	
	return entity;
}