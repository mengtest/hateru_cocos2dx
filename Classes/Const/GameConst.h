//
//  GameConst.h
//  hateru
//
//  Created by HaraKazunari on 2016/06/04.
//
//

#ifndef GameConst_h
#define GameConst_h

/// パーティ数
#define MAX_PARTY			3
/// 最大装備数
#define MAX_UNIT_STATUS		5
/// 最大スキル数
#define MAX_UNIT_SKILL		24
/// 最大アイテム数
#define MAX_UNIT_ITEM		16

#pragma mark - ユニット

/// ステータスタイプ
typedef enum {
	/// LV
	UnitStatusTypeLv = 0,
	/// 職業
	UnitStatusTypeJob,
	/// HP
	UnitStatusTypeHP,
	/// MP
	UnitStatusTypeMP,
	/// 最大HP
	UnitStatusTypeMaxHP,
	/// 最大MP
	UnitStatusTypeMaxMP,
	/// 攻撃力
	UnitStatusTypeAttack,
	/// 精神力
	UnitStatusTypeMental,
	/// 防御力
	UnitStatusTypeDefence,
	/// 機敏さ
	UnitStatusTypeSpeed,
	/// 経験値
	UnitStatusTypeEXP,
	/// 名声
	UnitStatusTypeFame,
	/// 道徳心
	UnitStatusTypeMoral,
	/// 装備後HP
	UnitStatusTypeHPEq,
	/// 装備後MP
	UnitStatusTypeMPEq,
	/// 装備後攻撃力
	UnitStatusTypeAttackEq,
	/// 装備後精神力
	UnitStatusTypeMentalEq,
	/// 装備後防御力
	UnitStatusTypeDefenceEq,
	/// 装備後機敏さ
	UnitStatusTypeSpeedEq,
	/// 装備後炎耐性
	UnitStatusTypeFireEq,
	/// 装備後氷耐性
	UnitStatusTypeIceEq,
	/// 装備後雷耐性
	UnitStatusTypeThunderEq,
	/// 装備後毒耐性
	UnitStatusTypePoisonEq,
	/// 次のレベルまでの経験値
	UnitStatusTypeNextEXP,
	/// 装備後名声
	UnitStatusTypeFameEq,
	/// 装備後道徳心
	UnitStatusTypeMoralEq,
	/// 命中率
	UnitStatusTypeHitRate,
	/// 必殺率
	UnitStatusTypeCriticalRate,
	/// 所持金(ステータス分岐用)
	UnitStatusTypeMoney,
	/// 方向(ステータス分岐用)
	UnitStatusTypeDirection,
} UnitStatusType;

/// 装備タイプ
typedef enum {
	/// 武器
	EquipmentTypeWeapon = 0,
	/// 防具
	EquipmentTypeArmar,
	/// 盾
	EquipmentTypeShield,
	/// 兜
	EquipmentTypeHelm,
	/// 装飾品
	EquipmentTypeAccessory,
} EquipmentType;

/// 状態治療
typedef enum {
	/// なし
	ConditionTypeNone = 0,
	/// 戦闘不能
	ConditionTypeDie,
	/// 毒
	ConditionTypePoison,
	/// 暗闇
	ConditionTypeDarkness,
	/// 沈黙
	ConditionTypeSilence,
	/// 混乱
	ConditionTypeConfusion,
	/// 睡眠
	ConditionTypeSleep,
	/// 麻痺
	ConditionTypeParray,
} ConditionType;

/// 攻撃属性
typedef enum {
	/// なし
	AttackAttributeTypeNone = 0,
	/// 打撃
	AttackAttributeTypeBlow,
	/// 炎
	AttackAttributeTypeFire,
	/// 氷
	AttackAttributeTypeIce,
	/// 雷
	AttackAttributeTypeThunder,
	/// 毒
	AttackAttributeTypePoison,
} AttackAttributeType;

#pragma mark - マップ

/// マップタイプ
typedef enum {
	/// 通常
	MapTypeNormal = 0,
	/// 自動
	MapTypeAuto
} MapType;

/// 地図端制御タイプ
typedef enum {
	/// 制御なし
	MapLoopTypeNone = 0,
	/// 固定
	MapLoopTypeFixtation,
	/// ループ
	MapLoopTypeLoop,
} MapLoopType;

/// 移動タイプ
typedef enum {
	/// 歩行
	MoveTypeWalk = 0,
	/// 船
	MoveTypeShip,
	/// 飛行船
	MoveTypeFlyShip,
} MoveType;

/// 乗り物タイプ
typedef enum {
	/// 船
	VehicleTypeShip = 0,
	/// 飛行船
	VehicleTypeFlyShip,
} VehicleType;

#pragma mark - 自動マップ

/// 下チップタイプ
typedef enum {
	/// 床
	AutoMapDownChipTypeFloor = 1,
	/// 壁(影有)
	AutoMapDownChipTypeWallShadow,
	/// 壁(影無)
	AutoMapDownChipTypeWall,
} AutoMapDownChipType;

/// 上チップタイプ
typedef enum {
	/// 下階段
	AutoMapUpChipTypeBelowStairs = 1,
	/// 上階段
	AutoMapUpChipTypeAboveStairs,
	/// 宝箱
	AutoMapUpChipTypeChest,
} AutoMapUpChipType;

/// イベントタイプ
typedef enum {
	/// 下階段
	AutoMapEventTypeBelowStairs = 1,
	/// 上階段
	AutoMapEventTypeAboveStairs,
	/// 宝箱
	AutoMapEventTypeChest,
} AutoMapEventType;

#pragma mark - イベント

/// イベントタイプ
typedef enum {
	///	メッセージ表示
	EventTypeMessage = 0,
	///	HP増減
	EventTypeFluctuateHP	,
	///	MP増減
	EventTypeFluctuateMP	,
	///	所持金増減
	EventTypeFluctuateGold	,
	///	経験値増減
	EventTypeFluctuateEXP	,
	///	アイテム増減
	EventTypeFluctuateItem	,
	///	変数操作
	EventTypeOperateVariable,
	///	BGM変更
	EventTypeChangeBGM		,
	///	マップチップ変更
	EventTypeChangeChip		,
	///	キャラ変更
	EventTypeChangeUnit		,
	///	場所移動
	EventTypeMoveLocation	,
	///	変数分岐
	EventTypeIfVariable		,
	///	セーブ
	EventTypeSave			,
	///	道具屋
	EventTypeItemShop		,
	///	宿屋
	EventTypeINN			,
	///	預り所
	EventTypeCloakroom		,
	///	教会
	EventTypeChurch			,
	///	戦闘
	EventTypeBattle			,
	///	テレポート位置増減
	EventTypeFluctuateTeleport,
	///	テレポート禁止変更
	EventTypeChangeTeleport	,
	///	エスケープ禁止変更
	EventTypeChangeEscape	,
	///	ワイプ
	EventTypeWipe			,
	///	メンバー入替
	EventTypeExchangeUnit	,
	///	変数分岐終了
	EventTypeEndIf			,
	///	画像表示
	EventTypeShowImage		,
	///	職業変更
	EventTypeChangeJob		,
	///	ステータス分岐
	EventTypeIfStatus		,
	///	アイテム分岐
	EventTypeIfItem			,
	///	特殊技能分岐
	EventTypeIfSkill		,
	///	敵出現率
	EventTypeEncountRate	,
	///	エスケープで戻る位置を保存
	EventTypeSaveEscapeLocation,
	///	船設定
	EventTypeSettingShip	,
	///	イベント終了
	EventTypeExit			,
	///	YESNO選択
	EventTypeSelectYesNo	,
	///	キャラ移動
	EventTypeMoveMobUnit	,
	///	主人公移動
	EventTypeMoveUnit		,
	///	船乗降り
	EventTypeGettingOnOff	,
	///	調合屋
	EventTypeMixShop		,
	///	リアルタイム分岐
	EventTypeIfTime			,
	///	酒場
	EventTypeBar			,
	///	バザー
	EventTypeItemBazaar		,
	///	掲示板
	EventTypeBBS			,
	///	機種判別
	EventTypeIfTerminal		,
	///	ジングル
	EventTypeJingle			,
	///	乱数
	EventTypeRandom			,
} EventType;

/// イベントターゲットタイプ　全て
#define EventTargetTypeAll	0

/// 増減タイプ
typedef enum {
	/// 増
	FluctuateTypeIncrease = 0,
	/// 減
	FluctuateTypeDecline
} FluctuateType;

/// サウンドフィールドタイプ
typedef enum {
	/// マップ
	SoundFieldTypeMap = 0,
	/// 戦闘
	SoundFieldTypeBattle,
} SoundFieldType;

/// 分岐式
typedef enum {
	/// ＝
	IfFormulaTypeEqual = 0,
	/// ≠
	IfFormulaTypeNotEqual,
	/// ＜
	IfFormulaTypeLessThan,
	/// ＞
	IfFormulaTypeGreaterThan,
	/// ≦
	IfFormulaTypeLessThanEqual,
	/// ≧
	IfFormulaTypeGreaterThanEqual,
} IfFormulaType;

/// メンバーチェンジタイプ
typedef enum {
	/// 外す
	ExchangeUnitTypeRemove = 0,
	/// 追加
	ExchangeUnitTypeAdd,
	/// 入替
	ExchangeUnitTypeShift,
} ExchangeUnitType;

/// イベント移動タイプ
typedef enum {
	/// 上移動
	EventMoveTypeMoveUp = 0,
	/// 右移動
	EventMoveTypeMoveRight,
	/// 下移動
	EventMoveTypeMoveDown,
	/// 左移動
	EventMoveTypeMoveLeft,
	/// 上向き
	EventMoveTypeFaceUp,
	/// 右向き
	EventMoveTypeFaceRight,
	/// 下向き
	EventMoveTypeFaceDown,
	/// 左向き
	EventMoveTypeFaceLeft,
	/// ループ
	EventMoveTypeLoop,
	/// 移動頻度
	EventMoveTypeMoveCount,
} EventMoveType;

/// 日時タイプ
typedef enum {
	/// 月
	DateTimeTypeMonth = 0,
	/// 日
	DateTimeTypeDay,
	/// 時
	DateTimeTypeHour,
	/// 分
	DateTimeTypeMinute,
	/// 秒
	DateTimeTypeSecond,
	/// 週
	DateTimeTypeWeek,
} DateTimeType;

/// イベント開始タイプ
typedef enum {
	/// キー
	EventInitConditionTypeKey = 0,
	/// 離れたら
	EventInitConditionTypeLeave,
	/// 触れたら
	EventInitConditionTypeTouch,
	/// 自動
	EventInitConditionTypeAuto,			
} EventInitConditionType;

/// イベント詳細移動タイプ
typedef enum {
	/// 動かない
	EventDetailMoveTypeNoMove = 0,
	/// ランダム
	EventDetailMoveTypeRandom,
	/// 主人公に近づく
	EventDetailMoveTypeNear,
	/// 主人公から離れる
	EventDetailMoveTypeFar,
	/// 詳細設定
	EventDetailMoveTypeSet,
} EventDetailMoveType;

/// イベント作業ステータスタイプ
typedef enum {
	// マップ上に存在しない
	EventWorkStatusNoMap = 0,
	// 無効
	EventWorkStatusInvalid,
	// 有効
	EventWorkStatusValid,
	// 実行
	EventWorkStatusExecute,
} EventWorkStatus;

#pragma mark - 敵

/// 敵ステータスタイプ
typedef enum {
	/// 最大HP
	EnemyStatusTypeMaxHP,
	/// 最大MP
	EnemyStatusTypeMaxMP,
	/// 攻撃力
	EnemyStatusTypeAttack,
	/// 精神力
	EnemyStatusTypeMental,
	/// 防御力
	EnemyStatusTypeDefence,
	/// 機敏さ
	EnemyStatusTypeSpeed,
	/// 装備後炎耐性
	EnemyStatusTypeFire,
	/// 装備後氷耐性
	EnemyStatusTypeIce,
	/// 装備後雷耐性
	EnemyStatusTypeThunder,
	/// 装備後毒耐性
	EnemyStatusTypePoison,
	/// 所持金
	EnemyStatusTypeMoney,
	/// 経験値
	EnemyStatusTypeEXP,
	/// 命中率
	EnemyStatusTypeHitRate,
	/// 必殺率
	EnemyStatusTypeCriticalRate,
} EnemyStatusType;

#pragma mark - 職業

/// 最大レベル
#define MAX_LEVEL		99

/// レベルアップ時のステータスタイプ
typedef enum {
	/// 最大HP
	AddStatusTypeMaxHP = 0,
	/// 最大MP
	AddStatusTypeMaxMP,
	/// 攻撃力
	AddStatusTypeAttack,
	/// 精神力
	AddStatusTypeMental,
	/// 防御力
	AddStatusTypeDefence,
	/// スピード
	AddStatusTypeSpeed,
	/// レベルアップ経験値
	AddStatusTypeEXP,
} AddStatusType;

#pragma mark - アイテム

/// アイテム種別
typedef enum {
	/// 通常
	ItemTypeNormal	=	0,
	/// 武器
	ItemTypeWeapon,
	/// 鎧
	ItemTypeArmar,
	/// 盾
	ItemTypeShield,
	/// 兜
	ItemTypeHelm,
	/// 装飾品
	ItemTypeAccess,
	/// 回復
	ItemTypeRecovery,
	/// 種
	ItemTypeSeed,
	/// 地図
	ItemTypeMap,
	/// 職業変更
	ItemTypeJob,
	/// 特技追加
	ItemTypeSkill,
} ItemType;

/// アイテムステータス種別
typedef enum {
	/// 影響なし
	ItemStatusTypeNothing = 0,
	/// 最大HPに影響
	ItemStatusTypeHP,
	/// 最大MPに影響
	ItemStatusTypeMP,
	/// 攻撃力に影響
	ItemStatusTypeAttack,
	/// 精神力に影響
	ItemStatusTypeMental,
	/// 防御力に影響
	ItemStatusTypeDefence,
	/// 機敏性に影響
	ItemStatusTypeSpeed,
	/// 炎耐性に影響
	ItemStatusTypeFire,
	/// 氷耐性に影響
	ItemStatusTypeIce,
	/// 雷耐性に影響
	ItemStatusTypeThunder,
	/// 毒耐性に影響
	ItemStatusTypePoison,
	/// ヒット回数
	ItemStatusTypeHitCount,
	/// 名声
	ItemStatusTypeFame,
	/// 道徳心
	ItemStatusTypeMoral,
	/// 命中率
	ItemStatusTypeHitRate,
	/// 必殺率
	ItemStatusTypeCriticalRate,
} ItemStatusType;

#pragma mark - スキル

/// 特殊技能種別
typedef enum {
	/// 攻撃
	SkillTypeAttack		=	0,
	/// 回復
	SkillTypeRecvary,
	/// テレポート
	SkillTypeTeleport,
	/// エスケープ
	SkillTypeEscape,
	/// 地図
	SkillTypeMap,
} SkillType;

/// 効果範囲
typedef enum {
	/// 使用者
	EffectRangeTypeUser	=	0,
	/// 単体
	EffectRangeTypeSingle,
	/// 全員
	EffectRangeTypeAll,
} EffectRangeType;

#pragma mark - 変数

/// 変数変化増減タイプ
typedef enum {
	///	代入
	VariableOperateTypeAssignment = 0,
	///	増
	VariableOperateTypeIncrease,
	///	減
	VariableOperateTypeDecline,
} VariableOperateType;

#pragma mark - サウンド

/// 初期メンバーカウント
#define INIT_MEMBER_COUNT 3

/// マップチップ最大数
#define MAPCHIP_VALUE_MAX 63

// 1マスのドット数
#define MAP_ONEPANEL_DOT 28

#pragma mark - バトル

/// バトル
typedef enum {
	/// 最大HP
	BattleStatusTypeMaxHP = 0,
	/// 最大MP
	BattleStatusTypeMaxMP,
	/// 移動中の攻撃力
	BattleStatusTypeMaxAttack,
	/// 移動中の精神力
	BattleStatusTypeMaxMental,
	/// 移動中の防御力
	BattleStatusTypeMaxDefence,
	/// 移動中の機敏さ
	BattleStatusTypeMaxSpeed,
	/// HP
	BattleStatusTypeHP,
	/// MP
	BattleStatusTypeMP,
	/// 攻撃力
	BattleStatusTypeAttack,
	/// 精神力
	BattleStatusTypeMental,
	/// 防御力
	BattleStatusTypeDefence,
	/// 機敏さ
	BattleStatusTypeSpeed,
	/// 炎耐性
	BattleStatusTypeFire,
	/// 氷耐性
	BattleStatusTypeIce,
	/// 雷耐性
	BattleStatusTypeThunder,
	/// 毒耐性
	BattleStatusTypePoison,
	/// 金
	BattleStatusTypeMoney,
	/// 経験値
	BattleStatusTypeEXP,
	/// 命中率
	BattleStatusTypeHitRate,
	/// 必殺率
	BattleStatusTypeCriticalRate,
	/// 状態
	BattleStatusTypeCondition,
	/// ヒット
	BattleStatusTypeHit,
	/// バトルステータスMAX
	BattleStatusTypeMax,
} BattleStatusType;


/// スプライト倍率
#define SPRITE_SCALE		4.0


#endif /* GameConst_h */
