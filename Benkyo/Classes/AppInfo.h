

#pragma once
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"


//-----------------------------------------------------------------
// マクロ
#define ANDROID_PACKAGE_NAME "test/cocos2dx/chaos/chaos"






//-----------------------------------------------------------------
// アプリ固有の設定値
namespace {
    // TODO:iOSInterface::getApplicationVersion()で取得できるので、そちらを使うように変更する
    const char*     API_VERSION                 = "1.1";        // APIバージョン
    const char*     APP_VERSION_NAME            = "1.3";        // アプリのバンドルバージョン
    const char*     APP_VERSION_CODE            = "4";          // サーバーと連携をとるためのアプリバージョン
    
    const int MAX_LIMIT_BREAK_COUNT                   = 4;
    
    const int QUEST_POINT_HEAL_SEC                    = 60;
    const int RAID_POINT_HEAL_SEC                     = 60;
    const int TECHNICAL_POINT_HEAL_SEC                = 60;
    
    const int NAME_MAX_LENGTH                         = 10;
    const int GUILD_NAME_MAX_LENGTH                   = 13;
    const int ACCOUNT_ID_MAX_LENGTH                   = 9;
    
    
    const int TOPIC_TITLE_MAX_LENGTH                   = 16;
    const int TOPIC_DETAIL_MAX_LENGTH                 = 100;
    
    const int ACCOUNT_STATE_FORM_MAX_LENGTH             = 600;
    
    const int RAID_CONQUER_COUNT_DIFF_OVER_MAX_RECORD = 50;
    const int RAID_CONQUER_COUNT_MAX_RECORD           = 350;
    
    const int MESSAGE_LIST_ROW_MAX                = 1000;
    
    
    const char *DUMMY_IMAGE_NAME                = "ui_dummy.png";
    
    const char *APP_STORE_URL                   = "https://itunes.apple.com/us/app/kaosudoraivu/id643553523?l=ja&ls=1&mt=8";
    
    const char *CONNECTION_ERROR_MESSAGE        = "通信エラーが発生しました。\nお手数ですが通信環境を確認し、再度お試しください。";
}

#pragma clang diagnostic pop
