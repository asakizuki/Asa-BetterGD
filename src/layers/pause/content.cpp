#include "./content.hpp"

bool noclipMode = false;

void PauseLayerInit::noclipActive(CCLayer *)
{
    noclipMode = !noclipMode;
    // Address by Absolute
    if (noclipMode)
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x20A23C), "\xE9\x79\x06\x00\x00", 5, NULL);
    else
        WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void *>(base + 0x20A23C), "\x6A\x14\x8B\xCB\xFF", 5, NULL);
};

void generateProgressbar(CCLayer *self, int Percent, int yPosition, ccColor3B color, const char *ProgressText, bool isPractice)
{
    auto size = CCDirector::sharedDirector()->getWinSize();
    auto gameInfo = GameManager::sharedState()->getPlayLayer();
    float getCurrentPercent = gameInfo->m_player1->getPositionX() * 100 / gameInfo->m_levelLength;

    auto progressbarBg = CCSprite::create("GJ_progressBar_001.png");
    progressbarBg->setScale(0.5f);
    progressbarBg->setColor({0, 0, 0});
    progressbarBg->setOpacity(100);
    progressbarBg->setAnchorPoint({1, 1});
    progressbarBg->setPosition({size.width - 35, size.height - yPosition});

    float getProgressOffset = (progressbarBg->getContentSize().width * Percent) / 100;
    float getCurrentProgressOffset = (progressbarBg->getContentSize().width * getCurrentPercent) / 100;

    auto newbestProgress = CCSprite::create("GJ_progressBar_001.png");
    newbestProgress->setScale(0.5f);
    newbestProgress->setColor(color);
    newbestProgress->setAnchorPoint({1, 1});
    newbestProgress->setPosition({size.width - 35 - ((progressbarBg->getTextureRect().size.width - getProgressOffset) / 2), size.height - yPosition});

    auto progressName = CCLabelBMFont::create(ProgressText, "bigFont.fnt");
    progressName->setScale(0.35f);
    progressName->setAnchorPoint({0, 0});
    progressName->setPosition({size.width - 171 - 35, size.height + 1 - yPosition});

    auto bestLabel = CCLabelBMFont::create(CCString::createWithFormat("Best: %i%%", Percent)->getCString(), "goldFont.fnt");
    bestLabel->setScale(0.5f);
    bestLabel->setAnchorPoint({1, 1});
    bestLabel->setPosition({size.width - 34, size.height - 8 - yPosition});

    auto nprogress = CCSize(getProgressOffset, newbestProgress->getContentSize().height);
    newbestProgress->setTextureRect(CCRect(0.0f, 0.0f, nprogress.width, nprogress.height));

    if (isPractice)
    {
        newbestProgress->setOpacity(75);
        auto currentProgress = CCSprite::create("GJ_progressBar_001.png");
        currentProgress->setScale(0.5f);
        currentProgress->setColor(color);
        currentProgress->setAnchorPoint({1, 1});
        currentProgress->setPosition({size.width - 35 - ((progressbarBg->getTextureRect().size.width - getCurrentProgressOffset) / 2), size.height - yPosition});
        auto progress = CCSize(getCurrentProgressOffset, currentProgress->getContentSize().height);
        currentProgress->setTextureRect(CCRect(0.0f, 0.0f, progress.width, progress.height));
        self->addChild(currentProgress, 52);

        int currentPerLabel = (int)getCurrentPercent;
        auto currentLabel = CCLabelBMFont::create(CCString::createWithFormat("%i%%", currentPerLabel)->getCString(), "bigFont.fnt");
        currentLabel->setScale(0.4f);
        currentLabel->setAnchorPoint({0, 1});
        currentLabel->setPosition({size.width - 171 - 35, size.height - 9 - yPosition});
        self->addChild(currentLabel, 51);
    }

    self->addChild(progressbarBg, 50);
    self->addChild(newbestProgress, 51);
    self->addChild(progressName, 51);
    self->addChild(bestLabel, 51);
};

void PauseLayerInit::init(CCLayer *self)
{
    auto size = CCDirector::sharedDirector()->getWinSize();
    auto gameInfo = GameManager::sharedState()->getPlayLayer();

    // Info
    auto levelName = CCLabelBMFont::create(gameInfo->m_level->levelName.c_str(), "goldFont.fnt");
    levelName->setPosition({35, size.height - 30});
    levelName->setAnchorPoint({0, 1});
    levelName->setScale(0.7f);

    const char *levelLength[5] = {"Tiny", "Short", "Medium", "Long", "XL"};
    auto levelCreate = CCLabelBMFont::create(
        CCString::createWithFormat((gameInfo->m_level->levelID > 99 || gameInfo->m_level->levelID == 0) ? "By %s" : "By Robtop%s", gameInfo->m_level->userName.c_str())->getCString(), "bigFont.fnt");
    levelCreate->setPosition({36, size.height - 50});
    levelCreate->setAnchorPoint({0, 1});
    levelCreate->setScale(0.4f);

    auto levelLengthLabel = CCLabelBMFont::create(CCString::createWithFormat("Length %s", levelLength[gameInfo->m_level->levelLength])->getCString(), "bigFont.fnt");
    levelLengthLabel->setPosition({326, size.height - 50});
    levelLengthLabel->setAnchorPoint({1, 1});
    levelLengthLabel->setScale(0.4f);

    auto id_level_0 = CCString::createWithFormat("Local Level")->getCString();
    auto robtopLevel = CCString::createWithFormat("Offcial Level")->getCString();
    auto online_level = CCString::createWithFormat("ID: %i", gameInfo->m_level->levelID)->getCString();
    auto levelType = CCLabelBMFont::create((gameInfo->m_level->levelID == 0) ? id_level_0 : (gameInfo->m_level->levelID < 100) ? robtopLevel
                                                                                                                               : online_level,
                                           "bigFont.fnt");

    levelType->setPosition({36, size.height - 62});
    levelType->setAnchorPoint({0, 1});
    levelType->setScale(0.4f);

    auto levelVersion = CCLabelBMFont::create(CCString::createWithFormat("Version %i", gameInfo->m_level->levelVersion)->getCString(), "bigFont.fnt");
    levelVersion->setPosition({326, size.height - 62});
    levelVersion->setAnchorPoint({1, 1});
    levelVersion->setScale(0.4f);

    self->addChild(levelName, 50);
    self->addChild(levelCreate, 50);
    self->addChild(levelLengthLabel, 50);
    self->addChild(levelType, 50);
    self->addChild(levelVersion, 50);

    // Progress Bar
    generateProgressbar(self, gameInfo->m_level->normalPercent, 45, ccColor3B({0, 255, 0}), "Normal", !gameInfo->m_isPracticeMode);
    generateProgressbar(self, gameInfo->m_level->practicePercent, 85, ccColor3B({0, 255, 255}), "Practice", gameInfo->m_isPracticeMode);
    for (int index = 1; index < 8; index++)
        ((CCNode *)self->getChildren()->objectAtIndex(1))->removeMeAndCleanup();

    // Someshit Button
    auto modMenuBtn = CCMenu::create();

    auto tggOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
    auto tggOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
    tggOff->setScale(0.7f);
    tggOn->setScale(0.7f);
    auto noClipButton = CCMenuItemToggler::create(tggOff, tggOn, self, menu_selector(PauseLayerInit::noclipActive));
    noClipButton->toggle(noclipMode);

    modMenuBtn->setPosition({size.width - 35 - 159, size.height - 128});
    modMenuBtn->addChild(noClipButton);
    modMenuBtn->setAnchorPoint({1, 0});

    auto buttonNoclipName = CCLabelBMFont::create("Noclip", "bigFont.fnt");
    buttonNoclipName->setScale(0.4f);
    buttonNoclipName->setAnchorPoint({0.5, 0});
    buttonNoclipName->setPosition(size.width - 175 + noClipButton->getContentSize().width, size.height - 128 - 6);

    auto settingBtnTexture = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
    settingBtnTexture->setScale(0.7f);
    auto buttonSetting = CCMenuItemSpriteExtra::create(settingBtnTexture, self, menu_selector(PauseLayerInit::setting));
    buttonSetting->setPosition({105, 0});

    auto challengeBtntexture = CCSprite::createWithSpriteFrameName("GJ_starBtn_001.png");
    challengeBtntexture->setScale(0.7f);
    auto buttonChallenge = CCMenuItemSpriteExtra::create(challengeBtntexture, self, menu_selector(PauseLayerInit::challenge));
    buttonChallenge->setPosition({145, 0});

    modMenuBtn->addChild(buttonSetting);
    modMenuBtn->addChild(buttonChallenge);
    self->addChild(modMenuBtn, 50);
    self->addChild(buttonNoclipName, 50);
};