//
//  CharaSendFetcher.cpp
//  hateru
//
//  Created by HaraKazunari on 2016/03/26.
//
//

#include "CharaSendFetcher.h"
#include "UrlConst.h"

/**
 *  URL取得
 *
 *  @return URL
 */
std::string CharaSendFetcher::url() {
	return UrlConst::domainName + "/chara_send";
}

