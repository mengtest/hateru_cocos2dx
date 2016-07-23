//
//  GameConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameConst_h
#define GameConst_h

/// ステータスタイプ
typedef enum {
	UnitStatusTypeLv = 0,		/// LV
	UnitStatusTypeJob,			/// 職業
	UnitStatusTypeHP,			/// HP
	UnitStatusTypeMP,			/// MP
	UnitStatusTypeMaxHP,		/// 最大HP
	UnitStatusTypeMaxMP,		/// 最大MP
	UnitStatusTypeAttack,		/// 攻撃力
	UnitStatusTypeMental,		/// 精神力
	UnitStatusTypeDefence,		/// 防御力
	UnitStatusTypeSpeed,		/// 機敏さ
	UnitStatusTypeEXP,			/// 経験値
	UnitStatusTypeFame,			/// 名声
	UnitStatusTypeMoral,		/// 道徳心
	UnitStatusTypeHPEq,			/// 装備後HP
	UnitStatusTypeMPEq,			/// 装備後MP
	UnitStatusTypeAttackEq,		/// 装備後攻撃力
	UnitStatusTypeMentalEq,		/// 装備後精神力
	UnitStatusTypeDefenceEq,	/// 装備後防御力
	UnitStatusTypeSpeedEq,		/// 装備後機敏さ
	UnitStatusTypeFireEq,		/// 装備後炎耐性
	UnitStatusTypeIceEq,		/// 装備後氷耐性
	UnitStatusTypeThunderEq,	/// 装備後雷耐性
	UnitStatusTypePoisonEq,		/// 装備後毒耐性
	UnitStatusTypeNextEXP,		/// 次のレベルまでの経験値
	UnitStatusTypeFameEq,		/// 装備後名声
	UnitStatusTypeMoralEq,		/// 装備後道徳心
	UnitStatusTypeHitRate,		/// 命中率
	UnitStatusTypeCriticalRate,	/// 必殺率
	UnitStatusTypeMoney,		/// 所持金(ステータス分岐用)
	UnitStatusTypeDirection,	/// 方向(ステータス分岐用)
} UnitStatusType;

/// 状態治療
typedef enum {
	ConditionTypeNone = 0,		/// なし
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
	AttackAttributeTypeNone = 0,	/// なし
	AttackAttributeTypeBlow,		/// 打撃
	AttackAttributeTypeFire,		/// 炎
	AttackAttributeTypeIce,			/// 氷
	AttackAttributeTypeThunder,		/// 雷
	AttackAttributeTypePoison,		/// 毒
} AttackAttributeType;

#pragma mark - マップ

/// マップタイプ
typedef enum {
	MapTypeNormal = 0,				/// 通常
	MapTypeAuto						/// 自動
} MapType;

/// 地図端制御タイプ
typedef enum {
	MapLoopTypeNone = 0,			/// 制御なし
	MapLoopTypeFixtation,			/// 固定
	MapLoopTypeLoop,				/// ループ
} MapLoopType;

/// 移動タイプ
typedef enum {
	MoveTypeWalk = 0,				/// 歩行
	MoveTypeShip,					/// 船
	MoveTypeFlyShip,				/// 飛行船
} MoveType;

/// 乗り物タイプ
typedef enum {
	VehicleTypeShip = 0,			/// 船
	VehicleTypeFlyShip,				/// 飛行船
} VehicleType;

#pragma mark - 自動マップ

/// 下チップタイプ
typedef enum {
	AutoMapDownChipTypeFloor = 1,		/// 床
	AutoMapDownChipTypeWallShadow,		/// 壁(影有)
	AutoMapDownChipTypeWall,			/// 壁(影無)
} AutoMapDownChipType;

/// 上チップタイプ
typedef enum {
	AutoMapUpChipTypeBelowStairs = 1,	/// 下階段
	AutoMapUpChipTypeAboveStairs,		/// 上階段
	AutoMapUpChipTypeChest,				/// 宝箱
} AutoMapUpChipType;

/// イベントタイプ
typedef enum {
	AutoMapEventTypeBelowStairs = 1,	/// 下階段
	AutoMapEventTypeAboveStairs,		/// 上階段
	AutoMapEventTypeChest,				/// 宝箱
} AutoMapEventType;

#pragma mark - イベント

/// イベントタイプ
typedef enum {
	EventTypeMessage = 0,				///	メッセージ表示
	EventTypeFluctuateHP	,			///	HP増減
	EventTypeFluctuateMP	,			///	MP増減
	EventTypeFluctuateGold	,			///	所持金増減
	EventTypeFluctuateEXP	,			///	経験値増減
	EventTypeFluctuateItem	,			///	アイテム増減
	EventTypeOperateVariable,			///	変数操作
	EventTypeChangeBGM		,			///	BGM変更
	EventTypeChangeChip		,			///	マップチップ変更
	EventTypeChangeUnit		,			///	キャラ変更
	EventTypeMoveLocation	,			///	場所移動
	EventTypeIfVariable		,			///	変数分岐
	EventTypeSave			,			///	セーブ
	EventTypeItemShop		,			///	道具屋
	EventTypeINN			,			///	宿屋
	EventTypeCloakroom		,			///	預り所
	EventTypeChurch			,			///	教会
	EventTypeBattle			,			///	戦闘
	EventTypeFluctuateTeleport,			///	テレポート位置増減
	EventTypeChangeTeleport	,			///	テレポート禁止変更
	EventTypeChangeEscape	,			///	エスケープ禁止変更
	EventTypeWipe			,			///	ワイプ
	EventTypeExchangeUnit	,			///	メンバー入替
	EventTypeEndIf			,			///	変数分岐終了
	EventTypeShowImage		,			///	画像表示
	EventTypeChangeJob		,			///	職業変更
	EventTypeIfStatus		,			///	ステータス分岐
	EventTypeIfItem			,			///	アイテム分岐
	EventTypeIfSkill		,			///	特殊技能分岐
	EventTypeEncountRate	,			///	敵出現率
	EventTypeSaveEscapeLocation,		///	エスケープで戻る位置を保存
	EventTypeSettingShip	,			///	船設定
	EventTypeExit			,			///	イベント終了
	EventTypeSelectYesNo	,			///	YESNO選択
	EventTypeMoveMobUnit	,			///	キャラ移動
	EventTypeMoveUnit		,			///	主人公移動
	EventTypeGettingOnOff	,			///	船乗降り
	EventTypeMixShop		,			///	調合屋
	EventTypeIfTime			,			///	リアルタイム分岐
	EventTypeBar			,			///	酒場
	EventTypeItemBazaar		,			///	バザー
	EventTypeBBS			,			///	掲示板
	EventTypeIfTerminal		,			///	機種判別
	EventTypeJingle			,			///	ジングル
	EventTypeRandom			,			///	乱数
} EventType;

/// 増減タイプ
typedef enum {
	FluctuateTypeIncrease = 0,			/// 増
	FluctuateTypeDecline				/// 減
} FluctuateType;

/// サウンドフィールドタイプ
typedef enum {
	SoundFieldTypeMap = 0,				/// マップ
	SoundFieldTypeBattle,				/// 戦闘
} SoundFieldType;

/// 分岐式
typedef enum {
	IfFormulaTypeEqual = 0,				/// ＝
	IfFormulaTypeNotEqual,				/// ≠
	IfFormulaTypeLessThan,				/// ＜
	IfFormulaTypeGreaterThan,			/// ＞
	IfFormulaTypeLessThanEqual,			/// ≦
	IfFormulaTypeGreaterThanEqual,		/// ≧
} IfFormulaType;

/// メンバーチェンジタイプ
typedef enum {
	ExchangeUnitTypeRemove = 0,			/// 外す
	ExchangeUnitTypeAdd,				/// 追加
	ExchangeUnitTypeShift,				/// 入替
} ExchangeUnitType;

/// イベント移動タイプ
typedef enum {
	EventMoveTypeMoveUp = 0,			/// 上移動
	EventMoveTypeMoveRight,				/// 右移動
	EventMoveTypeMoveDown,				/// 下移動
	EventMoveTypeMoveLeft,				/// 左移動
	EventMoveTypeFaceUp,				/// 上向き
	EventMoveTypeFaceRight,				/// 右向き
	EventMoveTypeFaceDown,				/// 下向き
	EventMoveTypeFaceLeft,				/// 左向き
	EventMoveTypeLoop,					/// ループ
	EventMoveTypeMoveCount,				/// 移動頻度
} EventMoveType;

/// 日時タイプ
typedef enum {
	DateTimeTypeMonth = 0,				/// 月
	DateTimeTypeDay,					/// 日
	DateTimeTypeHour,					/// 時
	DateTimeTypeMinute,					/// 分
	DateTimeTypeSecond,					/// 秒
	DateTimeTypeWeek,					/// 週
} DateTimeType;

/// イベント開始タイプ
typedef enum {
	EventInitConditionTypeKey = 0,		/// キー
	EventInitConditionTypeLeave,		/// 離れたら
	EventInitConditionTypeTouch,		/// 触れたら
	EventInitConditionTypeAuto,			/// 自動
} EventInitConditionType;

/// イベント詳細移動タイプ
typedef enum {
	EventDetailMoveTypeNoMove = 0,		/// 動かない
	EventDetailMoveTypeRandom,			/// ランダム
	EventDetailMoveTypeNear,			/// 主人公に近づく
	EventDetailMoveTypeFar,				/// 主人公から離れる
	EventDetailMoveTypeSet,				/// 詳細設定
} EventDetailMoveType;


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
	ItemTypeNormal	=	0,			/// 通常
	ItemTypeWeapon,					/// 武器
	ItemTypeArmar,					/// 鎧
	ItemTypeShield,					/// 盾
	ItemTypeHelm,					/// 兜
	ItemTypeAccess,					/// 装飾品
	ItemTypeRecovery,				/// 回復
	ItemTypeSeed,					/// 種
	ItemTypeMap,					/// 地図
	ItemTypeJob,					/// 職業変更
	ItemTypeSkill,					/// 特技追加
} ItemType;

/// アイテムステータス種別
typedef enum {
	ItemStatusTypeNothing = 0,		/// 影響なし
	ItemStatusTypeHP,				/// 最大HPに影響
	ItemStatusTypeMP,				/// 最大MPに影響
	ItemStatusTypeAttack,			/// 攻撃力に影響
	ItemStatusTypeMental,			/// 精神力に影響
	ItemStatusTypeDefence,			/// 防御力に影響
	ItemStatusTypeSpeed,			/// 機敏性に影響
	ItemStatusTypeFire,				/// 炎耐性に影響
	ItemStatusTypeIce,				/// 氷耐性に影響
	ItemStatusTypeThunder,			/// 雷耐性に影響
	ItemStatusTypePoison,			/// 毒耐性に影響
	ItemStatusTypeHitCount,			/// ヒット回数
	ItemStatusTypeFame,				/// 名声
	ItemStatusTypeMoral,			/// 道徳心
	ItemStatusTypeHitRate,			/// 命中率
	ItemStatusTypeCriticalRate,		/// 必殺率
} ItemStatusType;

#pragma mark - 特殊技能

/// 特殊技能種別
typedef enum {
	SkillTypeAttack		=	0,		/// 攻撃
	SkillTypeRecvary,				/// 回復
	SkillTypeTeleport,				/// テレポート
	SkillTypeEscape,				/// エスケープ
	SkillTypeMap,					/// 地図
} SkillType;

/// 効果範囲
typedef enum {
	EffectRangeTypeUser	=	0,		/// 使用者
	EffectRangeTypeSingle,			/// 単体
	EffectRangeTypeAll,				/// 全員
} EffectRangeType;

#pragma mark - 変数

/// 変数変化増減タイプ
typedef enum {
	VariableOperateTypeAssignment = 0,	///	代入
	VariableOperateTypeIncrease,		///	増
	VariableOperateTypeDecline,			///	減
} VariableOperateType;

#pragma mark - サウンド

/// 初期メンバーカウント
#define INIT_MEMBER_COUNT 3

/// マップチップ最大数
#define MAPCHIP_VALUE_MAX 63

#endif /* GameConst_h */
