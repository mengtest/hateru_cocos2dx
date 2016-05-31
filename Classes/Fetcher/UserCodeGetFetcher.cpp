//
//  UserCodeGetFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/06/01.
//
//

#include "UserCodeGetFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
std::string UserCodeGetFetcher::url() {
	return UrlConst::domainName + "/user_code_get";
}

