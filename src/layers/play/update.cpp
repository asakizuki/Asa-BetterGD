#include "./update.hpp"
#include "./../asa_player2_icon/content.hpp"

void setAnimation(CCNode *icon, CCNode *anims)
{
    icon->setPosition(anims->getPosition());
    icon->setRotation(anims->getRotation());
};

void setGlowID(PlayerObject *p)
{
    auto _g = p->m_vehicleGlow->getChildren();
    auto size = CCDirector::sharedDirector()->getWinSize();
    auto gameInfo = GameManager::sharedState()->getPlayLayer();
    gameInfo->m_percentLabel->setPositionX(size.width / 2);
    gameInfo->m_startPos->m_startPosition.setPoint(500, 500);

    static_cast<CCSprite *>(_g->objectAtIndex(0))->setTag(1);
    static_cast<CCSprite *>(_g->objectAtIndex(1))->setTag(2);
    static_cast<CCSprite *>(_g->objectAtIndex(2))->setTag(3);
}

void PlayLayerUpdate::init(PlayLayer *self)
{
    auto gm = GameManager::sharedState();
};