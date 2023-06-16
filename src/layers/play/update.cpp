#include "./update.hpp"
#include "./../asa_player2_icon/content.hpp"

void setAnimation(CCNode *icon, CCNode *anims)
{
    icon->setPosition(anims->getPosition());
    icon->setRotation(anims->getRotation());
};

void PlayLayerUpdate::init(PlayLayer *self)
{
    if (GameManager::sharedState()->getGameVariable("1001"))
        GameManager::sharedState()->m_pPlayLayer->m_player2->m_position =
            CCPoint(GameManager::sharedState()->m_pPlayLayer->m_player1->getPositionX(),
                    GameManager::sharedState()->m_pPlayLayer->m_player2->getPositionY());

    if (GameManager::sharedState()->getGameVariable("1000"))
    {
        auto thisLevel = GameManager::sharedState();
        auto levellayer = thisLevel->m_pPlayLayer;
        auto getPlayer = levellayer->m_player2;
        auto getFakeIcon = static_cast<CCSprite *>(levellayer->m_objectLayer->getChildByTag(5000));

        int color_1 = SecondPlayer::getColor();
        int color_2 = SecondPlayer::getSecondColor();

        auto col1 = GameManager::sharedState()->colorForIdx(color_1);
        auto col2 = GameManager::sharedState()->colorForIdx(color_2);

        getPlayer->m_regularTrail->setColor(col2);
        static_cast<CCSprite *>(static_cast<CCNode *>(self->m_objectLayer)->getChildByTag(7274))->setColor(col1);
        for (int index = 0; index < 9; index++)
        {
            static_cast<CCParticleSystemQuad *>(getPlayer->m_particleSystems->objectAtIndex(index))->setStartColor({(col1.r * 1.f), (col1.g * 1.f), (col1.b * 1.f), 1000});
            static_cast<CCParticleSystemQuad *>(getPlayer->m_particleSystems->objectAtIndex(index))->setEndColor({(col1.r * 1.f), (col1.g * 1.f), (col1.b * 1.f), 1000});
        }

        auto dashFire2 = static_cast<CCSprite *>(levellayer->m_objectLayer->getChildByTag(2568)->getChildren()->objectAtIndex(1));
        static_cast<CCSprite *>(dashFire2->getChildren()->objectAtIndex(0))->setColor(col1);
        static_cast<CCSprite *>(dashFire2->getChildren()->objectAtIndex(1))->setColor(col2);
        static_cast<CCSprite *>(dashFire2->getChildren()->objectAtIndex(2))->setColor(col1);

        getFakeIcon->setPosition(getPlayer->getPosition());
        getFakeIcon->setVisible(levellayer->m_isDualMode && getPlayer->isVisible());

        const char *gravity = "Flipped";
        getFakeIcon->setScaleX(getPlayer->getScaleX());
        getFakeIcon->setScaleY((getPlayer->m_gravity == atof(gravity)) ? (getPlayer->getScaleY() * -1) : getPlayer->getScaleY());

        static_cast<CCSprite *>(getFakeIcon->getChildByTag(1))->setVisible(getPlayer->m_isShip);
        static_cast<CCSprite *>(getFakeIcon->getChildByTag(2))->setVisible(getPlayer->m_isBird);
        static_cast<CCSprite *>(getFakeIcon->getChildByTag(3))->setVisible(getPlayer->m_isBall);
        static_cast<CCSprite *>(getFakeIcon->getChildByTag(4))->setVisible(getPlayer->m_isDart);
        static_cast<CCSprite *>(getFakeIcon->getChildByTag(5))->setVisible(getPlayer->m_isRobot);
        static_cast<CCSprite *>(getFakeIcon->getChildByTag(6))->setVisible(getPlayer->m_isSpider);
        static_cast<CCSprite *>(getFakeIcon->getChildByTag(0))->setVisible(!(getPlayer->m_isRobot || getPlayer->m_isSpider || getPlayer->m_isShip || getPlayer->m_isBird || getPlayer->m_isBall || getPlayer->m_isDart));

        if (!(getPlayer->m_isRobot || getPlayer->m_isSpider))
            (getPlayer->m_isDashing) ? getFakeIcon->setRotation(static_cast<CCSprite *>(getPlayer->getChildren()->objectAtIndex(0))->getRotation())
                                     : getFakeIcon->setRotation(getPlayer->getRotation());
        else
            getFakeIcon->setRotation(getPlayer->getRotation());

        if (getPlayer->m_isRobot)
        {
            const auto robotAnims = static_cast<CCNode *>(static_cast<GJRobotSprite *>(getPlayer->getChildren()->objectAtIndex(2))->getChildren()->objectAtIndex(0));
            const auto robotInDual = static_cast<CCNode *>(static_cast<GJRobotSprite *>(static_cast<SimplePlayer *>(static_cast<CCSprite *>(getFakeIcon->getChildByTag(5))->getChildByTag(0))->getChildByTag(1000))->getChildren()->objectAtIndex(0));

            for (int index = 1; index < 8; index++)
                setAnimation(static_cast<CCNode *>(robotInDual->getChildren()->objectAtIndex(index)), static_cast<CCNode *>(robotAnims->getChildren()->objectAtIndex(index)));
        }
        else if (getPlayer->m_isSpider)
        {
            const auto spiderAnims = static_cast<CCNode *>(static_cast<GJSpiderSprite *>(getPlayer->getChildren()->objectAtIndex(2))->getChildren()->objectAtIndex(0));
            const auto spiderInDual = static_cast<CCNode *>(static_cast<GJSpiderSprite *>(static_cast<SimplePlayer *>(static_cast<CCSprite *>(getFakeIcon->getChildByTag(6))->getChildByTag(0))->getChildByTag(1000))->getChildren()->objectAtIndex(0));

            for (int index = 1; index < 7; index++)
                setAnimation(static_cast<CCNode *>(spiderInDual->getChildren()->objectAtIndex(index)), static_cast<CCNode *>(spiderAnims->getChildren()->objectAtIndex(index)));
        };

        getPlayer->setOpacity(0);
    }
};