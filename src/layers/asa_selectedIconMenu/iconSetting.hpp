#include "./../../includes.hpp"
#include <string>

class IconSettingPopup : public FLAlertLayer
{
public:
    CCMenu *m_settingMenu;
    int toggleCount = 0;
    const char *SettingID[50] = {};
    char *SettingDescription[50] = {};

    static IconSettingPopup *create(CCLayer *layer)
    {
        IconSettingPopup *pRet = new IconSettingPopup();
        if (pRet && pRet->init(layer))
        {
            pRet->autorelease();
            return pRet;
        }
        delete pRet;
        pRet = nullptr;
        return nullptr;
    };
    bool init(CCLayer *);
    void keyBackClicked();
    void keyBackClicked(CCObject *)
    {
        this->keyBackClicked();
    };
    void callback(CCObject *)
    {
        this->create(this)->show();
    };

    void SettingAction(CCObject *self)
    {
        GameManager::sharedState()->setGameVariable(this->SettingID[self->getTag()], !GameManager::sharedState()->getGameVariable(this->SettingID[self->getTag()]));
    };

    void SettingHelp(CCObject *self){

    };

    void addSettingToggle(const char *SettingID, const char *SettingName, char *SettingDescription = nullptr)
    {
        auto tggOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
        auto tggOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
        tggOff->setScale(0.85f);
        tggOn->setScale(0.85f);
        auto toggle = CCMenuItemToggler::create(tggOff, tggOn, this, menu_selector(IconSettingPopup::SettingAction));
        toggle->toggle(GameManager::sharedState()->getGameVariable(SettingID));
        toggle->setPositionY(toggle->getPositionY() - (this->toggleCount * 32));

        auto settingNameLabel = CCLabelBMFont::create(SettingName, "bigFont.fnt");
        settingNameLabel->setScale(0.45f);
        settingNameLabel->setPosition({toggle->getPositionX() + 20, toggle->getPositionY()});
        settingNameLabel->setAnchorPoint({0, 0.5f});
        this->m_settingMenu->addChild(toggle, 1);
        this->m_settingMenu->addChild(settingNameLabel, 1);
        toggle->setTag(this->toggleCount);

        this->SettingID[this->toggleCount] = SettingID;
        this->SettingDescription[this->toggleCount] = SettingDescription;
        this->toggleCount++;
    };
};