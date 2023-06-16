#include "./colorSelected.hpp"
bool isCustomSecondColor = true;

void IconColorSelected::content::updatePlayerColor()
{

    auto _gameInfo = GameManager::sharedState();
    bool glow = _gameInfo->m_bPlayerGlow;
    auto col1 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor);
    auto col2 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor2);

    this->promanyColor->setColor((!isCustomSecondColor) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col1);
    this->secondColor->setColor((!isCustomSecondColor) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col2);

    this->m_pCube->setColor(col1);
    this->m_pCube->setSecondColor(col2);
    this->m_pCube->setGlowOutline(glow);

    this->m_pShip->setColor(col1);
    this->m_pShip->setSecondColor(col2);
    this->m_pShip->setGlowOutline(glow);

    this->m_pBall->setColor(col1);
    this->m_pBall->setSecondColor(col2);
    this->m_pBall->setGlowOutline(glow);

    this->m_pUFO->setColor(col1);
    this->m_pUFO->setSecondColor(col2);
    this->m_pUFO->setGlowOutline(glow);

    this->m_pWave->setColor(col1);
    this->m_pWave->setSecondColor(col2);
    this->m_pWave->setGlowOutline(glow);

    this->m_pRobot->setColor(col1);
    this->m_pRobot->setSecondColor(col2);
    this->m_pRobot->setGlowOutline(glow);

    this->m_pSpider->setColor(col1);
    this->m_pSpider->setSecondColor(col2);
    this->m_pSpider->setGlowOutline(glow);

    this->m_p2Cube->setSecondColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1);
    this->m_p2Cube->setColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2);
    this->m_p2Cube->setGlowOutline((GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);

    this->m_p2Ship->setSecondColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1);
    this->m_p2Ship->setColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2);
    this->m_p2Ship->setGlowOutline((GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);

    this->m_p2Ball->setSecondColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1);
    this->m_p2Ball->setColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2);
    this->m_p2Ball->setGlowOutline((GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);

    this->m_p2UFO->setSecondColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1);
    this->m_p2UFO->setColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2);
    this->m_p2UFO->setGlowOutline((GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);

    this->m_p2Wave->setSecondColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1);
    this->m_p2Wave->setColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2);
    this->m_p2Wave->setGlowOutline((GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);

    this->m_p2Robot->setSecondColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1);
    this->m_p2Robot->setColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2);
    this->m_p2Robot->setGlowOutline((GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);

    this->m_p2Spider->setSecondColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1);
    this->m_p2Spider->setColor((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2);
    this->m_p2Spider->setGlowOutline((GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);
};

void IconColorSelected::content::changeSelectedPlayerMode(CCObject *self)
{
    isCustomSecondColor = (self->getTag() == 1);
    if (isCustomSecondColor)
    {
        this->player1Mode->toggle(!isCustomSecondColor);
        this->player2Mode->toggle(!isCustomSecondColor);
        this->glowToggle->toggle(GameManager::sharedState()->getPlayerGlow());
    }
    else
    {
        this->player1Mode->toggle(isCustomSecondColor);
        this->player2Mode->toggle(isCustomSecondColor);
        this->glowToggle->toggle(SecondPlayer::getGlow());
    }

    this->colorSelected_1->setPosition(this->colorMenu->getChildByTag((!isCustomSecondColor) ? SecondPlayer::getColor() : GameManager::sharedState()->getPlayerColor())->getPosition());
    this->colorSelected_2->setPosition(this->colorMenu->getChildByTag((!isCustomSecondColor) ? SecondPlayer::getSecondColor() : GameManager::sharedState()->getPlayerColor2())->getPosition());
    this->promanyColor->setColor((!isCustomSecondColor) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : GameManager::sharedState()->colorForIdx(GameManager::sharedState()->getPlayerColor()));
    this->secondColor->setColor((!isCustomSecondColor) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : GameManager::sharedState()->colorForIdx(GameManager::sharedState()->getPlayerColor2()));
};

void IconColorSelected::content::changeColorMode(CCObject *self)
{

    {
        this->setSecondColor = (self->getTag() == 1);

        static_cast<CCLayer *>(self)->getParent()->getChildByTag(103)->setPosition(static_cast<CCLayer *>(self)->getPosition());
        if (self->getTag() == 1)
        {
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(101))->setColor({50, 50, 50});
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(102))->setColor({255, 255, 255});
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(101))->setZOrder(1);
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(102))->setZOrder(2);
        }
        else
        {
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(102))->setColor({50, 50, 50});
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(101))->setColor({255, 255, 255});
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(101))->setZOrder(2);
            static_cast<CCSprite *>(static_cast<CCLayer *>(self)->getParent()->getChildByTag(102))->setZOrder(1);
        }
    };
};

void IconColorSelected::content::changeGameGlow(CCObject *)
{
    if (!isCustomSecondColor)
        SecondPlayer::setGlow(!SecondPlayer::getGlow());
    else
        GameManager::sharedState()->setPlayerGlow(!GameManager::sharedState()->getPlayerGlow());
    content::updatePlayerColor();
};

void IconColorSelected::content::setPlayerColor(CCObject *layer)
{
    if (setSecondColor)
    {
        if (!isCustomSecondColor)
            SecondPlayer::setSecondColor(layer->getTag());
        else
            GameManager::sharedState()->setPlayerColor2(layer->getTag());
        static_cast<CCSprite *>(static_cast<CCLayer *>(layer)->getParent()->getChildByTag(102))->setPosition(static_cast<CCLayer *>(layer)->getPosition());
    }
    else
    {
        if (!isCustomSecondColor)
            SecondPlayer::setColor(layer->getTag());
        else
            GameManager::sharedState()->setPlayerColor(layer->getTag());
        static_cast<CCSprite *>(static_cast<CCLayer *>(layer)->getParent()->getChildByTag(101))->setPosition(static_cast<CCLayer *>(layer)->getPosition());
    }
    updatePlayerColor();
};

bool IconColorSelected::content::init(CCLayer *self)
{
    if (this->initWithColor({0, 0, 0, 125}))
    {
        this->setKeypadEnabled(true);
        this->setKeyboardEnabled(true);
        auto _s = CCDirector::sharedDirector()->getWinSize();

        auto layer = CCLayer::create();
        layer->setContentSize(_s);
        this->m_pLayer = layer;
        this->addChild(this->m_pLayer);

        auto background = cocos2d::extension::CCScale9Sprite::create("GJ_square05.png");
        background->setContentSize({450.0f, GameManager::sharedState()->getGameVariable("1000") ? 295.0f : 285.f});
        background->setPosition({_s.width / 2, _s.height / 2});
        this->m_pLayer->addChild(background);

        auto closeBtn = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
        auto close = CCMenuItemSpriteExtra::create(closeBtn, this, menu_selector(content::keyBackClicked));
        auto closeMenu = CCMenu::create();
        closeMenu->addChild(close);
        closeMenu->setPosition({10, background->getContentSize().height - 10});
        background->addChild(closeMenu, 1);

        // Cak
        auto _gameInfo = GameManager::sharedState();
        auto iconMenuSelect = CCMenu::create();
        {
            auto iconBG = extension::CCScale9Sprite::create("square02_small.png");
            iconBG->setPosition({228, 210});
            iconBG->setContentSize({370, 100});
            iconBG->setOpacity(75);
            iconBG->setTag(1000);
            background->addChild(iconBG);
            auto col1 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor);
            auto col2 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor2);
            bool glow = _gameInfo->m_bPlayerGlow;
            auto _cube = PlayerRenderer::cubeRenderer(col1, col2, _gameInfo->m_nPlayerFrame, glow);
            auto _ship = PlayerRenderer::shipRenderer(col1, col2, _gameInfo->m_nPlayerShip, glow);
            auto _ball = PlayerRenderer::ballRenderer(col1, col2, _gameInfo->m_nPlayerBall, glow);
            auto _ufo = PlayerRenderer::ufoRenderer(col1, col2, _gameInfo->m_nPlayerBird, glow);
            auto _wave = PlayerRenderer::waveRenderer(col1, col2, _gameInfo->m_nPlayerDart, glow);
            auto _robot = PlayerRenderer::robotRenderer(col1, col2, _gameInfo->m_nPlayerRobot, glow);
            auto _spider = PlayerRenderer::spiderRenderer(col1, col2, _gameInfo->m_nPlayerSpider, glow);
            _ship->setPosition({(_cube->getPositionX() + 50), _cube->getPositionY()});
            _ball->setPosition({(_ship->getPositionX() + 50), _cube->getPositionY()});
            _ufo->setPosition({(_ball->getPositionX() + 50), _cube->getPositionY()});
            _wave->setPosition({(_ufo->getPositionX() + 50), _cube->getPositionY()});
            _robot->setPosition({(_wave->getPositionX() + 50), _cube->getPositionY()});
            _spider->setPosition({(_robot->getPositionX() + 50), _cube->getPositionY()});
            auto __cube = PlayerRenderer::cubeRenderer((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getPlayerCube() : _gameInfo->m_nPlayerFrame,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);
            auto __ship = PlayerRenderer::shipRenderer((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getPlayerShip() : _gameInfo->m_nPlayerShip,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);
            auto __ball = PlayerRenderer::ballRenderer((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getPlayerBall() : _gameInfo->m_nPlayerBall,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);
            auto __ufo = PlayerRenderer::ufoRenderer((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2,
                                                     (GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1,
                                                     (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getPlayerUfo() : _gameInfo->m_nPlayerBird,
                                                     (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);
            auto __wave = PlayerRenderer::waveRenderer((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getPlayerWave() : _gameInfo->m_nPlayerDart,
                                                       (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);
            auto __robot = PlayerRenderer::robotRenderer((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2,
                                                         (GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1,
                                                         (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getPlayerRobot() : _gameInfo->m_nPlayerRobot,
                                                         (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);
            auto __spider = PlayerRenderer::spiderRenderer((GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getColor()) : col2,
                                                           (GameManager::sharedState()->getGameVariable("1000")) ? GameManager::sharedState()->colorForIdx(SecondPlayer::getSecondColor()) : col1,
                                                           (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getPlayerSpider() : _gameInfo->m_nPlayerSpider,
                                                           (GameManager::sharedState()->getGameVariable("1000")) ? SecondPlayer::getGlow() : glow);

            __cube->setPosition({_cube->getPositionX(), _cube->getPositionY() - 50});
            __ship->setPosition({(__cube->getPositionX() + 50), __cube->getPositionY()});
            __ball->setPosition({(__ship->getPositionX() + 50), __cube->getPositionY()});
            __ufo->setPosition({(__ball->getPositionX() + 50), __cube->getPositionY()});
            __wave->setPosition({(__ufo->getPositionX() + 50), __cube->getPositionY()});
            __robot->setPosition({(__wave->getPositionX() + 50), __cube->getPositionY()});
            __spider->setPosition({(__robot->getPositionX() + 50), __cube->getPositionY()});
            iconMenuSelect->addChild(_cube, 1);
            iconMenuSelect->addChild(_ship, 1);
            iconMenuSelect->addChild(_ball, 1);
            iconMenuSelect->addChild(_ufo, 1);
            iconMenuSelect->addChild(_wave, 1);
            iconMenuSelect->addChild(_robot, 1);
            iconMenuSelect->addChild(_spider, 1);
            iconMenuSelect->addChild(__cube, 1);
            iconMenuSelect->addChild(__ship, 1);
            iconMenuSelect->addChild(__ball, 1);
            iconMenuSelect->addChild(__ufo, 1);
            iconMenuSelect->addChild(__wave, 1);
            iconMenuSelect->addChild(__robot, 1);
            iconMenuSelect->addChild(__spider, 1);
            iconMenuSelect->setPosition({32, 75});
            this->m_pCube = static_cast<SimplePlayer *>(_cube->getChildren()->objectAtIndex(0));
            this->m_pShip = static_cast<SimplePlayer *>(_ship->getChildren()->objectAtIndex(0));
            this->m_pBall = static_cast<SimplePlayer *>(_ball->getChildren()->objectAtIndex(0));
            this->m_pUFO = static_cast<SimplePlayer *>(_ufo->getChildren()->objectAtIndex(0));
            this->m_pWave = static_cast<SimplePlayer *>(_wave->getChildren()->objectAtIndex(0));
            this->m_pRobot = static_cast<SimplePlayer *>(_robot->getChildren()->objectAtIndex(0));
            this->m_pSpider = static_cast<SimplePlayer *>(_spider->getChildren()->objectAtIndex(0));
            this->m_p2Cube = static_cast<SimplePlayer *>(__cube->getChildren()->objectAtIndex(0));
            this->m_p2Ship = static_cast<SimplePlayer *>(__ship->getChildren()->objectAtIndex(0));
            this->m_p2Ball = static_cast<SimplePlayer *>(__ball->getChildren()->objectAtIndex(0));
            this->m_p2UFO = static_cast<SimplePlayer *>(__ufo->getChildren()->objectAtIndex(0));
            this->m_p2Wave = static_cast<SimplePlayer *>(__wave->getChildren()->objectAtIndex(0));
            this->m_p2Robot = static_cast<SimplePlayer *>(__robot->getChildren()->objectAtIndex(0));
            this->m_p2Spider = static_cast<SimplePlayer *>(__spider->getChildren()->objectAtIndex(0));
            iconBG->addChild(iconMenuSelect, 5);
        }

        {
            auto colorMenu = CCMenu::create();
            colorMenu->setPosition({55, 130});

            this->colorMenu = colorMenu;

            auto colorSelected_1 = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
            colorSelected_1->setScale(0.75f);
            colorSelected_1->setTag(101);
            colorMenu->addChild(colorSelected_1, 2);

            auto colorSelected_2 = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
            colorSelected_2->setScale(0.75f);
            colorSelected_2->setTag(102);
            colorMenu->addChild(colorSelected_2, 1);

            this->colorSelected_1 = colorSelected_1;
            this->colorSelected_2 = colorSelected_2;

            auto colorMode = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
            colorMode->setScale(0.75f);
            colorMode->setTag(103);
            colorMenu->addChild(colorMode);

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

            auto white1 = this->createColorButton(12);
            auto white2 = this->createColorButton(17);
            auto white3 = this->createColorButton(18);
            auto white4 = this->createColorButton(15);
            white1->setPosition({green7->getPositionX(), green7->getPositionY() - 45});
            white2->setPosition({white1->getPositionX() + 25, white1->getPositionY()});
            white3->setPosition({white2->getPositionX() + 25, white1->getPositionY()});
            white4->setPosition({white3->getPositionX() + 25, white1->getPositionY()});
            colorMenu->addChild(white1);
            colorMenu->addChild(white2);
            colorMenu->addChild(white3);
            colorMenu->addChild(white4);

            auto _gameInfo = GameManager::sharedState();
            bool glow = _gameInfo->m_bPlayerGlow;
            auto col1 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor);
            auto col2 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor2);

            colorSelected_1->setPosition(static_cast<CCLayer *>(colorMenu->getChildByTag(_gameInfo->m_nPlayerColor))->getPosition());
            colorSelected_2->setPosition(static_cast<CCLayer *>(colorMenu->getChildByTag(_gameInfo->m_nPlayerColor2))->getPosition());
            colorSelected_2->setColor({112, 112, 112});

            auto promanyColor = CCSprite::createWithSpriteFrameName("GJ_colorBtn_001.png");
            promanyColor->setColor(col1);
            promanyColor->setScale(0.7f);
            auto promanyColorBTN = CCMenuItemSpriteExtra::create(promanyColor, this, menu_selector(content::changeColorMode));
            promanyColorBTN->setTag(0);

            auto secondColor = CCSprite::createWithSpriteFrameName("GJ_colorBtn_001.png");
            secondColor->setColor(col2);
            secondColor->setScale(0.7f);
            auto secondColorBTN = CCMenuItemSpriteExtra::create(secondColor, this, menu_selector(content::changeColorMode));
            secondColorBTN->setTag(1);

            this->promanyColor = promanyColor;
            this->secondColor = secondColor;

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
            promanyColorBTN->setPosition({white4->getPositionX() + 49, white4->getPositionY()});
            secondColorBTN->setPosition({promanyColorBTN->getPositionX() + 25, white4->getPositionY()});

            colorMode->setPosition(promanyColorBTN->getPosition());
            colorMenu->addChild(promanyColorBTN);
            colorMenu->addChild(secondColorBTN);

            auto tggOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
            auto tggOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
            tggOff->setScale(0.7f);
            tggOn->setScale(0.7f);
            auto glowToggle = CCMenuItemToggler::create(tggOff, tggOn, this, menu_selector(content::changeGameGlow));
            auto glowText = CCLabelBMFont::create("Glow", "goldFont.fnt");
            glowToggle->toggle(_gameInfo->getPlayerGlow());
            glowText->setScale(0.7f);
            glowToggle->setPosition({secondColorBTN->getPositionX() + 49, secondColorBTN->getPositionY()});
            glowText->setPosition({glowToggle->getPositionX() + 38, glowToggle->getPositionY() + 2});
            colorMenu->addChild(glowToggle, 1);
            colorMenu->addChild(glowText, 1);
            this->glowToggle = glowToggle;
            background->addChild(colorMenu, 5);
        }

        {
            auto playerMenu = CCMenu::create();
            auto btn1 = ButtonSprite::create("Player 1", 45, true, "bigFont.fnt", "GJ_button_02.png", 25, 1);
            auto btn2 = ButtonSprite::create("Player 2", 45, true, "bigFont.fnt", "GJ_button_02.png", 25, 1);
            auto btn1on = ButtonSprite::create("Player 1", 45, true, "bigFont.fnt", "GJ_button_04.png", 25, 1);
            auto btn2on = ButtonSprite::create("Player 2", 45, true, "bigFont.fnt", "GJ_button_04.png", 25, 1);
            isCustomSecondColor = true;
            auto player1Mode = CCMenuItemToggler::create(btn1on, btn1, this, menu_selector(IconColorSelected::content::changeSelectedPlayerMode));
            auto player2Mode = CCMenuItemToggler::create(btn2on, btn2, this, menu_selector(IconColorSelected::content::changeSelectedPlayerMode));
            player1Mode->toggle(isCustomSecondColor);
            player2Mode->toggle(!isCustomSecondColor);
            this->player1Mode = player1Mode;
            this->player2Mode = player2Mode;
            player1Mode->setTag(1);
            player2Mode->setTag(2);
            player2Mode->setPosition({player1Mode->getPositionX() + 65, player1Mode->getPositionY()});
            playerMenu->addChild(player1Mode);
            playerMenu->addChild(player2Mode);
            playerMenu->setPosition({318, 275});
            playerMenu->setVisible(GameManager::sharedState()->getGameVariable("1000"));
            background->addChild(playerMenu, 1);
        }
        return true;
    };
    return false;
};