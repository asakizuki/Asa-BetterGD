#include "./../../includes.hpp"

namespace selectedLiveOverlay
{
    class overlay : FLAlertLayer
    {
    public:
        static void init(CCLayer *self, ColorAction *col_1, ColorAction *col_2, EffectGameObject *gObj);
        static void onSelectTab(CCLayer *self, CCObject *obj);

        EffectGameObject *m_effectGameObject;
        cocos2d::CCArray *m_barSprites;
        cocos2d::CCArray *m_12buttons;
        ColorAction *m_baseColorAction;
        ColorAction *m_detailColorAction;
        PAD(0x64);
        bool m_detailMode;
    };

    class callback
    {
    public:
        void onBlending(CCLayer *sender)
        {
            selectedLiveOverlay::overlay *asa;
            if (asa->m_detailMode)
                asa->m_detailColorAction->m_blending = !asa->m_detailColorAction->m_blending;
            else
                asa->m_baseColorAction->m_blending = !asa->m_baseColorAction->m_blending;
        };
    };
};