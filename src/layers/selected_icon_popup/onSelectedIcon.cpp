#include "./onSelectedIcon.hpp"
#include "../asa_player2_icon/content.hpp"
#include "../../libarries/iconRenderer.hpp"
#include "./content.hpp"

int selectedIconType = 0;

void updatePlayerIconInPlay(PlayerObject *player)
{
    auto gameManage = GameManager::sharedState();

    player->updatePlayerFrame(gameManage->getPlayerFrame());
    player->updatePlayerShipFrame(gameManage->getPlayerShip());
    player->updatePlayerRollFrame(gameManage->getPlayerBall());
    player->updatePlayerBirdFrame(gameManage->getPlayerBird());
    player->updatePlayerDartFrame(gameManage->getPlayerDart());
    player->m_pRobot->updateFrame(gameManage->getPlayerRobot());
    player->m_pSpider->updateFrame(gameManage->getPlayerSpider());

    if (player->m_isShip)
    {
        player->updatePlayerShipFrame(gameManage->getPlayerShip());
        player->updatePlayerFrame(gameManage->getPlayerFrame());
    }
    else if (player->m_isBall)
        player->updatePlayerRollFrame(gameManage->getPlayerBall());
    else if (player->m_isBird)
    {
        player->updatePlayerBirdFrame(gameManage->getPlayerBird());
        player->updatePlayerFrame(gameManage->getPlayerFrame());
    }
    else if (player->m_isDart)
        player->updatePlayerDartFrame(gameManage->getPlayerDart());
    else if (player->m_isRobot)
        player->m_pRobot->updateFrame(gameManage->getPlayerRobot());
    else if (player->m_isSpider)
        player->m_pSpider->updateFrame(gameManage->getPlayerSpider());
    else
        player->updatePlayerFrame(gameManage->getPlayerFrame());
}

void SelectedIconScreen::scrollWheel(float _dy, float _dx)
{
    auto lr = this->m_pScrollingLayer->m_pScrollLayer;
    auto dest = lr->getPositionY() + _dy * 2;
    lr->setPositionY(dest);
    if (dest < 0)
        lr->setPositionY(0);
    if (dest > this->m_pScrollingLayer->m_fLayerHeight)
        lr->setPositionY(this->m_pScrollingLayer->m_fLayerHeight);
}

void SelectedIconScreen::setIcon(CCObject *btn)
{
    auto gm = GameManager::sharedState();
    switch (selectedIconType)
    {
    case 0:
        gm->setPlayerFrame(btn->getTag());
        break;
    case 1:
        gm->setPlayerShip(btn->getTag());
        break;
    case 2:
        gm->setPlayerBall(btn->getTag());
        break;
    case 3:
        gm->setPlayerBird(btn->getTag());
        break;
    case 4:
        gm->setPlayerDart(btn->getTag());
        break;
    case 5:
        gm->setPlayerRobot(btn->getTag());
        break;
    case 6:
        gm->setPlayerSpider(btn->getTag());
        break;
    }

    updatePlayerIconInPlay(gm->getPlayLayer()->m_player1);
    updatePlayerIconInPlay(gm->getPlayLayer()->m_player2);
    SelectedIconPopup::updatePlayerIcon(btn->getTag(), selectedIconType);
    this->player[0]->updatePlayerFrame(btn->getTag(), static_cast<IconType>(selectedIconType));
    this->player[1]->updatePlayerFrame(btn->getTag(), static_cast<IconType>(selectedIconType));
    this->selectedIcon->setPosition(static_cast<CCLayer *>(btn)->getPosition());
}

void SelectedIconScreen::loadIconList()
{
    float posX = 0;
    float posY = 0;
    auto gm = GameManager::sharedState();
    auto iconMenu = CCMenu::create();
    iconMenu->setPosition({241, 220});

    auto col1 = gm->colorForIdx(gm->getPlayerColor());
    auto col2 = gm->colorForIdx(gm->getPlayerColor2());
    auto glow = gm->getPlayerGlow();
    auto selectedIcon = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
    this->selectedIcon = selectedIcon;
    iconMenu->addChild(selectedIcon, 2);
    for (int iconId = 0; iconId < SecondPlayer::getMaxIcon(selectedIconType) - 1; iconId++)
    {
        CCSprite *icon;
        int currentIcon;
        switch (selectedIconType)
        {
        case 0:
            icon = PlayerRenderer::cubeRenderer(col1, col2, iconId + 1, glow, 0.9f);
            currentIcon = gm->getPlayerFrame();
            break;
        case 1:
            icon = PlayerRenderer::shipRenderer(col1, col2, iconId + 1, glow, 0.75f);
            currentIcon = gm->getPlayerShip();
            break;
        case 2:
            icon = PlayerRenderer::ballRenderer(col1, col2, iconId + 1, glow, 0.9f);
            currentIcon = gm->getPlayerBall();
            break;
        case 3:
            icon = PlayerRenderer::ufoRenderer(col1, col2, iconId + 1, glow, 0.75f);
            currentIcon = gm->getPlayerBird();
            break;
        case 4:
            icon = PlayerRenderer::waveRenderer(col1, col2, iconId + 1, glow, 0.9f);
            currentIcon = gm->getPlayerDart();
            break;
        case 5:
            icon = PlayerRenderer::robotRenderer(col1, col2, iconId + 1, glow, 0.85f);
            currentIcon = gm->getPlayerRobot();
            break;
        case 6:
            icon = PlayerRenderer::spiderRenderer(col1, col2, iconId + 1, glow, 0.8f);
            currentIcon = gm->getPlayerSpider();
            break;
        }

        if (currentIcon == iconId + 1)
            selectedIcon->setPosition({posX, posY});

        auto btn = CCMenuItemSpriteExtra::create(icon, this, menu_selector(SelectedIconScreen::setIcon));
        btn->setPosition({posX, posY});
        btn->setTag(iconId + 1);
        posX += 35;
        iconMenu->addChild(btn, 1);
        if (iconId % 10 == 9)
        {
            posX = 0;
            posY -= 35;
        }
    }
    this->m_pScrollingLayer->m_pScrollLayer->addChild(iconMenu, 1);
}

void SelectedIconScreen::keyBackClicked()
{
    this->setKeypadEnabled(false);
    this->setTouchEnabled(false);
    this->setKeyboardEnabled(false);
    this->removeFromParentAndCleanup(true);
}

void SelectedIconScreen::callback(CCObject *btn)
{
    selectedIconType = btn->getTag();
    this->create(this)->show();
};

CCLayer *SelectedIconScreen::iconPreview()
{
    auto previewIconLayer = CCLayer::create();

    auto gameManage = GameManager::sharedState();
    auto color1 = gameManage->colorForIdx(gameManage->getPlayerColor());
    auto color2 = gameManage->colorForIdx(gameManage->getPlayerColor2());
    auto hasglow = gameManage->getPlayerGlow();
    CCSprite *p1;
    CCSprite *p2;

    switch (selectedIconType)
    {
    case 0:
        p1 = PlayerRenderer::cubeRenderer(color1, color2, gameManage->getPlayerFrame(), hasglow);
        p2 = PlayerRenderer::cubeRenderer(color2, color1, gameManage->getPlayerFrame(), hasglow);
        break;
    case 1:
        p1 = PlayerRenderer::shipRenderer(color1, color2, gameManage->getPlayerShip(), hasglow);
        p2 = PlayerRenderer::shipRenderer(color2, color1, gameManage->getPlayerShip(), hasglow);
        break;
    case 2:
        p1 = PlayerRenderer::ballRenderer(color1, color2, gameManage->getPlayerBall(), hasglow);
        p2 = PlayerRenderer::ballRenderer(color2, color1, gameManage->getPlayerBall(), hasglow);
        break;
    case 3:
        p1 = PlayerRenderer::ufoRenderer(color1, color2, gameManage->getPlayerBird(), hasglow);
        p2 = PlayerRenderer::ufoRenderer(color2, color1, gameManage->getPlayerBird(), hasglow);
        break;
    case 4:
        p1 = PlayerRenderer::waveRenderer(color1, color2, gameManage->getPlayerDart(), hasglow);
        p2 = PlayerRenderer::waveRenderer(color2, color1, gameManage->getPlayerDart(), hasglow);
        break;
    case 5:
        p1 = PlayerRenderer::robotRenderer(color1, color2, gameManage->getPlayerRobot(), hasglow);
        p2 = PlayerRenderer::robotRenderer(color2, color1, gameManage->getPlayerRobot(), hasglow);
        break;
    case 6:
        p1 = PlayerRenderer::spiderRenderer(color1, color2, gameManage->getPlayerSpider(), hasglow);
        p2 = PlayerRenderer::spiderRenderer(color2, color1, gameManage->getPlayerSpider(), hasglow);
        break;
    }

    this->player[0] = static_cast<SimplePlayer *>(p1->getChildByTag(0));
    this->player[1] = static_cast<SimplePlayer *>(p2->getChildByTag(0));

    p1->setPositionX(-50);
    p2->setPositionX(50);
    previewIconLayer->addChild(p1, 1);
    previewIconLayer->addChild(p2, 1);
    return previewIconLayer;
}

bool SelectedIconScreen::init(CCLayer *thisLayer)
{
    if (this->initWithColor({0, 0, 0, 125}))
    {
        auto dir = CCDirector::sharedDirector();
        auto winSize = dir->getWinSize();
        auto gameManage = GameManager::sharedState();
        auto background = extension::CCScale9Sprite::create("GJ_square05.png");
        {
            background->setContentSize({420, 270});
            background->setPosition({winSize.width / 2, winSize.height / 2});
            dir->getTouchDispatcher()->incrementForcePrio(2);
            dir->getTouchDispatcher()->addTargetedDelegate(this, -100, true);
            this->m_pLayer = CCLayer::create();
            this->m_pLayer->setContentSize(winSize);
            this->m_pLayer->addChild(background, 1);
            this->addChild(this->m_pLayer);

            auto exitBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"), this, menu_selector(SelectedIconScreen::keyBack));
            auto exitBtnMenu = CCMenu::create();
            exitBtnMenu->addChild(exitBtn);
            background->addChild(exitBtnMenu, 1);
            exitBtnMenu->setTouchEnabled(true);
            exitBtnMenu->setPosition({10, background->getContentSize().height - 10});
        }
        {
            this->setKeypadEnabled(true);
            this->setKeyboardEnabled(true);
            this->setTouchEnabled(true);
            this->setMouseEnabled(true);
        }

        {
            auto iconBG = extension::CCScale9Sprite::create("square02_small.png");
            iconBG->setPosition({210, 115});
            iconBG->setContentSize({360, 175});
            iconBG->setOpacity(90);
            background->addChild(iconBG);

            auto preview = this->iconPreview();
            preview->setPosition({background->getContentSize().width / 2, 235});
            background->addChild(preview, 1);

            int scrollHeightSize = ((SecondPlayer::getMaxIcon(selectedIconType) - 1) / 10) * 35;
            auto scrollLayer = ScrollingLayer::create({390, 158}, {390, 158}, static_cast<float>(scrollHeightSize - 125));
            scrollLayer->setPosition({-218, -71});
            this->m_pScrollingLayer = scrollLayer;
            iconBG->addChild(scrollLayer);
            static_cast<CCLayer *>(scrollLayer->getChildren()->objectAtIndex(0))->setVisible(false);
            this->loadIconList();
                }
        return true;
    }
    return false;
}