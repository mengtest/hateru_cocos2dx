//
//  EncryptUtil.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/08/19.
//
//

#include "EncryptUtil.h"

#include <iostream>
#include <iomanip>
#include "openssl/md5.h"

#include "EncryptConst.h"


/**
 *  ハッシュ化
 *
 *  @param inStr 入力文字列
 *
 *  @return ハッシュ値
 */
string EncryptUtil::hash(const string &inStr) {
	unsigned char md5[MD5_DIGEST_LENGTH];
	MD5((unsigned char*)(inStr.c_str()), inStr.length(), md5);
	string result = "";
	ostringstream ostr;
	for (auto i = 0; i < MD5_DIGEST_LENGTH; i++) {
		result += StringUtils::format("%02x", md5[i]);
	}
	return result;
}

/**
 *  暗号化
 *
 *  @param inStr 入力文字列
 *
 *  @return 暗号化文字列
 */
string EncryptUtil::encrypt(const string &inStr) {
	return "";
}

/**
 *  復号化
 *
 *  @param inStr 入力文字列
 *
 *  @return 復号化文字列
 */
string EncryptUtil::decrypt(const string &inStr) {
	return "";
}
