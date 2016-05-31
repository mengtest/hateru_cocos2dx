//
//  ItemExchangeConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/03/29.
//
//

#ifndef ItemExchangeConst_h
#define ItemExchangeConst_h

#include <stdio.h>

/// レイヤーの基底クラス
class ItemExchangeConst final {
public:
	
	/// 交換タイプ 交換
	static const std::string exchangeTypeExchange;
	/// 交換タイプ 譲渡
	static const std::string exchangeTypeTransfer;
	
private:
	
	/**
	 *  コンストラクタ
	 */
	ItemExchangeConst();
	
};

#endif /* ItemExchangeConst_h */
