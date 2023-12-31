#include "./../../includes.hpp"

class PauseLayerInit
{
public:
    static void init(CCLayer *self);
    void noclipActive(CCLayer *);
    void setting(CCLayer *)
    {
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        auto settingLayer = reinterpret_cast<FLAlertLayer *(__fastcall *)()>(base + 0x1de850)();
        reinterpret_cast<void(__thiscall *)(FLAlertLayer *)>(base + 0x23560)(settingLayer);
    };
    void challenge(CCLayer *)
    {
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        auto challengeLayer = reinterpret_cast<FLAlertLayer *(__fastcall *)()>(base + 0x3e050)();
        reinterpret_cast<void(__thiscall *)(FLAlertLayer *)>(base + 0x23560)(challengeLayer);
    };
    void InfoLayer(CCLayer *)
    {
        auto scene = CCDirector::sharedDirector()->getRunningScene();
        auto gameManage = GameManager::sharedState();

        auto infoLayer = reinterpret_cast<FLAlertLayer *(__fastcall *)(GJGameLevel *, GJUserScore *)>(base + 0x14f4f0)(gameManage->m_pPlayLayer->m_level, nullptr);
        reinterpret_cast<void(__thiscall *)(FLAlertLayer *)>(base + 0x23560)(infoLayer);
    }
};