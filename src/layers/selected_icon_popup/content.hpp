#include "./../../includes.hpp"

class SelectedIconPopup : public FLAlertLayer
{
protected:
    CCMenu *colorMenu;
    CCMenu *iconButtonMenu;
    SimplePlayer *iconKitList[14];
    CCSprite *colorSelected_1;
    CCSprite *colorSelected_2;
    CCSprite *colorSelectedType;
    CCSprite *promanyColor;
    CCSprite *secondColor;

public:
    static SelectedIconPopup *create(CCLayer *self)
    {
        SelectedIconPopup *pRet = new SelectedIconPopup();
        if (pRet && pRet->init(self))
        {
            pRet->autorelease();
            return pRet;
        }
        delete pRet;
        pRet = nullptr;
        return nullptr;
    };
    void iconUpdate();

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
    CCMenuItemSpriteExtra *createColorButton(int colorID = 0)
    {
        auto colorByID = GameManager::sharedState()->colorForIdx(colorID);
        auto colorBtnTexture = CCSprite::createWithSpriteFrameName("GJ_colorBtn_001.png");
        colorBtnTexture->setColor(colorByID);
        colorBtnTexture->setScale(0.7f);
        auto button = CCMenuItemSpriteExtra::create(colorBtnTexture, this, menu_selector(SelectedIconPopup::setPlayerColor));
        button->setTag(colorID);
        return button;
    };

    void colorSelectedMode(CCObject *);
    void setPlayerColor(CCObject *);

    CCMenuItemSpriteExtra *createIconButton(int iconID, int iconType, ccColor3B col1, ccColor3B col2, bool hasGlow);
    static void updatePlayerIcon(int iconId, int iconType);
    void updateGlow(CCObject *);
};