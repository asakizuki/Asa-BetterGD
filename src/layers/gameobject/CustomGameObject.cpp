#include "./CustomGameObject.hpp"

void customGameObject::createWithkey(GameObject *object)
{
    if (GameManager::sharedState()->m_pPlayLayer)
    {
        auto label = CCLabelBMFont::create(CCString::createWithFormat("%i", object->m_objectID)->getCString(), "bigFont.fnt");
        label->setScale(0.3f);

        label->setPosition(object->getPosition());

        GameManager::sharedState()->getPlayLayer()->m_objectLayer->addChild(label, 250);
    }
};