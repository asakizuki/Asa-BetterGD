#include "./iconSetting.hpp"
#include "./content.hpp"

void IconSettingPopup::keyBackClicked()
{

    this->setKeypadEnabled(false);
    this->setKeyboardEnabled(false);
    this->removeFromParentAndCleanup(true);
    AsaSelectedIcon::ContentLayer *asaLayer = new AsaSelectedIcon::ContentLayer();
    asaLayer->iconSelectedSetting();
};

bool IconSettingPopup::init(CCLayer *)
{
    if (this->initWithColor({0, 0, 0, 125}))
    {
        auto _s = CCDirector::sharedDirector()->getWinSize();
        {
            this->setKeypadEnabled(true);
            this->setKeyboardEnabled(true);

            auto layer = CCLayer::create();
            layer->setContentSize(_s);
            this->m_pLayer = layer;
            this->addChild(this->m_pLayer);

            auto background = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png");
            background->setContentSize({280.0f, 245.0f});
            background->setPosition({_s.width / 2, _s.height / 2});
            this->m_pLayer->addChild(background);

            auto iconOptionsText = CCLabelBMFont::create("Icon Options", "goldFont.fnt");
            background->addChild(iconOptionsText, 1);
            iconOptionsText->setScale(0.75);
            iconOptionsText->setPosition({background->getContentSize().width / 2, background->getContentSize().height - 20});

            auto closeBtn = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
            auto close = CCMenuItemSpriteExtra::create(closeBtn, this, menu_selector(IconSettingPopup::keyBackClicked));
            auto closeMenu = CCMenu::create();
            closeMenu->addChild(close);
            closeMenu->setPosition({10, background->getContentSize().height - 10});
            background->addChild(closeMenu, 1);

            auto settingMenu = CCMenu::create();
            settingMenu->setPosition({45, 195});
            this->m_settingMenu = settingMenu;
            background->addChild(this->m_settingMenu, 1);

            this->addSettingToggle("0100", "Practice Death Effect");
            this->addSettingToggle("0061", "Switch Spider Teleport\nColor");
            this->addSettingToggle("0062", "Switch Dash Fire Color");
            this->addSettingToggle("0096", "Switch Wave Trail Color");
            this->addSettingToggle("0060", "Default Mini Icon");
            this->addSettingToggle("1000", "Custom Second Player");
            this->addSettingToggle("1001", "Fixed Second Player\nPosition");
        }
        return true;
    };
    return false;
};