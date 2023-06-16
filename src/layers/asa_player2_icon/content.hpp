#include "./../../includes.hpp"

class SecondPlayer
{
public:
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