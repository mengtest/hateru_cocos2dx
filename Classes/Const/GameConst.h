//
//  GameConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameConst_h
#define GameConst_h

/// 状態治療
typedef enum {
	ConditionTypeNone	=	0,	/// なし
	ConditionTypeDie,			/// 戦闘不能
	ConditionTypePoison,		/// 毒
	ConditionTypeDarkness,		/// 暗闇
	ConditionTypeSilence,		/// 沈黙
	ConditionTypeConfusion,		/// 混乱
	ConditionTypeSleep,			/// 睡眠
	ConditionTypeParray,		/// 麻痺
} ConditionType;

/// 攻撃属性
typedef enum {
	AttackAttributeTypeNone	=	0,	/// なし
	AttackAttributeTypeBlow,		/// 打撃
	AttackAttributeTypeFire,		/// 炎
	AttackAttributeTypeIce,			/// 氷
	AttackAttributeTypeThunder,		/// 雷
	AttackAttributeTypePoison,		/// 毒
} AttackAttributeType;

#pragma mark - マップ

/// マップタイプ
typedef enum {
	MapTypeNormal			=	0,	/// 通常
	MapTypeAuto						/// 自動
} MapType;

/// 地図端制御タイプ
typedef enum {
	MapLoopTypeNone			=	0,	/// 制御なし
	MapLoopTypeFixtation,			/// 固定
	MapLoopTypeLoop,				/// ループ
} MapLoopType;

#pragma mark - イベント

/// イベントタイプ
typedef enum {
	EVENT_TYPE_BUNSYO	=	0,		///	文章表示
	EVENT_TYPE_HP_ZG	,			///	HP増減
	EVENT_TYPE_MP_ZG	,			///	MP増減
	EVENT_TYPE_KANE_ZG	,			///	所持金増減
	EVENT_TYPE_EXP_ZG	,			///	経験値増減
	EVENT_TYPE_ITEM_ZG	,			///	アイテム増減
	EVENT_TYPE_NUM		,			///	変数操作
	EVENT_TYPE_BGM		,			///	BGM変更
	EVENT_TYPE_CHGCHIP	,			///	マップチップ変更
	EVENT_TYPE_CHGCHARA	,			///	キャラ変更
	EVENT_TYPE_IDO		,			///	場所移動
	EVENT_TYPE_IF_NUM	,			///	変数分岐
	EVENT_TYPE_SAVE		,			///	セーブ
	EVENT_TYPE_DOGUYA	,			///	道具屋
	EVENT_TYPE_YADOYA	,			///	宿屋
	EVENT_TYPE_ADUKARIYA,			///	預り所
	EVENT_TYPE_KYOKAI	,			///	教会
	EVENT_TYPE_BATTLE	,			///	戦闘
	EVENT_TYPE_TELEZG	,			///	テレポート位置増減
	EVENT_TYPE_TELEKH	,			///	テレポート禁止変更
	EVENT_TYPE_ESCAPEKH	,			///	エスケープ禁止変更
	EVENT_TYPE_WIPE		,			///	ワイプ
	EVENT_TYPE_MENBER	,			///	メンバー入替
	EVENT_TYPE_ENDIF	,			///	変数分岐終了
	EVENT_TYPE_SHOWIMG	,			///	画像表示
	EVENT_TYPE_CHGJOB	,			///	職業変更
	EVENT_TYPE_IF_STS	,			///	ステータス分岐
	EVENT_TYPE_IF_ITEM	,			///	アイテム分岐
	EVENT_TYPE_IF_WAZA	,			///	特殊技能分岐
	EVENT_TYPE_ENERITU	,			///	敵出現率
	EVENT_TYPE_ESCAPESAVE,			///	エスケープで戻る位置を保存
	EVENT_TYPE_SETSHIP	,			///	船設定
	EVENT_TYPE_EXIT		,			///	イベント終了
	EVENT_TYPE_YESNO	,			///	YESNO選択
	EVENT_TYPE_CHARAIDO	,			///	キャラ移動
	EVENT_TYPE_SYUIDO	,			///	主人公移動
	EVENT_TYPE_NORIORI	,			///	船乗降り
	EVENT_TYPE_TYOGO	,			///	調合屋
	EVENT_TYPE_IF_TIME	,			///	リアルタイム分岐
	EVENT_TYPE_SAKABA	,			///	酒場
	EVENT_TYPE_ITEMBAZA	,			///	バザー
	EVENT_TYPE_BBS		,			///	掲示板
	EVENT_TYPE_IF_TERM	,			///	機種判別
	EVENT_TYPE_JINGLE	,			///	ジングル
	EVENT_TYPE_RAND		,			///	乱数
} EVENT_TYPE;

#pragma mark - 職業

/// 最大レベル
#define MAX_LEVEL		99

/// レベルアップ時のステータスタイプ
typedef enum {
	AddStatusTypeMaxHP = 0,			/// 最大HP
	AddStatusTypeMaxMP,				/// 最大MP
	AddStatusTypeAttack,			/// 攻撃力
	AddStatusTypeMental,			/// 精神力
	AddStatusTypeDefence,			/// 防御力
	AddStatusTypeSpeed,				/// スピード
	AddStatusTypeEXP,				/// レベルアップ経験値
} AddStatusType;

#pragma mark - アイテム

/// アイテム種別
typedef enum {
	ITEM_TYPE_NORMAL	=	0,		/// 通常
	ITEM_TYPE_WEAPON,				/// 武器
	ITEM_TYPE_ARMAR,				/// 鎧
	ITEM_TYPE_SHIELD,				/// 盾
	ITEM_TYPE_HELM,					/// 兜
	ITEM_TYPE_ACCESS,				/// 装飾品
	ITEM_TYPE_RECOVERY,				/// 回復
	ITEM_TYPE_SEED,					/// 種
	ITEM_TYPE_MAP,					/// 地図
	ITEM_TYPE_JOB,					/// 職業変更
	ITEM_TYPE_SKILL,				/// 特技追加
} ITEM_TYPE;

/// アイテムステータス種別
typedef enum {
	ITEM_STATUS_TYPE_NOTHING = 0,	/// 影響なし
	ITEM_STATUS_TYPE_HP,			/// 最大HPに影響
	ITEM_STATUS_TYPE_MP,			/// 最大MPに影響
	ITEM_STATUS_TYPE_ATTACK,		/// 攻撃力に影響
	ITEM_STATUS_TYPE_MENTAL,		/// 精神力に影響
	ITEM_STATUS_TYPE_DEFENCE,		/// 防御力に影響
	ITEM_STATUS_TYPE_SPEED,			/// 機敏性に影響
	ITEM_STATUS_TYPE_FIRE,			/// 炎耐性に影響
	ITEM_STATUS_TYPE_ICE,			/// 氷耐性に影響
	ITEM_STATUS_TYPE_THUNDER,		/// 雷耐性に影響
	ITEM_STATUS_TYPE_POISON,		/// 毒耐性に影響
	ITEM_STATUS_TYPE_HITCOUNT,		/// ヒット回数
	ITEM_STATUS_TYPE_FAME,			/// 名声
	ITEM_STATUS_TYPE_MORAL,			/// 道徳心
	ITEM_STATUS_TYPE_HITRATE,		/// 命中率
	ITEM_STATUS_TYPE_CRITICALRATE,	/// 必殺率
} ITEM_STATUS_TYPE;

#pragma mark - 特殊技能

/// 特殊技能種別
typedef enum {
	SKILL_TYPE_ATTACK		=	0,	/// 攻撃
	SKILL_TYPE_RECVARY,				/// 回復
	SKILL_TYPE_TELEPORT,			/// テレポート
	SKILL_TYPE_ESCAPE,				/// エスケープ
	SKILL_TYPE_MAP,					/// 地図
} SKILL_TYPE;

/// 効果範囲
typedef enum {
	EFFECT_RANGE_TYPE_USER	=	0,	/// 使用者
	EFFECT_RANGE_TYPE_SINGLE,		/// 単体
	EFFECT_RANGE_TYPE_ALL,			/// 全員
} EFFECT_RANGE_TYPE;

#pragma mark - 変数

/// 変数変化増減タイプ
typedef enum {
	VARIABLE_ZG_TYPE_EQUAL	=	0,	///	イコール
	VARIABLE_ZG_TYPE_ADD,			///	増
	VARIABLE_ZG_TYPE_SUB,			///	減
} VARIABLE_ZG_TYPE;

/// 初期メンバーカウント
#define INIT_MEMBER_COUNT 3

/// マップチップ最大数
#define MAPCHIP_VALUE_MAX 63

#endif /* GameConst_h */
