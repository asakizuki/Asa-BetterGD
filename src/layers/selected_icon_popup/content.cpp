#include "./content.hpp"
#include "../../libarries/iconRenderer.hpp"
#include "./onSelectedIcon.hpp"

bool isSetSecondColor = false;
int iconList = 0;
SimplePlayer *currentIconList[14];

void SelectedIconPopup::keyBackClicked()
{
    this->setKeypadEnabled(false);
    this->setKeyboardEnabled(false);
    this->removeFromParentAndCleanup(true);
};

void SelectedIconPopup::updatePlayerIcon(int id, int type)
{
    currentIconList[type]->updatePlayerFrame(id, static_cast<IconType>(type));
    currentIconList[type + 7]->updatePlayerFrame(id, static_cast<IconType>(type));
}

CCMenuItemSpriteExtra *SelectedIconPopup::createIconButton(int iconID, int iconType, ccColor3B col1, ccColor3B col2, bool hasGlow)
{
    CCSprite *iconTexture;

    switch (iconType)
    {
    case 0:
        iconTexture = PlayerRenderer::cubeRenderer(col1, col2, iconID, hasGlow);
        break;
    case 1:
        iconTexture = PlayerRenderer::shipRenderer(col1, col2, iconID, hasGlow);
        break;
    case 2:
        iconTexture = PlayerRenderer::ballRenderer(col1, col2, iconID, hasGlow);
        break;
    case 3:
        iconTexture = PlayerRenderer::ufoRenderer(col1, col2, iconID, hasGlow);
        break;
    case 4:
        iconTexture = PlayerRenderer::waveRenderer(col1, col2, iconID, hasGlow);
        break;
    case 5:
        iconTexture = PlayerRenderer::robotRenderer(col1, col2, iconID, hasGlow);
        break;
    case 6:
        iconTexture = PlayerRenderer::spiderRenderer(col1, col2, iconID, hasGlow);
        break;
    }

    this->iconKitList[iconList] = static_cast<SimplePlayer *>(iconTexture->getChildByTag(0));
    currentIconList[iconList] = static_cast<SimplePlayer *>(iconTexture->getChildByTag(0));
    iconList += 1;
    auto button = CCMenuItemSpriteExtra::create(iconTexture, this, menu_selector(SelectedIconScreen::callback));
    button->setTag(iconType);
    return button;
};

void setColorC(PlayerObject *playerObject)
{
    auto gm = GameManager::sharedState();
    auto c1 = gm->colorForIdx(gm->getPlayerColor());
    auto c2 = gm->colorForIdx(gm->getPlayerColor2());
    playerObject->m_iconGlow->setColor(c2);
    playerObject->m_bHasGlow = gm->getPlayerGlow();

    playerObject->setColor(c1);
    playerObject->setSecondColor(c2);
    playerObject->updatePlayerGlow();
}

void setColorB(PlayerObject *playerObject)
{
    auto gm = GameManager::sharedState();
    auto c1 = gm->colorForIdx(gm->getPlayerColor());
    auto c2 = gm->colorForIdx(gm->getPlayerColor2());

    playerObject->setColor(c2);
    playerObject->setSecondColor(c1);
    playerObject->m_iconGlow->setColor(c1);
    playerObject->m_bHasGlow = gm->getPlayerGlow();
    playerObject->updatePlayerGlow();
}

void SelectedIconPopup::iconUpdate()
{
    auto gm = GameManager::sharedState();
    auto c1 = gm->colorForIdx(gm->getPlayerColor());
    auto c2 = gm->colorForIdx(gm->getPlayerColor2());
    auto glow = gm->getPlayerGlow();

    setColorC(gm->getPlayLayer()->m_player1);
    setColorB(gm->getPlayLayer()->m_player2);

    for (int index = 0; index < 7; index++)
    {
        this->iconKitList[index]->setColor(c1);
        this->iconKitList[index]->setSecondColor(c2);
        this->iconKitList[index]->setGlowOutline(glow);
        this->iconKitList[index + 7]->setColor(c2);
        this->iconKitList[index + 7]->setSecondColor(c1);
        this->iconKitList[index + 7]->setGlowOutline(glow);
    }
}

void SelectedIconPopup::updateGlow(CCObject *)
{
    auto gm = GameManager::sharedState();
    gm->setPlayerGlow(!gm->getPlayerGlow());
    this->iconUpdate();
}

bool SelectedIconPopup::init(CCLayer *layer)
{
    iconList = 0;
    if (this->initWithColor({0, 0, 0, 125}))
    {
        auto _s = CCDirector::sharedDirector()->getWinSize();
        auto layer = CCLayer::create();
        auto _gm = GameManager::sharedState();
        layer->setContentSize(_s);
        this->m_pLayer = layer;
        auto _bg = extension::CCScale9Sprite::create("GJ_square05.png");

        CCDirector::sharedDirector()->getTouchDispatcher()->incrementForcePrio(2);
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -100, true);
        this->addChild(this->m_pLayer);
        {
            _bg->setPosition({_s.width / 2, _s.height / 2});
            _bg->setContentSize({450, 280});
            this->m_pLayer->addChild(_bg, 1);
            auto _bgS = _bg->getContentSize();

            auto exitBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png"), this, menu_selector(SelectedIconPopup::keyBack));
            auto exitBtnMenu = CCMenu::create();
            exitBtnMenu->addChild(exitBtn);
            _bg->addChild(exitBtnMenu, 1);
            exitBtnMenu->setTouchEnabled(true);
            exitBtnMenu->setPosition({10, _bgS.height - 10});
            exitBtnMenu->setTouchMode(kCCTouchesAllAtOnce);
        }

        {
            auto colorMenu = CCMenu::create();
            colorMenu->setPosition({50, 135});
            this->m_pButtonMenu = colorMenu;
            _bg->addChild(this->m_pButtonMenu);
            colorMenu->setTouchMode(kCCTouchesAllAtOnce);

            auto colorSelected_1 = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
            colorSelected_1->setScale(0.75f);
            colorSelected_1->setTag(101);
            colorMenu->addChild(colorSelected_1, 2);

            auto colorSelected_2 = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
            colorSelected_2->setScale(0.75f);
            colorSelected_2->setTag(102);
            colorMenu->addChild(colorSelected_2, 1);
            colorSelected_2->setColor({50, 50, 50});

            this->colorSelected_1 = colorSelected_1;
            this->colorSelected_2 = colorSelected_2;

            auto green1 = this->createColorButton(0);
            auto green2 = this->createColorButton(1);
            auto green3 = this->createColorButton(2);
            auto green4 = this->createColorButton(27);
            auto green5 = this->createColorButton(32);
            auto green6 = this->createColorButton(28);
            auto green7 = this->createColorButton(38);
            auto green8 = this->createColorButton(20);
            auto green9 = this->createColorButton(33);
            green2->setPosition({green1->getPositionX() + 25, green1->getPositionY()});
            green3->setPosition({green2->getPositionX() + 25, green1->getPositionY()});
            green4->setPosition({green1->getPositionX(), green1->getPositionY() - 25});
            green5->setPosition({green4->getPositionX() + 25, green4->getPositionY()});
            green6->setPosition({green5->getPositionX() + 25, green4->getPositionY()});
            green7->setPosition({green4->getPositionX(), green4->getPositionY() - 25});
            green8->setPosition({green7->getPositionX() + 25, green7->getPositionY()});
            green9->setPosition({green8->getPositionX() + 25, green7->getPositionY()});
            colorMenu->addChild(green1);
            colorMenu->addChild(green2);
            colorMenu->addChild(green3);
            colorMenu->addChild(green4);
            colorMenu->addChild(green5);
            colorMenu->addChild(green6);
            colorMenu->addChild(green7);
            colorMenu->addChild(green8);
            colorMenu->addChild(green9);

            auto blue1 = this->createColorButton(3);
            auto blue2 = this->createColorButton(16);
            auto blue3 = this->createColorButton(4);
            auto blue4 = this->createColorButton(5);
            auto blue5 = this->createColorButton(21);
            auto blue6 = this->createColorButton(34);
            auto blue7 = this->createColorButton(22);
            auto blue8 = this->createColorButton(39);
            blue1->setPosition({green3->getPositionX() + 49, green3->getPositionY()});
            blue2->setPosition({blue1->getPositionX() + 25, blue1->getPositionY()});
            blue3->setPosition({blue2->getPositionX() + 25, blue1->getPositionY()});
            blue4->setPosition({blue1->getPositionX(), blue1->getPositionY() - 25});
            blue5->setPosition({blue4->getPositionX() + 25, blue4->getPositionY()});
            blue6->setPosition({blue5->getPositionX() + 25, blue4->getPositionY()});
            blue7->setPosition({blue4->getPositionX(), blue4->getPositionY() - 25});
            blue8->setPosition({blue7->getPositionX() + 25, blue7->getPositionY()});

            colorMenu->addChild(blue1);
            colorMenu->addChild(blue2);
            colorMenu->addChild(blue3);
            colorMenu->addChild(blue4);
            colorMenu->addChild(blue5);
            colorMenu->addChild(blue6);
            colorMenu->addChild(blue7);
            colorMenu->addChild(blue8);

            auto purple1 = this->createColorButton(6);
            auto purple2 = this->createColorButton(13);
            auto purple3 = this->createColorButton(7);
            auto purple4 = this->createColorButton(8);
            auto purple5 = this->createColorButton(23);
            auto purple6 = this->createColorButton(35);
            auto purple7 = this->createColorButton(24);
            auto purple8 = this->createColorButton(36);
            auto purple9 = this->createColorButton(25);
            purple1->setPosition({blue3->getPositionX() + 49, blue3->getPositionY()});
            purple2->setPosition({purple1->getPositionX() + 25, purple1->getPositionY()});
            purple3->setPosition({purple2->getPositionX() + 25, purple1->getPositionY()});
            purple4->setPosition({purple1->getPositionX(), purple1->getPositionY() - 25});
            purple5->setPosition({purple4->getPositionX() + 25, purple4->getPositionY()});
            purple6->setPosition({purple5->getPositionX() + 25, purple4->getPositionY()});
            purple7->setPosition({purple4->getPositionX(), purple4->getPositionY() - 25});
            purple8->setPosition({purple7->getPositionX() + 25, purple7->getPositionY()});
            purple9->setPosition({purple8->getPositionX() + 25, purple7->getPositionY()});
            colorMenu->addChild(purple1);
            colorMenu->addChild(purple2);
            colorMenu->addChild(purple3);
            colorMenu->addChild(purple4);
            colorMenu->addChild(purple5);
            colorMenu->addChild(purple6);
            colorMenu->addChild(purple7);
            colorMenu->addChild(purple8);
            colorMenu->addChild(purple9);

            auto red1 = this->createColorButton(9);
            auto red2 = this->createColorButton(29);
            auto red3 = this->createColorButton(10);
            auto red4 = this->createColorButton(14);
            auto red5 = this->createColorButton(11);
            auto red6 = this->createColorButton(37);
            auto red7 = this->createColorButton(30);
            auto red8 = this->createColorButton(26);
            auto red9 = this->createColorButton(31);
            auto red10 = this->createColorButton(19);
            auto red11 = this->createColorButton(40);
            auto red12 = this->createColorButton(41);

            red1->setPosition({purple3->getPositionX() + 49, purple3->getPositionY()});
            red2->setPosition({red1->getPositionX() + 25, red1->getPositionY()});
            red3->setPosition({red2->getPositionX() + 25, red1->getPositionY()});
            red4->setPosition({red1->getPositionX(), red3->getPositionY() - 25});
            red5->setPosition({red4->getPositionX() + 25, red4->getPositionY()});
            red6->setPosition({red5->getPositionX() + 25, red4->getPositionY()});
            red7->setPosition({red4->getPositionX(), red6->getPositionY() - 25});
            red8->setPosition({red7->getPositionX() + 25, red7->getPositionY()});
            red9->setPosition({red8->getPositionX() + 25, red7->getPositionY()});
            red10->setPosition({red7->getPositionX(), red9->getPositionY() - 25});
            red11->setPosition({red10->getPositionX() + 25, red10->getPositionY()});
            red12->setPosition({red11->getPositionX() + 25, red10->getPositionY()});
            colorMenu->addChild(red1);
            colorMenu->addChild(red2);
            colorMenu->addChild(red3);
            colorMenu->addChild(red4);
            colorMenu->addChild(red5);
            colorMenu->addChild(red6);
            colorMenu->addChild(red7);
            colorMenu->addChild(red8);
            colorMenu->addChild(red9);
            colorMenu->addChild(red10);
            colorMenu->addChild(red11);
            colorMenu->addChild(red12);

            auto white2 = this->createColorButton(17);
            auto white3 = this->createColorButton(18);
            auto white4 = this->createColorButton(15);
            auto white1 = this->createColorButton(12);
            white1->setPosition({green7->getPositionX(), green7->getPositionY() - 45});
            white2->setPosition({white1->getPositionX() + 25, white1->getPositionY()});
            white3->setPosition({white2->getPositionX() + 25, white1->getPositionY()});
            white4->setPosition({white3->getPositionX() + 25, white1->getPositionY()});
            colorMenu->addChild(white2);
            colorMenu->addChild(white3);
            colorMenu->addChild(white4);
            colorMenu->addChild(white1);

            this->colorSelected_1->setPosition(colorMenu->getChildByTag(_gm->m_nPlayerColor)->getPosition());
            this->colorSelected_2->setPosition(colorMenu->getChildByTag(_gm->m_nPlayerColor2)->getPosition());
        }
        this->setKeypadEnabled(true);
        this->setKeyboardEnabled(true);
        this->setTouchEnabled(true);

        {
            // Icon Renderer
            this->iconButtonMenu = CCMenu::create();
            auto iconBG = extension::CCScale9Sprite::create("square02_small.png");
            iconBG->setPosition({280, 232});
            iconBG->setContentSize({340, 96});
            iconBG->setOpacity(125);
            iconBG->setTag(1000);
            iconBG->addChild(iconButtonMenu, 1);
            iconButtonMenu->setPosition({30, 70});

            auto cube = this->createIconButton(_gm->getPlayerFrame(), 0, _gm->colorForIdx(_gm->getPlayerColor()), _gm->colorForIdx(_gm->getPlayerColor2()), _gm->getPlayerGlow());
            auto ship = this->createIconButton(_gm->getPlayerShip(), 1, _gm->colorForIdx(_gm->getPlayerColor()), _gm->colorForIdx(_gm->getPlayerColor2()), _gm->getPlayerGlow());
            auto ball = this->createIconButton(_gm->getPlayerBall(), 2, _gm->colorForIdx(_gm->getPlayerColor()), _gm->colorForIdx(_gm->getPlayerColor2()), _gm->getPlayerGlow());
            auto bird = this->createIconButton(_gm->getPlayerBird(), 3, _gm->colorForIdx(_gm->getPlayerColor()), _gm->colorForIdx(_gm->getPlayerColor2()), _gm->getPlayerGlow());
            auto dart = this->createIconButton(_gm->getPlayerDart(), 4, _gm->colorForIdx(_gm->getPlayerColor()), _gm->colorForIdx(_gm->getPlayerColor2()), _gm->getPlayerGlow());
            auto robot = this->createIconButton(_gm->getPlayerRobot(), 5, _gm->colorForIdx(_gm->getPlayerColor()), _gm->colorForIdx(_gm->getPlayerColor2()), _gm->getPlayerGlow());
            auto spider = this->createIconButton(_gm->getPlayerSpider(), 6, _gm->colorForIdx(_gm->getPlayerColor()), _gm->colorForIdx(_gm->getPlayerColor2()), _gm->getPlayerGlow());

            auto cube2 = this->createIconButton(_gm->getPlayerFrame(), 0, _gm->colorForIdx(_gm->getPlayerColor2()), _gm->colorForIdx(_gm->getPlayerColor()), _gm->getPlayerGlow());
            auto ship2 = this->createIconButton(_gm->getPlayerShip(), 1, _gm->colorForIdx(_gm->getPlayerColor2()), _gm->colorForIdx(_gm->getPlayerColor()), _gm->getPlayerGlow());
            auto ball2 = this->createIconButton(_gm->getPlayerBall(), 2, _gm->colorForIdx(_gm->getPlayerColor2()), _gm->colorForIdx(_gm->getPlayerColor()), _gm->getPlayerGlow());
            auto bird2 = this->createIconButton(_gm->getPlayerBird(), 3, _gm->colorForIdx(_gm->getPlayerColor2()), _gm->colorForIdx(_gm->getPlayerColor()), _gm->getPlayerGlow());
            auto dart2 = this->createIconButton(_gm->getPlayerDart(), 4, _gm->colorForIdx(_gm->getPlayerColor2()), _gm->colorForIdx(_gm->getPlayerColor()), _gm->getPlayerGlow());
            auto robot2 = this->createIconButton(_gm->getPlayerRobot(), 5, _gm->colorForIdx(_gm->getPlayerColor2()), _gm->colorForIdx(_gm->getPlayerColor()), _gm->getPlayerGlow());
            auto spider2 = this->createIconButton(_gm->getPlayerSpider(), 6, _gm->colorForIdx(_gm->getPlayerColor2()), _gm->colorForIdx(_gm->getPlayerColor()), _gm->getPlayerGlow());

            ship->setPositionX(cube->getPositionX() + 45);
            ball->setPositionX(ship->getPositionX() + 45);
            bird->setPositionX(ball->getPositionX() + 45);
            dart->setPositionX(bird->getPositionX() + 45);
            robot->setPositionX(dart->getPositionX() + 45);
            spider->setPositionX(robot->getPositionX() + 45);

            cube2->setPositionY(cube->getPositionY() - 45);
            ship2->setPosition(cube2->getPositionX() + 45, cube2->getPositionY());
            ball2->setPosition(ship2->getPositionX() + 45, ship2->getPositionY());
            bird2->setPosition(ball2->getPositionX() + 45, ball2->getPositionY());
            dart2->setPosition(bird2->getPositionX() + 45, bird2->getPositionY());
            robot2->setPosition(dart2->getPositionX() + 45, dart2->getPositionY());
            spider2->setPosition(robot2->getPositionX() + 45, robot2->getPositionY());

            this->iconButtonMenu->addChild(cube, 1);
            this->iconButtonMenu->addChild(ship, 1);
            this->iconButtonMenu->addChild(ball, 1);
            this->iconButtonMenu->addChild(bird, 1);
            this->iconButtonMenu->addChild(dart, 1);
            this->iconButtonMenu->addChild(robot, 1);
            this->iconButtonMenu->addChild(spider, 1);
            this->iconButtonMenu->addChild(cube2, 1);
            this->iconButtonMenu->addChild(ship2, 1);
            this->iconButtonMenu->addChild(ball2, 1);
            this->iconButtonMenu->addChild(bird2, 1);
            this->iconButtonMenu->addChild(dart2, 1);
            this->iconButtonMenu->addChild(robot2, 1);
            this->iconButtonMenu->addChild(spider2, 1);
            this->m_pLayer->addChild(iconBG, 10);
        }
        {
            isSetSecondColor = false;

            auto promanyColor = CCSprite::createWithSpriteFrameName("GJ_colorBtn_001.png");
            promanyColor->setColor(_gm->colorForIdx(_gm->getPlayerColor()));
            promanyColor->setScale(0.7f);
            auto promanyColorBTN = CCMenuItemSpriteExtra::create(promanyColor, this, menu_selector(SelectedIconPopup::colorSelectedMode));
            promanyColorBTN->setTag(0);

            auto secondColor = CCSprite::createWithSpriteFrameName("GJ_colorBtn_001.png");
            secondColor->setColor(_gm->colorForIdx(_gm->getPlayerColor2()));
            secondColor->setScale(0.7f);
            auto secondColorBTN = CCMenuItemSpriteExtra::create(secondColor, this, menu_selector(SelectedIconPopup::colorSelectedMode));
            secondColorBTN->setTag(1);

            auto C1 = CCLabelBMFont::create("C1", "bigFont.fnt");
            auto C2 = CCLabelBMFont::create("C2", "bigFont.fnt");
            C1->setScale(0.7f);
            C2->setScale(0.7f);
            C1->setPosition({promanyColor->getContentSize().width / 2, promanyColor->getContentSize().height / 2});
            C2->setPosition({secondColor->getContentSize().width / 2, secondColor->getContentSize().height / 2});
            promanyColor->addChild(C1, 1);
            secondColor->addChild(C2, 1);

            this->promanyColor = promanyColor;
            this->secondColor = secondColor;
            promanyColorBTN->setPositionY(secondColorBTN->getPositionY() + 30);

            auto iconMenu = CCMenu::create();
            iconMenu->addChild(promanyColorBTN, 1);
            iconMenu->addChild(secondColorBTN, 1);
            iconMenu->setPosition({480, 237});

            auto colorModeSelected = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
            colorModeSelected->setScale(0.75f);
            colorModeSelected->setTag(101);
            colorModeSelected->setPosition(promanyColorBTN->getPosition());
            this->colorSelectedType = colorModeSelected;
            iconMenu->addChild(colorModeSelected, 2);

            auto tggOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
            auto tggOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
            tggOff->setScale(0.7f);
            tggOn->setScale(0.7f);
            auto glowButton = CCMenuItemToggler::create(tggOff, tggOn, this, menu_selector(SelectedIconPopup::updateGlow));
            glowButton->toggle(_gm->getPlayerGlow());
            glowButton->setPositionY(secondColorBTN->getPositionY() - 30);
            iconMenu->addChild(glowButton, 1);

            auto glowLabel = CCLabelBMFont::create("Glow", "goldFont.fnt");
            glowLabel->setScale(0.5f);
            glowLabel->setPositionY(glowButton->getPositionY() - 18);
            iconMenu->addChild(glowLabel);

            this->m_pLayer->addChild(iconMenu, 10);
        }

        return true;
    }
    return false;
}

void SelectedIconPopup::colorSelectedMode(CCObject *thisBtn)
{
    isSetSecondColor = (thisBtn->getTag() == 1);
    this->colorSelectedType->setPosition(static_cast<CCLayer *>(thisBtn)->getPosition());

    this->colorSelected_2->setZOrder((isSetSecondColor) ? 2 : 1);
    this->colorSelected_1->setZOrder((isSetSecondColor) ? 1 : 2);
    if (isSetSecondColor)
    {
        this->colorSelected_2->setColor({255, 255, 255});
        this->colorSelected_1->setColor({50, 50, 50});
    }
    else
    {
        this->colorSelected_1->setColor({255, 255, 255});
        this->colorSelected_2->setColor({50, 50, 50});
    }
}

void SelectedIconPopup::setPlayerColor(CCObject *thisBtn)
{
    const auto getButton = static_cast<CCLayer *>(thisBtn);
    if (isSetSecondColor)
    {
        this->colorSelected_2->setPosition(getButton->getPosition());
        this->secondColor->setColor(GameManager::sharedState()->colorForIdx(getButton->getTag()));
        GameManager::sharedState()->setPlayerColor2(getButton->getTag());
    }
    else
    {
        this->colorSelected_1->setPosition(getButton->getPosition());
        this->promanyColor->setColor(GameManager::sharedState()->colorForIdx(getButton->getTag()));
        GameManager::sharedState()->setPlayerColor(getButton->getTag());
    }

    this->iconUpdate();
}