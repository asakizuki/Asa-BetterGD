#include "./../../includes.hpp"

class SelectedIconScreen : public FLAlertLayer
{
public:
    CCLayer *iconScrollLayer;
    CCSprite *selectedIcon;
    SimplePlayer *player[2];
    static SelectedIconScreen *create(CCLayer *self)
    {
        SelectedIconScreen *pRet = new SelectedIconScreen();
        if (pRet && pRet->init(self))
        {
            pRet->autorelease();
            return pRet;
        }
        CC_SAFE_DELETE(pRet);
        pRet = nullptr;
        return nullptr;
    };
    bool init(CCLayer *);
    void keyBackClicked();
    void scrollWheel(float px, float py) override;
    void keyBack(CCObject *)
    {
        this->keyBackClicked();
    };
    void callback(CCObject *);
    void loadIconList();
    void setIcon(CCObject *);
    CCLayer *iconPreview();
};