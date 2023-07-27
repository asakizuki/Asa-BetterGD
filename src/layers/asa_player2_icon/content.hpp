#include "./../../includes.hpp"

class SecondPlayer
{
public:
    static const char *addZero(int num)
    {
        if (num < 10)
            return CCString::createWithFormat("0%i", num)->getCString();
        else
            return CCString::createWithFormat("%i", num)->getCString();
    };
    static int getMaxSingleIcon(const char *iconName)
    {
        int totalIcon = 1;
        if (iconName == "robot" || iconName == "spider")
        {
            for (int currentIcon = 1; currentIcon < 5000; currentIcon++)
            {
                auto pCubeIndex = SecondPlayer::addZero(currentIcon);

                auto p1_1 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_01_001.png", iconName, pCubeIndex)->getCString());
                auto p2_1 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_01_2_001.png", iconName, pCubeIndex)->getCString());
                auto pGlow_1 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_01_glow_001.png", iconName, pCubeIndex)->getCString());

                auto p1_2 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_02_001.png", iconName, pCubeIndex)->getCString());
                auto p2_2 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_02_2_001.png", iconName, pCubeIndex)->getCString());
                auto pGlow_2 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_02_glow_001.png", iconName, pCubeIndex)->getCString());

                auto p1_3 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_03_001.png", iconName, pCubeIndex)->getCString());
                auto p2_3 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_03_2_001.png", iconName, pCubeIndex)->getCString());
                auto pGlow_3 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_03_glow_001.png", iconName, pCubeIndex)->getCString());

                auto p1_4 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_04_001.png", iconName, pCubeIndex)->getCString());
                auto p2_4 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_04_2_001.png", iconName, pCubeIndex)->getCString());
                auto pGlow_4 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_04_glow_001.png", iconName, pCubeIndex)->getCString());

                if (!(p1_1 && p2_1 && pGlow_1 && p1_2 && p2_2 && pGlow_2 && p1_3 && p2_3 && pGlow_3 && p1_4 && p2_4 && pGlow_4) || !(currentIcon < 999))
                    break;
                else
                    totalIcon = currentIcon + 1;
            };
        }
        else
        {
            for (int currentIcon = 1; currentIcon < 5000; currentIcon++)
            {
                auto pCubeIndex = SecondPlayer::addZero(currentIcon);
                auto p1 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_001.png", iconName, pCubeIndex)->getCString());
                auto p2 = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_2_001.png", iconName, pCubeIndex)->getCString());
                auto glow = CCSprite::createWithSpriteFrameName(CCString::createWithFormat("%s_%s_glow_001.png", iconName, pCubeIndex)->getCString());

                if (!(p1 && p2 && glow) || !(currentIcon < 999))
                    break;
                else
                    totalIcon = currentIcon + 1;
            };
        }
        return totalIcon;
    };
    static void setupMaxIcon();
    static int getMaxIcon(int index);
    static void fixCrashIssue();

    static void setPlayerCube(int ID);
    static void setPlayerShip(int ID);
    static void setPlayerBall(int ID);
    static void setPlayerUfo(int ID);
    static void setPlayerWave(int ID);
    static void setPlayerRobot(int ID);
    static void setPlayerSpider(int ID);
    static int getPlayerCube();
    static int getPlayerShip();
    static int getPlayerBall();
    static int getPlayerUfo();
    static int getPlayerWave();
    static int getPlayerRobot();
    static int getPlayerSpider();
    static void setColor(int ID);
    static void setSecondColor(int ID);
    static int getColor();
    static int getSecondColor();
    static void setGlow(bool hasGlow);
    static bool getGlow();

    static void firstTime()
    {
        auto gManage = GameManager::sharedState();
        if (!gManage->getGameVariable("asaIsNotFirstTimeSetup"))
        {
            SecondPlayer::setPlayerCube(1);
            SecondPlayer::setPlayerShip(1);
            SecondPlayer::setPlayerBall(1);
            SecondPlayer::setPlayerWave(1);
            SecondPlayer::setPlayerUfo(1);
            SecondPlayer::setPlayerRobot(1);
            SecondPlayer::setPlayerSpider(1);
            SecondPlayer::setColor(0);
            SecondPlayer::setSecondColor(3);
            SecondPlayer::setGlow(false);

            gManage->setGameVariable("asaIsNotFirstTimeSetup", true);
        }
    };
};