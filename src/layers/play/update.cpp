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
    }
};