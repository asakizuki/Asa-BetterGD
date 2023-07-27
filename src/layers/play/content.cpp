#include "./content.hpp"
#include "./../asa_player2_icon/content.hpp"

void PlayLayerInit::init(PlayLayer *self, GJGameLevel *lvl)
{
    int cube_id = SecondPlayer::getPlayerCube();
    int ship_id = SecondPlayer::getPlayerShip();
    int ball_id = SecondPlayer::getPlayerBall();
    int ufo_id = SecondPlayer::getPlayerUfo();
    int wave_id = SecondPlayer::getPlayerWave();
    int robot_id = SecondPlayer::getPlayerRobot();
    int spider_id = SecondPlayer::getPlayerSpider();
    int color_1 = SecondPlayer::getColor();
    int color_2 = SecondPlayer::getSecondColor();
    bool hasGlow = SecondPlayer::getGlow();

    auto objectLayer = GameManager::sharedState()->m_pPlayLayer->m_objectLayer;
    auto getPlayer = GameManager::sharedState();

    auto col1 = getPlayer->colorForIdx(color_1);
    auto col2 = getPlayer->colorForIdx(color_2);

    objectLayer->getChildren()->objectAtIndex(5)->setTag(2568);
    objectLayer->getChildren()->objectAtIndex(5)->setTag(2568);

    auto iconKit = CCSprite::create();

    static_cast<CCNode *>(self->m_player2->m_waveTrail)->setTag(7274);

    // Icon renderer
    auto cube = PlayLayerInit::cubeRenderer(col1, col2, cube_id, hasGlow);
    auto ship = PlayLayerInit::iconWithShipRenderer(col1, col2, cube_id, ship_id, hasGlow);
    auto ufo = PlayLayerInit::iconWithUFORenderer(col1, col2, cube_id, ufo_id, hasGlow);
    auto ball = PlayLayerInit::ballRenderer(col1, col2, ball_id, hasGlow);
    auto wave = PlayLayerInit::waveRenderer(col1, col2, wave_id, hasGlow);
    auto robot = PlayLayerInit::robotRenderer(col1, col2, robot_id, hasGlow);
    auto spider = PlayLayerInit::spiderRenderer(col1, col2, spider_id, hasGlow);

    // Full icon stack
    iconKit->addChild(cube);
    iconKit->addChild(ship);
    iconKit->addChild(ufo);
    iconKit->addChild(ball);
    iconKit->addChild(wave);
    iconKit->addChild(robot);
    iconKit->addChild(spider);
    iconKit->setTag(5000);
    cube->setTag(0);
    ship->setTag(1);
    ufo->setTag(2);
    ball->setTag(3);
    wave->setTag(4);
    robot->setTag(5);
    spider->setTag(6);
    ufo->setPosition({20, 20});
    ship->setPosition({20, 20});

    cube->setVisible(false);
    ship->setVisible(false);
    ball->setVisible(false);
    ufo->setVisible(false);
    wave->setVisible(false);
    robot->setVisible(false);

    objectLayer->addChild(iconKit, 3);
};