//
//  GameConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameConst_h
#define GameConst_h

/// ステータス
typedef enum{
	STATUS_TYPE_LV			=	0,	/// レベル
	STATUS_TYPE_MAXHP,				/// 最大HP
	STATUS_TYPE_HP,					/// HP
	STATUS_TYPE_MAXMP,				/// 最大MP
	STATUS_TYPE_MP,					/// MP
	STATUS_TYPE_ATTACK_NORMAL,		/// 攻撃力(総合)
	STATUS_TYPE_ATTACK_FIRE,		/// 攻撃力(炎)
	STATUS_TYPE_ATTACK_WATER,		/// 攻撃力(水)
	STATUS_TYPE_ATTACK_EARTH,		/// 攻撃力(木)
	STATUS_TYPE_ATTACK_SHINE,		/// 攻撃力(光)
	STATUS_TYPE_ATTACK_DARK,		/// 攻撃力(闇)
	STATUS_TYPE_DEFENCE_NORMAL,		/// 防御力(総合)
	STATUS_TYPE_DEFENCE_FIRE,		/// 防御力(炎)
	STATUS_TYPE_DEFENCE_WATER,		/// 防御力(水)
	STATUS_TYPE_DEFENCE_EARTH,		/// 防御力(木)
	STATUS_TYPE_DEFENCE_SHINE,		/// 防御力(光)
	STATUS_TYPE_DEFENCE_DARK,		/// 防御力(闇)
	STATUS_TYPE_SPEED,				/// スピード
	STATUS_TYPE_EXP,				/// 経験値
	STATUS_TYPE_CRITICAL,			/// クリティカル率
	STATUS_TYPE_STATE,				/// 状態
	STATUS_TYPE_MONEY,				/// 所持金
	STATUS_TYPE_MORAL,				/// 道徳
	STATUS_TYPE_POPULAR,			/// 知名度
	STATUS_TYPE_FRIEND				/// フレンド
} STATUS_TYPE;

/// 属性
typedef enum {
	ATTRIBUTE_TYPE_NORMAL	=	0,	/// ノーマル
	ATTRIBUTE_TYPE_FIRE	,			/// 火
	ATTRIBUTE_TYPE_WATER,			/// 水
	ATTRIBUTE_TYPE_EARTH,			/// 大地
	ATTRIBUTE_TYPE_SHINE,			/// 光
	ATTRIBUTE_TYPE_DARK,			/// 闇
} ATTRIBUTE_TYPE;

/// 状態治療
typedef enum {
	CONDITION_TYPE_NONE	=	0,	/// なし
	CONDITION_TYPE_DIE,			/// 戦闘不能
	CONDITION_TYPE_POISON,		/// 毒
	CONDITION_TYPE_DARKNESS,	/// 暗闇
	CONDITION_TYPE_SILENCE,		/// 沈黙
	CONDITION_TYPE_CONFUSION,	/// 混乱
	CONDITION_TYPE_SLEEP,		/// 睡眠
	CONDITION_TYPE_PARRAY,		/// 麻痺
} CONDITION_TYPE;

#pragma mark - マップ

/// 地図端制御タイプ
typedef enum {
	MAP_END_TYPE_NONE		=	0,	/// 制御なし
	MAP_END_TYPE_FIXTATION,			/// 固定
	MAP_END_TYPE_LOOP,				/// ループ
} MAP_END_TYPE;

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
	ADDSTATUS_TYPE_MAXHP    =    0,	/// 最大HP
	ADDSTATUS_TYPE_MAXMP,			/// 最大MP
	ADDSTATUS_TYPE_ATTACK_NORMAL,	/// 攻撃力(総合)
	ADDSTATUS_TYPE_DEFENCE_NORMAL,	/// 防御力(総合)
	ADDSTATUS_TYPE_SPEED,			/// スピード
	ADDSTATUS_TYPE_EXP,				/// レベルアップ経験値
} ADDSTATUS_TYPE;

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

#pragma mark - 特殊技能

/// 特殊技能種別
typedef enum {
	SKILL_TYPE_ATTACK		=	0,	/// 攻撃
	SKILL_TYPE_RECVARY,				/// 回復
	SKILL_TYPE_TELEPORT,			/// テレポート
	SKILL_TYPE_ESCAPE,				/// エスケープ
	SKILL_TYPE_MAP,					/// 地図
} SKILL_TYPE;

#pragma mark - 変数

/// 変数変化増減タイプ
typedef enum {
	VARIABLE_ZG_TYPE_EQUAL	=	0,	///	イコール
	VARIABLE_ZG_TYPE_ADD,			///	増
	VARIABLE_ZG_TYPE_SUB,			///	減
} VARIABLE_ZG_TYPE;

#endif /* GameConst_h */
