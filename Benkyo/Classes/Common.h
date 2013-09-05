//
//  Common.h
//  chaos
//
//  Created by B03744 on 13/03/28.
//  Copyright (c) 2013年 Applibot inc. All rights reserved.
//

#pragma once
// unused warning ignore
#pragma GCC diagnostic ignored "-Wunused-variable"

#include "cocos2d.h"
//#include "DBUtil.h"
//#include "MasterDBInfo.h"
#include "AppInfo.h"
#include "SoundManager.h"

//using namespace COLUMNNAME;

//-----------------------------------------------------------------
// マクロ
#define ARRAY_SIZE( array )		( sizeof( array ) / sizeof( array[0] ) )

#define USER_SETTING_DB_PATH CCFileUtils::sharedFileUtils()->getWritablePath() + "other.db"

// デバッグDBを使うためのフラグ
//#define USE_DEBUG_DATABASE 1


//-----------------------------------------------------------------
// 定数
namespace {
	const char*		CCB_TIMELINE_SCENEIN		= "SceneIn";
	const char*		CCB_TIMELINE_SCENEOUT		= "SceneOut";
	const char*		CCB_TIMELINE_SCENEIDLE		= "SceneIdle";
//	const char*		CCB_TIMELINE_SCENEPOPIN		= "ScenePopIn";
//	const char*		CCB_TIMELINE_SCENEPOPOUT	= "ScenePopOut";
//	const char*		CCB_TIMELINE_SCENEPOPIDLE	= "ScenePopIdle";
//	const char*		CCB_TIMELINE_SCENEOUT_MONSTER_STATUS = "SceneOutMonsterStatus";
	
	const cocos2d::CCSize	windowSize_g		(320.0f, 480.0f);

    const char* htmlBase = "<!DOCTYPE HTML><html lang=\"ja\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=320, user-scalable=no\"><meta name=\"apple-mobile-web-app-capable\" content=\"yes\" /><link rel=\"stylesheet\" type=\"text/css\" href=\"css/game/reset.css\" /><link rel=\"stylesheet\" type=\"text/css\" href=\"css/game/common.css\" /><link rel=\"stylesheet\" type=\"text/css\" href=\"css/game/help.css\" /></head><body>%s</body></html>";
    
    const char* GACHA_POINT_IMAGE_PATH = "item/130x130/ui_common_item_kizuna.jpg";
    const char* VIRTUAL_MONEY_IMAGE_PATH = "item/130x130/item_coin_001.jpg";
    const char* MONEY_IMAGE_PATH = "item/130x130/item_gold_85_001.jpg";     //CHAOS-2940     = "item_gold_85_001.jpg";
    

    namespace GACHA{
        //-----------------------------------------------------------------
        //ガチャAPIパラメータ
        //ガチャ台情報
        const char*		GACHA_LIST_GACHALIST		= "gachaList";
        const char*		GACHA_LIST_GACHAMACHINE_ID		= "gachaMachineId";             //ガチャ台ID
        const char*		GACHA_LIST_MANAGEID		= "manageId";                           //ガチャ台管理ID
        const char*		GACHA_LIST_MANAGE_COMMENT		= "manageComment";              //管理側コメント
        const char*		GACHA_LIST_DISPLAY_POSITION		= "displayPosition";            //タブ分け
        const char*		GACHA_LIST_DISPLAY_NO		= "displayNo";                      //ガチャ台表示順位
        const char*		GACHA_LIST_TITLE		= "title";                              //ガチャ台タイトル
        const char*		GACHA_LIST_GACHATYPE		= "gachaType";                      //ガチャタイプ
        const char*		GACHA_LIST_COMMENT		= "comment";                            //ガチャ台コメント(サムネイル横　ガチャで手に入る内容)
        const char*		GACHA_LIST_COMMENT_DETAIL		= "commentDetail";              //ガチャ台コメント(サムネイル下　ガチャ詳細説明)
        const char*		GACHA_LIST_STARTDATE		= "startDate";                      //ガチャ開始時間
        const char*		GACHA_LIST_ENDDATE		= "endDate";                            //ガチャ終了時間
        const char*		GACHA_LIST_GACHA_END_DATE		= "gachaEndDate";               //ガチャが終了する日付(ユーザー毎に違う場合もあり)
        const char*		GACHA_LIST_USEIETEM_DIVISION		= "useItemDivision";        //ガチャ支払いタイプ
        const char*		GACHA_LIST_ITEMID		= "itemId";                             //消費するアイテムID
        const char*		GACHA_LIST_USEITEM_COUNT		= "useItemCount";               //消費するアイテム個数
        const char*		GACHA_LIST_IMAGEPATH		= "imagePath";                      //ガチャ台画像パス
        const char*		GACHA_LIST_RECOMMEND_IMAGEPATH		= "recommendImagePath";                      //ガチャ台詳細画像パス
        const char*		GACHA_LIST_BUY_DIVISION		= "buyDivision";                    //ガチャ購入限度タイプ
        const char*		GACHA_LIST_BUY_LIMIT		= "buyLimit";                       //購入限度回数
        const char*		GACHA_LIST_DEFAULT_PRICE		= "defaultPrice";                   //基本となる値段(基本は300円、ガチャ台によってここの値段は変わる、表示用)
        const char*		GACHA_LIST_DRAW_PRICE           = "drawPrice";                      //実際に引くときの値段(安いときもあれば高いときもあり、表示用)
        const char*		GACHA_LIST_GACHADETAIL_LIST		= "gachaDetailList";                      //ガチャ台ディテイルリスト(値段設定)
        const char*		GACHA_LIST_GACHAMACHINE_DETAILID	= "gachaMachineDetailId";   //ガチャ台ディテイルID
        const char*		GACHA_LIST_DRAWCARD_COUNT		= "drawCardCount";              //引く回数
        const char*		GACHA_LIST_PRICE		= "price";                              //値段
        const char*		GACHA_LIST_GACHA_RECOMMEND_CARDLIST	= "gachaRecommendCardList";       //一押しカード一覧リスト
        const char*		GACHA_LIST_GACHA_RECOMMEND_ID	= "gachaMachineRecommendId";       //一押しカードID
        const char*		GACHA_LIST_CARD_ID		= "cardId";                              //カードID
        const char*		GACHA_LIST_GACHA_TITLE_LIST		= "gachaTitleList";                              //入手できるガチャ台のタイトルリスト
        const char*		GACHA_LIST_REST_BUY_LIMIT		= "restBuyLimit";                              //残り購入可能回数(回数が1以上の場合残り回数を表示)
        
        //ガチャトップコメント
        const char*     GACHA_TOP_GACHA_TOP_COMMENT_LIST= "gachaTopCommentList";    //ガチャトップコメント
        const char*     GACHA_TOP_COMMENT_ID = "gachaTopCommentId";     //ガチャTopコメント詳細ID
        const char*     GACHA_TOP_COMMENT = "comment";    //ガチャトップコメント詳細
        const char*     GACHA_TOP_DISPLAY_POSITION = "displayPosition";    //表示場所区分け[Rare:レアガチャ,RAID:レイドガチャ,NORMAL:ノーマルガチャ]
        const char*     GACHA_TOP_START_DATE = "startDate";    //表示開始時間
        const char*     GACHA_TOP_END_DATE = "endDate";    //表示終了時間
        
        
        //新カード情報
        const char*		GACHA_NEW_NEW_CARD_LIST		= "newCardList";     //新カード一覧
        const char*		GACHA_NEW_COMMENT 	= "comment";     //ガチャTopに見せるタイトル
        const char*		GACHA_NEW_START_DATE		= "startDate";    //表示開始時間
        const char*		GACHA_NEW_END_DATE		= "endDate";     //表示終了時間
        const char*		GACHA_NEW_DISPLAY_POSITION		= "displayPosition";     ///表示タブ分け
        const char*		GACHA_NEW_CARD_LIST		= "cardList";     //カード一覧
        
        const char*		GACHA_REPORT_RARE_CARD_REPORT		= "rareCardReport";    //レアカード速報(レア)
        const char*		GACHA_REPORT_RAID_CARD_REPORT		= "raidCardReport";    //レアカード速報(レイド)
        const char*		GACHA_REPORT_NORMAL_CARD_REPORT		= "normalCardReport";    //レアカード速報(ノーマル)
        const char*		GACHA_REPORT_USER_ID		= "userId";     //ユーザーID
        const char*		GACHA_REPORT_CARD_ID		= "cardId";     //カードID
        const char*		GACHA_REPORT_AVATER_ID		= "avatarId";     //アバター画像
        const char*		GACHA_REPORT_CREATE_DATE		= "createDate";    //入手時間
        const char*		GACHA_REPORT_NAME		= "name";    //ユーザー名
        const char*		GACHA_REPORT_USER_FLAG		= "userFlag";  //ユーザーの手に入れたカードか否か[false:他人,true:自分]
        
        //Value
        //タブ分け
        const char*		DISPLAY_POSITION_RARE = "RARE";
        const char*		DISPLAY_POSITION_RAID = "RAID";
        const char*		DISPLAY_POSITION_NORMAL = "NORMAL";
        
        //ガチャタイプ
        const char*		GACHA_TYPE_RARE	= "RARE";
        const char*		GACHA_TYPE_NORMAL	= "NORMAL";
        const char*		GACHA_TYPE_BEGGINER	= "BEGGINER";
        
        //ガチャ支払いタイプ
        const char*     USE_ITEM_DIVISION_MONEY	= "MONEY";
        const char*     USE_ITEM_DIVISION_GACHA_POINT	= "GACHA_POINT";
        const char*     USE_ITEM_DIVISION_VIRTUAL_MONEY	= "VIRTUAL_MONEY";
        const char*     USE_ITEM_DIVISION_GACHA_TICKET	= "GACHA_TICKET";
        
        //ガチャ購入限度タイプ
        const char*     BUY_DIVISION_NORMAL	= "NORMAL";
        const char*     BUY_DIVISION_TIME	= "TIME";
        const char*     BUY_DIVISION_DAY	= "DAY";
        
        
        //ガチャドローデータ
        const char*		GACHA_CARD_DRAWLIST		= "drawList";
        const char*		GACHA_CARD_REWARD_ID		= "rewardId";             //報酬ID
        const char*		GACHA_CARD_IMAGEPATH		= "imagePath";          //カード画像パス
        const char*		GACHA_CARD_PARTICLE		= "particle";   //カードパーティクル効果
        const char*		GACHA_CARD_NEWCARD_FLAG		= "newCardFlag";             //Newカード判定
        const char*		GACHA_CARD_REVERSE_FLAG		= "reverseFlag";             //逆転演出判定
        const char*		GACHA_CARD_DUMMY_IMAGEPATH		= "dummyImagePath";             //逆転演出用ダミー画像
        const char*		GACHA_CARD_DUMMY_PARTICLE		= "dummyParticle";             //逆転演出発生時用のダミーパーティクル効果
        const char*		GACHA_CARD_ITEMID		= "itemId";                             //取得するアイテムID
        const char*		GACHA_CARD_REWARD_DIVISION		= "rewardDivision";                             //アイテム判別
        const char*		GACHA_CARD_GIFT_FLAG		= "giftFlag";                             //ギフトに入ったかフラグ
        
        const char*		GACHA_CARD_VIBRATION		= "vibration";          //バイブレーション判定
        const char*		GACHA_CARD_SPEECH		= "speech";   //台詞パターン
        const char*		GACHA_CARD_GATECOLOR		= "gateColor";             //ゲート色
        const char*		GACHA_CARD_BACKCOLOR		= "backColor";            //背景色
        const char*		GACHA_CARD_GROUPWARNING		= "groupWarning";             //群予告
        const char*		GACHA_CARD_CUTIN		= "cutIn";             //カットイン予告
        
        const char*		GACHA_CARD_COMMENT_DETAIL		= "commentDetail";             //コメントリスト
        const char*		GACHA_CARD_BEFORE_TAP_COMMENT		= "beforeTapComment";             //TAP前のセリフ
        const char*		GACHA_CARD_AFTER_TAP_COMMENT		= "afterTapComment";             //TAP直後のセリフ
        const char*		GACHA_CARD_CUTIN_COMMENT		= "cutInComment";             //カットイン時のセリフ
        const char*		GACHA_CARD_RESULT_COMMENT_LIST		= "resultCommentList";             //カード出現時のセリフ,
        const char*		GACHA_CARD_BEFORE_REVERCE_COMMENT		= "beforeReverseComment";            //逆転演出開始時のセリフ
        const char*		GACHA_CARD_AFTER_REVERCE_COMMENT		= "afterReverseComment";            //逆転演出終了時のセリフ
        
        const char*     GACHA_CARD_COMMENT = "comment";//セリフ
        const char*     GACHA_CARD_COMMENT_CHARA = "chara";//キャラ区別
        const char*     GACHA_CARD_COMMENT_EXPRESSION = "expression";//表情区別
        
        
        const char*		GACHA_CARD_USER_PRICE		= "userPrice";             //ユーザーの残金
        const char*		GACHA_CARD_USER_GACHAPOINT		= "userGachaPoint";              //ユーザーの残ガチャポイント
        const char*		GACHA_CARD_USER_ITEMLIST		= "userItemList";              //ユーザーの所持アイテム
        const char*		GACHA_CARD_USER_ITEM_ID		= "userItemId";              //ユーザーアイテムID
        const char*		GACHA_CARD_ITEM_ID		= "itemId";              //アイテムID
        const char*		GACHA_CARD_COUNT		= "count";              //アイテム個数
        
        const char*		GACHA_CARD_CARD_ID		= "cardId";              //カードID
        
        
        const char*		GACHA_CARD_USER_CARDLIST		= "userCardList";              //取得したカードリスト
        const char*		GACHA_CARD_USER_CARD_ID		= "userCardId";             //ユーザーカードID
        
        const char*		GACHA_CARD_RESULT_MACHINE		= "resultMachine";
        const char*		GACHA_CARD_CHECK_DISPLAY		= "checkDisplay";  //表示するか否か[true:表示する, false:表示しない]
        const char*		GACHA_CARD_DRAW_GACHA_ID		= "drawGachaId";    //引いたガチャID
        
        const char*     GACHA_DECK_LIST = "deckList";
        const char*     GACHA_DECK_USER_RAID_DECK_LIST = "userRaidDeckList";
        const char*     GACHA_DECK_USER_GUILD_DECK_LIST = "userGuildDeckList";
        
        //パーティクル効果[N:無し,R:レア,SR:Sレア,SS:SSレア,LG:レジェンド]
        const char*		PARTICLE_EFFECT_N		= "N";
        const char*		PARTICLE_EFFECT_R		= "R";
        const char*		PARTICLE_EFFECT_SR		= "SR";
        const char*		PARTICLE_EFFECT_SSR		= "SSR";
        const char*		PARTICLE_EFFECT_LG		= "LG";
        
        
        //レアリティ[WHITE:白,RED:赤,GOLD:金]
        const char*     RARE_COLOR_WHITE = "WHITE";
        const char*     RARE_COLOR_RED = "RED";
        const char*     RARE_COLOR_GOLD = "GOLD";
        
        //演出量[WITHOUT:無し,SMALL:少,NORMAL:中,BIG:多,VERYBIG:特盛]
        const char*     DIRECTION_SIZE_WITHOUT = "WITHOUT";
        const char*     DIRECTION_SIZE_SMALL = "SMALL";
        const char*     DIRECTION_SIZE_NORMAL = "NORMAL";
        const char*     DIRECTION_SIZE_BIG = "BIG";
        const char*     DIRECTION_SIZE_VERYBIG = "VERYBIG";
        
        //カード、アイテム判別[CARD:カード　ITEM:アイテム]
        const char*     GIFT_DIVISION_CARD = "CARD";
        const char*     GIFT_DIVISION_ITEM = "ITEM";
        
        //キャラ区別[DRACO:ドラコ,ANGE:アンジェ,ASUL:アスル]
        const char*     CHARA_DIVISION_DRACO = "DRACO";
        const char*     CHARA_DIVISION_ANGE = "ANGE";
        const char*     CHARA_DIVISION_ASUL = "ASUL";
        
        //表情区別[NORMAL:普通,SAD:哀,HAPPY:喜,SURPRISED:驚き]
        const char*     EXPRESSION_DIVISION_NORMAL = "NORMAL";
        const char*     EXPRESSION_DIVISION_SAD = "SAD";
        const char*     EXPRESSION_DIVISION_HAPPY = "HAPPY";
        const char*     EXPRESSION_DIVISION_SURPRISED = "SURPRISED";
        
        //一押しカード用パラメータ
        const char*     GACHA_CARD_DETAIL = "cardDetail";
        const char*     GACHA_CARD_FRONT_ABILITY = "frontAbility";
        const char*     GACHA_CARD_BACK_ABILITY = "backAbility";
        const char*     GACHA_CARD_SUPPORT_ABILITY = "supportAbility";
        
        
        //-----------------------------------------------------------------
        //ガチャタイムライン
        //Window
        const char*		DRACO_START_GACHA_TIMELINE = "windowDraco_start";
        const char*		DRACO_NORMAL_GACHA_TIMELINE =  "windowDraco_normal";
        const char*		DRACO_HAPPY_GACHA_TIMELINE =  "windowDraco_Happy";
        const char*		DRACO_SAD_GACHA_TIMELINE =  "windowDraco_Sad";
        const char*		DRACO_HAPPEN_GACHA_TIMELINE =  "windowDraco_Happen";
        const char*		ANGE_START_GACHA_TIMELINE = "windowAnge_start";
        const char*		ANGE_NORMAL_GACHA_TIMELINE =  "windowAnge_nomal";
        const char*		ANGE_HAPPY_GACHA_TIMELINE =  "windowAnge_Happy";
        const char*		ANGE_SAD_GACHA_TIMELINE =  "windowAnge_Sad";
        const char*		ANGE_HAPPEN_GACHA_TIMELINE =  "windowAnge_Happen";
        const char*		ASURU_START_GACHA_TIMELINE = "windowAsuru_start";
        const char*		ASURU_NORMAL_GACHA_TIMELINE =  "windowAsuru_normal";
        const char*		ASURU_HAPPY_GACHA_TIMELINE =  "windowAsuru_Happy";
        
        const char*		NORMAL_CARD_APEAR_TIMELINE =  "NormalCard_Apear";
        const char*		NORMAL_CARD_TIMELINE =  "NormalCard";
        const char*		NORMAL_CARD_NEW_TIMELINE =  "NormalCard_New";
        const char*		RARE_CARD_APEAR_TIMELINE =  "RareCard_Apear";
        const char*		RARE_CARD_TIMELINE =  "RareCard";
        const char*		RARE_CARD_NEW_TIMELINE =  "RareCard_New";
        const char*		SRARE_CARD_APEAR_TIMELINE =  "SRareCard_Apear";
        const char*		SRARE_CARD_TIMELINE =  "SRareCard";
        const char*		SRARE_CARD_NEW_TIMELINE =  "SRareCard_New";
        const char*		SSRARE_CARD_APEAR_TIMELINE =  "SSRareCard_Apear";
        const char*		SSRARE_CARD_TIMELINE =  "SSRareCard";
        const char*		SSRARE_CARD_NEW_TIMELINE =  "SSRareCard_New";
        const char*		LEGEND_CARD_APEAR_TIMELINE =  "LegendCard_Apear";
        const char*		LEGEND_CARD_TIMELINE =  "LegendCard";
        const char*		LEGEND_CARD_NEW_TIMELINE =  "LegendCard_New";
        const char*		CARD_APEAR_TIMELINE =  "Card Apear";
        
        const char* LOOP_TIMELINTE = "loop";
        
        //-----------------------------------------------------------------
        //ガチャ画像
        
        //ガチャ画像
        
        const char* BACKGROUND_IMAGE_RED = "gc_imgBackground_red.jpg";
        const char* BACKGROUNDE_IMAGE_GOLD = "gc_imgBackground_gold.jpg";
        const char* SCOPE_IMAGE_RED = "gc_gate_red.png";
        const char* SCOPE_IMAGE_GOLD = "gc_gate_gold.png";
        
        const char* WINDOW_IMAGE_GOLD = "gc_window_rare.png";
        
        const cocos2d::ccColor3B FONT_COLOR_NAVY = cocos2d::ccc3(0, 0, 100);
    }

    namespace MYPAGE{
        
        
        const char* MYPAGE_TOP_START_LOGIN_STAMP_FLAG = "startLoginStampFlag"; //スタートログインスタンプが貰えるかどうか[false:貰えない, true:貰える]
        const char* MYPAGE_TOP_GUILD_NAME = "guildName"; //ギルド名
        
        const char* MYPAGE_USER_SKILL_POINT = "userSkillPoint"; //ユーザーの持つ全てのスキルポイントの合計値
        
        const char* RAID_BOSS_RAID_BOSS = "raidBoss";
        const char* RAID_BOSS_USER_RAID_BOSS_ID = "userRaidBossId"; //ユーザーレイドボスID
        const char* RAID_BOSS_RAID_BOSS_ID = "raidBossId"; //レイドボスID
        const char* RAID_BOSS_NEW_FLAG = "newFlag"; //新規フラグ
        const char* RAID_BOSS_COMBO_FLAG = "comboFlag"; //コンボフラグ
        
        const char* RAID_HELP_RAID_HELP = "raidHelp";
        const char* RAID_HELP_RAID_HELP_COUNT = "raidHelpCount"; //応援依頼数
        const char* RAID_HELP_RAID_HELP_LIST = "raidHelpList"; //レイド応援依頼
        const char* RAID_HELP_USER_RAID_BOSS_ID =  "userRaidBossId"; //ユーザレイドボスID
        const char* RAID_HELP_NEW_FLAG = "newFlag"; //新規フラグ
        const char* RAID_HELP_RAID_BOSS_ID = "raidBossId"; //レイドボスID
        const char* RAID_HELP_BOSS_NAME = "bossName"; //レイドボス名
        const char* RAID_HELP_LEVEL = "level"; //レイドボスレベル
        const char* RAID_HELP_IMAGE_PATH = "imagePath"; //イメージパス
        const char* RAID_HELP_MAX_BOSS_HP = "maxBossHp"; //ボス最大体力
        const char* RAID_HELP_CURRENT_BOSS_HP = "currentBossHp"; //ボス残り体力
        const char* RAID_HELP_TIMEOUT = "timeout"; //タイムアウト時間(分)
        const char* RAID_HELP_COMBO_FLAG = "comboFlag"; //コンボフラグ
        const char* RAID_HELP_COMBO_COUNT = "comboCount"; //コンボ数
        const char* RAID_HELP_APPEAR_DATE = "appearDate"; //出現時間
        const char* RAID_HELP_DISCOVER_USER_ID = "discoverUserId"; //発見者ユーザーId
        const char* RAID_HELP_AVATAR_ID = "avatarId"; //発見者アバターId
        const char* RAID_BOSS_JOIN_USER_COUNT = "joinUserCount"; //参加者人数
        
        const char* MYPAGE_GREETING_GREETING = "greeting";
        const char* MYPAGE_GREETING_GREETING_COUNT =  "greetingCount";//挨拶リスト
        const char* MYPAGE_GREETING_GREETING_LIST =  "greetingList";//挨拶リスト
        const char* MYPAGE_GREETING_GREETING_BBS_ID = "greetingBbsId"; //挨拶ID
        const char* MYPAGE_GREETING_FORM_USER_ID = "fromUserId"; //発信者Id
        const char* MYPAGE_GREETING_COMMENT = "comment"; //コメント
        const char* MYPAGE_GREETING_AVATAR_ID = "avatarId"; //発信者アバターID
        const char* MYPAGE_GREETING_LEADER_CARD_ID = "leaderCardId"; //リーダーカードID
        const char* MYPAGE_GREETING_CREATE_DATE =  "createDate"; //発信時間
        
        const char* MYPAGE_GIFT_GIFT = "gift";
        const char* MYPAGE_GIFT_REMAIN_COUNT = "remainCount"; //ギフト数
        const char* MYPAGE_GIFT_GIFT_LIST = "giftList"; //ギフトリスト
        const char* MYPAGE_GIFT_USER_GIFT_ID = "userGiftId"; //ユーザーギフトID
        const char* MYPAGE_GIFT_GIFT_DIVISION = "giftDivision";//ギフト種別[CARD:カード,ITEM:アイテム,GACHA_POINT:ガチャポイント,MONEY:お金]
        const char* MYPAGE_GIFT_GIFT_ID = "giftId"; //giftDivisionがCARDならcard_idが,ITEMならitem_idに紐づく
        const char* MYPAGE_GIFT_COMMENT = "comment"; //ギフトメッセージ
        const char* MYPAGE_GIFT_CREATE_DATE = "createDate"; //ギフトされた時間
        const char* MYPAGE_GIFT_GIFT_COUNT = "giftCount"; //一つのアイテムに含まれるカウント
        
        const char* MYPAGE_ANNOUNCE_ANNOUNCE = "announce";
        const char* MYPAGE_ANNOUNCE_ANNOUNCE_COUNT = "announceCount"; //未読お知らせ数
        
        
        const char* MYPAGE_NAVI_MESSAGE_LIST = "naviMessageList"; //ナビメッセージリスト
        const char* MYPAGE_NAVI_MYPAGE_MESSAGE_ID = "mypageMessageId"; //マイページメッセージID
        const char* MYPAGE_NAVI_PRIORITY_FLAG = "priorityFlag"; //優先フラグ[true:優先, false:非優先]
        const char* MYPAGE_NAVI_DISPLAY_NO = "displayNo"; //表示優先順位(グループ順位)
        const char* MYPAGE_NAVI_INTERNAL_NO = "internalNo"; //表示優先順位(グループ内順位)
        const char* MYPAGE_NAVI_CONDITION_1 = "condition1";  //表示条件
        const char* MYPAGE_NAVI_COMMENT = "comment"; //セリフ
        const char* MYPAGE_NAVI_CHARACTER_NAME = "characterName"; //キャラクター名
        const char* MYPAGE_NAVI_CHARACTER_IMAGE_PATH = "characterImagePath"; //キャラクター画像パス
        const char* MYPAGE_NAVI_START_DATE = "startDate"; //表示開始時間
        const char* MYPAGE_NAVI_END_DATE = "endDate"; //表示終了時間
        
        const char* MYPAGE_BANNER_LIST = "bannerList"; //マイページバナーリスト
        const char* MYPAGE_BANNER_ID = "mypageBannerId"; //マイページバナーID
        const char* MYPAGE_BANNER_TRANSITION_DIVISION = "transitionDivision"; //遷移先区分け['GACHA_GOLD','GACHA_TICKET','GACHA_RAID','GACHA_NORMAL','GUILD_BATTLE','SHOP','EXCHANGE','BINGO','INVITE','RAID','QUEST','HELP','LIMIT_BREAK','SKILL','FUSION','CARD_SELL','DECK','POP_UP','WEB_VIEW','RAID_BOSS_ANNOUNCE']
        const char* MYPAGE_BANNER_PRIORITIES = "priorities"; //優先順位
        const char* MYPAGE_BANNER_IMAGE_PATH = "bannerImagePath"; //バナー画像パス
        const char* MYPAGE_BANNER_POPUP_IMAGE_PATH = "popupImagePath"; //ポップアップ画像パス
        const char* MYPAGE_BANNER_POPUP_TITLE = "popupTitle"; //ポップアップタイトル
        const char* MYPAGE_BANNER_POPUP_URL_PATH = "urlPath"; //URLパス
        const char* MYPAGE_BANNER_START_DATE = "startDate"; //表示開始時間
        const char* MYPAGE_BANNER_END_DATE = "endDate"; //表示終了時間
        
        const char* LOGIN_STAMP_INFO = "loginStampInfo"; //ログインスタンプ情報
        const char* LOGIN_STAMP_FLAG = "loginStampFlag"; //ログインスタンプが貰えるかどうか[false:貰えない, true:貰える]
        const char* LOGIN_STAMP_ID = "loginStampId"; //ログインスタンプID
        const char* LOGIN_STAMP_DISPLAY_NO = "displayNo"; //ログインスタンプ表示優先順位
        const char* LOGIN_STAMP_DIVISION = "loginStampDivision"; //ログインスタンプ種別[UNTIL_LAST_DAY:通常ログインスタンプ, UNTIL_ITEM_COUNT:回数限定ログインスタンプ]
        const char* LOGIN_STAMP_START_DATE = "startDate"; //開始日時
        const char* LOGIN_STAMP_END_DATE = "endDate"; //終了日時
        const char* LOGIN_STAMP_BACK_GROUND_IMAGE_PATH = "backGroundImagePath"; //背景画像
        const char* LOGIN_STAMP_BANNER_IMAGE_PATH = "bannerImagePath"; //スタンプタイトル画像
        const char* LOGIN_STAMP_MAX_COUNT = "maxCount"; //獲得できる最大スタンププレゼントの種類
        const char* LOGIN_STAMP_GET_INTERNAL_NO = "getInternalNo"; //当日獲得できるスタンププレゼントの番号
        const char* LOGIN_STAMP_NEXT_INTERNAL_NO = "nextInternalNo"; //次回獲得できるスタンププレゼントの番号
        const char* LOGIN_STAMP_DETAIL_LIST = "loginStampDetailList"; //ログインスタンプの詳細リスト
        const char* LOGIN_STAMP_INTERNAL_NO = "internalNo"; //獲得優先順位
        const char* LOGIN_STAMP_IMAGE_PATH = "imagePath"; //獲得物のimagePathが入る
        const char* LOGIN_STAMP_MESSAGE_LIST = "loginStampMessageList";  //回数に応じたコメントが入るリスト
        const char* LOGIN_STAMP_CHARACTER_NAME = "characterName";  //キャラクター名
        const char* LOGIN_STAMP_CHARACTER_IMAGE_PATH = "characterImagePath"; //キャラクター画像パス
        const char* LOGIN_STAMP_MESSAGE = "message";  //セリフ
        
        //ログインスタンプ種別[UNTIL_LAST_DAY:通常ログインスタンプ, UNTIL_ITEM_COUNT:回数限定ログインスタンプ]
        const char* DIVISION_UNTIL_LAST_DAY = "UNTIL_LAST_DAY";
        const char* DIVISION_UNTIL_ITEM_COUNT = "UNTIL_ITEM_COUNT";
        
        
        const char* MISSON_BINGO_INFO = "missionBingoInfo";

        
        const char* GIFT_RECEIVE_CARD_LIST = "receivedCardList"; //: 追加されたユーザーカード情報
        const char* GIFT_RECEIVE_ITEM_LIST = "receivedItemList";    //: 追加されたアイテム数
        const char* GIFT_RECEIVE_USER_ITEM_ID = "userItemId";
        const char* GIFT_RECEIVE_ITEM_ID = "itemId";
        const char* GIFT_RECEIVE_ITEM_COUNT = "count";
        const char* GIFT_RECEIVE_USER_MONEY = "userMoney"; //: 追加されたマネー値
        const char* GIFT_RECEIVE_USER_VIRTUAL_MONEY = "userVirtualMoney";  //: 追加された課金マネー値
        const char* GIFT_RECEIVE_USER_GACHA_POINT = "userGachaPoint";     //: 追加されたがチャーポイント
        
        const char* GIFT_RECEIVE_USER_CANDY_COUNT = "userCandyCount";     //: 追加されたがチャーポイント
        
        const char* GREETING_SEARCH_GREETING_LIST = "greetingList"; //挨拶リスト
        const char* GREETING_SEARCH_GREETING_BBS_ID = "greetingBbsId"; //挨拶コメントID
        const char* GREETING_SEARCH_TO_USER_ID = "toUserId"; //挨拶先ユーザーID
        const char* GREETING_SEARCH_FROM_USER_ID = "fromUserId"; //挨拶元ユーザーID
        const char* GREETING_SEARCH_USER_NAME = "userName"; //ユーザー名
        const char* GREETING_SEARCH_AVATAR_ID = "avatarId"; //アバターID
        const char* GREETING_SEARCH_CARD_ID = "cardId"; //カードID
        const char* GREETING_SEARCH_COMMENT = "comment"; //コメント
        const char* GREETING_SEARCH_LIMIT_BREAK_COUNT = "limitBreakCount"; //限界突破回数(ユーザーのリーダーカード画像を取得するためカードIDと限界突破回数を送る)
        const char* GREETING_SEARCH_READ_FLAG = "readFlag"; //未読か既読かのフラグ[false:未読, true:既読]
        const char* GREETING_SEARCH_REPLY_FLAG = "replyFlag"; //返信したかどうかのフラグ[false:未返信, true:返信済み]
        const char* GREETING_SEARCH_CREATE_DATE = "createDate"; //作成時間
        const char* GREETING_SEARCH_NOT_READ_CHANGE_COUNT = "notReadChangeCount"; //未読を既読にした回数
        const char* GREETING_SEARCH_NEXT_OFFSET = "nextOffset"; //次のoffset
        
        const char* GREETING_TRANSMISSION_LIST = "greetingTransmissionList"; //送信リスト
        
        const char* GREETING_UPDATE_GET_GACHA_POINT = "getGachaPoint"; //獲得したガチャポイント
        const char* GREETING_UPDATE_TO_USER_GET_GACHA_POINT = "toUserGetGachaPoint"; //相手が獲得したガチャポイント
        const char* GREETING_UPDATE_USER_GACHA_POINT = "userGachaPoint"; //獲得後のユーザー累計ガチャポイント
        
        const char* MYPAGE_POPUP_INFO = "popupInfo";
        const char* MYPAGE_POPUP_FLAG = "popupFlag";
        const char* MYPAGE_POPUP_LIST = "mypagePopupList";
        const char* MYPAGE_POPUP_TITLE = "popupTitle";
        const char* MYPAGE_POPUP_IMAGE_PATH = "imagePath";
        const char* MYPAGE_POPUP_MESSAGE = "message";
        
        const char* MYPAGE_POPUP_DIVISION = "popupDivision";
        const char* MYPAGE_POPUP_PRIORITY = "priority";
        
        //ENUM型[IMAGE_ONLY , TEXT_ONLY , WEB_VIEW] NOT NULL
        const char* POPUP_DIVISION_IMAGE_ONLY = "IMAGE_ONLY";
        const char* POPUP_DIVISION_TEXT_ONLY = "TEXT_ONLY";
        const char* POPUP_DIVISION_WEB_VIEW = "WEB_VIEW";
        
        
        
        
        //遷移先区分け[GACHA:ガチャ, SHOP:ショップ, GUILD_BATTLE:ギルバト, BINGO:ビンゴ, INVITE:招待, RAID:レイド, QUEST:クエスト]
        const char* TRANSITION_DIVISION_GACHA_GOLD = "GACHA_GOLD";
        const char* TRANSITION_DIVISION_GACHA_TICKET = "GACHA_TICKET";
        const char* TRANSITION_DIVISION_GACHA_RAIDA = "GACHA_RAID";
        const char* TRANSITION_DIVISION_GACHA_NORMAL = "GACHA_NORMAL";
        const char* TRANSITION_DIVISION_SHOP = "SHOP";
        const char* TRANSITION_DIVISION_GUILD_BATTLE = "GUILD_BATTLE";
        const char* TRANSITION_DIVISION_BINGO = "BINGO";
        const char* TRANSITION_DIVISION_INVITE = "INVITE";
        const char* TRANSITION_DIVISION_RAID = "RAID";
        const char* TRANSITION_DIVISION_QUEST = "QUEST";
        const char* TRANSITION_DIVISION_WEB_VIEW = "WEB_VIEW";
        
        //ギフト種別判定[CARD:カード, ITEM:アイテム]
        const char* GIFT_DIVISION_CARD = "CARD";
        const char* GIFT_DIVISION_ITEM = "ITEM";
        const char* GIFT_DIVISION_GACHA_POINT = "GACHA_POINT";
        const char* GIFT_DIVISION_MONEY = "MONEY";
        const char* GIFT_DIVISION_VIRTUAL_MONEY = "VIRTUAL_MONEY";
        
        //情報タイプ[GET_CARD:カード獲得, CARD_LEVEL_UP:カードレベル上昇, RAID_ENCOUNT:レイドボス遭遇, SKILL_MASTER:スキルMAX, WEB_VIEW:webview表示]
        const char* ACTION_DIVISION_GET_CARD = "GET_CARD";
        const char* ACTION_DIVISION_CARD_LEVEL_UP = "CARD_LEVEL_UP";
        const char* ACTION_DIVISION_RAID_ENCOUNT = "RAID_ENCOUNT";
        const char* ACTION_DIVISION_SKILL_MASTER = "SKILL_MASTER";
        const char* ACTION_DIVISION_WEB_VIEW = "WEB_VIEW";
    
    const char* MYPAGE_NOTICE_NEWEST_TIME = "newestTime";
    const char* MYPAGE_NOTICE_DIVISION = "division";
    const char* MYPAGE_NOTICE_COUNT = "count";
    
    const char* NOTICE_DIVISION_GREET = "GREET";
    const char* NOTICE_DIVISION_GIFT = "GIFT";
    const char* NOTICE_DIVISION_GUILD = "GUILD";

    }
    
    namespace BINGO{
        
        const char* BINGO_PLATE_IMAGE_PATH = "plateImagePath"; //文字列　カード画像の書かれたプレートの画像パス
        const char* BINGO_COMPLETE_CARD_ID = "completeCardId"; //数値　コンプリート時にもらえるカードのカードID
        const char* BINGO_START_COMMENT = "startComment"; //文字列　アニメーション開始時のコメント
        const char* BINGO_END_COMMENT = "endComment"; //文字列　アニメーション終了時のコメント
        const char* BINGO_REVERSE_COUNT = "reverseCount";
        const char* BINGO_REWARD_LIST = "bingoRewardList"; //ビンゴ発生時の報酬リスト
        const char* BINGO_ACHIEVENT_MISSION = "achievementMission"; //文字列　達成条件名
        const char* BINGO_ITEM_ID = "itemId"; //数値　報酬のアイテムID
        const char* BINGO_COUNT = "count"; //数値　アイテムの個数
        const char* BINGO_GET_FLAG = "getFlag"; //論理値　今回取得したアイテムか
        const char* BINGO_PANEL_REWARD_LIST = "panelRewardList"; //パネル情報のリスト
        const char* BINGO_PANEL_POSITION = "panelPosition"; //数値 パネルの表示位置[1:左上, 2:上, 3:右上, 4:左, 5:右, 6:左下, 7:下, 8:右下]
        const char* BINGO_ACHIEVEMENT_LEVEL = "achievementLevel"; //文字列　達成度
        const char* BINGO_PANEL_IMAGE_PATH = "panelImagePath"; //文字列　パネルの画像パス
        const char* BINGO_STATE_DIVISION = "stateDivision"; //文字列　パネルの状態区分け[OPEN:達成済み REVERSE:今回達成 CLOSE:未達成]
        const char* BINGO_TRANSITION_DIVISION = "transitionDivision"; //文字列 パネルタップ時の遷移先区分け[HELP:ヘルプ, GACHA:ガチャ, SKILL:スキル, GUILD_BATTLE:ギルバト, ENHANCE_EVOLVE:限界突破, CARD_SELL:カード売却, RAID:レイド, QUEST:クエスト, ENHANCE:強化, COIN_SHOP:コインショップ, DECK:デッキ]
        
        //add suizu
        const char* BINGO_REWARD_DIVISION = "rewardDivision";
        const char* REWARD_DIVISION_CARD = "CARD";
        const char* REWARD_DIVISION_ITEM = "ITEM";
        
        
        
        const char* STATE_DIVISION_OPEN = "OPEN";
        const char* STATE_DIVISION_REVERSE = "REVERSE";
        const char* STATE_DIVISION_CLOSE = "CLOSE";
        
        const char* TRANSITION_DIVISION_GACHA_NORMAL = "GACHA_NORMAL";
        const char* TRANSITION_DIVISION_GACHA_RAID = "GACHA_RAID";
        const char* TRANSITION_DIVISION_GACHA_RARE = "GACHA_RARE";
        const char* TRANSITION_DIVISION_GACHA_TICKET = "GACHA_TICKET";
        const char* TRANSITION_DIVISION_GUILD_BATTLE = "GUILD_BATTLE";
        const char* TRANSITION_DIVISION_SHOP = "SHOP";
        const char* TRANSITION_DIVISION_EXCHANGE = "EXCHANGE";
        const char* TRANSITION_DIVISION_INVITE = "INVITE";
        const char* TRANSITION_DIVISION_RAID = "RAID";
        const char* TRANSITION_DIVISION_QUEST = "QUEST";
        const char* TRANSITION_DIVISION_HELP = "HELP";
        const char* TRANSITION_DIVISION_LIMIT_BREAK = "LIMIT_BREAK";
        const char* TRANSITION_DIVISION_SKILL = "SKILL";
        const char* TRANSITION_DIVISION_FUSION = "FUSION";
        const char* TRANSITION_DIVISION_CARD_SELL = "CARD_SELL";
        const char* TRANSITION_DIVISION_DECK = "DECK";
        
    }
    
    namespace COMMUNITY{
        
        const char* LOAD_ANY_TOPIC_DATA_LIST = "anyTopicDataList"; // 雑談のトピックリスト
        const char* LOAD_RECRUIT_TOPIC_DATA_LIST = "recruitTopicDataList"; // 募集のトピックリスト
        const char* LOAD_WISH_TOPIC_DATA_LIST = "wishTopicDataList"; // 要望のトピックリスト
        
        
        
        const char* ALL_BBS_TOPIC_DATA_LIST = "allBbsTopicDataList"; // トピックリスト
        //共通で使う
        
        const char* ALL_BBS_TOPIC_ID = "allBbsTopicId"; // トピックID
        const char* ALL_BBS_RESPONSE_ID = "allBbsResponseId"; // メッセージID(整数値)
        const char* DELETED = "deleted"; // 削除フラグ
        const char* TOPIC_ID = "topicId"; // トピックを識別するID(整数値)
        const char* TIME_DATE = "timedate"; // メッセージ投稿日時
        const char* DATE = "date";          // 現在表示されているメッセージの投稿日時で、一番新しい時間を設定
        const char* BBS_STAMP_ID = "bbsStampId";    // スタンプID
        const char* COMMENT = "comment";
        const char* TITLE = "title";  // トピックのタイトル
        const char* MESSAGE_ID = "messageId"; // メッセージID(整数値)
        const char* EVAL_TOPIC_ID = "evalTopicId"; // 現在画面に表示されている中で、最も新しいメッセージのID
        const char* EVAL_RESPONSE_ID = "evalResponseId"; // 現在画面に表示されている中で、最も新しいメッセージのID
        const char* ROW_COUNT = "rowCount"; //取得数
        const char* ALL_BBS_TOPIC_DIVISION_STR = "allBbsTopicDivisionStr"; // 投稿トピック種別(ANY(雑談)、RECRUIT(募集)、WISH(要望))
        const char* LIST_SIZE = "listSize";  // 投稿されたメッセージの件数
        const char* PAGE = "page";// 表示ページを表す1以上の整数値
        const char* ANY_PAGE_TOTAL_NUM = "anyPageTotalNum"; // 雑談のページ総数
        const char* RECRUIT_PAGE_TOTAL_NUM = "recruitPageTotalNum"; // 募集のページ総数
        const char* WISH_PAGE_TOTAL_NUM = "wishPageTotalNum"; // 要望のページ総数
        const char* PAGE_TOTAL_NUM = "pageTotalNum"; // 要望のページ総数
        const char* IS_POSTED_MESSAGE_TOPIC = "isPostedMessageTopic"; // 要望のページ総数
        const char* CURRENT_PAGE_NUM = "currentPageNum"; // 現在のページの位置を表す
        
        const char* LOAD_USER_ID = "userId";  // トピックを立てたユーザーID(整数値)
        const char* LOAD_USER_NAME = "userName";  // トピックを作成したユーザー名
        const char* LOAD_DIVISION = "division";    // トピックの種別
        const char* LOAD_COUNT = "count";  // 投稿されたメッセージの件数
        const char* LOAD_HAS_OWN_MESSAGE = "hasOwnMessage"; // 自分で投稿したメッセージが含まれていればtrue、含まれていなければfalse
        const char* LOAD_UPDATE_DATE = "updateDate"; // 最終更新日
        
        const char* LOAD_IS_SELF_TOPIC = "isSelfTopic"; // false固定
        
        const char* DELETE_IS_DELETE_SUCCESS = "isDeleteSuccess";  // 成功の場合true
        
        const char* CREATE_TITLE = "title"; // 投稿トピックのタイトル
        
        const char* RESPONSE_LOAD_BBS_DATA_LIST = "bbsDataList"; //データのリスト
        
        
        // 投稿トピック種別(ANY(雑談)、RECRUIT(募集)、WISH(要望))
        const char* ALL_BBS_TOPIC_DIVISION_STR_ANY = "ANY";
        const char* ALL_BBS_TOPIC_DIVISION_STR_RECRUIT = "RECRUIT";
        const char* ALL_BBS_TOPIC_DIVISION_STR_WISH = "WISH";
        
        
        
        
        
    }
    
    
    namespace GUILD{
        //ギルドAPIパラメータ
        
        const char* GUILD_INFO_GUILD_INFO ="guildInfo";
        const char* GUILD_INFO_GUILD_INFO_COUNT ="guildInfoCount"; //ギルド情報数
        const char* GUILD_INFO_GUILD_ACTION_HISTORY_LIST = "guildActionHistoryList"; //ギルド情報リスト
        const char* GUILD_INFO_USER_ID = "userId";
        const char* GUILD_INFO_NAME = "name";
        const char* GUILD_INFO_AVATER_ID = "avatarId";
        const char* GUILD_INFO_ACTION_DIVISION = "actionDivision"; //情報タイプ[GET_CARD:カード獲得, CARD_LEVEL_UP:カードレベル上昇, RAID_ENCOUNT:レイドボス遭遇, SKILL_MASTER:スキルMAX]
        const char* GUILD_INFO_CARD_ID = "cardId"; //カードID(nullの場合あり)
        const char* GUILD_INFO_RAID_BOSS_ID = "raidBossId"; //レイドボスID(nullの場合あり)
        const char* GUILD_INFO_RAID_BOSS_NAME = "raidBossName";
        const char* GUILD_INFO_SKILL_ID = "skillId"; //スキルID(nullの場合あり)
        const char* GUILD_INFO_SKILL_NAME = "skillName";
        const char* GUILD_INFO_POST_ID = "postId";
        const char* GUILD_INFO_POST_NAME = "postName";
        const char* GUILD_INFO_MESSAGE = "message";
        const char* GUILD_INFO_GREETING = "greeting"; // 祝福済みかどうか
        const char* GUILD_INFO_CREATE_DATE = "createDate";
        
        const char* GUILD_INFO_NEXT_OFFSET = "nextOffset";
        const char* GUILD_INFO_NOT_READ_CHANGE_COUNT = "notReadChangeCount";
        
    }
    
    namespace MAINTENANCE{
        const char* MAINTENANCE_TITLE = "title";
        const char* MAINTENANCE_MESSAGE = "comment";
        
    }
    
    namespace API_MYDATA
    {
        //-----------------------------------------------------------------
        //マイデータAPIパラメータ

        const char*		DECK_DECKATTACK		= "deckAttack";     //: デッキーカード攻撃合計
        const char*		DECK_DECKDEFENSE		= "deckDefense";     //: デッキーカード防御合計
        const char*		DECK_DECKMAGICATTACK		= "deckMagicAttack";     //: 特攻合計
        const char*		DECK_DECKMAGICDEFENSE		= "deckMagicDefense";     //: 特防合計
        const char*		DECK_GUILDBATTLEPOINT		= "guildBattlePoint";     //: トータル合計（攻・防・特攻・防）
        const char*		DECK_RAIDBATTLEPOINT		= "raidBattlePoint";     //: トータル合計（攻・防・特攻・防）
        
        const char*		DECK_CURRENTFORMATIONPOINT		= "currentFormationPoint";     //: デッキー編成にかかるコスト合計
        const char*		DECK_FORMATIONCOUNT         = "formationCount";     //: デッキー編成中のカード枚数
        
        
    }
    
    //-----------------------------------------------------------------
    //メッセージ置換文字列
	const char*		REPLACE_KEY_PLAYER_NAME		= "@@user_name@@";  // プレイヤー名
	const char*		REPLACE_KEY_NEW_LINE		= "¥n";             // 改行コード

    //-----------------------------------------------------------------
    //画像パス置換文字列
	const char*		REPLACE_KEY_PLAYER_IMG_PATH = "@@user_image_path@@";  // プレイヤー画像

    //-----------------------------------------------------------------
    //エスケープ文字
    const char*		ESCAPE_SINGLE_QUOTE		= "\'";             // シングルクオート
    
    
	typedef enum {
		issuePassPopup
	}PopupTAG;
	
	
	const int8_t	monsterListSortTypeCount_g = 17;
	const char*		monsterListSortTypeName_g[monsterListSortTypeCount_g] = {
		"新着順",
		"総戦闘力高い順",
		"総戦闘力低い順",
		"コスト高い順",
		"コスト低い順",
		"レア度高い順",
		"レア度低い順",
		"Lv高い順",
		"Lv低い順",
		"攻高い順",
		"攻低い順",
		"防高い順",
		"防低い順",
		"特攻高い順",
		"特攻低い順",
		"特防高い順",
		"特防低い順",
	};
	const int8_t	monsterListDisplayTypeCount_g = 4;
	const char*		monsterListDisplayTypeName_g[monsterListDisplayTypeCount_g] = {
		"全て",
		"技",
		"力",
		"知",
	};
	const int8_t	rarityAppendCount_g	= 5;
	const char*		rarityAppendName_g[rarityAppendCount_g] = {
		"",
		"+",
		"++",
		"+++",
		"MAX",
	};
	const float		thumbnailLongTapTime_g = 0.2f;


}

#pragma GCC diagnostic warning "-Wunused-variable"
