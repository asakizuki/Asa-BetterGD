#include "./content.hpp"
#include "./iconSetting.hpp"
#include "./../../libarries/iconRenderer.hpp"

int iconPage = 0;
bool isCustomSecondPlayer = true;
int selectedPage[7] = {0, 0, 0, 0, 0, 0, 0};
int maxIcon[7] = {0, 0, 0, 0, 0, 0, 0};

void AsaSelectedIcon::ContentLayer::iconSelectedSetting()
{
    isCustomSecondPlayer = true;
    static_cast<CCMenu *>(static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0))->getChildByTag(1250))->setVisible(GameManager::sharedState()->getGameVariable("1000"));

    if (!GameManager::sharedState()->getGameVariable("1000"))
    {
        auto scene = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
        auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(scene->getChildByTag(1000));
        auto asaPlayer = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(iconPage))->getChildByTag(1))->getChildren()->objectAtIndex(0));

        auto _dir = GameManager::sharedState()->getPlayerFrame();
        switch (iconPage)
        {
        case 1:
            _dir = GameManager::sharedState()->getPlayerShip();
            break;
        case 2:
            _dir = GameManager::sharedState()->getPlayerBall();
            break;
        case 3:
            _dir = GameManager::sharedState()->getPlayerBird();
            break;
        case 4:
            _dir = GameManager::sharedState()->getPlayerDart();
            break;
        case 5:
            _dir = GameManager::sharedState()->getPlayerRobot();
            break;
        case 6:
            _dir = GameManager::sharedState()->getPlayerSpider();
            break;
        }

        auto iconMenu = static_cast<CCMenu *>(static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0))->getChildByTag(1500)->getChildren()->objectAtIndex(1));
        if (selectedPage[iconPage] * 36 >= _dir || selectedPage[iconPage] * 36 + 36 < _dir)
        {
            iconMenu->getChildByTag(5000)->setVisible(false);
        }
        else
        {
            iconMenu->getChildByTag(5000)->setVisible(true);
            iconMenu->getChildByTag(5000)->setPosition(iconMenu->getChildByTag(_dir)->getPosition());
        }

        switch (iconPage)
        {
        case 0:
            asaPlayer->updatePlayerFrame(GameManager::sharedState()->getPlayerFrame(), IconType::kIconTypeCube);
            break;
        case 1:
            asaPlayer->updatePlayerFrame(GameManager::sharedState()->getPlayerShip(), IconType::kIconTypeShip);
            break;
        case 2:
            asaPlayer->updatePlayerFrame(GameManager::sharedState()->getPlayerBall(), IconType::kIconTypeBall);
            break;
        case 3:
            asaPlayer->updatePlayerFrame(GameManager::sharedState()->getPlayerBird(), IconType::kIconTypeUfo);
            break;
        case 4:
            asaPlayer->updatePlayerFrame(GameManager::sharedState()->getPlayerDart(), IconType::kIconTypeWave);
            break;
        case 5:
            asaPlayer->updatePlayerFrame(GameManager::sharedState()->getPlayerRobot(), IconType::kIconTypeRobot);
            break;
        case 6:
            asaPlayer->updatePlayerFrame(GameManager::sharedState()->getPlayerSpider(), IconType::kIconTypeSpider);
            break;
        };

        static_cast<CCMenuItemToggler *>(static_cast<CCMenu *>(static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0))->getChildByTag(1250))->getChildren()->objectAtIndex(0))->toggle(true);
        static_cast<CCMenuItemToggler *>(static_cast<CCMenu *>(static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0))->getChildByTag(1250))->getChildren()->objectAtIndex(1))->toggle(false);
    }
};

void AsaSelectedIcon::ContentLayer::changeTabPage(CCLayer *self, int iconType)
{
    auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(self->getChildByTag(1500));
    auto pageLabel = static_cast<extension::CCScale9Sprite *>(self->getChildByTag(1501));
    const int iconSlot = selectedPage[iconType] * 36;

    {
        auto _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerCube() : GameManager::sharedState()->getPlayerFrame();
        switch (iconPage)
        {
        case 1:
            _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerShip() : GameManager::sharedState()->getPlayerShip();
            break;
        case 2:
            _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerBall() : GameManager::sharedState()->getPlayerBall();
            break;
        case 3:
            _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerUfo() : GameManager::sharedState()->getPlayerBird();
            break;
        case 4:
            _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerWave() : GameManager::sharedState()->getPlayerDart();
            break;
        case 5:
            _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerRobot() : GameManager::sharedState()->getPlayerRobot();
            break;
        case 6:
            _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerSpider() : GameManager::sharedState()->getPlayerSpider();
            break;
        }

        auto iconSelectedMenu = CCMenu::create();
        iconSelectedMenu->setTag(0);
        selectedIconBG->addChild(iconSelectedMenu, 1);
        iconSelectedMenu->setPosition({22.5, 22.5});

        auto selectedIcon = CCSprite::createWithSpriteFrameName("GJ_select_001.png");
        selectedIcon->setScale(0.8f);
        selectedIcon->setTag(5000);
        iconSelectedMenu->addChild(selectedIcon, 2);

        auto col1 = GameManager::sharedState()->colorForIdx(17);
        auto col2 = GameManager::sharedState()->colorForIdx(12);

        float iconLine[2] = {0, 2};
        for (int iconIndex = 1; iconIndex < 37; iconIndex++)
        {
            if (!(iconIndex + iconSlot > maxIcon[iconType] - 1 || iconIndex + iconSlot < 1))
            {
                auto _selectedCube = PlayerRenderer::cubeRenderer(col1, col2, iconIndex + iconSlot, false, 0.8f);
                if (iconPage == 1)
                    _selectedCube = PlayerRenderer::shipRenderer(col1, col2, iconIndex + iconSlot, false, 0.65f);
                else if (iconPage == 2)
                    _selectedCube = PlayerRenderer::ballRenderer(col1, col2, iconIndex + iconSlot, false, 0.8f);
                else if (iconPage == 3)
                    _selectedCube = PlayerRenderer::ufoRenderer(col1, col2, iconIndex + iconSlot, false, 0.7f);
                else if (iconPage == 4)
                    _selectedCube = PlayerRenderer::waveRenderer(col1, col2, iconIndex + iconSlot, false, 0.9f);
                else if (iconPage == 5)
                    _selectedCube = PlayerRenderer::robotRenderer(col1, col2, iconIndex + iconSlot, false, 0.8f);
                else if (iconPage == 6)
                    _selectedCube = PlayerRenderer::spiderRenderer(col1, col2, iconIndex + iconSlot, false, 0.65f);

                auto _selectedIcon = CCMenuItemSpriteExtra::create(_selectedCube, self, menu_selector(AsaSelectedIcon::iconSelected::changeIcon));
                _selectedIcon->setTag(iconIndex + iconSlot);
                iconSelectedMenu->addChild(_selectedIcon, 5);
                _selectedIcon->setPosition({iconLine[0] * 30, iconLine[1] * 30});

                if (iconIndex + iconSlot == _dir)
                {
                    selectedIcon->setPosition(_selectedIcon->getPosition());
                };
            };

            if (iconSlot >= _dir || iconSlot + 36 < _dir)
            {
                selectedIcon->setVisible(false);
            };

            iconLine[0]++;
            if (iconLine[0] > 11)
            {
                iconLine[0] = 0;
                iconLine[1]--;
            }
            if (iconLine[1] < 0)
                iconLine[1] = 2;
        }
    }

    {
        auto label = static_cast<CCLabelBMFont *>(pageLabel->getChildByTag(0));
        int totalPage = (maxIcon[iconType] - 2) / 36;
        auto pageString = CCString::createWithFormat("%i/%i", (selectedPage[iconType] + 1), (totalPage + 1))->getCString();
        label->setString(pageString);
        pageLabel->setVisible(totalPage != 0);
    }
};

void AsaSelectedIcon::iconSelected::changeIcon(CCLayer *self)
{
    auto scene = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
    auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(scene->getChildByTag(1000));
    auto asaPlayer = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(iconPage))->getChildByTag(1))->getChildren()->objectAtIndex(0));

    static_cast<CCSprite *>(self->getParent()->getChildByTag(5000))->setPosition(self->getPosition());
    static_cast<CCSprite *>(self->getParent()->getChildByTag(5000))->setVisible(true);
    switch (iconPage)
    {
    case 0:
        (!isCustomSecondPlayer) ? SecondPlayer::setPlayerCube(self->getTag()) : GameManager::sharedState()->setPlayerFrame(self->getTag());
        asaPlayer->updatePlayerFrame(self->getTag(), IconType::kIconTypeCube);
        break;
    case 1:
        (!isCustomSecondPlayer) ? SecondPlayer::setPlayerShip(self->getTag()) : GameManager::sharedState()->setPlayerShip(self->getTag());
        asaPlayer->updatePlayerFrame(self->getTag(), IconType::kIconTypeShip);
        break;
    case 2:
        (!isCustomSecondPlayer) ? SecondPlayer::setPlayerBall(self->getTag()) : GameManager::sharedState()->setPlayerBall(self->getTag());
        asaPlayer->updatePlayerFrame(self->getTag(), IconType::kIconTypeBall);
        break;
    case 3:
        (!isCustomSecondPlayer) ? SecondPlayer::setPlayerUfo(self->getTag()) : GameManager::sharedState()->setPlayerBird(self->getTag());
        asaPlayer->updatePlayerFrame(self->getTag(), IconType::kIconTypeUfo);
        break;
    case 4:
        (!isCustomSecondPlayer) ? SecondPlayer::setPlayerWave(self->getTag()) : GameManager::sharedState()->setPlayerDart(self->getTag());
        asaPlayer->updatePlayerFrame(self->getTag(), IconType::kIconTypeWave);
        break;
    case 5:
        (!isCustomSecondPlayer) ? SecondPlayer::setPlayerRobot(self->getTag()) : GameManager::sharedState()->setPlayerRobot(self->getTag());
        asaPlayer->updatePlayerFrame(self->getTag(), IconType::kIconTypeRobot);
        break;
    case 6:
        (!isCustomSecondPlayer) ? SecondPlayer::setPlayerSpider(self->getTag()) : GameManager::sharedState()->setPlayerSpider(self->getTag());
        asaPlayer->updatePlayerFrame(self->getTag(), IconType::kIconTypeSpider);
        break;
    };
};

void AsaSelectedIcon::iconSelected::changeIconSelectedPage(CCLayer *self)
{
    auto scene = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
    auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(scene->getChildByTag(1500));
    static_cast<CCMenu *>(selectedIconBG->getChildByTag(0))->removeMeAndCleanup();
    iconPage = self->getTag();
    static_cast<CCMenu *>(scene->getChildByTag(2000))->setVisible(!(maxIcon[iconPage] < 37));
    AsaSelectedIcon::ContentLayer *layers = new AsaSelectedIcon::ContentLayer();
    layers->changeTabPage(scene, iconPage);
};

void AsaSelectedIcon::iconSelected::iconPageRight(CCLayer *)
{
    auto self = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
    auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(self->getChildByTag(1500));
    static_cast<CCMenu *>(selectedIconBG->getChildByTag(0))->removeMeAndCleanup();
    selectedPage[iconPage]++;
    auto maxPage = (maxIcon[iconPage] - 2) / 36;
    if (selectedPage[iconPage] > maxPage)
        selectedPage[iconPage] = 0;
    AsaSelectedIcon::ContentLayer *layers = new AsaSelectedIcon::ContentLayer();
    layers->changeTabPage(self, iconPage);
};

void AsaSelectedIcon::iconSelected::iconPageLeft(CCLayer *)
{
    auto self = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
    auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(self->getChildByTag(1500));
    static_cast<CCMenu *>(selectedIconBG->getChildByTag(0))->removeMeAndCleanup();
    selectedPage[iconPage]--;
    auto maxPage = (maxIcon[iconPage] - 2) / 36;
    if (selectedPage[iconPage] < 0)
        selectedPage[iconPage] = (int)maxPage;
    AsaSelectedIcon::ContentLayer *layers = new AsaSelectedIcon::ContentLayer();
    layers->changeTabPage(self, iconPage);
};

void AsaSelectedIcon::ContentLayer::changeSelectedPlayerMode(CCObject *self)
{
    isCustomSecondPlayer = (self->getTag() == 1);
    if (isCustomSecondPlayer)
    {
        this->player1Mode->toggle(!isCustomSecondPlayer);
        this->player2Mode->toggle(!isCustomSecondPlayer);
    }
    else
    {
        this->player1Mode->toggle(isCustomSecondPlayer);
        this->player2Mode->toggle(isCustomSecondPlayer);
    }

    auto _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerCube() : GameManager::sharedState()->getPlayerFrame();
    switch (iconPage)
    {
    case 1:
        _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerShip() : GameManager::sharedState()->getPlayerShip();
        break;
    case 2:
        _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerBall() : GameManager::sharedState()->getPlayerBall();
        break;
    case 3:
        _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerUfo() : GameManager::sharedState()->getPlayerBird();
        break;
    case 4:
        _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerWave() : GameManager::sharedState()->getPlayerDart();
        break;
    case 5:
        _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerRobot() : GameManager::sharedState()->getPlayerRobot();
        break;
    case 6:
        _dir = (!isCustomSecondPlayer) ? SecondPlayer::getPlayerSpider() : GameManager::sharedState()->getPlayerSpider();
        break;
    }

    auto iconMenu = static_cast<CCMenu *>(static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0))->getChildByTag(1500)->getChildren()->objectAtIndex(1));

    if (selectedPage[iconPage] * 36 >= _dir || selectedPage[iconPage] * 36 + 36 < _dir)
    {
        iconMenu->getChildByTag(5000)->setVisible(false);
    }
    else
    {
        iconMenu->getChildByTag(5000)->setVisible(true);
        iconMenu->getChildByTag(5000)->setPosition(iconMenu->getChildByTag(_dir)->getPosition());
    }

    ContentLayer *playerIcon = new ContentLayer();
    playerIcon->updatePlayerIcon();
};

void AsaSelectedIcon::ContentLayer::updatePlayerIcon()
{
    auto scene = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
    auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(scene->getChildByTag(1000));

    auto cube = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(0))->getChildByTag(1))->getChildren()->objectAtIndex(0));
    auto ship = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(1))->getChildByTag(1))->getChildren()->objectAtIndex(0));
    auto ball = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(2))->getChildByTag(1))->getChildren()->objectAtIndex(0));
    auto ufo = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(3))->getChildByTag(1))->getChildren()->objectAtIndex(0));
    auto wave = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(4))->getChildByTag(1))->getChildren()->objectAtIndex(0));
    auto robot = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(5))->getChildByTag(1))->getChildren()->objectAtIndex(0));
    auto spider = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(6))->getChildByTag(1))->getChildren()->objectAtIndex(0));

    cube->updatePlayerFrame((!isCustomSecondPlayer) ? SecondPlayer::getPlayerCube() : GameManager::sharedState()->getPlayerFrame(), IconType::kIconTypeCube);
    ship->updatePlayerFrame((!isCustomSecondPlayer) ? SecondPlayer::getPlayerShip() : GameManager::sharedState()->getPlayerShip(), IconType::kIconTypeShip);
    ball->updatePlayerFrame((!isCustomSecondPlayer) ? SecondPlayer::getPlayerBall() : GameManager::sharedState()->getPlayerBall(), IconType::kIconTypeBall);
    ufo->updatePlayerFrame((!isCustomSecondPlayer) ? SecondPlayer::getPlayerUfo() : GameManager::sharedState()->getPlayerBird(), IconType::kIconTypeUfo);
    wave->updatePlayerFrame((!isCustomSecondPlayer) ? SecondPlayer::getPlayerWave() : GameManager::sharedState()->getPlayerDart(), IconType::kIconTypeWave);
    robot->updatePlayerFrame((!isCustomSecondPlayer) ? SecondPlayer::getPlayerRobot() : GameManager::sharedState()->getPlayerRobot(), IconType::kIconTypeRobot);
    spider->updatePlayerFrame((!isCustomSecondPlayer) ? SecondPlayer::getPlayerSpider() : GameManager::sharedState()->getPlayerSpider(), IconType::kIconTypeSpider);

    auto ColorID1 = GameManager::sharedState()->colorForIdx((!isCustomSecondPlayer) ? SecondPlayer::getColor() : GameManager::sharedState()->getPlayerColor());
    auto ColorID2 = GameManager::sharedState()->colorForIdx((!isCustomSecondPlayer) ? SecondPlayer::getSecondColor() : GameManager::sharedState()->getPlayerColor2());

    cube->setColor(ColorID1);
    cube->setSecondColor(ColorID2);
    ship->setColor(ColorID1);
    ship->setSecondColor(ColorID2);
    ball->setColor(ColorID1);
    ball->setSecondColor(ColorID2);
    ufo->setColor(ColorID1);
    ufo->setSecondColor(ColorID2);
    wave->setColor(ColorID1);
    wave->setSecondColor(ColorID2);
    robot->setColor(ColorID1);
    robot->setSecondColor(ColorID2);
    spider->setColor(ColorID1);
    spider->setSecondColor(ColorID2);

    cube->setGlowOutline((!isCustomSecondPlayer) ? SecondPlayer::getGlow() : GameManager::sharedState()->getPlayerGlow());
    ship->setGlowOutline((!isCustomSecondPlayer) ? SecondPlayer::getGlow() : GameManager::sharedState()->getPlayerGlow());
    ball->setGlowOutline((!isCustomSecondPlayer) ? SecondPlayer::getGlow() : GameManager::sharedState()->getPlayerGlow());
    ufo->setGlowOutline((!isCustomSecondPlayer) ? SecondPlayer::getGlow() : GameManager::sharedState()->getPlayerGlow());
    wave->setGlowOutline((!isCustomSecondPlayer) ? SecondPlayer::getGlow() : GameManager::sharedState()->getPlayerGlow());
    robot->setGlowOutline((!isCustomSecondPlayer) ? SecondPlayer::getGlow() : GameManager::sharedState()->getPlayerGlow());
    spider->setGlowOutline((!isCustomSecondPlayer) ? SecondPlayer::getGlow() : GameManager::sharedState()->getPlayerGlow());
}

bool AsaSelectedIcon::ContentLayer::init()
{
    maxIcon[0] = SecondPlayer::getMaxIcon(0);
    maxIcon[1] = SecondPlayer::getMaxIcon(1);
    maxIcon[2] = SecondPlayer::getMaxIcon(2);
    maxIcon[3] = SecondPlayer::getMaxIcon(3);
    maxIcon[4] = SecondPlayer::getMaxIcon(4);
    maxIcon[5] = SecondPlayer::getMaxIcon(5);
    maxIcon[6] = SecondPlayer::getMaxIcon(6);

    this->setKeypadEnabled(true);
    SecondPlayer::firstTime();
    auto _d = CCDirector::sharedDirector();
    auto _s = _d->getWinSize();
    auto _bg = CCSprite::create("GJ_gradientBG.png");
    auto _bgSize = _bg->getContentSize();
    _bg->setScaleX(_s.width / _bgSize.width);
    _bg->setScaleY(_s.height / _bgSize.height);
    _bg->setAnchorPoint({0, 0});
    _bg->setColor({163, 163, 163});
    isCustomSecondPlayer = true;
    auto iconBG = extension::CCScale9Sprite::create("square02_small.png");
    this->addChild(_bg, -30);
    {
        auto iconPage = extension::CCScale9Sprite::create("square02_small.png");
        iconPage->setPosition({_s.width / 2, 50});
        iconPage->setTag(1501);
        iconPage->setOpacity(75);
        iconPage->setContentSize({145, 50});
        iconPage->setScale(0.5);
        this->addChild(iconPage, 1);

        auto pageLabel = CCLabelBMFont::create("1/1", "bigFont.fnt");
        pageLabel->setPosition({iconPage->getContentSize().width / 2, iconPage->getContentSize().height / 2});
        pageLabel->setTag(0);
        iconPage->addChild(pageLabel, 1);
    }

    {
        auto backBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this, menu_selector(ContentLayer::gobackBtn));
        auto backBtnMenu = CCMenu::create();
        backBtnMenu->addChild(backBtn, 0);
        backBtnMenu->setPosition({25, _s.height - 25});
        this->addChild(backBtnMenu, 0);
        auto cornerLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
        cornerLeft->setAnchorPoint({0, 0});
        cornerLeft->setScaleX(1.f);
        cornerLeft->setScaleY(-1.f);
        cornerLeft->setPosition({0, _s.height});
        this->addChild(cornerLeft, -1);
        auto cornerRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
        cornerRight->setAnchorPoint({0, 0});
        cornerRight->setScaleX(-1.f);
        cornerRight->setScaleY(-1.f);
        cornerRight->setPosition({_s.width, _s.height});
        this->addChild(cornerRight, -1);

        auto iconOptions = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        auto iconOptionsPopup = CCMenuItemSpriteExtra::create(iconOptions, this, menu_selector(IconSettingPopup::callback));
        backBtnMenu->addChild(iconOptionsPopup, 1);
        iconOptions->setScale(0.75f);
        iconOptionsPopup->setPosition({45, -1});
    }
    {
        auto _gameInfo = GameManager::sharedState();
        auto iconMenuSelect = CCMenu::create();

        iconBG->setPosition({_s.width / 2, _s.height - 80});
        iconBG->setContentSize({370, 50});
        iconBG->setOpacity(75);
        iconBG->setTag(1000);
        this->addChild(iconBG);

        auto col1 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor);
        auto col2 = _gameInfo->colorForIdx(_gameInfo->m_nPlayerColor2);
        bool glow = _gameInfo->m_bPlayerGlow;

        auto _cubeBtn = PlayerRenderer::cubeRenderer(col1, col2, _gameInfo->m_nPlayerFrame, glow);
        auto _shipBtn = PlayerRenderer::shipRenderer(col1, col2, _gameInfo->m_nPlayerShip, glow);
        auto _ballBtn = PlayerRenderer::ballRenderer(col1, col2, _gameInfo->m_nPlayerBall, glow);
        auto _ufoBtn = PlayerRenderer::ufoRenderer(col1, col2, _gameInfo->m_nPlayerBird, glow);
        auto _waveBtn = PlayerRenderer::waveRenderer(col1, col2, _gameInfo->m_nPlayerDart, glow);
        auto _robotBtn = PlayerRenderer::robotRenderer(col1, col2, _gameInfo->m_nPlayerRobot, glow);
        auto _spiderBtn = PlayerRenderer::spiderRenderer(col1, col2, _gameInfo->m_nPlayerSpider, glow);

        auto _cube = CCMenuItemSpriteExtra::create(_cubeBtn, this, menu_selector(AsaSelectedIcon::iconSelected::changeIconSelectedPage));
        auto _ship = CCMenuItemSpriteExtra::create(_shipBtn, this, menu_selector(AsaSelectedIcon::iconSelected::changeIconSelectedPage));
        auto _ball = CCMenuItemSpriteExtra::create(_ballBtn, this, menu_selector(AsaSelectedIcon::iconSelected::changeIconSelectedPage));
        auto _ufo = CCMenuItemSpriteExtra::create(_ufoBtn, this, menu_selector(AsaSelectedIcon::iconSelected::changeIconSelectedPage));
        auto _wave = CCMenuItemSpriteExtra::create(_waveBtn, this, menu_selector(AsaSelectedIcon::iconSelected::changeIconSelectedPage));
        auto _robot = CCMenuItemSpriteExtra::create(_robotBtn, this, menu_selector(AsaSelectedIcon::iconSelected::changeIconSelectedPage));
        auto _spider = CCMenuItemSpriteExtra::create(_spiderBtn, this, menu_selector(AsaSelectedIcon::iconSelected::changeIconSelectedPage));

        _cube->setTag(0);
        _ship->setTag(1);
        _ball->setTag(2);
        _ufo->setTag(3);
        _wave->setTag(4);
        _robot->setTag(5);
        _spider->setTag(6);

        _ship->setPosition({(_cube->getPositionX() + 50), _cube->getPositionY()});
        _ball->setPosition({(_ship->getPositionX() + 50), _cube->getPositionY()});
        _ufo->setPosition({(_ball->getPositionX() + 50), _cube->getPositionY()});
        _wave->setPosition({(_ufo->getPositionX() + 50), _cube->getPositionY()});
        _robot->setPosition({(_wave->getPositionX() + 50), _cube->getPositionY()});
        _spider->setPosition({(_robot->getPositionX() + 50), _cube->getPositionY()});

        iconMenuSelect->addChild(_cube, 1);
        iconMenuSelect->addChild(_ship, 1);
        iconMenuSelect->addChild(_ball, 1);
        iconMenuSelect->addChild(_ufo, 1);
        iconMenuSelect->addChild(_wave, 1);
        iconMenuSelect->addChild(_robot, 1);
        iconMenuSelect->addChild(_spider, 1);
        iconMenuSelect->setPosition({32, 25});

        iconBG->addChild(iconMenuSelect, 5);

        auto selectedIconBG = extension::CCScale9Sprite::create("square02_small.png");
        selectedIconBG->setPosition({_s.width / 2, 130});
        selectedIconBG->setContentSize({375, 105.5});
        selectedIconBG->setOpacity(75);
        selectedIconBG->setTag(1500);
        this->addChild(selectedIconBG);

        auto arrowLeft = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
        auto arrowRight = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
        arrowRight->setFlipX(true);
        arrowLeft->setScale(0.75);
        arrowRight->setScale(0.75);
        auto arrowMenu = CCMenu::create();
        auto arrowBTNLeft = CCMenuItemSpriteExtra::create(arrowLeft, this, menu_selector(AsaSelectedIcon::iconSelected::iconPageLeft));
        auto arrowBTNRight = CCMenuItemSpriteExtra::create(arrowRight, this, menu_selector(AsaSelectedIcon::iconSelected::iconPageRight));
        arrowBTNLeft->setPosition({-210, 0});
        arrowBTNRight->setPosition({210, 0});
        arrowMenu->addChild(arrowBTNLeft, 5);
        arrowMenu->addChild(arrowBTNRight, 6);
        arrowMenu->setPosition({_s.width / 2, _s.height / 2 - 30});
        arrowMenu->setTag(2000);
        arrowMenu->setVisible(!(maxIcon[iconPage] < 37));
        this->addChild(arrowMenu, 5);

        auto selectedColor = CCSprite::createWithSpriteFrameName("GJ_shardsBtn_001.png");
        auto selectedColorPopup = CCMenuItemSpriteExtra::create(selectedColor, this, menu_selector(IconColorSelected::GJColorSelected::callback));
        auto selectedMenu = CCMenu::create();
        selectedMenu->addChild(selectedColorPopup);
        selectedMenu->setPosition({30, _s.height / 2 + 45});
        this->addChild(selectedMenu, 1);

        AsaSelectedIcon::ContentLayer *layers = new AsaSelectedIcon::ContentLayer();
        layers->changeTabPage(this, iconPage);
    }

    {
        auto playerMenu = CCMenu::create();

        auto btn1 = ButtonSprite::create("Player 1", 45, true, "bigFont.fnt", "GJ_button_02.png", 25, 1);
        auto btn2 = ButtonSprite::create("Player 2", 45, true, "bigFont.fnt", "GJ_button_02.png", 25, 1);
        auto btn1on = ButtonSprite::create("Player 1", 45, true, "bigFont.fnt", "GJ_button_04.png", 25, 1);
        auto btn2on = ButtonSprite::create("Player 2", 45, true, "bigFont.fnt", "GJ_button_04.png", 25, 1);

        auto player1Mode = CCMenuItemToggler::create(btn1on, btn1, this, menu_selector(AsaSelectedIcon::ContentLayer::changeSelectedPlayerMode));
        auto player2Mode = CCMenuItemToggler::create(btn2on, btn2, this, menu_selector(AsaSelectedIcon::ContentLayer::changeSelectedPlayerMode));
        player1Mode->toggle(isCustomSecondPlayer);
        player2Mode->toggle(!isCustomSecondPlayer);
        this->player1Mode = player1Mode;
        this->player2Mode = player2Mode;

        player1Mode->setTag(1);
        player2Mode->setTag(2);
        player2Mode->setPosition({player1Mode->getPositionX(), player1Mode->getPositionY() - 26});
        playerMenu->setPosition({iconBG->getPositionX() + iconBG->getContentSize().width / 2 + 35, iconBG->getPositionY() + iconBG->getContentSize().height / 2 - 11});

        playerMenu->addChild(player1Mode);
        playerMenu->addChild(player2Mode);
        playerMenu->setTag(1250);
        playerMenu->setVisible(GameManager::sharedState()->getGameVariable("1000"));

        this->addChild(playerMenu, 1);
    }
    return true;
}

AsaSelectedIcon::ContentLayer *AsaSelectedIcon::ContentLayer::create()
{
    auto createLayer = new ContentLayer();
    if (createLayer && createLayer->init())
    {
        createLayer->autorelease();
        return createLayer;
    }
    CC_SAFE_DELETE(createLayer);
    return nullptr;
};

void AsaSelectedIcon::ContentLayer::callback(CCObject *)
{
    auto scene = CCScene::create();
    auto contentLayer = ContentLayer::create();
    scene->addChild(contentLayer);
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
};