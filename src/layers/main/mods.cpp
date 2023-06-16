#include "./mods.hpp"
#include "./../asa_selectedIconMenu/content.hpp"

void MainMenuMods::customBackground(CCLayer *self)
{
    auto winsize = CCDirector::sharedDirector()->getWinSize();
    std::string bgURL = "asakizuki/background.jpg";

    auto bg = CCSprite::create(bgURL.c_str());

    if (bg)
    {
        auto quickWidth = winsize.width / bg->getContentSize().width;
        auto quickHeight = winsize.height / bg->getContentSize().height;

        if (quickHeight > (bg->getScaleY() * quickWidth))
        {
            bg->setScaleY(quickHeight);
            bg->setScaleX(bg->getScaleX() * quickHeight);
        }
        else
        {
            bg->setScaleX(quickWidth);
            bg->setScaleY(bg->getScaleY() * quickWidth);
        }

        bg->setPositionX(winsize.width / 2);
        bg->setPositionY(winsize.height / 2);

        ((CCNode *)self->getChildren()->objectAtIndex(0))
            ->addChild(bg, 50);
    }
};

void MainMenuMods::secondPlayerSelectedIcon(CCLayer *self)
{
    auto winsize = CCDirector::sharedDirector()->getWinSize();
    self->getChildren()->removeObjectAtIndex(5);

    auto btnTex = CCSprite::createWithSpriteFrameName("GJ_createBtn_001.png");
    auto btn = CCMenuItemSpriteExtra::create(btnTex, self, menu_selector(AsaSelectedIcon::ContentLayer::callback));
    auto menu = CCMenu::create();
    btnTex->setScale(0.75f);

    menu->addChild(btn);
    menu->setPosition(winsize.width - 5 - (btnTex->getContentSize().width / 2), 5 + (btnTex->getContentSize().height / 2));
    menu->setAnchorPoint({0, 1});
    self->addChild(menu);
};