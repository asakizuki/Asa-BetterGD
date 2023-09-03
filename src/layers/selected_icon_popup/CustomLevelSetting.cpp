#include "./CustomLevelSetting.hpp"

void LevelSettingPopup::keyBackClicked()
{
    this->setKeypadEnabled(false);
    this->setKeyboardEnabled(false);
    this->removeFromParentAndCleanup(true);
}

bool LevelSettingPopup::init(CCLayer *self)
{
    if (!this->initWithColor({0, 0, 0, 125}))
        return false;

    auto dir = CCDirector::sharedDirector();
    auto ws = dir->getWinSize();
    auto gm = GameManager::sharedState();
    auto bg = extension::CCScale9Sprite::create("GJ_square01.png");

    {
        dir->getTouchDispatcher()->incrementForcePrio(2);
        bg->setContentSize({350, 200});
        bg->setPosition({ws.width / 2, ws.height / 2});
        this->m_pLayer = CCLayer::create();
        this->addChild(this->m_pLayer);

        auto exitBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"), this, menu_selector(LevelSettingPopup::keyBack));
        auto exitBtnMenu = CCMenu::create();
        exitBtnMenu->addChild(exitBtn);
        bg->addChild(exitBtnMenu, 1);
        exitBtnMenu->setTouchEnabled(true);
        exitBtnMenu->setPosition({10, bg->getContentSize().height - 10});
        this->m_pLayer->addChild(bg, 1);
        this->setKeyboardEnabled(true);
        this->setKeypadEnabled(true);
        this->setTouchEnabled(true);

        this->levelSetting = GameManager::sharedState()->m_pPlayLayer->m_levelSettings;
        this->playLayer = GameManager::sharedState()->m_pPlayLayer;
        this->level = GameManager::sharedState()->m_pPlayLayer->m_level;
    }
    {
    }
    return true;
};