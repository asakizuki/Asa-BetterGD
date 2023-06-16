#include <matdash.hpp>
#include <matdash/minhook.hpp>
#include <matdash/boilerplate.hpp>
#include "./includes.hpp"
#include "./importFile.hpp"

namespace LayerInit
{
    void main(CCLayer *layers)
    {
        matdash::orig<&main>(layers);
        MainLayerInit::init(layers);
    };
    void editorUI(CCLayer *layers, LevelEditorLayer *lvl)
    {
        matdash::orig<&editorUI>(layers, lvl);
        EditorLayerInit::init(layers, lvl);
    };
    void selectedLiveOverlay(CCLayer *self, ColorAction *col_1, ColorAction *col_2, EffectGameObject *gObj)
    {
        matdash::orig<&selectedLiveOverlay>(self, col_1, col_2, gObj);
        selectedLiveOverlay::overlay::init(self, col_1, col_2, gObj);
    };
    void onSelectedTabLiveOverlay(CCLayer *self, CCObject *obj)
    {
        matdash::orig<&onSelectedTabLiveOverlay>(self, obj);
        selectedLiveOverlay::overlay::onSelectTab(self, obj);
    };
    void pause(CCLayer *self)
    {
        matdash::orig<&pause>(self);
        PauseLayerInit::init(self);
    };
    void play(PlayLayer *self, GJGameLevel *lvl)
    {
        matdash::orig<&play>(self, lvl);
        PlayLayerInit::init(self, lvl);
    };
    void playUpdate(PlayLayer *self, float *lvl)
    {
        matdash::orig<&playUpdate>(self, lvl);
        PlayLayerUpdate::init(self);
    };
};