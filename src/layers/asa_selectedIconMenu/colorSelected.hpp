#include "./../../includes.hpp"
#include "./../asa_player2_icon/content.hpp"

namespace IconColorSelected
{
    class content : public FLAlertLayer
    {
        SimplePlayer *m_pCube;
        SimplePlayer *m_pShip;
        SimplePlayer *m_pBall;
        SimplePlayer *m_pUFO;
        SimplePlayer *m_pWave;
        SimplePlayer *m_pRobot;
        SimplePlayer *m_pSpider;

        SimplePlayer *m_p2Cube;
        SimplePlayer *m_p2Ship;
        SimplePlayer *m_p2Ball;
        SimplePlayer *m_p2UFO;
        SimplePlayer *m_p2Wave;
        SimplePlayer *m_p2Robot;
        SimplePlayer *m_p2Spider;

        CCSprite *promanyColor;
        CCSprite *secondColor;

        CCMenu *colorMenu;

        CCSprite *colorSelected_1;
        CCSprite *colorSelected_2;

        CCMenuItemToggler *player1Mode;
        CCMenuItemToggler *player2Mode;
        CCMenuItemToggler *glowToggle;

        float setSecondColor = false;

    public:
        void changeSelectedPlayerMode(CCObject *);
        bool init(CCLayer *layer);
        void changeGameGlow(CCObject *);
        void changeColorMode(CCObject *self);
        void setPlayerColor(CCObject *layer);
        void keyBackClicked()
        {
            this->setKeypadEnabled(false);
            this->setKeyboardEnabled(false);
            this->removeFromParentAndCleanup(true);

            bool player1Active = static_cast<CCMenuItemToggler *>(
                                     static_cast<extension::CCScale9Sprite *>(
                                         static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0))->getChildByTag(1250))
                                         ->getChildren()
                                         ->objectAtIndex(0))
                                     ->isOn();

            auto _gameInfo = GameManager::sharedState();
            bool glow = (player1Active) ? _gameInfo->m_bPlayerGlow : SecondPlayer::getGlow();
            auto col1 = _gameInfo->colorForIdx((player1Active) ? _gameInfo->m_nPlayerColor : SecondPlayer::getColor());
            auto col2 = _gameInfo->colorForIdx((player1Active) ? _gameInfo->m_nPlayerColor2 : SecondPlayer::getSecondColor());

            auto scene = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
            auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(scene->getChildByTag(1000));
            auto cube = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(0))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto ship = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(1))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto ball = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(2))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto ufo = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(3))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto wave = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(4))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto robot = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(5))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto spider = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(6))->getChildByTag(1))->getChildren()->objectAtIndex(0));

            cube->setColor(col1);
            cube->setSecondColor(col2);
            cube->setGlowOutline(glow);
            ship->setColor(col1);
            ship->setSecondColor(col2);
            ship->setGlowOutline(glow);
            ball->setColor(col1);
            ball->setSecondColor(col2);
            ball->setGlowOutline(glow);
            ufo->setColor(col1);
            ufo->setSecondColor(col2);
            ufo->setGlowOutline(glow);
            wave->setColor(col1);
            wave->setSecondColor(col2);
            wave->setGlowOutline(glow);
            robot->setColor(col1);
            robot->setSecondColor(col2);
            robot->setGlowOutline(glow);
            spider->setColor(col1);
            spider->setSecondColor(col2);
            spider->setGlowOutline(glow);
        };
        static content *create(CCLayer *layer)
        {
            content *pRet = new content();
            if (pRet && pRet->init(layer))
            {
                pRet->autorelease();
                return pRet;
            }
            CC_SAFE_DELETE(pRet);
            pRet = nullptr;
            return nullptr;
        };
        void keyBackClicked(CCObject *)
        {
            this->setKeypadEnabled(false);
            this->setKeyboardEnabled(false);
            this->removeFromParentAndCleanup(true);

            bool player1Active = static_cast<CCMenuItemToggler *>(
                                     static_cast<extension::CCScale9Sprite *>(
                                         static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0))->getChildByTag(1250))
                                         ->getChildren()
                                         ->objectAtIndex(0))
                                     ->isOn();

            auto _gameInfo = GameManager::sharedState();
            bool glow = (player1Active) ? _gameInfo->m_bPlayerGlow : SecondPlayer::getGlow();
            auto col1 = _gameInfo->colorForIdx((player1Active) ? _gameInfo->m_nPlayerColor : SecondPlayer::getColor());
            auto col2 = _gameInfo->colorForIdx((player1Active) ? _gameInfo->m_nPlayerColor2 : SecondPlayer::getSecondColor());

            auto scene = static_cast<CCLayer *>(CCDirector::sharedDirector()->getRunningScene()->getChildren()->objectAtIndex(0));
            auto selectedIconBG = static_cast<extension::CCScale9Sprite *>(scene->getChildByTag(1000));
            auto cube = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(0))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto ship = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(1))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto ball = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(2))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto ufo = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(3))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto wave = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(4))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto robot = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(5))->getChildByTag(1))->getChildren()->objectAtIndex(0));
            auto spider = static_cast<SimplePlayer *>(static_cast<CCSprite *>(static_cast<CCMenuItemSpriteExtra *>(static_cast<CCMenu *>(selectedIconBG->getChildren()->objectAtIndex(1))->getChildByTag(6))->getChildByTag(1))->getChildren()->objectAtIndex(0));

            cube->setColor(col1);
            cube->setSecondColor(col2);
            cube->setGlowOutline(glow);
            ship->setColor(col1);
            ship->setSecondColor(col2);
            ship->setGlowOutline(glow);
            ball->setColor(col1);
            ball->setSecondColor(col2);
            ball->setGlowOutline(glow);
            ufo->setColor(col1);
            ufo->setSecondColor(col2);
            ufo->setGlowOutline(glow);
            wave->setColor(col1);
            wave->setSecondColor(col2);
            wave->setGlowOutline(glow);
            robot->setColor(col1);
            robot->setSecondColor(col2);
            robot->setGlowOutline(glow);
            spider->setColor(col1);
            spider->setSecondColor(col2);
            spider->setGlowOutline(glow);
        };
        CCMenuItemSpriteExtra *createColorButton(int colorID = 0)
        {
            auto colorByID = GameManager::sharedState()->colorForIdx(colorID);
            auto colorBtnTexture = CCSprite::createWithSpriteFrameName("GJ_colorBtn_001.png");
            colorBtnTexture->setColor(colorByID);
            colorBtnTexture->setScale(0.7f);
            auto button = CCMenuItemSpriteExtra::create(colorBtnTexture, this, menu_selector(content::setPlayerColor));
            button->setTag(colorID);
            return button;
        };
        void updatePlayerColor();
    };

    class GJColorSelected : public CCLayer
    {
    public:
        void callback(CCObject *)
        {
            content::create(this)->show();
        };
    };

    class PlayerRenderer
    {
    public:
        static CCSprite *cubeRenderer(ccColor3B color_1, ccColor3B color_2, int cube_id = 1, bool has_glow = false, float scale = 1.f)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);
            iconKit->setScale(scale);
            auto simplePlayerIcon = SimplePlayer::create(cube_id);
            simplePlayerIcon->setGlowOutline(has_glow);
            simplePlayerIcon->setColor(color_1);
            simplePlayerIcon->setSecondColor(color_2);
            simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
            simplePlayerIcon->updatePlayerFrame(cube_id, IconType::kIconTypeCube);
            iconKit->addChild(simplePlayerIcon);
            return iconKit;
        };

        static CCSprite *shipRenderer(ccColor3B color_1, ccColor3B color_2, int ship_id = 1, bool has_glow = false, float scale = 1.f)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);
            iconKit->setScale(scale);
            auto simplePlayerIcon = SimplePlayer::create(ship_id);
            simplePlayerIcon->setGlowOutline(has_glow);
            simplePlayerIcon->setColor(color_1);
            simplePlayerIcon->setSecondColor(color_2);
            simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
            simplePlayerIcon->updatePlayerFrame(ship_id, IconType::kIconTypeShip);
            iconKit->addChild(simplePlayerIcon);
            return iconKit;
        };

        static CCSprite *ballRenderer(ccColor3B color_1, ccColor3B color_2, int ball_id = 1, bool has_glow = false, float scale = 1.f)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);
            iconKit->setScale(scale);
            auto simplePlayerIcon = SimplePlayer::create(ball_id);
            simplePlayerIcon->setGlowOutline(has_glow);
            simplePlayerIcon->setColor(color_1);
            simplePlayerIcon->setSecondColor(color_2);
            simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
            simplePlayerIcon->updatePlayerFrame(ball_id, IconType::kIconTypeBall);
            iconKit->addChild(simplePlayerIcon);
            return iconKit;
        };

        static CCSprite *ufoRenderer(ccColor3B color_1, ccColor3B color_2, int ufo_id = 1, bool has_glow = false, float scale = 1.f)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);
            iconKit->setScale(scale);
            auto simplePlayerIcon = SimplePlayer::create(ufo_id);
            simplePlayerIcon->setGlowOutline(has_glow);
            simplePlayerIcon->setColor(color_1);
            simplePlayerIcon->setSecondColor(color_2);
            simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
            simplePlayerIcon->updatePlayerFrame(ufo_id, IconType::kIconTypeUfo);
            iconKit->addChild(simplePlayerIcon);
            return iconKit;
        };

        static CCSprite *waveRenderer(ccColor3B color_1, ccColor3B color_2, int wave_id = 1, bool has_glow = false, float scale = 1.f)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);
            iconKit->setScale(scale);
            auto simplePlayerIcon = SimplePlayer::create(wave_id);
            simplePlayerIcon->setGlowOutline(has_glow);
            simplePlayerIcon->setColor(color_1);
            simplePlayerIcon->setSecondColor(color_2);
            simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
            simplePlayerIcon->updatePlayerFrame(wave_id, IconType::kIconTypeWave);
            iconKit->addChild(simplePlayerIcon);
            return iconKit;
        };

        static CCSprite *robotRenderer(ccColor3B color_1, ccColor3B color_2, int robot_id = 1, bool has_glow = false, float scale = 1.f)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);
            iconKit->setScale(scale);
            auto simplePlayerIcon = SimplePlayer::create(robot_id);
            simplePlayerIcon->setGlowOutline(has_glow);
            simplePlayerIcon->setColor(color_1);
            simplePlayerIcon->setSecondColor(color_2);
            simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
            simplePlayerIcon->updatePlayerFrame(robot_id, IconType::kIconTypeRobot);
            simplePlayerIcon->setTag(0);
            iconKit->addChild(simplePlayerIcon);

            static_cast<GJRobotSprite *>(simplePlayerIcon->getChildren()->objectAtIndex(1))->setTag(1000);

            return iconKit;
        };

        static CCSprite *spiderRenderer(ccColor3B color_1, ccColor3B color_2, int spider_id = 1, bool has_glow = false, float scale = 1.f)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);
            iconKit->setScale(scale);
            auto simplePlayerIcon = SimplePlayer::create(spider_id);
            simplePlayerIcon->setGlowOutline(has_glow);
            simplePlayerIcon->setColor(color_1);
            simplePlayerIcon->setSecondColor(color_2);
            simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
            simplePlayerIcon->updatePlayerFrame(spider_id, IconType::kIconTypeSpider);
            simplePlayerIcon->setTag(0);
            iconKit->addChild(simplePlayerIcon);

            static_cast<GJSpiderSprite *>(simplePlayerIcon->getChildren()->objectAtIndex(2))->setTag(1000);

            return iconKit;
        };

        static CCSprite *iconWithShipRenderer(ccColor3B color_1, ccColor3B color_2, int cube_id = 1, int ship_id = 1, bool hasGlow = false)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);

            auto cube = PlayerRenderer::cubeRenderer(color_1, color_2, cube_id, hasGlow);
            auto ship = PlayerRenderer::shipRenderer(color_1, color_2, ship_id, hasGlow);

            cube->setScale(0.55f);
            cube->setPosition({0.5, 5});
            ship->setPosition({0, -5});
            iconKit->addChild(cube, 1);
            iconKit->addChild(ship, 2);

            return iconKit;
        };

        static CCSprite *iconWithUFORenderer(ccColor3B color_1, ccColor3B color_2, int cube_id = 1, int ufo_id = 1, bool hasGlow = false)
        {
            auto iconKit = CCSprite::create("square02_small.png");
            iconKit->setOpacity(0);

            auto cube = PlayerRenderer::cubeRenderer(color_1, color_2, cube_id, hasGlow);
            auto ufo = PlayerRenderer::ufoRenderer(color_1, color_2, ufo_id, hasGlow);

            cube->setScale(0.55f);
            cube->setPosition({0, 12.5 - 7});
            ufo->setPosition({0, 0});
            iconKit->addChild(cube, 1);
            iconKit->addChild(ufo, 2);

            return iconKit;
        };
    };
}