#include "./content.hpp"

void SecondPlayer::setPlayerCube(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerCube", ID); }
void SecondPlayer::setPlayerShip(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerShip", ID); }
void SecondPlayer::setPlayerBall(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerBall", ID); }
void SecondPlayer::setPlayerUfo(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerUfo", ID); }
void SecondPlayer::setPlayerWave(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerWave", ID); }
void SecondPlayer::setPlayerRobot(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerRobot", ID); }
void SecondPlayer::setPlayerSpider(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerSpider", ID); }

int SecondPlayer::getPlayerCube() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerCube"); };
int SecondPlayer::getPlayerShip() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerShip"); };
int SecondPlayer::getPlayerBall() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerBall"); };
int SecondPlayer::getPlayerUfo() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerUfo"); };
int SecondPlayer::getPlayerWave() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerWave"); };
int SecondPlayer::getPlayerRobot() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerRobot"); };
int SecondPlayer::getPlayerSpider() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerSpider"); };

void SecondPlayer::setColor(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerColor", ID); };
void SecondPlayer::setSecondColor(int ID) { GameManager::sharedState()->setIntGameVariable("SecondPlayerSecondColor", ID); };

int SecondPlayer::getColor() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerColor"); };
int SecondPlayer::getSecondColor() { return GameManager::sharedState()->getIntGameVariable("SecondPlayerSecondColor"); };

void SecondPlayer::setGlow(bool hasGlow) { GameManager::sharedState()->setGameVariable("SecondPlayerGlow", hasGlow); };

bool SecondPlayer::getGlow() { return GameManager::sharedState()->getGameVariable("SecondPlayerGlow"); };

int CurrentMaxIcon[7] = {0, 0, 0, 0, 0, 0, 0};
void SecondPlayer::setupMaxIcon()
{
    CurrentMaxIcon[0] = SecondPlayer::getMaxSingleIcon("player");
    CurrentMaxIcon[1] = SecondPlayer::getMaxSingleIcon("ship");
    CurrentMaxIcon[2] = SecondPlayer::getMaxSingleIcon("player_ball");
    CurrentMaxIcon[3] = SecondPlayer::getMaxSingleIcon("bird");
    CurrentMaxIcon[4] = SecondPlayer::getMaxSingleIcon("dart");
    CurrentMaxIcon[5] = SecondPlayer::getMaxSingleIcon("robot");
    CurrentMaxIcon[6] = SecondPlayer::getMaxSingleIcon("spider");
};
int SecondPlayer::getMaxIcon(int index)
{
    return CurrentMaxIcon[index];
};

void SecondPlayer::fixCrashIssue()
{
    auto gm = GameManager::sharedState();

    if (CurrentMaxIcon[0] - 1 < gm->getPlayerFrame())
        gm->setPlayerFrame(CurrentMaxIcon[0] - 1);
    if (CurrentMaxIcon[1] - 1 < gm->getPlayerShip())
        gm->setPlayerShip(CurrentMaxIcon[1] - 1);
    if (CurrentMaxIcon[2] - 1 < gm->getPlayerBall())
        gm->setPlayerBall(CurrentMaxIcon[2] - 1);
    if (CurrentMaxIcon[3] - 1 < gm->getPlayerBird())
        gm->setPlayerBird(CurrentMaxIcon[3] - 1);
    if (CurrentMaxIcon[4] - 1 < gm->getPlayerDart())
        gm->setPlayerDart(CurrentMaxIcon[4] - 1);
    if (CurrentMaxIcon[5] - 1 < gm->getPlayerRobot())
        gm->setPlayerRobot(CurrentMaxIcon[5] - 1);
    if (CurrentMaxIcon[6] - 1 < gm->getPlayerSpider())
        gm->setPlayerSpider(CurrentMaxIcon[6] - 1);

    if (CurrentMaxIcon[0] - 1 < SecondPlayer::getPlayerCube())
        SecondPlayer::setPlayerCube(CurrentMaxIcon[0] - 1);
    if (CurrentMaxIcon[1] - 1 < SecondPlayer::getPlayerShip())
        SecondPlayer::setPlayerShip(CurrentMaxIcon[1] - 1);
    if (CurrentMaxIcon[2] - 1 < SecondPlayer::getPlayerBall())
        SecondPlayer::setPlayerBall(CurrentMaxIcon[2] - 1);
    if (CurrentMaxIcon[3] - 1 < SecondPlayer::getPlayerUfo())
        SecondPlayer::setPlayerUfo(CurrentMaxIcon[3] - 1);
    if (CurrentMaxIcon[4] - 1 < SecondPlayer::getPlayerWave())
        SecondPlayer::setPlayerWave(CurrentMaxIcon[4] - 1);
    if (CurrentMaxIcon[5] - 1 < SecondPlayer::getPlayerRobot())
        SecondPlayer::setPlayerRobot(CurrentMaxIcon[5] - 1);
    if (CurrentMaxIcon[6] - 1 < SecondPlayer::getPlayerSpider())
        SecondPlayer::setPlayerSpider(CurrentMaxIcon[6] - 1);
}