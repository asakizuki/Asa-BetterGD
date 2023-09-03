#include "./../../includes.hpp"

class LevelSettingPopup : public FLAlertLayer, public FLAlertLayerProtocol, public TextInputDelegate
{
public:
    LevelSettingsObject *levelSetting;
    PlayLayer *playLayer;
    GJGameLevel *level;

    static LevelSettingPopup *create(CCLayer *self)
    {
        LevelSettingPopup *pRet = new LevelSettingPopup();
        if (pRet && pRet->init(self))
        {
            pRet->autorelease();
            return pRet;
        }

        CC_SAFE_DELETE(pRet);
        pRet = nullptr;
        return nullptr;
    }
    bool init(CCLayer *);
    void keyBackClicked();
    void keyBack(CCObject *)
    {
        this->keyBackClicked();
    };
    void callback(CCObject *)
    {
        this->create(this)->show();
    };
};