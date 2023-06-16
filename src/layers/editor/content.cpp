#include "./content.hpp"

void EditorLayerInit::init(CCLayer *self, LevelEditorLayer *lvl)
{
    // Preview Mode Toggle
    auto size = CCDirector::sharedDirector()->getWinSize();
    auto menu = CCMenu::create();
    auto tggOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
    auto tggOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
    tggOff->setScale(0.7f);
    tggOn->setScale(0.7f);

    auto _prevMode = CCMenuItemToggler::create(tggOff, tggOn, self, menu_selector(EditorMods::prevMode));
    _prevMode->toggle(GameManager::sharedState()->getGameVariable("0036"));
    auto prevmodelab = CCLabelBMFont::create("Prev\nMode", "bigFont.fnt");
    prevmodelab->setScale(0.35f);
    prevmodelab->setPosition({30, 0});
    menu->addChild(_prevMode);
    menu->addChild(prevmodelab);
    menu->setPosition({size.width - 141, size.height - 20});
    menu->setVisible(false);
    self->addChild(menu, 100);

    // Build Helper Button
    auto btnBGTemp = CCSprite::create("GJ_button_01.png");
    btnBGTemp->setScale(0.75f);
    auto scaleBtn = CCMenuItemSpriteExtra::create(btnBGTemp, self, menu_selector(EditorMods::buildHelper));
    scaleBtn->setPosition({-117, -40});
    auto buildLa = CCLabelBMFont::create("Build", "bigFont.fnt");
    auto helperLa = CCLabelBMFont::create("Helper", "bigFont.fnt");
    buildLa->setPosition({15, 19});
    buildLa->setScale(0.28f);
    helperLa->setPosition({15, 12});
    helperLa->setScale(0.22f);
    scaleBtn->addChild(buildLa);
    scaleBtn->addChild(helperLa);

    auto getBtnMenu = reinterpret_cast<CCMenu *>(self->getChildren()->objectAtIndex(21));
    getBtnMenu->addChild(scaleBtn, 10);
};