#include "./../includes.hpp"

namespace PlayerRenderer
{
    CCSprite *cubeRenderer(ccColor3B color_1, ccColor3B color_2, int cube_id = 1, bool has_glow = false, float scale = 1.f)
    {
        auto iconKit = CCSprite::create("square02_small.png");
        iconKit->setOpacity(0);
        iconKit->setScale(scale);
        auto simplePlayerIcon = SimplePlayer::create(cube_id);
        simplePlayerIcon->setGlowOutline(has_glow);
        simplePlayerIcon->setColor(color_1);
        simplePlayerIcon->setSecondColor(color_2);
        simplePlayerIcon->setTag(0);
        simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
        simplePlayerIcon->updatePlayerFrame(cube_id, IconType::kIconTypeCube);
        iconKit->addChild(simplePlayerIcon);
        return iconKit;
    };

    CCSprite *shipRenderer(ccColor3B color_1, ccColor3B color_2, int ship_id = 1, bool has_glow = false, float scale = 1.f)
    {
        auto iconKit = CCSprite::create("square02_small.png");
        iconKit->setOpacity(0);
        iconKit->setScale(scale);
        auto simplePlayerIcon = SimplePlayer::create(ship_id);
        simplePlayerIcon->setGlowOutline(has_glow);
        simplePlayerIcon->setColor(color_1);
        simplePlayerIcon->setSecondColor(color_2);
        simplePlayerIcon->setTag(0);
        simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
        simplePlayerIcon->updatePlayerFrame(ship_id, IconType::kIconTypeShip);
        iconKit->addChild(simplePlayerIcon);
        return iconKit;
    };

    CCSprite *ballRenderer(ccColor3B color_1, ccColor3B color_2, int ball_id = 1, bool has_glow = false, float scale = 1.f)
    {
        auto iconKit = CCSprite::create("square02_small.png");
        iconKit->setOpacity(0);
        iconKit->setScale(scale);
        auto simplePlayerIcon = SimplePlayer::create(ball_id);
        simplePlayerIcon->setGlowOutline(has_glow);
        simplePlayerIcon->setColor(color_1);
        simplePlayerIcon->setSecondColor(color_2);
        simplePlayerIcon->setTag(0);
        simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
        simplePlayerIcon->updatePlayerFrame(ball_id, IconType::kIconTypeBall);
        iconKit->addChild(simplePlayerIcon);
        return iconKit;
    };

    CCSprite *ufoRenderer(ccColor3B color_1, ccColor3B color_2, int ufo_id = 1, bool has_glow = false, float scale = 1.f)
    {
        auto iconKit = CCSprite::create("square02_small.png");
        iconKit->setOpacity(0);
        iconKit->setScale(scale);
        auto simplePlayerIcon = SimplePlayer::create(ufo_id);
        simplePlayerIcon->setGlowOutline(has_glow);
        simplePlayerIcon->setColor(color_1);
        simplePlayerIcon->setSecondColor(color_2);
        simplePlayerIcon->setTag(0);
        simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
        simplePlayerIcon->updatePlayerFrame(ufo_id, IconType::kIconTypeUfo);
        iconKit->addChild(simplePlayerIcon);
        return iconKit;
    };

    CCSprite *waveRenderer(ccColor3B color_1, ccColor3B color_2, int wave_id = 1, bool has_glow = false, float scale = 1.f)
    {
        auto iconKit = CCSprite::create("square02_small.png");
        iconKit->setOpacity(0);
        iconKit->setScale(scale);
        auto simplePlayerIcon = SimplePlayer::create(wave_id);
        simplePlayerIcon->setGlowOutline(has_glow);
        simplePlayerIcon->setColor(color_1);
        simplePlayerIcon->setSecondColor(color_2);
        simplePlayerIcon->setTag(0);
        simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
        simplePlayerIcon->updatePlayerFrame(wave_id, IconType::kIconTypeWave);
        iconKit->addChild(simplePlayerIcon);
        return iconKit;
    };

    CCSprite *robotRenderer(ccColor3B color_1, ccColor3B color_2, int robot_id = 1, bool has_glow = false, float scale = 1.f)
    {
        auto iconKit = CCSprite::create("square02_small.png");
        iconKit->setOpacity(0);
        iconKit->setScale(scale);
        auto simplePlayerIcon = SimplePlayer::create(robot_id);
        simplePlayerIcon->setGlowOutline(has_glow);
        simplePlayerIcon->setColor(color_1);
        simplePlayerIcon->setSecondColor(color_2);
        simplePlayerIcon->setTag(0);
        simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
        simplePlayerIcon->updatePlayerFrame(robot_id, IconType::kIconTypeRobot);
        simplePlayerIcon->setTag(0);
        iconKit->addChild(simplePlayerIcon);

        static_cast<GJRobotSprite *>(simplePlayerIcon->getChildren()->objectAtIndex(1))->setTag(1000);

        return iconKit;
    };

    CCSprite *spiderRenderer(ccColor3B color_1, ccColor3B color_2, int spider_id = 1, bool has_glow = false, float scale = 1.f)
    {
        auto iconKit = CCSprite::create("square02_small.png");
        iconKit->setOpacity(0);
        iconKit->setScale(scale);
        auto simplePlayerIcon = SimplePlayer::create(spider_id);
        simplePlayerIcon->setGlowOutline(has_glow);
        simplePlayerIcon->setColor(color_1);
        simplePlayerIcon->setSecondColor(color_2);
        simplePlayerIcon->setTag(0);
        simplePlayerIcon->setPosition({iconKit->getContentSize().width / 2, iconKit->getContentSize().height / 2});
        simplePlayerIcon->updatePlayerFrame(spider_id, IconType::kIconTypeSpider);
        simplePlayerIcon->setTag(0);
        iconKit->addChild(simplePlayerIcon);

        static_cast<GJSpiderSprite *>(simplePlayerIcon->getChildren()->objectAtIndex(2))->setTag(1000);

        return iconKit;
    };

    CCSprite *iconWithShipRenderer(ccColor3B color_1, ccColor3B color_2, int cube_id = 1, int ship_id = 1, bool hasGlow = false)
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

    CCSprite *iconWithUFORenderer(ccColor3B color_1, ccColor3B color_2, int cube_id = 1, int ufo_id = 1, bool hasGlow = false)
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