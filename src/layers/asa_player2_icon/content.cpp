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

bool SecondPlayer::getGlow() { return GameManager::sharedState()->getGameVariable("SecondPlayerGlow"); }