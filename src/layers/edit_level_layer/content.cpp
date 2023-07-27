#include "./content.hpp"

void EditLevelLayerInit::init(CCLayer *self, GJGameLevel *lvl)
{
    auto songWidget = CustomSongWidget::create();

    self->addChild(songWidget, 1000);
};