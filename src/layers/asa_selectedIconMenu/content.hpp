#include "./../../includes.hpp"
#include "./colorSelected.hpp"

namespace AsaSelectedIcon
{
    class ContentLayer : public CCLayer
    {
    protected:
        virtual bool init();
        virtual void keyBackClicked()
        {
            CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
        };
        void gobackBtn(CCObject *)
        {
            keyBackClicked();
        };

    public:
        CCSprite *selectedIconImg;
        CCMenu *iconSelectedMenu;
        CCMenuItemToggler *player1Mode;
        CCMenuItemToggler *player2Mode;

        static ContentLayer *
        create();
        void callback(CCObject *);
        void changeTabPage(CCLayer *self, int iconType);
        void changeSelectedPlayerMode(CCObject *self);
        void updatePlayerIcon();
        void iconSelectedSetting();
    };

    class iconSelected
    {
    public:
        void iconPageLeft(CCLayer *);
        void iconPageRight(CCLayer *);
        void changeIconSelectedPage(CCLayer *self);
        void changeIcon(CCLayer *);
    };
}