#include "./selectedLiveOverlay.hpp"

void selectedLiveOverlay::overlay::init(CCLayer *self, ColorAction *col_1, ColorAction *col_2, EffectGameObject *gObj)
{
    auto tggOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
    auto tggOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
    tggOff->setScale(0.7f);
    tggOn->setScale(0.7f);

    auto s = CCDirector::sharedDirector()->getWinSize();
    auto menu = CCMenu::create();

    auto blendingTgg = CCMenuItemToggler::create(tggOff, tggOn, self, menu_selector(selectedLiveOverlay::callback::onBlending));
    blendingTgg->toggle(col_1->m_blending);
    blendingTgg->setTag(1000);
    menu->addChild(blendingTgg);
    menu->setPosition({220, 165});
    self->addChild(menu, 101);
};

void selectedLiveOverlay::overlay::onSelectTab(CCLayer *self, CCObject *obj)
{
    selectedLiveOverlay::overlay *asa;
    auto tgg = static_cast<CCMenuItemToggler *>(static_cast<CCMenu *>(self->getChildren()->objectAtIndex(1))->getChildByTag(1000));
    if (asa->m_detailMode)
        tgg->toggle(asa->m_detailColorAction->m_blending);
    else
        tgg->toggle(asa->m_baseColorAction->m_blending);
};